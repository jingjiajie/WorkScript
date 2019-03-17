#include "WorkScriptCompiler.h"
#include "Options.h"
#include <Program.h>
#include <Expression.h>
#include <Report.h>
#include <Exception.h>
#include <Locales.h>
#include <FunctionFragment.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/Triple.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/CodeGen/LinkAllAsmWriterComponents.h>
#include <llvm/CodeGen/LinkAllCodegenComponents.h>
#include <llvm/CodeGen/MIRParser/MIRParser.h>
#include <llvm/CodeGen/MachineFunctionPass.h>
#include <llvm/CodeGen/MachineModuleInfo.h>
#include <llvm/CodeGen/TargetPassConfig.h>
#include <llvm/CodeGen/TargetSubtargetInfo.h>
#include <llvm/IR/AutoUpgrade.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/DiagnosticInfo.h>
#include <llvm/IR/DiagnosticPrinter.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/MC/SubtargetFeature.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/WithColor.h>
#include <memory>

using namespace std;
using namespace WorkScript;
using namespace llvm;

WorkScriptCompiler::WorkScriptCompiler()
{

}

void WorkScriptCompiler::run()
{
  vector<std::string> objFiles;
  this->compile(&objFiles);
  this->link(objFiles);
}

static std::unique_ptr<ToolOutputFile> GetOutputStream(const string &filePath, bool isBinary)
{
  std::error_code EC;
  sys::fs::OpenFlags OpenFlags = sys::fs::F_None;
  if (!isBinary)
    OpenFlags |= sys::fs::F_Text;
  auto FDOut = llvm::make_unique<ToolOutputFile>(filePath, EC, OpenFlags);
  if (EC) {
    WithColor::error() << EC.message() << '\n';
    return nullptr;
  }

  return FDOut;
}

struct LLCDiagnosticHandler : public DiagnosticHandler {
    bool *HasError;
    explicit LLCDiagnosticHandler(bool *HasErrorPtr) : HasError(HasErrorPtr) {}
    bool handleDiagnostics(const DiagnosticInfo &DI) override {
      if (DI.getSeverity() == DS_Error)
        *HasError = true;

      if (auto *Remark = dyn_cast<DiagnosticInfoOptimizationBase>(&DI))
        if (!Remark->isEnabled())
          return true;

      DiagnosticPrinterRawOStream DP(errs());
      errs() << LLVMContext::getDiagnosticMessagePrefix(DI.getSeverity()) << ": ";
      DI.print(DP);
      errs() << "\n";
      return true;
    }
};

static void InlineAsmDiagHandler(const SMDiagnostic &SMD, void *Context,
                                 unsigned LocCookie) {
  bool *HasError = static_cast<bool *>(Context);
  if (SMD.getKind() == SourceMgr::DK_Error)
    *HasError = true;

  SMD.print(nullptr, errs());

  // For testing purposes, we print the LocCookie here.
  if (LocCookie)
    WithColor::note() << "!srcloc = " << LocCookie << "\n";
}

static bool addPass(PassManagerBase &PM,
                    StringRef PassName, TargetPassConfig &TPC) {
  if (PassName == "none")
    return false;

  const PassRegistry *PR = PassRegistry::getPassRegistry();
  const PassInfo *PI = PR->getPassInfo(PassName);
  if (!PI) {
    WithColor::error(errs())
            << "run-pass " << PassName << " is not registered.\n";
    return true;
  }

  Pass *P;
  if (PI->getNormalCtor())
    P = PI->getNormalCtor()();
  else {
    WithColor::error(errs())
            << "cannot create pass: " << PI->getPassName() << "\n";
    return true;
  }
  std::string Banner = std::string("After ") + std::string(P->getPassName());
  PM.add(P);
  TPC.printAndVerify(Banner);

  return false;
}

static int compileModule(LLVMContext &llvmContext, vector<string> *outObjFiles) {
  // Load the module to be compiled...
  SMDiagnostic Err;
  Triple TheTriple;


  	Program program(InputFilename);
	auto M = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
	try
    {
        program.generateLLVMIR(&llvmContext, M.get());
    }catch (const CancelException &ex){
        ex.rethrowAbove(CancelScope::COMPILATION);
	}
	Report *report = program.getReport();
	if(report->getErrorCount() > 0)
    {
      report->dump();
      return 1;
    }


  bool SkipModule = MCPU == "help" ||
                    (!MAttrs.empty() && MAttrs.front() == "help");

  // If user just wants to list available options, skip module loading
  if (!SkipModule) {

    // If we are supposed to override the target triple, do so now.
    if (!TargetTriple.empty())
      M->setTargetTriple(Triple::normalize(TargetTriple));
    TheTriple = Triple(M->getTargetTriple());
  } else {
    TheTriple = Triple(Triple::normalize(TargetTriple));
  }

  if (TheTriple.getTriple().empty())
    TheTriple.setTriple(sys::getDefaultTargetTriple());

  // Get the target specific parser.
  std::string Error;
  const Target *TheTarget = TargetRegistry::lookupTarget(MArch, TheTriple,
                                                         Error);
  if (!TheTarget) {
    WithColor::error(errs()) << Error;
    return 1;
  }

  std::string CPUStr = getCPUStr(), FeaturesStr = getFeaturesStr();

  CodeGenOpt::Level OLvl = CodeGenOpt::Default;
  switch (OptLevel) {
    default:
      WithColor::error(errs()) << "invalid optimization level.\n";
          return 1;
    case ' ': break;
    case '0': OLvl = CodeGenOpt::None; break;
    case '1': OLvl = CodeGenOpt::Less; break;
    case '2': OLvl = CodeGenOpt::Default; break;
    case '3': OLvl = CodeGenOpt::Aggressive; break;
  }

  TargetOptions Options = InitTargetOptionsFromCodeGenFlags();
  Options.DisableIntegratedAS = NoIntegratedAssembler;
  Options.MCOptions.ShowMCEncoding = ShowMCEncoding;
  Options.MCOptions.MCUseDwarfDirectory = EnableDwarfDirectory;
  Options.MCOptions.AsmVerbose = AsmVerbose;
  Options.MCOptions.PreserveAsmComments = PreserveComments;
  Options.MCOptions.IASSearchPaths = IncludeDirs;
  Options.MCOptions.SplitDwarfFile = SplitDwarfFile;

  std::unique_ptr<TargetMachine> Target(TheTarget->createTargetMachine(
          TheTriple.getTriple(), CPUStr, FeaturesStr, Options, getRelocModel(),
          getCodeModel(), OLvl));

  assert(Target && "Could not allocate target machine!");

  // If we don't have a module then just exit now. We do this down
  // here since the CPU/Feature help is underneath the target machine
  // creation.
  if (SkipModule)
    return 0;

  assert(M && "Should have exited if we didn't have a module!");
  if (FloatABIForCalls != FloatABI::Default)
    Options.FloatABIType = FloatABIForCalls;

  // Figure out where we are going to send the output.
  string objFile = InputFilename;
  objFile = objFile + ".o";
  outObjFiles->push_back(objFile);
  std::unique_ptr<ToolOutputFile> Out = GetOutputStream(objFile, true);
  if (!Out) return 1;

  std::unique_ptr<ToolOutputFile> DwoOut;
  if (!SplitDwarfOutputFile.empty()) {
    std::error_code EC;
    DwoOut = llvm::make_unique<ToolOutputFile>(SplitDwarfOutputFile, EC,
                                               sys::fs::F_None);
    if (EC) {
      WithColor::error(errs()) << EC.message() << '\n';
      return 1;
    }
  }

  // Build up all of the passes that we want to do to the module.
  legacy::PassManager PM;

  // Add an appropriate TargetLibraryInfo pass for the module's triple.
  TargetLibraryInfoImpl TLII(Triple(M->getTargetTriple()));

  // The -disable-simplify-libcalls flag actually disables all builtin optzns.
  if (DisableSimplifyLibCalls)
    TLII.disableAllFunctions();
  PM.add(new TargetLibraryInfoWrapperPass(TLII));

  // Add the target data from the target machine, if it exists, or the module.
  M->setDataLayout(Target->createDataLayout());

  // This needs to be done after setting datalayout since it calls verifier
  // to check debug info whereas verifier relies on correct datalayout.
  UpgradeDebugInfo(*M);

  // Verify module immediately to catch problems before doInitialization() is
  // called on any passes.
  if (!NoVerify && verifyModule(*M, &errs())) {
    std::string Prefix = InputFilename;
    WithColor::error(errs(), Prefix) << "input module is broken!\n";
    return 1;
  }

  // Override function attributes based on CPUStr, FeaturesStr, and command line
  // flags.
  setFunctionAttributes(CPUStr, FeaturesStr, *M);


    raw_pwrite_stream *OS = &Out->os();

  SmallVector<char,0> Buffer;
  std::unique_ptr<raw_svector_ostream> BOS;
  if (!Out->os().supportsSeeking()) {
    BOS = std::unique_ptr<raw_svector_ostream>(new raw_svector_ostream(Buffer));
    OS = BOS.get();
  }

    LLVMTargetMachine &LLVMTM = static_cast<LLVMTargetMachine&>(*Target);
    MachineModuleInfo *MMI = new MachineModuleInfo(&LLVMTM);

  if (Target->addPassesToEmitFile(PM, *OS, TargetMachine::CGFT_ObjectFile, NoVerify, MMI)) {
      WithColor::warning(errs())
              << "target does not support generation of this"
              << " file type!\n";
      return 1;
    }

    // Before executing passes, print the final values of the LLVM options.
    cl::PrintOptionValues();

    PM.run(*M);

    auto HasError =
            ((const LLCDiagnosticHandler *)(llvmContext.getDiagHandlerPtr()))->HasError;
    if (*HasError)
      return 1;

  // Declare success.
  Out->keep();
  if (DwoOut)
    DwoOut->keep();

  return 0;
}

int WorkScriptCompiler::compile(std::vector<std::string> *outObjFilePaths)
{
  // Enable debug stream buffering.
  EnableDebugBuffering = true;

  LLVMContext Context;

  Context.setDiscardValueNames(DiscardValueNames);

  // Set a diagnostic handler that doesn't exit on the first error
  bool HasError = false;
  Context.setDiagnosticHandler(
          llvm::make_unique<LLCDiagnosticHandler>(&HasError));
  Context.setInlineAsmDiagnosticHandler(InlineAsmDiagHandler, &HasError);

  if (PassRemarksWithHotness)
    Context.setDiagnosticsHotnessRequested(true);

  if (PassRemarksHotnessThreshold)
    Context.setDiagnosticsHotnessThreshold(PassRemarksHotnessThreshold);

  std::unique_ptr<ToolOutputFile> YamlFile;
  if (RemarksFilename != "") {
    std::error_code EC;
    YamlFile =
            llvm::make_unique<ToolOutputFile>(RemarksFilename, EC, sys::fs::F_None);
    if (EC) {
      WithColor::error(errs()) << EC.message() << '\n';
      return 1;
    }
    Context.setDiagnosticsOutputFile(
            llvm::make_unique<yaml::Output>(YamlFile->os()));
  }

  // Compile the module TimeCompilations times to give better compile time
  // metrics.
  if (int RetVal = compileModule(Context, outObjFilePaths))
    return RetVal;

  if (YamlFile)
    YamlFile->keep();
  return 0;
}
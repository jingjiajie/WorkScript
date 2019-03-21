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


CompileResult WorkScriptCompiler::compile(const CmdArgs &args)
{
    LLVMContext llvmContext;

    Program program(InputFilename);
    auto M = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
    try {
        program.generateLLVMIR(&llvmContext, M.get());
    } catch (const CancelException &ex) {
        ex.rethrowAbove(CancelScope::COMPILATION);
    }
    Report *report = program.getReport();
    if (report->getErrorCount() > 0) {
        report->dump();
        return CompileResult::ERROR;
    }
    return CompileResult::OK;
}
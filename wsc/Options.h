#ifndef OPTIONS_H
#define OPTIONS_H

#include <llvm/ADT/StringExtras.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/MC/SubtargetFeature.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Host.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <string>

extern llvm::cl::opt<bool> SaveTemps;

extern llvm::cl::opt<std::string> MArch;

extern llvm::cl::opt<std::string> MCPU;

extern llvm::cl::list<std::string> MAttrs;

extern llvm::cl::opt<llvm::Reloc::Model> RelocModel;

LLVM_ATTRIBUTE_UNUSED extern llvm::Optional<llvm::Reloc::Model> getRelocModel();

extern llvm::cl::opt<llvm::ThreadModel::Model> TMModel;

extern llvm::cl::opt<llvm::CodeModel::Model> CMModel;

LLVM_ATTRIBUTE_UNUSED extern llvm::Optional<llvm::CodeModel::Model> getCodeModel();

extern llvm::cl::opt<llvm::ExceptionHandling> ExceptionModel;

extern llvm::cl::opt<bool> DisableFPElim;

extern llvm::cl::opt<bool> EnableUnsafeFPMath;

extern llvm::cl::opt<bool> EnableNoInfsFPMath;

extern llvm::cl::opt<bool> EnableNoNaNsFPMath;

extern llvm::cl::opt<bool> EnableNoSignedZerosFPMath;

extern llvm::cl::opt<bool> EnableNoTrappingFPMath;

extern llvm::cl::opt<llvm::FPDenormal::DenormalMode> DenormalMode;

extern llvm::cl::opt<bool> EnableHonorSignDependentRoundingFPMath;

extern llvm::cl::opt<llvm::FloatABI::ABIType> FloatABIForCalls;

extern llvm::cl::opt<llvm::FPOpFusion::FPOpFusionMode> FuseFPOps;

extern llvm::cl::opt<bool> DontPlaceZerosInBSS;

extern llvm::cl::opt<bool> EnableGuaranteedTailCallOpt;

extern llvm::cl::opt<bool> DisableTailCalls;

extern llvm::cl::opt<bool> StackSymbolOrdering;

extern llvm::cl::opt<unsigned> OverrideStackAlignment;

extern llvm::cl::opt<bool> StackRealign;

extern llvm::cl::opt<std::string> TrapFuncName;

extern llvm::cl::opt<bool> UseCtors;

extern llvm::cl::opt<bool> RelaxELFRelocations;

extern llvm::cl::opt<bool> DataSections;

extern llvm::cl::opt<bool> FunctionSections;

extern llvm::cl::opt<bool> EmulatedTLS;

extern llvm::cl::opt<bool> UniqueSectionNames;

extern llvm::cl::opt<llvm::EABI> EABIVersion;

extern llvm::cl::opt<llvm::DebuggerKind> DebuggerTuningOpt;

extern llvm::cl::opt<bool> EnableStackSizeSection;

extern llvm::cl::opt<std::string> InputFilename;

extern llvm::cl::opt<std::string> OutputFilename;

extern llvm::cl::opt<std::string> SplitDwarfOutputFile;

extern llvm::cl::opt<bool> NoIntegratedAssembler;

extern llvm::cl::opt<bool> PreserveComments;

// Determine optimization level.
extern llvm::cl::opt<char> OptLevel;

extern llvm::cl::opt<std::string> TargetTriple;

extern llvm::cl::opt<std::string> SplitDwarfFile;

extern llvm::cl::opt<bool> NoVerify;

extern llvm::cl::opt<bool> DisableSimplifyLibCalls;
extern llvm::cl::opt<bool> ShowMCEncoding;

extern llvm::cl::opt<bool> EnableDwarfDirectory;

extern llvm::cl::opt<bool> AsmVerbose;

extern llvm::cl::opt<bool> DiscardValueNames;

extern llvm::cl::list<std::string> IncludeDirs;

extern llvm::cl::opt<bool> PassRemarksWithHotness;

extern llvm::cl::opt<unsigned> PassRemarksHotnessThreshold;
extern llvm::cl::opt<std::string> RemarksFilename;

extern llvm::ManagedStatic<std::vector<std::string>> RunPassNames;

struct RunPassOption
{
    void operator=(const std::string &Val) const
    {
        if (Val.empty())
            return;
        llvm::SmallVector<llvm::StringRef, 8> PassNames;
        llvm::StringRef(Val).split(PassNames, ',', -1, false);
        for (auto PassName : PassNames)
            RunPassNames->push_back(PassName);
    }
};

extern RunPassOption RunPassOpt;

extern llvm::cl::opt<RunPassOption, true, llvm::cl::parser<std::string>> RunPass;


extern llvm::cl::opt<llvm::MCTargetOptions::AsmInstrumentation> AsmInstrumentation;

extern llvm::cl::opt<bool> RelaxAll;

extern llvm::cl::opt<bool> IncrementalLinkerCompatible;

extern llvm::cl::opt<bool> PIECopyRelocations;

extern llvm::cl::opt<int> DwarfVersion;

extern llvm::cl::opt<bool> ShowMCInst;

extern llvm::cl::opt<bool> FatalWarnings;

extern llvm::cl::opt<bool> NoWarn;

extern llvm::cl::opt<bool> NoDeprecatedWarn;

extern llvm::cl::opt<std::string> ABIName;


/*********************************************************************************/

extern llvm::MCTargetOptions InitMCTargetOptionsFromFlags();
extern llvm::TargetOptions InitTargetOptionsFromCodeGenFlags();
LLVM_ATTRIBUTE_UNUSED extern std::string getCPUStr();
LLVM_ATTRIBUTE_UNUSED extern std::string getFeaturesStr();
LLVM_ATTRIBUTE_UNUSED extern std::vector<std::string> getFeatureList();
LLVM_ATTRIBUTE_UNUSED extern void setFunctionAttributes(llvm::StringRef CPU, llvm::StringRef Features, llvm::Module &M);

#endif //OPTIONS_H

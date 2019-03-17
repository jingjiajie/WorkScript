#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"
#include "Options.h"
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
#include <llvm/Pass.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Transforms/Utils/Cloning.h>

using namespace llvm;

using namespace std;
using namespace WorkScript;

static void initLLVM(int argc, const char **argv);
static void initArgs(int argc, const char **argv);

int main(int argc, const char **argv) {
	setlocale(LC_CTYPE,"");
	InitLLVM X(argc, argv);
	initLLVM(argc, argv);
	initArgs(argc, argv);

	WorkScriptCompiler compiler;
	compiler.run();
}

static void initLLVM(int argc, const char **argv)
{
	// Initialize targets first, so that --version shows registered targets.
	InitializeAllTargets();
	InitializeAllTargetMCs();
	InitializeAllAsmPrinters();
	InitializeAllAsmParsers();

	// Initialize codegen and IR passes used by llc so that the -print-after,
	// -print-before, and -stop-after options work.
	PassRegistry *Registry = PassRegistry::getPassRegistry();
	initializeCore(*Registry);
	initializeCodeGen(*Registry);
	initializeLoopStrengthReducePass(*Registry);
	initializeLowerIntrinsicsPass(*Registry);
	initializeEntryExitInstrumenterPass(*Registry);
	initializePostInlineEntryExitInstrumenterPass(*Registry);
	initializeUnreachableBlockElimLegacyPassPass(*Registry);
	initializeConstantHoistingLegacyPassPass(*Registry);
	initializeScalarOpts(*Registry);
	initializeVectorization(*Registry);
	initializeScalarizeMaskedMemIntrinPass(*Registry);
	initializeExpandReductionsPass(*Registry);

	// Initialize debugging passes.
	initializeScavengerTestPass(*Registry);

}

static void initArgs(int argc, const char **argv)
{
//	// Register the target printer for --version.
//	cl::AddExtraVersionPrinter(TargetRegistry::printRegisteredTargetsForVersion);

    cl::ParseCommandLineOptions(argc, argv, "WorkScript Compiler\n");
    if (InputFilename.empty()) {
        fprintf(stderr, "%ls", L"请输入文件名\n");
        exit(1);
    }

    if(OutputFilename.empty()){
        string i = InputFilename;
        auto slashPos = InputFilename.find_last_of('/');
        string dir;
        if(slashPos != string::npos){
            dir = InputFilename.substr(0, slashPos);
        }
        OutputFilename = dir + "/a.out";
    }
}
#include "WorkScriptEngine.h"
#include "Program.h"
#include "Expression.h"
#include "Report.h"
#include "Exception.h"
#include "Locales.h"
#include "FunctionFragment.h"
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>

using namespace std;
using namespace WorkScript;

WorkScriptEngine::WorkScriptEngine()
{
}


WorkScriptEngine::~WorkScriptEngine()
{
}

void WorkScriptEngine::run(const char * filePath)
{
	llvm::InitializeNativeTarget();
	llvm::InitializeNativeTargetAsmParser();
	llvm::InitializeNativeTargetAsmPrinter();
	llvm::InitializeNativeTargetDisassembler();
	Program program(filePath);
	llvm::LLVMContext llvmContext;
	auto llvmModule = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
	try
    {
        program.generateLLVMIR(&llvmContext, llvmModule.get());
    }catch (const CancelException &ex){
        ex.rethrowAbove(CancelScope::COMPILATION);
	}
	Report *report = program.getReport();
	if(report->getErrorCount() > 0){
		report->dump();
		return;
	}
	printf("IR dump:\n");
	llvmModule->print(llvm::outs(),nullptr);
	printf("\n\n");
	string errorStr;

	llvm::EngineBuilder b(std::move(llvmModule));

	//llvm::RTDyldMemoryManager* RTDyldMM = NULL;
	b.setEngineKind(llvm::EngineKind::JIT)
		.setErrorStr(&errorStr);
	//.setVerifyModules(true)
	//.setMCJITMemoryManager(std::unique_ptr<llvm::RTDyldMemoryManager>(RTDyldMM))
	//.setOptLevel(llvm::CodeGenOpt::Default)
	auto e = b.create();
	e->finalizeObject();
	printf("开始JIT执行：\n");
	typedef int(*TFMAIN)();
	TFMAIN fmain = (TFMAIN)e->getPointerToNamedFunction("main");
	//double startTime = clock();
	auto ret = fmain();
	//double endTime = clock();
	printf("\n执行完毕，返回值：%d\n", ret);
}


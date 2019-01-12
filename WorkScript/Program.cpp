#include "stdafx.h"
#include "Program.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "VoidType.h"
#include "FunctionType.h"
#include "Function.h"
#include "FunctionCache.h"

using namespace std;
using namespace WorkScript;

Program::Program()
	:globalAbstractContext(nullptr, 0)
{

}

Program::~Program()
{

}


void WorkScript::Program::generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule)
{
	FunctionCache funcCache;
	InstantializeContext funcInstCtx(&this->globalAbstractContext, &funcCache);
	GenerateContext ctx(llvmContext, llvmModule, nullptr, &funcInstCtx);
	Function *funcMain = this->globalAbstractContext.getFirstFunction(L"main", {});
	funcMain->generateLLVMIR(&ctx);
}
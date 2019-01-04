#include "stdafx.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "Program.h"
#include "MultiValueExpression.h"
#include "Utils.h"
#include "Function.h"
#include "InstantializeContext.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::CallExpression::generateIR(GenerateContext * context)
{
	//获取函数声明
	auto paramTypes = this->parameters->getTypes(context->getInstantializeContext());
	Function *func = this->getProgram()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(L"未找到函数：" + func->getName());
	}
	//生成LLVM函数调用
	auto llvmArgs = this->parameters->getLLVMArgs(context);
	auto prevInstCtx = context->getInstantializeContext();
	auto builder = context->getIRBuilder();
	SymbolTable newInstTable;
	InstantializeContext newInstCtx(this->expressionInfo.getAbstractContext(), this->expressionInfo.getProgram()->getFunctionCache(), &newInstTable);
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(Function::getStdParameterName(i), paramType);
	}
	context->setInstantializeContext(&newInstCtx);
	llvm::Function *llvmFunc = func->getLLVMFunction(context);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
	context->setInstantializeContext(prevInstCtx);
	return ret;
}

Type * CallExpression::getType(InstantializeContext *context) const
{
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->getProgram()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(L"未找到函数：" + this->functionName);
	}
	SymbolTable newInstTable;
	InstantializeContext newInstCtx(this->expressionInfo.getAbstractContext(), this->getProgram()->getFunctionCache(), &newInstTable);
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(Function::getStdParameterName(i), paramType);
	}
	return func->getReturnType(&newInstCtx);
}

std::wstring CallExpression::toString() const
{
	auto leftStr = this->functionName;
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

ExpressionType CallExpression::getExpressionType() const
{
	return ExpressionType::CALL_EXPRESSION;
}

Expression * WorkScript::CallExpression::clone() const
{
	auto newInstance = new thistype(expressionInfo, functionName, parameters);
	return newInstance;
}
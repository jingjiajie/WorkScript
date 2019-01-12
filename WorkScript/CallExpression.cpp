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
	//��ȡ��������
	auto paramTypes = this->parameters->getTypes(context->getInstantializeContext());
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(this->expressionInfo.getLocation(), L"δ�ҵ�������" + this->functionName);
	}
	//����LLVM��������
	auto outerInstCtx = context->getInstantializeContext();
	auto builder = context->getIRBuilder();
	SymbolTable newInstTable;
	InstantializeContext innerInstCtx(this->expressionInfo.getAbstractContext(), this->expressionInfo.getProgram()->getFunctionCache(), &newInstTable);
	//ʹ�÷��ű���
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(Function::getStdParameterName(i), paramType);
	}
	auto llvmArgs = this->parameters->getLLVMArgs(context, func->getParameterTypes(&innerInstCtx)); //���������context����innerInstCtx֮ǰִ��
	context->setInstantializeContext(&innerInstCtx);
	llvm::Function *llvmFunc = func->getLLVMFunction(context);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
	context->setInstantializeContext(outerInstCtx);
	return ret;
}

Type * CallExpression::getType(InstantializeContext *context) const
{
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(this->expressionInfo.getLocation(), L"δ�ҵ�������" + this->functionName);
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
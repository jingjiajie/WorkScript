#include <sstream>
#include <string>
#include "Call.h"
#include "Variable.h"
#include "Program.h"
#include "MultiValue.h"
#include "Utils.h"
#include "Function.h"
#include "InstantialContext.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::Call::generateIR(GenerateContext * context)
{
	auto outerInstCtx = context->getInstantialContext();
	//获取函数声明
	auto paramTypes = this->parameters->getTypes(context->getInstantialContext());
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未找到函数：" + this->toFunctionDeclString(outerInstCtx));
	}
	//生成LLVM函数调用
	auto builder = context->getIRBuilder();
	SymbolTable newInstTable;
	InstantialContext innerInstCtx(this->expressionInfo.getAbstractContext(), this->expressionInfo.getProgram()->getFunctionCache(), &newInstTable);
	//使用符号表传参
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(this->getDebugInfo(), Function::getStdParameterName(i), paramType, LinkageType::DEFAULT);
	}
	auto llvmArgs = this->parameters->getLLVMArgs(context, func->getParameterTypes(this->getDebugInfo(), &innerInstCtx)); //这个必须在context设置innerInstCtx之前执行
    context->setInstantialContext(&innerInstCtx);
	llvm::Function *llvmFunc = func->getLLVMFunction(this->getDebugInfo(), context);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
    context->setInstantialContext(outerInstCtx);
	return ret;
}

Type * Call::getType(InstantialContext *context) const
{
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
	    auto str = this->toFunctionDeclString(context);
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未找到函数：" + str);
	}
	SymbolTable newInstTable;
	InstantialContext newInstCtx(this->expressionInfo.getAbstractContext(), this->getProgram()->getFunctionCache(), &newInstTable);
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(this->getDebugInfo(), Function::getStdParameterName(i), paramType, LinkageType::DEFAULT);
	}
	return func->getReturnType(this->getDebugInfo(), &newInstCtx);
}

std::wstring Call::toString() const
{
	auto leftStr = this->functionName;
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

std::wstring Call::toFunctionDeclString(InstantialContext *context) const
{
	wstringstream ss;
	ss << this->functionName;
	vector<Type*> paramTypes = this->parameters->getTypes(context);
	size_t paramCount = paramTypes.size();
	ss << L"(";
	for(size_t i=0;i<paramCount;++i){
		ss << paramTypes[i]->getName();
		if(i != paramCount - 1){
			ss << L", ";
		}
	}
	ss << L")";
	return ss.str();
}

ExpressionType Call::getExpressionType() const
{
	return ExpressionType::CALL_EXPRESSION;
}

Expression * WorkScript::Call::clone() const
{
	auto newInstance = new thistype(expressionInfo, functionName, parameters);
	return newInstance;
}
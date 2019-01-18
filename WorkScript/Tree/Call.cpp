#include <sstream>
#include <string>
#include "Call.h"
#include "Variable.h"
#include "Program.h"
#include "MultiValue.h"
#include "Utils.h"
#include "Function.h"
#include "InstantializeContext.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::Call::generateIR(GenerateContext * context)
{
	auto outerInstCtx = context->getInstantializeContext();
	//获取函数声明
	auto paramTypes = this->parameters->getTypes(context->getInstantializeContext());
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
		throw WorkScriptException(this->expressionInfo.getLocation(), L"未找到函数：" + this->toFunctionDeclString(outerInstCtx));
	}
	//生成LLVM函数调用
	auto builder = context->getIRBuilder();
	SymbolTable newInstTable;
	InstantializeContext innerInstCtx(this->expressionInfo.getAbstractContext(), this->expressionInfo.getProgram()->getFunctionCache(), &newInstTable);
	//使用符号表传参
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		Type *paramType = paramTypes[i];
		newInstTable.setSymbol(Function::getStdParameterName(i), paramType);
	}
	auto llvmArgs = this->parameters->getLLVMArgs(context, func->getParameterTypes(&innerInstCtx)); //这个必须在context设置innerInstCtx之前执行
	context->setInstantializeContext(&innerInstCtx);
	llvm::Function *llvmFunc = func->getLLVMFunction(context);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
	context->setInstantializeContext(outerInstCtx);
	return ret;
}

Type * Call::getType(InstantializeContext *context) const
{
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->expressionInfo.getAbstractContext()->getFirstFunction(this->functionName, paramTypes);
	if (!func) {
	    auto str = this->toFunctionDeclString(context);
		throw WorkScriptException(this->expressionInfo.getLocation(), L"未找到函数：" + str);
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

std::wstring Call::toString() const
{
	auto leftStr = this->functionName;
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

std::wstring Call::toFunctionDeclString(InstantializeContext *context) const
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
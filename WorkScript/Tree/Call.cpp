#include <sstream>
#include <string>
#include "Call.h"
#include "Variable.h"
#include "Program.h"
#include "MultiValue.h"
#include "Utils.h"
#include "Function.h"
#include "InstantialContext.h"
#include "Exception.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::Call::generateIR(GenerateContext * context)
{
	auto outerInstCtx = context->getInstantialContext();
	//获取函数声明
	auto paramTypes = this->parameters->getTypes(context->getInstantialContext());
 	Function *func = this->expressionInfo.getAbstractContext()->getFunction(this->getDebugInfo(),FunctionQuery(this->functionName, paramTypes,
																											   false));
	if (!func) {
		this->expressionInfo.getDebugInfo().getReport()->error(UndefinedSymbolError(this->expressionInfo.getDebugInfo(),
																					L"未找到函数：" +
																					this->toFunctionDeclString(
																							outerInstCtx)),
															   ErrorBehavior::CANCEL_EXPRESSION);
	}
	//生成LLVM函数调用
	auto builder = context->getIRBuilder();
	auto llvmArgs = this->parameters->getLLVMValues(context, paramTypes); //这个必须在context设置innerInstCtx之前执行
	llvm::Function *llvmFunc = func->getLLVMFunction(this->getDebugInfo(), context);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
    context->setInstantialContext(outerInstCtx);
	return ret;
}

Type * Call::getType(InstantialContext *context) const
{
    if(this->parameters->isNested(context)) context->setBlockAttribute(BlockAttributeItem::SFINAE, true);
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->expressionInfo.getAbstractContext()->getFunction(this->getDebugInfo(),FunctionQuery(this->functionName, paramTypes, false));
	if (!func) {
		if (context->getBlockAttribute(BlockAttributeItem::SFINAE)) {
			throw CancelException(CancelScope::FUNCTION_FRAGMENT);
		}
		else {
			auto str = this->toFunctionDeclString(context);
			this->expressionInfo.getDebugInfo().getReport()->error(UndefinedSymbolError(this->expressionInfo.getDebugInfo(), L"未找到函数：" + str), ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
	else
	{
		return func->getReturnType(this->getDebugInfo(), context);
	}
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
	return ExpressionType::CALL;
}

Expression * WorkScript::Call::clone() const
{
	auto newInstance = new thistype(expressionInfo, functionName, parameters);
	return newInstance;
}

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
#include "Locales.h"

using namespace WorkScript;
using namespace std;

GenerateResult Call::generateIR(GenerateContext * context) {
	auto outerInstCtx = context->getInstantialContext();
	//获取函数声明
	auto paramTypes = this->parameters->getTypes(outerInstCtx);
	Function *func = this->expressionInfo.getAbstractContext()->getFunction(
			this->getDebugInfo(),
			FunctionQuery(this->functionName, paramTypes, false));
	bool isParamNested = this->parameters->isNested(context->getInstantialContext());
	if (!func) {
		if (isParamNested) {
			throw CancelException(CancelScope::FUNCTION_FRAGMENT, true);
		} else {
			this->expressionInfo.getDebugInfo().getReport()->error(
					UndefinedSymbolError(this->expressionInfo.getDebugInfo(),
							L"未找到函数："
									+ this->toFunctionDeclString(outerInstCtx)),
					ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
	//生成LLVM函数调用
	auto builder = context->getIRBuilder();
	auto llvmArgs = this->parameters->getLLVMValues(context, paramTypes); //这个必须在context设置innerInstCtx之前执行
	llvm::Function *llvmFunc = func->getLLVMFunction(this->getDebugInfo(),
			context, paramTypes);
	auto ret = builder->CreateCall(llvmFunc, llvmArgs);
	context->setInstantialContext(outerInstCtx);
	return ret;
}

Type * Call::getType(InstantialContext *context) const {
	auto paramTypes = this->parameters->getTypes(context);
	Function *func = this->expressionInfo.getAbstractContext()->getFunction(
			this->getDebugInfo(),
			FunctionQuery(this->functionName, paramTypes, false));
	bool isParamNested = this->parameters->isNested(context);
	if (!func) {
		if (isParamNested) {
			throw CancelException(CancelScope::FUNCTION_FRAGMENT, true);
		} else {
			auto str = this->toFunctionDeclString(context);
			this->expressionInfo.getDebugInfo().getReport()->error(
					UndefinedSymbolError(this->expressionInfo.getDebugInfo(),
							L"无法n找到函数：" + str),
					ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
	try {
		Type *returnType = func->getReturnType(this->getDebugInfo(), context,
				paramTypes);
		return returnType;
	} catch (const CancelException &ex) {
		ex.rethrowAbove(CancelScope::EXPRESSION);
		if (!isParamNested) {
			auto str = this->toFunctionDeclString(context);
			this->getDebugInfo().getReport()->error(
					TypeMismatchedError(this->getDebugInfo(),
							L"无法推导" + str + L"的返回值类型"),
					ErrorBehavior::CANCEL_EXPRESSION);
		} else {
			throw;
		}
	}
}

std::wstring Call::toString() const {
	auto leftStr = this->functionName;
	auto paramStr = this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

std::wstring Call::toFunctionDeclString(InstantialContext *context) const {
	wstringstream ss;
	ss << this->functionName;
	vector<Type*> paramTypes = this->parameters->getTypes(context);
	size_t paramCount = paramTypes.size();
	ss << L"(";
	for (size_t i = 0; i < paramCount; ++i) {
		ss << paramTypes[i]->getName();
		if (i != paramCount - 1) {
			ss << L", ";
		}
	}
	ss << L")";
	return ss.str();
}

ExpressionType Call::getExpressionType() const {
	return ExpressionType::CALL;
}

Expression * WorkScript::Call::clone() const {
	auto newInstance = new thistype(expressionInfo, functionName, parameters);
	return newInstance;
}

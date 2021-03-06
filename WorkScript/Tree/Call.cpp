#include <sstream>
#include <string>
#include "Call.h"
#include "Variable.h"
#include "Module.h"
#include "MultiValue.h"
#include "Utils.h"
#include "Function.h"
#include "InstantialContext.h"
#include "Exception.h"
#include "Locales.h"

using namespace WorkScript;
using namespace std;

GenerateResult Call::generateIR(GenerateContext * context) {
	//获取函数声明
	DeducedInfo paramInfo = this->parameters->deduce(context);
	auto paramTypes = paramInfo.getTypes();
	auto paramDescs = paramInfo.getValueDescriptors();
	Function *func = this->expressionInfo.getAbstractContext()->getFunction(
			this->getDebugInfo(),
			FunctionQuery(this->functionName, paramTypes, false));
	bool isParamNested = this->parameters->isNested(context);
	if (!func) {
		if (isParamNested) {
			throw CancelException(CancelScope::FUNCTION_FRAGMENT, true);
		} else {
			this->expressionInfo.getDebugInfo().getReport()->error(
					UndefinedSymbolError(this->expressionInfo.getDebugInfo(),
							L"未找到函数："
									+ this->toFunctionDeclString(context)),
					ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
	//生成LLVM函数调用
	auto builder = context->getIRBuilder();
	vector<ValueDescriptor> varDescs;
	varDescs.reserve(paramDescs.size());
	for(ValueDescriptor &paramDesc : paramDescs){
		varDescs.push_back(ValueDescriptor(paramDesc.getType(), ValueKind::VARIABLE));
	}
	vector<llvm::Value*> llvmArgs = ValueDescriptor::generateLLVMConvert(this->getDebugInfo(), context, this->parameters, varDescs).getValues();
	llvm::Function *llvmFunc = func->getLLVMFunction(this->getDebugInfo(),
			context, paramTypes);
	return builder->CreateCall(llvmFunc, llvmArgs);
}

DeducedInfo Call::deduce(WorkScript::InstantialContext *context) const
{
	auto paramTypes = this->parameters->deduce(context).getTypes();
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
							L"无法找到函数：" + str),
					ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
	try {
		Type *returnType = func->getReturnType(this->getDebugInfo(), context,
				paramTypes);
		return ValueDescriptor(returnType, ValueKind::VALUE);
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
	vector<Type*> paramTypes = this->parameters->deduce(context).getTypes();
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

Expression * Call::clone() const {
	auto newInstance = new thistype(expressionInfo, functionName, parameters);
	return newInstance;
}

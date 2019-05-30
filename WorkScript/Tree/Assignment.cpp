#include "Assignment.h"
#include "Report.h"
#include "Utils.h"
#include "Variable.h"
#include "Exception.h"
#include "InstantialContext.h"
#include "GeneralSymbolInfo.h"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace WorkScript;

WorkScript::Assignment::Assignment(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression)
	: BinaryOperator(exprInfo,leftExpression,rightExpression)
{
	auto *leftVar = dynamic_cast<Variable*>(this->leftExpression);
	if (!leftVar) {
		this->getDebugInfo().getReport()->error(SyntaxError(this->getDebugInfo(), this->leftExpression->toString() + L"不可以赋值"), ErrorBehavior::CANCEL_EXPRESSION);
	}
}

GenerateResult WorkScript::Assignment::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE) {
		auto leftVar = (Variable *) this->leftExpression;
		SymbolInfo *info = this->syncSymbol(leftVar->getName(), context);
	}
	ValueDescriptor leftDesc = this->leftExpression->deduce(context);
	ValueDescriptor rightDesc = this->rightExpression->deduce(context);
	llvm::Value *rawVal = ValueDescriptor::generateLLVMConvert(this->expressionInfo.getDebugInfo(), context, this->rightExpression, ValueDescriptor(rightDesc.getType(), ValueKind::VALUE));
	//创建临时变量
	wstring tmpVarName = L"$";
	SymbolInfo *info = context->getInstanceSymbolTable()->setSymbol(GeneralSymbolInfo(this->getDebugInfo(), tmpVarName,
																   ValueDescriptor(rightDesc.getType(), ValueKind::VALUE),LinkageType::INTERNAL));
	((GeneralSymbolInfo*)info)->setLLVMValue(rawVal);
	Variable tmpVar(ExpressionInfo(nullptr, this->getDebugInfo(), this->expressionInfo.getAbstractContext()), L"$");

	llvm::Value *convertedVal = nullptr;
	if(leftDesc.getType()) {
		convertedVal = ValueDescriptor::generateLLVMConvert(this->expressionInfo.getDebugInfo(), context, &tmpVar,
											 ValueDescriptor(leftDesc.getType(), ValueKind::VALUE));
	}else{
		convertedVal = rawVal;
	}
	llvm::Value *var = ValueDescriptor::generateLLVMConvert(this->expressionInfo.getDebugInfo(), context, this->leftExpression, ValueDescriptor(leftDesc.getType(), ValueKind::VARIABLE));
	irBuilder->CreateStore(convertedVal, var);
	return rawVal;
}

ExpressionType Assignment::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT;
}

Expression * Assignment::clone() const
{
	return new thistype(expressionInfo,leftExpression,rightExpression);
}

DeducedInfo Assignment::deduce(InstantialContext *context) const
{
	auto leftExpr = this->leftExpression;
	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE) {
		auto leftVar = (Variable *) leftExpr;
		SymbolInfo *info = this->syncSymbol(leftVar->getName(), context);
	}
	ValueDescriptor rightDesc = this->rightExpression->deduce(context);
	if (rightDesc.getType()) return rightDesc;
	else {
		this->getDebugInfo().getReport()->error(
				UninferableTypeError(this->getDebugInfo(), L"无法推导" + this->leftExpression->toString() + L"的类型"),
				ErrorBehavior::CANCEL_EXPRESSION);
	}
}

std::wstring WorkScript::Assignment::getOperatorString() const
{
	return L"=";
}

SymbolInfo * WorkScript::Assignment::syncSymbol(const wstring &name, InstantialContext *ctx) const {
	SymbolInfo *oriSymbolInfo = ctx->getInstanceSymbolTable()->getSymbolInfo(name);
	ValueDescriptor rightDesc = this->rightExpression->deduce(ctx);
	if(oriSymbolInfo){
		ValueDescriptor oriDesc = oriSymbolInfo->deduce(ctx);
		if (oriDesc.getType() && !ValueDescriptor::convertableTo(this->getDebugInfo(),rightDesc, oriDesc)) {
            wstringstream ss;
            ss << L"表达式 ";
            ss << left << setw(20) << this->toString() << L" ";
            ss << L"无法将" << rightDesc.getType()->getName() << L"类型的值赋值给" << oriDesc.getType()->getName() << L"类型的变量";
            this->getDebugInfo().getReport()->error(IncompatibleTypeError(this->getDebugInfo(), ss.str()),
                                                    ErrorBehavior::CANCEL_EXPRESSION);
        }
		return oriSymbolInfo;
	}else {
		//等号隐式定义变量连接属性为INTERNAL
		return ctx->getInstanceSymbolTable()->setSymbol(
				GeneralSymbolInfo(this->getDebugInfo(), name,ValueDescriptor(rightDesc.getType(), ValueKind::VARIABLE), LinkageType::INTERNAL));
	}
}

#include "Assignment.h"
#include "Report.h"
#include "Utils.h"
#include "Variable.h"
#include "Exception.h"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace WorkScript;

WorkScript::Assignment::Assignment(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression)
	: BinaryOperator(exprInfo,leftExpression,rightExpression)
{
	Variable *leftVar = dynamic_cast<Variable*>(this->leftExpression);
	if (!leftVar) {
		this->getDebugInfo().getReport()->error(SyntaxError(this->getDebugInfo(), this->leftExpression->toString() + L"不可以赋值"), ErrorBehavior::CANCEL_EXPRESSION);
	}
}

GenerateResult WorkScript::Assignment::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	Type *leftType = this->getType(context->getInstantialContext());
	Type *rightType = this->rightExpression->getType(context->getInstantialContext());
	Type *promotedType = Type::getPromotedType(this->expressionInfo.getDebugInfo(), leftType, rightType);
	context->setLeftValue(false);
	llvm::Value *val = Type::generateLLVMTypeConvert(this->expressionInfo.getDebugInfo(), context, this->rightExpression, promotedType).getValue();
	context->setLeftValue(true);
	llvm::Value *var = this->leftExpression->generateIR(context).getValue();
	context->setLeftValue(false);
	irBuilder->CreateStore(val, var);
	return val;
}

ExpressionType Assignment::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT_EXPRESSION;
}

Expression * WorkScript::Assignment::clone() const
{
	return new thistype(expressionInfo,leftExpression,rightExpression);
}

Type * WorkScript::Assignment::getType(InstantialContext *context) const {
	auto leftExpr = this->getLeftExpression();
	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
		auto leftVar = (Variable *) leftExpr;
		SymbolInfo *info = this->syncSymbol(leftVar->getName(), context);
		return info->getType();
	}else{
		Type *rightType = this->rightExpression->getType(context);
		if(rightType) return rightType;
		else {
			this->getDebugInfo().getReport()->error(
					UninferableTypeError(this->getDebugInfo(), L"无法推导" + this->leftExpression->toString() + L"的类型"),
					ErrorBehavior::CANCEL_EXPRESSION);
		}
	}
}

std::wstring WorkScript::Assignment::getOperatorString() const
{
	return L":=";
}

SymbolInfo * WorkScript::Assignment::syncSymbol(const wstring &name, InstantialContext *ctx) const {
	SymbolInfo *oriSymbolInfo = ctx->getInstanceSymbolTable()->getSymbolInfo(name);
	Type *rightType = this->rightExpression->getType(ctx);
	if(oriSymbolInfo){
		Type *oriType = oriSymbolInfo->getType();
		if (oriType && !Type::convertableTo(this->getDebugInfo(), rightType, oriType))
		{
			wstringstream ss;
			ss << L"表达式 ";
			ss << left << setw(20) << this->toString() << L" ";
			ss << L"无法将" << rightType->getName() << L"类型的值赋值给" << oriType->getName() << L"类型的变量";
			this->getDebugInfo().getReport()->error(IncompatibleTypeError(this->getDebugInfo(), ss.str()),
													ErrorBehavior::CANCEL_EXPRESSION);
		}
		return oriSymbolInfo;
	}else {
		return ctx->getInstanceSymbolTable()->setSymbol(this->getDebugInfo(), name, rightType, LinkageType::DEFAULT);
	}
}

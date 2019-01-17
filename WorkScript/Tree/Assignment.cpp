#include "Assignment.h"
#include "SyntaxErrorException.h"
#include "Utils.h"
#include "Variable.h"

using namespace std;
using namespace WorkScript;

WorkScript::Assignment::Assignment(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression)
	: BinaryOperator(exprInfo,leftExpression,rightExpression)
{
	Variable *leftVar = dynamic_cast<Variable*>(this->leftExpression);
	if (!leftVar) {
		throw SyntaxErrorException(getLocation(), this->leftExpression->toString() + L"不可以赋值");
	}
}

GenerateResult WorkScript::Assignment::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	Type *leftType = this->getType(context->getInstantializeContext());
	Type *rightType = this->rightExpression->getType(context->getInstantializeContext());
	Type *promotedType = Type::getPromotedType(leftType, rightType);
	context->setLeftValue(false);
	llvm::Value *val = Type::generateLLVMTypeConvert(context, this->rightExpression, promotedType).getValue();
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

Type * WorkScript::Assignment::getType(InstantializeContext *context) const
{
	auto leftExpr = this->getLeftExpression();
	Type *leftType = leftExpr->getType(context);
	if (leftType)return leftType;
	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
		auto leftVar = (Variable*)leftExpr;
		this->makeSymbolOfRightType(leftVar->getName(), context);
	}
	else {
		throw WorkScriptException(this->getLocation(), L"无法推导" + this->leftExpression->toString() + L"的类型");
	}
	return this->rightExpression->getType(context);
}

std::wstring WorkScript::Assignment::getOperatorString() const
{
	return L":=";
}

Type * WorkScript::Assignment::makeSymbolOfRightType(const wstring &name, InstantializeContext *ctx) const
{
	auto rightExpr = this->getRightExpression();
	Type *rightType = rightExpr->getType(ctx);
	ctx->getInstanceSymbolTable()->setSymbol(name, rightType);
	return rightType;
}

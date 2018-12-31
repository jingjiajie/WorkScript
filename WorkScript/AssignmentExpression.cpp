#include "stdafx.h"
#include "AssignmentExpression.h"
#include "SyntaxErrorException.h"
#include "Utils.h"
#include "VariableExpression.h"

using namespace std;
using namespace WorkScript;

WorkScript::AssignmentExpression::AssignmentExpression(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression)
	: BinaryOperatorExpression(exprInfo,leftExpression,rightExpression)
{
	VariableExpression *leftVar = dynamic_cast<VariableExpression*>(this->leftExpression);
	if (!leftVar) {
		throw SyntaxErrorException(getLocation(), this->leftExpression->toString() + L"不可以赋值");
	}
}

GenerateResult WorkScript::AssignmentExpression::generateIR(GenerateContext * context)
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	auto irBuilder = context->getIRBuilder();
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType(context->getInstantializeContext());
	Type *rightType = rightExpr->getType(context->getInstantializeContext());
	TypeClassification leftCls = leftType->getClassification();
	TypeClassification rightCls = rightType->getClassification();
	Type *promotedType = Type::getPromotedType(leftType, rightType);
	context->setLeftValue(false);
	llvm::Value *val = Type::generateLLVMTypePromote(context, this->rightExpression, promotedType).getValue();
	context->setLeftValue(true);
	llvm::Value *var = this->leftExpression->generateIR(context).getValue();
	context->setLeftValue(false);
	irBuilder->CreateStore(val, var);
	return val;
}

ExpressionType AssignmentExpression::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT_EXPRESSION;
}

Expression * WorkScript::AssignmentExpression::clone() const
{
	return new thistype(expressionInfo,leftExpression,rightExpression);
}

Type * WorkScript::AssignmentExpression::getType(InstantializeContext *context) const
{
	return this->rightExpression->getType(context);
}

std::wstring WorkScript::AssignmentExpression::getOperatorString() const
{
	return L":=";
}
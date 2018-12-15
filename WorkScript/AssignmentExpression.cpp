#include "stdafx.h"
#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "UnassignableExpection.h"
#include "VariableExpression.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::AssignmentExpression::generateIR(GenerateContext * context)
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	auto irBuilder = context->getIRBuilder();
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType();
	Type *rightType = rightExpr->getType();
	TypeClassification leftCls = leftType->getClassification();
	TypeClassification rightCls = rightType->getClassification();
	Type *promotedType = Type::getPromotedType(leftType, rightType);

	llvm::Value *val = Type::generateLLVMTypePromote(context, this->rightExpression, promotedType).getValue();

	//TODO 如果右部也是变量会不会出问题
	llvm::Value *var = this->leftExpression->generateIR(context).getValue();
	return irBuilder->CreateStore(val, var);
}

ExpressionType AssignmentExpression::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT_EXPRESSION;
}

Expression * WorkScript::AssignmentExpression::clone() const
{
	return new thistype(program, this->leftExpression, this->rightExpression);
}

Type * WorkScript::AssignmentExpression::getType() const
{
	return this->rightExpression->getType();
}

std::wstring WorkScript::AssignmentExpression::getOperatorString() const
{
	return L":=";
}
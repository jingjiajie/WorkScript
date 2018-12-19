#include "stdafx.h"
#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "TemplateVariable.h"
#include "SyntaxErrorException.h"
#include "Utils.h"
#include "VariableExpression.h"

using namespace std;
using namespace WorkScript;

WorkScript::AssignmentExpression::AssignmentExpression(BINARY_OPERATOR_CTOR_FORMAL_PARAMS)
	: BINARY_OPERATOR_CTOR_CALL
{
	VariableExpression *leftV = dynamic_cast<VariableExpression*>(this->leftExpression);
if (leftV)return;
	TemplateVariableExpression *leftVar = dynamic_cast<TemplateVariableExpression*>(this->leftExpression);
	if (!leftVar) {
		throw SyntaxErrorException(location, this->leftExpression->toString() + L"�����Ը�ֵ");
	}
	Type *rightType = this->rightExpression->getType();
	Type *varType = leftVar->getType();
	if (varType && !varType->equals(rightType)) {
		throw SyntaxErrorException(location, L"�����Խ�" + rightType->getName() + L"���͵�ֵ��ֵ��" + varType->getName() + L"���͵ı���");
	}
	else {
		leftVar->promoteType(rightType);
	}
}

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
	context->setLeftValue(false);
	llvm::Value *val = Type::generateLLVMTypePromote(context, this->rightExpression, promotedType).getValue();
	context->setLeftValue(true);
	llvm::Value *var = this->leftExpression->generateIR(context).getValue();
	context->setLeftValue(false);
	irBuilder->CreateStore(val, var);
	return val;
}

Expression * WorkScript::AssignmentExpression::instantialize(InstantializeContext *context)
{
	return new AssignmentExpression(program, location, leftExpression->instantialize(context), rightExpression->instantialize(context));
}

ExpressionType AssignmentExpression::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT_EXPRESSION;
}

Expression * WorkScript::AssignmentExpression::clone() const
{
	return new thistype(BINARY_OPERATOR_MEMBERS);
}

Type * WorkScript::AssignmentExpression::getType() const
{
	return this->rightExpression->getType();
}

std::wstring WorkScript::AssignmentExpression::getOperatorString() const
{
	return L":=";
}
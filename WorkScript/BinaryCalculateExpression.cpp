#include "stdafx.h"
#include "BinaryCalculateExpression.h"
#include "UncalculatableException.h"

using namespace std;
using namespace WorkScript;

BinaryCalculateExpression::~BinaryCalculateExpression()
{
}

GenerateResult WorkScript::BinaryCalculateExpression::generateIR(GenerateContext * context)
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType();
	Type *rightType = rightExpr->getType();
	auto leftVal = leftExpr->generateIR(context).getValue();
	auto rightVal = rightExpr->generateIR(context).getValue();
	switch (leftType->getClassification())
	{
	case TypeClassification::INTEGER:
		if (rightType->getClassification() == TypeClassification::INTEGER) {


		}
	default:
		break;
	}
}

#include "stdafx.h"
#include "BinaryCompareExpression.h"
#include "IntegerType.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::BinaryCompareExpression::generateIR(GenerateContext * context)
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType(context->getInstantializeContext());
	Type *rightType = rightExpr->getType(context->getInstantializeContext());
	TypeClassification leftCls = leftType->getClassification();
	TypeClassification rightCls = rightType->getClassification();
	Type *promotedType = Type::getPromotedType(leftType, rightType);
	GenerateResult res = Type::generateLLVMTypePromote(context, leftExpr, rightExpr, promotedType);
	switch (promotedType->getClassification())
	{
	case TypeClassification::INTEGER: {
		return this->generateLLVMIRInteger(context, res.getValue(), res.getValue1(), (IntegerType*)promotedType);
	}

	case TypeClassification::FLOAT: {
		return this->generateLLVMIRFloat(context, res.getValue(), res.getValue1(), (FloatType*)promotedType);
	}
	default:
		goto UNSUPPORTED;
	}

UNSUPPORTED:
	throw WorkScriptException(L"˫Ŀ�Ƚ��������֧������" + leftType->getName() + L" �� " + rightType->getName());
}

IntegerType * WorkScript::BinaryCompareExpression::getType(InstantializeContext *context) const
{
	return this->getProgram()->getUInt1Type();
}

Expression * WorkScript::BinaryCompareExpression::clone() const
{
	return new BinaryCompareExpression(expressionInfo,leftExpression,rightExpression, compareType);
}

ExpressionType WorkScript::BinaryCompareExpression::getExpressionType() const
{
	return ExpressionType::BINARY_COMPARE_EXPRESSION;
}

GenerateResult WorkScript::BinaryCompareExpression::generateLLVMIRInteger(GenerateContext * context, llvm::Value * left, llvm::Value * right, IntegerType * promotedType) const
{
	auto irBuilder = context->getIRBuilder();
	llvm::Value *res;
	switch (this->compareType)
	{
	case CompareType::EQUAL:
		res = irBuilder->CreateICmpEQ(left, right);
		break;
	case CompareType::GREATER_THAN:
		if(promotedType->isSigned()) res = irBuilder->CreateICmpSGT(left, right);
		else res = irBuilder->CreateICmpUGT(left, right);
		break;
	case CompareType::GREATER_THAN_EQUAL:
		if (promotedType->isSigned()) res = irBuilder->CreateICmpSGE(left, right);
		else res = irBuilder->CreateICmpUGE(left, right);
		break;
	case CompareType::LESS_THAN:
		if (promotedType->isSigned()) res = irBuilder->CreateICmpSLT(left, right);
		else res = irBuilder->CreateICmpULT(left, right);
		break;
	case CompareType::LESS_THAN_EQUAL:
		if (promotedType->isSigned()) res = irBuilder->CreateICmpSLE(left, right);
		else res = irBuilder->CreateICmpULE(left, right);
		break;
	default:
		throw WorkScriptException(L"δ֪�ıȽ������");
	}

	return res;
}

GenerateResult WorkScript::BinaryCompareExpression::generateLLVMIRFloat(GenerateContext * context, llvm::Value * left, llvm::Value * right, FloatType * promotedType) const
{
	auto irBuilder = context->getIRBuilder();
	llvm::Value *res;
	switch (this->compareType)
	{
	case CompareType::EQUAL:
		res = irBuilder->CreateFCmpOEQ(left, right);
		break;
	case CompareType::GREATER_THAN:
		res = irBuilder->CreateFCmpOGT(left, right);
		break;
	case CompareType::GREATER_THAN_EQUAL:
		res = irBuilder->CreateFCmpOGE(left, right);
			break;
	case CompareType::LESS_THAN:
		res = irBuilder->CreateFCmpOLT(left, right);
		break;
	case CompareType::LESS_THAN_EQUAL:
		res = irBuilder->CreateFCmpOLE(left, right);
		break;
	default:
		throw WorkScriptException(L"δ֪�ıȽ������");
	}

	return res;
}

std::wstring WorkScript::BinaryCompareExpression::getOperatorString() const
{
	switch (this->compareType)
	{
	case CompareType::EQUAL:
		return L"==";
		break;
	case CompareType::GREATER_THAN:
		return L">";
		break;
	case CompareType::GREATER_THAN_EQUAL:
		return L"=>";
		break;
	case CompareType::LESS_THAN:
		return L"<";
		break;
	case CompareType::LESS_THAN_EQUAL:
		return L"<=";
		break;
	default:
		throw WorkScriptException(L"δ֪�ıȽ������");
	}
}

#include "stdafx.h"
#include "BinaryOperatorExpression.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "Function.h"
#include "IntegerExpression.h"
#include "FloatExpression.h"

using namespace std;
using namespace WorkScript;

BinaryOperatorExpression::~BinaryOperatorExpression()
{
	delete this->leftExpression;
	delete this->rightExpression;
}

GenerateResult WorkScript::BinaryOperatorExpression::generateIR(GenerateContext * context)
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType();
	Type *rightType = rightExpr->getType();
	TypeClassification leftCls = leftType->getClassification();
	TypeClassification rightCls = rightType->getClassification();
	GenerateResult res;
	switch (leftCls)
	{
		/*��ΪInteger�����*/
	case TypeClassification::INTEGER: {
		switch (rightCls)
		{
		case WorkScript::TypeClassification::INTEGER: {
			res = this->generateLLVMIRIntegerInteger(context, leftExpr, rightExpr);
			break;
		}
		case WorkScript::TypeClassification::FLOAT: {
			res = this->generateLLVMIRIntegerFloat(context, leftExpr, rightExpr);
			break;
		}
		default:
			goto UNSUPPORTED;
		}

	}
									  /*��ΪFloat�����*/
	case TypeClassification::FLOAT: {
		switch (rightCls)
		{
		case WorkScript::TypeClassification::INTEGER: {
			res = this->generateLLVMIRFloatInteger(context, leftVal, rightVal);
			break;
		}
		case WorkScript::TypeClassification::FLOAT: {
			res = this->generateLLVMIRFloatFloat(context, leftVal, rightVal);
			break;
		}
		default:
			goto UNSUPPORTED;
		}

	}
	default:
		goto UNSUPPORTED;
	}

	return res;
UNSUPPORTED:
	throw WorkScriptException(L"��֧�ֵļӷ���" + leftType->getName() + L" �� " + rightType->getName());
}

std::wstring WorkScript::BinaryOperatorExpression::toString() const
{
	auto left = this->leftExpression->toString();
	auto right = this->rightExpression->toString();
	return left + this->getOperatorString() + right;
}


const Type * WorkScript::BinaryOperatorExpression::getPromotedType(const Type * left, const Type * right) const
{
	switch (left->getClassification())
	{
	case TypeClassification::INTEGER: {
		IntegerType *leftIntegerType = (IntegerType*)left;
		switch (right->getClassification())
		{
		case TypeClassification::INTEGER: {
			IntegerType *rightIntegerType = (IntegerType*)right;
			auto leftLen = leftIntegerType->getLength();
			auto rightLen = rightIntegerType->getLength();
			if (leftLen > rightLen) return left;
			else if (leftLen < rightLen) return right;
			else if (leftIntegerType->isSigned() && !rightIntegerType->isSigned()) return right;
			else if (!leftIntegerType->isSigned() && rightIntegerType->isSigned()) return left;
			else return left;
		}
		case TypeClassification::FLOAT: {
			return right;
		}
		default:
			goto UNSUPPORTED;
		}
	}

	case TypeClassification::FLOAT: {
		FloatType *leftFloatType = (FloatType*)left;
		switch (right->getClassification())
		{
		case TypeClassification::INTEGER: {
			return left;
		}
		case TypeClassification::FLOAT: {
			FloatType *rightFloatType = (FloatType*)right;
			if (leftFloatType->getLength() > rightFloatType->getLength()) return left;
			else return right;
		}
		default:
			goto UNSUPPORTED;
		}
	}
	default:
		goto UNSUPPORTED;
	}

UNSUPPORTED:
	throw WorkScriptException(L"��֧�ֵ�����ת��" + left->getName() + L" �� " + right->getName());
}

GenerateResult WorkScript::BinaryOperatorExpression::generateLLVMTypePromote(GenerateContext * context, Expression * left, Expression * right) const
{
	auto builder = context->getIRBuilder();
	Type *leftType = left->getType();
	Type *rightType = right->getType();
	if (leftType->equals(rightType))
	{
		return GenerateResult(left->generateIR(context).getValue(), right->generateIR(context).getValue());
	}
	const Type *promotedType = this->getPromotedType(leftType,rightType);
	Type *srcType = nullptr;
	Expression *srcExpr = nullptr;
	if (promotedType->equals(leftType)) {
		srcType = rightType;
	}
	else {
		srcType = leftType;
	}
}

GenerateResult WorkScript::BinaryOperatorExpression::generateLLVMTypePromote(GenerateContext * context, Expression * expr, Type * targetType) const
{
	Type *srcType = expr->getType();
	llvm::Value *srcValue = expr->generateIR(context).getValue();
	if (targetType->equals(srcType)) {
		return GenerateResult(srcValue);
	}
	llvm::Type *targetLLVMType = targetType->getLLVMType(context);
	auto irBuilder = context->getIRBuilder();

	switch (srcType->getClassification())
	{
	case TypeClassification::INTEGER: /*Դ����ΪInteger*/ {
		IntegerType *srcIntegerType = (IntegerType*)srcType;
		switch (targetType->getClassification())
		{
		case TypeClassification::INTEGER:/*Ŀ������ΪInteger*/ {
			IntegerType *targetIntegerType = (IntegerType*)targetType;
			//���������ͬ���������޷��Ų�ͬ�����ý���ת��
			if (srcIntegerType->getLength() == targetIntegerType->getLength())return GenerateResult(srcValue);
			//��������Ƿ��з��Ž��з�����չ����λ��չ
			if (srcIntegerType->isSigned()) {
				return irBuilder->CreateSExt(srcValue, targetLLVMType);
			}
			else {
				return irBuilder->CreateZExt(srcValue, targetLLVMType);
			}
		}
		case TypeClassification::FLOAT: /*Ŀ������ΪFloat*/ {
			if (srcIntegerType->isSigned()) return irBuilder->CreateSIToFP(srcValue, targetLLVMType);
			else return irBuilder->CreateUIToFP(srcValue, targetLLVMType);
		}
		default:
			goto UNSUPPORTED;
		}

	}
		  
	case TypeClassification::FLOAT: /*Դ����ΪFloat*/ {
		FloatType *srcFloatType = (FloatType*)srcValue;
		switch (targetType->getClassification())
		{
		case TypeClassification::INTEGER: /*Ŀ������ΪInteger*/ {
			IntegerType *targetIntegerType = (IntegerType*)targetType;
			if(targetIntegerType->isSigned()) return irBuilder->CreateFPToSI(srcValue, targetLLVMType);
			else return irBuilder->CreateFPToUI(srcValue, targetLLVMType);
		}
		case TypeClassification::FLOAT: /*Ŀ������ΪFloat*/ {
			return irBuilder->CreateFPExt(srcValue, targetLLVMType);
		}
		default:
			goto UNSUPPORTED;
		}

	}
	default:
		goto UNSUPPORTED;
	}

UNSUPPORTED:
	throw WorkScriptException(L"��֧�ֵ�����ת����" + srcType->getName() + L" �� " + targetType->getName());
}

//
//void WorkScript::BinaryOperatorExpression::typePromoteIntegerInteger(const IntegerExpression * left, const IntegerExpression * right, IntegerExpression * outLeft, IntegerExpression * outRight)
//{
//	IntegerType *leftType = left->getType();
//	IntegerType *rightType = right->getType();
//	if (leftType->getLength() > rightType->getLength())
//	{
//
//	}
//}
//
//void WorkScript::BinaryOperatorExpression::typePromoteIntegerFloat(const IntegerExpression * left, const IntegerExpression * right, IntegerExpression * outLeft, IntegerExpression * outRight)
//{
//}
//
//void WorkScript::BinaryOperatorExpression::typePromoteFloatInteger(const IntegerExpression * left, const IntegerExpression * right, IntegerExpression * outLeft, IntegerExpression * outRight)
//{
//}
//
//void WorkScript::BinaryOperatorExpression::typePromoteFloatFloat(const IntegerExpression * left, const IntegerExpression * right, IntegerExpression * outLeft, IntegerExpression * outRight)
//{
//}

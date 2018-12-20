#include "stdafx.h"
#include "Type.h"
#include "Expression.h"
#include "Program.h"
#include "Function.h"
#include "StringExpression.h"
#include "IntegerType.h"
#include "FloatType.h"

using namespace WorkScript;
using namespace std;


//bool Type::isSubTypeOf(const Type *type) const
//{
//	const Type *curType = this;
//	while (curType) {
//		if (curType->equals(type)) {
//			return true;
//		}
//		if (curType->baseType != nullptr && curType->baseType != curType) {
//			curType = curType->baseType;
//		}
//		else {
//			return false;
//		}
//	}
//	return false;
//}
//
//void WorkScript::Type::addMemberFunction(Function * func)
//{
//	this->getProgram()->addFunction(func);
//	this->memberFunctions[func->getName()] = func;
//}

bool WorkScript::Type::equals(const Type * type) const
{
	return (this->getClassification() == type->getClassification()) && (this->name == type->name);
}


Type * Type::getPromotedType(Type * left, Type * right)
{
	if (!left)return right;
	if (!right)return left;
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

GenerateResult Type::generateLLVMTypePromote(GenerateContext * context, Expression * left, Expression * right, Type *promotedType)
{
	auto builder = context->getIRBuilder();
	Type *leftType = left->getType();
	Type *rightType = right->getType();
	if (promotedType->equals(leftType)) { //����������������
		return GenerateResult(left->generateIR(context).getValue(), Type::generateLLVMTypePromote(context, right, promotedType).getValue());
	}
	else if (promotedType->equals(rightType)) { //�����������Ҳ�����
		return GenerateResult(Type::generateLLVMTypePromote(context, left, promotedType).getValue(), right->generateIR(context).getValue());
	}
	else { //���߶���Ҫ����
		return GenerateResult(
			Type::generateLLVMTypePromote(context, left, promotedType).getValue(),
			Type::generateLLVMTypePromote(context, right, promotedType).getValue()
		);
	}
}

GenerateResult Type::generateLLVMTypePromote(GenerateContext * context, Expression * expr, Type * targetType)
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
			if (targetIntegerType->isSigned()) return irBuilder->CreateFPToSI(srcValue, targetLLVMType);
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

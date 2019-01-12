#include "stdafx.h"
#include "Type.h"
#include "Expression.h"
#include "Program.h"
#include "Function.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "VoidType.h"

using namespace WorkScript;
using namespace std;

//bool Type::isSubTypeOf(const Type *abstractType) const
//{
//	const Type *curType = this;
//	while (curType) {
//		if (curType->equals(abstractType)) {
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
	return (this->getClassification() == type->getClassification()) 
		&& (this->_const == type->_const)
		&& (this->_volatile == type->_volatile);
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
	//TODO Location信息
	throw WorkScriptException(Location(), L"不支持的类型转换" + left->getName() + L" 和 " + right->getName());
}

bool WorkScript::Type::convertableTo(Type * src, Type * target)
{
	if (src->equals(target))return true;
	switch (src->getClassification())
	{
	case TypeClassification::FLOAT:
	case TypeClassification::INTEGER:
	{
		switch (target->getClassification())
		{
		case TypeClassification::FLOAT:
		case TypeClassification::INTEGER:
		{
			return true;
		}
		default:
			return false;
		}
	}
	default:
		return false;
	}
}

bool WorkScript::Type::convertableTo(Type * target)
{
	return Type::convertableTo(this, target);
}

GenerateResult Type::generateLLVMTypeConvert(GenerateContext * context, Expression * left, Expression * right, Type *promotedType)
{
	auto builder = context->getIRBuilder();
	Type *leftType = left->getType(context->getInstantializeContext());
	Type *rightType = right->getType(context->getInstantializeContext());
	if (promotedType->equals(leftType)) { //类型提升到左部类型
		return GenerateResult(left->generateIR(context).getValue(), Type::generateLLVMTypeConvert(context, right, promotedType).getValue());
	}
	else if (promotedType->equals(rightType)) { //类型提升到右部类型
		return GenerateResult(Type::generateLLVMTypeConvert(context, left, promotedType).getValue(), right->generateIR(context).getValue());
	}
	else { //两边都需要提升
		return GenerateResult(
			Type::generateLLVMTypeConvert(context, left, promotedType).getValue(),
			Type::generateLLVMTypeConvert(context, right, promotedType).getValue()
		);
	}
}

GenerateResult Type::generateLLVMTypeConvert(GenerateContext * context, Expression * expr, Type * targetType)
{
	Type *srcType = expr->getType(context->getInstantializeContext());
	llvm::Value *srcValue = expr->generateIR(context).getValue();
	if (targetType->equals(srcType)) {
		return GenerateResult(srcValue);
	}
	llvm::Type *targetLLVMType = targetType->getLLVMType(context);
	auto irBuilder = context->getIRBuilder();

	switch (srcType->getClassification())
	{
	case TypeClassification::INTEGER: /*源类型为Integer*/ {
		IntegerType *srcIntegerType = (IntegerType*)srcType;
		switch (targetType->getClassification())
		{
		case TypeClassification::INTEGER:/*目标类型为Integer*/ {
			IntegerType *targetIntegerType = (IntegerType*)targetType;
			//如果长度相同，仅仅有无符号不同，则不用进行转换
			if (srcIntegerType->getLength() == targetIntegerType->getLength())return GenerateResult(srcValue);
			//否则根据是否有符号进行符号扩展或零位扩展
			if (srcIntegerType->isSigned()) {
				return irBuilder->CreateSExt(srcValue, targetLLVMType);
			}
			else {
				return irBuilder->CreateZExt(srcValue, targetLLVMType);
			}
		}
		case TypeClassification::FLOAT: /*目标类型为Float*/ {
			if (srcIntegerType->isSigned()) return irBuilder->CreateSIToFP(srcValue, targetLLVMType);
			else return irBuilder->CreateUIToFP(srcValue, targetLLVMType);
		}
		default:
			goto UNSUPPORTED;
		}

	}

	case TypeClassification::FLOAT: /*源类型为Float*/ {
		FloatType *srcFloatType = (FloatType*)srcValue;
		switch (targetType->getClassification())
		{
		case TypeClassification::INTEGER: /*目标类型为Integer*/ {
			IntegerType *targetIntegerType = (IntegerType*)targetType;
			if (targetIntegerType->isSigned()) return irBuilder->CreateFPToSI(srcValue, targetLLVMType);
			else return irBuilder->CreateFPToUI(srcValue, targetLLVMType);
		}
		case TypeClassification::FLOAT: /*目标类型为Float*/ {
			return irBuilder->CreateFPCast(srcValue, targetLLVMType);
		}
		default:
			goto UNSUPPORTED;
		}

	}
	default:
		goto UNSUPPORTED;
	}

UNSUPPORTED:
	//Location 信息
	throw WorkScriptException(Location(), L"不支持的类型转换：" + srcType->getName() + L" 到 " + targetType->getName());
}

#include "BinaryCompare.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "Report.h"
#include "Exception.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::BinaryCompare::generateIR(GenerateContext * context)
{
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->deduce(context);
	Type *rightType = rightExpr->deduce(context);
	Type *promotedType = Type::getPromotedType(this->getDebugInfo(), leftType, rightType);
	llvm::Value *leftVal = ValueDescriptor::generateLLVMConvert(this->getDebugInfo(), context, leftExpr, ValueDescriptor(promotedType, ValueKind::VALUE));
	llvm::Value *rightVal = ValueDescriptor::generateLLVMConvert(this->getDebugInfo(), context, rightExpr, ValueDescriptor(promotedType, ValueKind::VALUE));
	switch (promotedType->getClassification())
	{
		case TypeClassification::POINTER:
		case TypeClassification::INTEGER:
		{
			return this->generateLLVMIRInteger(context, leftVal, rightVal, (IntegerType *) promotedType);
		}
		case TypeClassification::FLOAT:
		{
			return this->generateLLVMIRFloat(context, leftVal, rightVal, (FloatType *) promotedType);
		}
		default:
			goto UNSUPPORTED;
	}

UNSUPPORTED:
	this->expressionInfo.getDebugInfo().getReport()->error(IncompatibleTypeError(this->expressionInfo.getDebugInfo(), L"双目比较运算符不支持类型" + leftType->getName() + L" 和 " + rightType->getName()), ErrorBehavior::CANCEL_EXPRESSION);
}

DeducedInfo BinaryCompare::deduce(InstantialContext *context) const
{
	return ValueDescriptor(IntegerType::get(IntegerTypeClassification::BOOL), ValueKind::VALUE);
}

Expression * BinaryCompare::clone() const
{
	return new BinaryCompare(expressionInfo,leftExpression,rightExpression, compareType);
}

ExpressionType BinaryCompare::getExpressionType() const
{
	return ExpressionType::BINARY_COMPARE;
}

GenerateResult BinaryCompare::generateLLVMIRInteger(GenerateContext * context, llvm::Value * left, llvm::Value * right, IntegerType * promotedType) const
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
		throw InternalException(L"未知的比较运算符");
	}

	return res;
}

GenerateResult WorkScript::BinaryCompare::generateLLVMIRFloat(GenerateContext * context, llvm::Value * left, llvm::Value * right, FloatType * promotedType) const
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
		throw InternalException(L"未知的比较运算符");
	}

	return res;
}

std::wstring WorkScript::BinaryCompare::getOperatorString() const
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
		throw InternalException(L"未知的比较运算符");
	}
}

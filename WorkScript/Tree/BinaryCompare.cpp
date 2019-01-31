#include "BinaryCompare.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "ErrorManager.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::BinaryCompare::generateIR(GenerateContext * context)
{
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType(context->getInstantialContext());
	Type *rightType = rightExpr->getType(context->getInstantialContext());
	Type *promotedType = Type::getPromotedType(this->getDebugInfo(), leftType, rightType);
	GenerateResult res = Type::generateLLVMTypeConvert(this->getDebugInfo(), context, leftExpr, rightExpr, promotedType);
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
	throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"双目比较运算符不支持类型" + leftType->getName() + L" 和 " + rightType->getName());
}

IntegerType * WorkScript::BinaryCompare::getType(InstantialContext *context) const
{
	return IntegerType::get(1);
}

Expression * WorkScript::BinaryCompare::clone() const
{
	return new BinaryCompare(expressionInfo,leftExpression,rightExpression, compareType);
}

ExpressionType WorkScript::BinaryCompare::getExpressionType() const
{
	return ExpressionType::BINARY_COMPARE_EXPRESSION;
}

GenerateResult WorkScript::BinaryCompare::generateLLVMIRInteger(GenerateContext * context, llvm::Value * left, llvm::Value * right, IntegerType * promotedType) const
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知的比较运算符");
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知的比较运算符");
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知的比较运算符");
	}
}

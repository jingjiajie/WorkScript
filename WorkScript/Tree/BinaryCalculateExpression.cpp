#include "BinaryCalculateExpression.h"
#include "IntegerType.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::BinaryCalculateExpression::generateIR(GenerateContext * context)
{
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType(context->getInstantializeContext());
	Type *rightType = rightExpr->getType(context->getInstantializeContext());

	Type *promotedType = Type::getPromotedType(leftType, rightType);
	GenerateResult res = Type::generateLLVMTypeConvert(context, leftExpr, rightExpr, promotedType);
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
	throw WorkScriptException(this->expressionInfo.getLocation(), L"双目运算符不支持类型" + leftType->getName() + L" 和 " + rightType->getName());
}

Type * WorkScript::BinaryCalculateExpression::getType(InstantializeContext *context) const
{
	return Type::getPromotedType(this->leftExpression->getType(context), this->rightExpression->getType(context));
}

Expression * WorkScript::BinaryCalculateExpression::clone() const
{
	return new BinaryCalculateExpression(expressionInfo,leftExpression,rightExpression, calculateType);
}

ExpressionType WorkScript::BinaryCalculateExpression::getExpressionType() const
{
	return ExpressionType::BINARY_CALCULATE_EXPRESSION;
}

std::wstring WorkScript::BinaryCalculateExpression::getOperatorString() const
{
	switch (this->calculateType)
	{
	case PLUS:
		return L"+";
		break;
	case MINUS:
		return L"-";
		break;
	case MULTIPLY:
		return L"*";
		break;
	case DIVIDE:
		return L"/";
		break;
	case MODULUS:
		return L"%";
		break;
	default:
		throw WorkScriptException(this->expressionInfo.getLocation(), L"未知操作符");
	}
}

GenerateResult WorkScript::BinaryCalculateExpression::generateLLVMIRInteger(GenerateContext * context, llvm::Value * left, llvm::Value * right, IntegerType * promotedType) const
{
	auto irBuilder = context->getIRBuilder();
	llvm::Value *res;
	switch (this->calculateType)
	{
	case PLUS:
		res = irBuilder->CreateAdd(left, right);
		break;
	case MINUS:
		res = irBuilder->CreateSub(left, right);
		break;
	case MULTIPLY:
		res = irBuilder->CreateMul(left, right);
		break;
	case DIVIDE:
		if (promotedType->isSigned()) {
			res = irBuilder->CreateSDiv(left, right);
		}
		else {
			res = irBuilder->CreateUDiv(left, right);
		}
		break;
	case MODULUS:
		if (promotedType->isSigned()) {
			res = irBuilder->CreateSRem(left, right);
		}
		else {
			res = irBuilder->CreateURem(left, right);
		}
		break;
	default:
		throw WorkScriptException(this->expressionInfo.getLocation(), L"未知操作符");
	}

	return res;
}

GenerateResult WorkScript::BinaryCalculateExpression::generateLLVMIRFloat(GenerateContext * context, llvm::Value * left, llvm::Value * right, FloatType * promotedType) const
{
	auto irBuilder = context->getIRBuilder();
	llvm::Value *res;
	switch (this->calculateType)
	{
	case PLUS:
		res = irBuilder->CreateFAdd(left, right);
		break;
	case MINUS:
		res = irBuilder->CreateFSub(left, right);
		break;
	case MULTIPLY:
		res = irBuilder->CreateFMul(left, right);
		break;
	case DIVIDE:
			res = irBuilder->CreateFDiv(left, right);
		break;
	case MODULUS:
			res = irBuilder->CreateFRem(left, right);
		break;
	default:
		throw WorkScriptException(this->expressionInfo.getLocation(), L"未知操作符");
	}

	return res;
}


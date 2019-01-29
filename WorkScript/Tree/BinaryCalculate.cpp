#include "BinaryCalculate.h"
#include "IntegerType.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::BinaryCalculate::generateIR(GenerateContext * context)
{
	auto leftExpr = this->getLeftExpression();
	auto rightExpr = this->getRightExpression();
	Type *leftType = leftExpr->getType(context->getInstantializeContext());
	Type *rightType = rightExpr->getType(context->getInstantializeContext());

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
	throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"双目运算符不支持类型" + leftType->getName() + L" 和 " + rightType->getName());
}

Type * WorkScript::BinaryCalculate::getType(InstantializeContext *context) const
{
	return Type::getPromotedType(this->getDebugInfo(), this->leftExpression->getType(context), this->rightExpression->getType(context));
}

Expression * WorkScript::BinaryCalculate::clone() const
{
	return new BinaryCalculate(expressionInfo,leftExpression,rightExpression, calculateType);
}

ExpressionType WorkScript::BinaryCalculate::getExpressionType() const
{
	return ExpressionType::BINARY_CALCULATE_EXPRESSION;
}

std::wstring WorkScript::BinaryCalculate::getOperatorString() const
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知操作符");
	}
}

GenerateResult WorkScript::BinaryCalculate::generateLLVMIRInteger(GenerateContext * context, llvm::Value * left, llvm::Value * right, IntegerType * promotedType) const
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知操作符");
	}

	return res;
}

GenerateResult WorkScript::BinaryCalculate::generateLLVMIRFloat(GenerateContext * context, llvm::Value * left, llvm::Value * right, FloatType * promotedType) const
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
		throw WorkScriptException(this->expressionInfo.getDebugInfo(), L"未知操作符");
	}

	return res;
}


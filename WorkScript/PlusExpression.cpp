#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"
#include "Program.h"
#include "TempExpression.h"

using namespace std;

PlusExpression::~PlusExpression()
{
}

Expression* const PlusExpression::evaluate(Context *const& context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	auto leftType = evaluatedLeftExpr->getType(context);
	auto rightType = evaluatedRightExpr->getType(context);
	Expression *ret;
	//��ʼ���ӷ����㡣
	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
	auto stringType = &TypeExpression::STRING_EXPRESSION;

	if (leftType->equals(context, numberType) && rightType->equals(context, numberType)) {
		ret = this->numberPlusNumber(context, (NumberExpression *const&)(evaluatedLeftExpr), (NumberExpression *const&)(evaluatedRightExpr));
		goto OK;
	}
	else {
		ret = this->exprPlusExpr(context, evaluatedLeftExpr, evaluatedRightExpr);
		goto OK;
	}
OK:
	evaluatedLeftExpr->releaseTemp();
	evaluatedRightExpr->releaseTemp();
	leftType->releaseTemp();
	rightType->releaseTemp();
	return ret;
//MISMATCHED:
//	leftType->releaseTemp();
//	rightType->releaseTemp();
//	return ret;
}

//bool PlusExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	//���ƥ����Ǽӷ����ʽ�������ұ��ʽƥ��
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchPlusExpression = (PlusExpression *const&)(matchExpression);
//		return this->leftExpression->match(matchPlusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchPlusExpression->rightExpression, context);
//	}
//	else //���ƥ��Ĳ��Ǽӷ����ʽ
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		VariableExpression * myVarExpr;
//		Expression * myNonVarExpr;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//���Լ������ұ��ʽ��ֻ��һ���Ǳ���
//		if (evaluatedLeft->getType(context)->equals(variableType) && !evaluatedRight->getType(context)->equals(variableType))
//		{
//			myVarExpr = (VariableExpression *const&)(evaluatedLeft);
//			myNonVarExpr = (Expression *const&)(evaluatedRight);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			myNonVarExpr = (Expression *const&)(evaluatedLeft);
//			myVarExpr = (VariableExpression *const&)(evaluatedRight);
//		}
//		else {
//			return false;
//		}
//		//���������ʽ��Ϊƥ����ʽ-�Ǳ������ʽ
//		MinusExpression * minusExpr(new MinusExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(minusExpr,context);
//	}
//}

TypeExpression* const PlusExpression::getType(Context *const& context) const
{
	return &TypeExpression::PLUS_EXPRESSION;
}

StringExpression *const PlusExpression::toString(Context *const& context)
{
	static StringExpression sign("+", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &sign);
}

NumberExpression * PlusExpression::numberPlusNumber(Context *const &context, NumberExpression* const&left, NumberExpression* const&right) const
{
	return NumberExpression::newInstance(left->getValue() + right->getValue());
}

StringExpression * PlusExpression::exprPlusExpr(Context *const &context, Expression* const&left, Expression* const&right) const
{
	TempExpression<StringExpression> leftEvaluatedString(left, left->toString(context));
	TempExpression<StringExpression> rightEvaluatedString(right, right->toString(context));
	StringExpression *exprs[] = { leftEvaluatedString,rightEvaluatedString };
	auto result = StringExpression::combine(exprs, 2);
	return result;
}
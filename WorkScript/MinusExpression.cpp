#include "MinusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "VariableExpression.h"
#include "PlusExpression.h"
#include "Program.h"

using namespace std;

MinusExpression::~MinusExpression()
{
}

Expression* const MinusExpression::evaluate(Context *const& context)
{
	TempExpression<Expression> evaluatedLeftExpr(this->leftExpression, this->leftExpression->evaluate(context));
	TempExpression<Expression> evaluatedRightExpr(this->rightExpression, this->rightExpression->evaluate(context));
	auto leftType = evaluatedLeftExpr->getType(context);
	auto rightType = evaluatedRightExpr->getType(context);
	//开始做减法运算。
	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
	auto stringType = &TypeExpression::STRING_EXPRESSION;

	if (leftType->isSubTypeOf(context, numberType) && rightType->isSubTypeOf(context, numberType)) {
		return this->numberMinusNumber((NumberExpression* const&)evaluatedLeftExpr, (NumberExpression* const&)evaluatedRightExpr);
	}
	//else if (leftType->equals(context, stringType) && rightType->equals(context, numberType)) {
	//	ret = this->stringMinusNumber((StringExpression* const&)evaluatedLeftExpr, (NumberExpression* const&)evaluatedRightExpr);
	//	goto OK;
	//}
	else {
		return new MinusExpression(evaluatedLeftExpr, evaluatedRightExpr);
	}
}

//bool MinusExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchMinusExpression = (MinusExpression *const&)(matchExpression);
//		return this->leftExpression->match(matchMinusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchMinusExpression->rightExpression, context);
//	}
//	else //如果匹配的不是减法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//且自己的左右表达式中只有一个是变量
//		if (evaluatedLeft->getType(context)->equals(variableType) && !evaluatedRight->getType(context)->equals(variableType))
//		{
//			return (VariableExpression *const&)(evaluatedLeft)->match(PlusExpression *(new PlusExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			return (VariableExpression *const&)(evaluatedRight)->match(MinusExpression *(new MinusExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

TypeExpression* const MinusExpression::getType(Context *const& context) const
{
	return &TypeExpression::MINUS_EXPRESSION;
}

StringExpression *const MinusExpression::toString(Context *const& context)
{
	static StringExpression sign(L"-", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &sign);
}

NumberExpression * MinusExpression::numberMinusNumber(NumberExpression* const&left, NumberExpression* const&right) const
{
	return left->minus(right);
}

//StringExpression * MinusExpression::stringMinusString(StringExpression* const&left, StringExpression* const&right) const
//{
//	StringExpression * newStringExpr(new StringExpression(this->context, left->getValue() + right->getValue()));
//	return newStringExpr;
//}

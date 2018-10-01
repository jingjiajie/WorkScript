#include "stdafx.h"
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

//const Pointer<Expression> MinusExpression::evaluate(Context *const& context)
//{
//	Pointer<Expression> evaluatedLeftExpr =  this->leftExpression->evaluate(context);
//	Pointer<Expression> evaluatedRightExpr =  this->rightExpression->evaluate(context);
//	auto leftType = evaluatedLeftExpr->getType(context);
//	auto rightType = evaluatedRightExpr->getType(context);
//	//开始做减法运算。
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = TypeExpression::STRING_EXPRESSION;
//
//	if (leftType->isSubTypeOf(context, numberType) && rightType->isSubTypeOf(context, numberType)) {
//		return ((const Pointer<NumberExpression>)evaluatedLeftExpr)->minus((const Pointer<NumberExpression>)evaluatedRightExpr);
//	}
//	//else if (leftType->equals(context, stringType) && rightType->equals(context, numberType)) {
//	//	ret = this->stringMinusNumber((const Pointer<StringExpression> &)evaluatedLeftExpr, (const Pointer<NumberExpression> &)evaluatedRightExpr);
//	//	goto OK;
//	//}
//	else {
//		return new MinusExpression(evaluatedLeftExpr, evaluatedRightExpr);
//	}
//}

//bool MinusExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchMinusExpression = (const Pointer<MinusExpression> &)(matchExpression);
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
//			return (const Pointer<VariableExpression> &)(evaluatedLeft)->match(Pointer<PlusExpression>(new PlusExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			return (const Pointer<VariableExpression> &)(evaluatedRight)->match(Pointer<MinusExpression>(new MinusExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

const Pointer<TypeExpression> MinusExpression::getType(Context *const& context) const
{
	return TypeExpression::MINUS_EXPRESSION;
}

const Pointer<StringExpression> MinusExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> sign(new StringExpression(L"-", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<NumberExpression> MinusExpression::numberCalcNumber(Context * const context, const Pointer<NumberExpression> & left, const Pointer<NumberExpression> & right) const
{
	return left->minus(right);
}

//Pointer<StringExpression> MinusExpression::stringMinusString(const Pointer<StringExpression> &left, const Pointer<StringExpression> &right) const
//{
//	Pointer<StringExpression> newStringExpr(new StringExpression(this->context, left->getValue() + right->getValue()));
//	return newStringExpr;
//}

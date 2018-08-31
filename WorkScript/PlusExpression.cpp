#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "DoubleExpression.h"
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

//Expression* const PlusExpression::evaluate(Context *const& context)
//{
//	TempExpression<Expression> evaluatedLeftExpr(this->leftExpression, this->leftExpression->evaluate(context));
//	TempExpression<Expression> evaluatedRightExpr(this->rightExpression, this->rightExpression->evaluate(context));
//	auto leftType = evaluatedLeftExpr->getType(context);
//	auto rightType = evaluatedRightExpr->getType(context);
//	//开始做加法运算。
//	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = &TypeExpression::STRING_EXPRESSION;
//
//	if (leftType->isSubTypeOf(context, numberType) && rightType->isSubTypeOf(context, numberType)) {
//		return ((NumberExpression *const)evaluatedLeftExpr)->plus((NumberExpression *const)evaluatedRightExpr);
//	}
//	else {
//		return this->exprPlusExpr(context, evaluatedLeftExpr, evaluatedRightExpr);
//	}
//}

//bool PlusExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	//如果匹配的是加法表达式，则按左右表达式匹配
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchPlusExpression = (PlusExpression *const&)(matchExpression);
//		return this->leftExpression->match(matchPlusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchPlusExpression->rightExpression, context);
//	}
//	else //如果匹配的不是加法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		VariableExpression * myVarExpr;
//		Expression * myNonVarExpr;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//且自己的左右表达式中只有一个是变量
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
//		//将变量表达式绑定为匹配表达式-非变量表达式
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
	static StringExpression sign(L"+", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &sign);
}

NumberExpression * const PlusExpression::numberCalcNumber(Context * const context, NumberExpression * const & left, NumberExpression * const & right) const
{
	return left->plus(right);
}

//StringExpression * PlusExpression::exprPlusExpr(Context *const &context, Expression* const&left, Expression* const&right) const
//{
//	TempExpression<StringExpression> leftEvaluatedString(left, left->toString(context));
//	TempExpression<StringExpression> rightEvaluatedString(right, right->toString(context));
//	StringExpression *exprs[] = { leftEvaluatedString,rightEvaluatedString };
//	auto result = StringExpression::combine(exprs, 2);
//	return result;
//}
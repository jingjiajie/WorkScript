#include <sstream>
#include "DivideExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "Context.h"
#include "Program.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"

using namespace std;

DivideExpression::~DivideExpression()
{
}

//Expression* const DivideExpression::evaluate(Context *const& context)
//{
//	TempExpression<Expression> evaluatedLeftExpr(this->leftExpression, this->leftExpression->evaluate(context));
//	TempExpression<Expression> evaluatedRightExpr(this->rightExpression, this->rightExpression->evaluate(context));
//	Expression *ret;
//	//开始做除法运算。
//	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = &TypeExpression::STRING_EXPRESSION;
//
//	if (evaluatedLeftExpr->getType(context)->isSubTypeOf(context, numberType) && evaluatedRightExpr->getType(context)->isSubTypeOf(context, numberType)) {
//		ret = this->numberDivideNumber((DoubleExpression *const&)(evaluatedLeftExpr), (DoubleExpression *const&)(evaluatedRightExpr));
//	}
//
//	ret = new DivideExpression(evaluatedLeftExpr, evaluatedRightExpr); //newMe
//	return ret;
//}

//bool DivideExpression::match(Expression* const& matchExpression, Context *const& context) const
//
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchDivideExpression = (DivideExpression *const&)(matchExpression);
//		return this->leftExpression->match(matchDivideExpression->leftExpression, context)
//			&& this->rightExpression->match(matchDivideExpression->rightExpression, context);
//	}
//	else //如果匹配的不是除法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//且自己的左右表达式中只有一个是变量
//		if (evaluatedLeft->getType(context)->equals(variableType) && !evaluatedRight->getType(context)->equals(variableType))
//		{
//			return (VariableExpression *const&)(evaluatedLeft)->match(MultiplyExpression *(new MultiplyExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			return (VariableExpression *const&)(evaluatedRight)->match(DivideExpression *(new DivideExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

StringExpression * const DivideExpression::toString(Context * const & context)
{
	static StringExpression divisionSign(L"/", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &divisionSign);
}

NumberExpression * const DivideExpression::numberCalcNumber(Context * const context, NumberExpression * const & left, NumberExpression * const & right) const
{
	return left->divide(right);
}
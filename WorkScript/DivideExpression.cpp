#include <sstream>
#include "DivideExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "Program.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"

using namespace std;

DivideExpression::~DivideExpression()
{
}

Expression* const DivideExpression::evaluate(Context *const& context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	Expression *ret;
	//开始做除法运算。
	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
	auto stringType = &TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType(context)->equals(context, numberType)) {
		if (evaluatedRightExpr->getType(context)->equals(context, numberType)) {
			ret = this->numberDivideNumber((NumberExpression *const&)(evaluatedLeftExpr), (NumberExpression *const&)(evaluatedRightExpr));
			goto OK;
		}
	}

	ret = new DivideExpression(evaluatedLeftExpr, evaluatedRightExpr); //newMe
	goto OK;

OK:
	evaluatedLeftExpr->releaseTemp();
	evaluatedRightExpr->releaseTemp();
	return ret;
}

//bool DivideExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
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
	static StringExpression divisionSign("/");
	return BinaryTermExpression::toString(context, &divisionSign);
}

NumberExpression *const DivideExpression::numberDivideNumber(NumberExpression *const &left, NumberExpression *const &right) const
{
	return NumberExpression::newInstance(left->getValue() / right->getValue());
}
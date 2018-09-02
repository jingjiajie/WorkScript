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

//const Pointer<Expression> DivideExpression::evaluate(Context *const& context)
//{
//	Pointer<Expression> evaluatedLeftExpr =  this->leftExpression->evaluate(context);
//	Pointer<Expression> evaluatedRightExpr =  this->rightExpression->evaluate(context);
//	Pointer<Expression> ret;
//	//开始做除法运算。
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = TypeExpression::STRING_EXPRESSION;
//
//	if (evaluatedLeftExpr->getType(context)->isSubTypeOf(context, numberType) && evaluatedRightExpr->getType(context)->isSubTypeOf(context, numberType)) {
//		ret = this->numberDivideNumber((const Pointer<DoubleExpression> &)(evaluatedLeftExpr), (const Pointer<DoubleExpression> &)(evaluatedRightExpr));
//	}
//
//	ret = new DivideExpression(evaluatedLeftExpr, evaluatedRightExpr); //newMe
//	return ret;
//}

//bool DivideExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchDivideExpression = (const Pointer<DivideExpression> &)(matchExpression);
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
//			return (const Pointer<VariableExpression> &)(evaluatedLeft)->match(Pointer<MultiplyExpression>(new MultiplyExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			return (const Pointer<VariableExpression> &)(evaluatedRight)->match(Pointer<DivideExpression>(new DivideExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

const Pointer<StringExpression> DivideExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> divisionSign(new StringExpression(L"/", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, divisionSign);
}

const Pointer<NumberExpression> DivideExpression::numberCalcNumber(Context * const context, const Pointer<NumberExpression> & left, const Pointer<NumberExpression> & right) const
{
	return left->divide(right);
}
#include <sstream>
#include "MultiplyExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "DivideExpression.h"
#include "Program.h"

using namespace std;

MultiplyExpression::~MultiplyExpression()
{
}

Expression* const MultiplyExpression::evaluate(Context *const& context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	//开始做乘法运算。
	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
	auto stringType = &TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType(context)->equals(context, numberType)) {
		if (evaluatedRightExpr->getType(context)->equals(context, numberType)) {
			return this->numberMultiplyNumber(context, (NumberExpression *const&)(evaluatedLeftExpr), (NumberExpression *const&)(evaluatedRightExpr));
		}
	}
	else if (evaluatedLeftExpr->getType(context)->equals(context, stringType)) {
		if (evaluatedRightExpr->getType(context)->equals(context, numberType)) {
			return this->stringMultiplyNumber(context, (StringExpression *const&)(evaluatedLeftExpr), (NumberExpression *const&)(evaluatedRightExpr));
		}
	}
	auto newMe = new MultiplyExpression(evaluatedLeftExpr, evaluatedRightExpr);
	return newMe;
}
//
//bool MultiplyExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchMultiplyExpression = (MultiplyExpression *const&)(matchExpression);
//		return this->leftExpression->match(matchMultiplyExpression->leftExpression, context)
//			&& this->rightExpression->match(matchMultiplyExpression->rightExpression, context);
//	}
//	else //如果匹配的不是乘法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		VariableExpression * myVarExpr;
//		Expression * myNonVarExpr;
//		//且自己的左右表达式中只有一个是变量
//		if (this->leftExpression->getType(context)->equals(variableType) && !this->rightExpression->getType(context)->equals(variableType))
//		{
//			myVarExpr = (VariableExpression *const&)(this->leftExpression);
//			myNonVarExpr = (Expression *const&)(this->rightExpression);
//		}
//		else if (!this->leftExpression->getType(context)->equals(variableType) && this->rightExpression->getType(context)->equals(variableType)) {
//			myNonVarExpr = (Expression *const&)(this->leftExpression);
//			myVarExpr = (VariableExpression *const&)(this->rightExpression);
//		}
//		else {
//			return false;
//		}
//		//将变量表达式绑定为匹配表达式-非变量表达式
//		DivideExpression * divideExpr(new DivideExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(divideExpr, context);
//	}
//}

TypeExpression* const MultiplyExpression::getType(Context *const& context) const
{
	return &TypeExpression::MULTIPLY_EXPRESSION;
}

StringExpression *const MultiplyExpression::toString(Context *const& context)
{
	static StringExpression sign(L"*", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &sign);
}

NumberExpression * MultiplyExpression::numberMultiplyNumber(Context *const &context, NumberExpression* const&left, NumberExpression* const&right) const
{
	return NumberExpression::newInstance(left->getValue() * right->getValue());
}

StringExpression * MultiplyExpression::stringMultiplyNumber(Context *const &context, StringExpression* const&left, NumberExpression* const&right) const
{
	auto oriString = left->getValue();
	double times = right->getValue();
	wstringstream ss;
	for (int i = 0; i < times; ++i) {
		ss << oriString;
	}
	wstring resultStr = ss.str();
	return StringExpression::newInstance(resultStr.c_str());
}

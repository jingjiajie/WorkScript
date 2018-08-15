#include <sstream>
#include "MultiplyExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "DivideExpression.h"

using namespace std;

MultiplyExpression::MultiplyExpression()
{
}

MultiplyExpression::MultiplyExpression(const std::shared_ptr<TermExpression> &leftExpr, const std::shared_ptr<TermExpression>&rightExpr)
{
	this->setLeftExpression(leftExpr);
	this->setRightExpression(rightExpr);
}

MultiplyExpression::~MultiplyExpression()
{
}

const std::shared_ptr<TermExpression> MultiplyExpression::evaluate(Context *context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	//开始做乘法运算。
	auto numberType = TypeExpression::NUMBER_EXPRESSION;
	auto stringType = TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberMultiplyNumber(dynamic_pointer_cast<NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<NumberExpression>(evaluatedRightExpr));
		}
	}
	else if (evaluatedLeftExpr->getType()->equals(stringType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->stringMultiplyNumber(dynamic_pointer_cast<StringExpression>(evaluatedLeftExpr), dynamic_pointer_cast<NumberExpression>(evaluatedRightExpr));
		}
	}
	auto newMe = shared_ptr<MultiplyExpression>(new MultiplyExpression(evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}
//
//bool MultiplyExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	if (matchExpression->getType()->equals(this->getType())) {
//		auto matchMultiplyExpression = dynamic_pointer_cast<MultiplyExpression>(matchExpression);
//		return this->leftExpression->match(matchMultiplyExpression->leftExpression, context)
//			&& this->rightExpression->match(matchMultiplyExpression->rightExpression, context);
//	}
//	else //如果匹配的不是乘法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		shared_ptr<VariableExpression> myVarExpr;
//		shared_ptr<TermExpression> myNonVarExpr;
//		//且自己的左右表达式中只有一个是变量
//		if (this->leftExpression->getType()->equals(variableType) && !this->rightExpression->getType()->equals(variableType))
//		{
//			myVarExpr = dynamic_pointer_cast<VariableExpression>(this->leftExpression);
//			myNonVarExpr = dynamic_pointer_cast<TermExpression>(this->rightExpression);
//		}
//		else if (!this->leftExpression->getType()->equals(variableType) && this->rightExpression->getType()->equals(variableType)) {
//			myNonVarExpr = dynamic_pointer_cast<TermExpression>(this->leftExpression);
//			myVarExpr = dynamic_pointer_cast<VariableExpression>(this->rightExpression);
//		}
//		else {
//			return false;
//		}
//		//将变量表达式绑定为匹配表达式-非变量表达式
//		shared_ptr<DivideExpression> divideExpr(new DivideExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(divideExpr, context);
//	}
//}

const std::shared_ptr<TypeExpression> MultiplyExpression::getType() const
{
	return TypeExpression::MULTIPLY_EXPRESSION;
}

const std::string MultiplyExpression::toString() const
{
	return this->leftExpression->toString() + "*" + this->rightExpression->toString();
}

std::shared_ptr<NumberExpression> MultiplyExpression::numberMultiplyNumber(const std::shared_ptr<NumberExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	shared_ptr<NumberExpression> newNumExpr(new NumberExpression(left->getValue() * right->getValue()));
	return newNumExpr;
}

std::shared_ptr<StringExpression> MultiplyExpression::stringMultiplyNumber(const std::shared_ptr<StringExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	string oriString = left->getValue();
	double times = right->getValue();
	stringstream ss;
	for (int i = 0; i < times; i++) {
		ss << oriString;
	}
	string resultStr = ss.str();
	shared_ptr<StringExpression> newStringExpr(new StringExpression(resultStr));
	return newStringExpr;
}

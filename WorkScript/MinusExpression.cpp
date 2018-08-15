#include "MinusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "VariableExpression.h"
#include "PlusExpression.h"

using namespace std;

MinusExpression::MinusExpression()
{

}

MinusExpression::MinusExpression(const std::shared_ptr<TermExpression> &leftExpression, const std::shared_ptr<TermExpression> &rightExpression)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}


MinusExpression::~MinusExpression()
{
}

const std::shared_ptr<TermExpression> MinusExpression::evaluate(Context *context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	//开始做减法运算。
	auto numberType = TypeExpression::NUMBER_EXPRESSION;
	auto stringType = TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberMinusNumber((const shared_ptr<NumberExpression>&)evaluatedLeftExpr, (const shared_ptr<NumberExpression>&)evaluatedRightExpr);
		}
	}
	else if (evaluatedLeftExpr->getType()->equals(stringType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->stringMinusNumber((const shared_ptr<StringExpression>&)evaluatedLeftExpr, (const shared_ptr<NumberExpression>&)evaluatedRightExpr);
		}
		//TODO 字符串可以减字符串
	/*	else if (evaluatedRightExpr->getType()->equals(stringType)) {
			return this->stringPlusString(dynamic_pointer_cast<StringExpression>(evaluatedLeftExpr), dynamic_pointer_cast<StringExpression>(evaluatedRightExpr));
		}*/
	}
	auto newMe = shared_ptr<MinusExpression>(new MinusExpression(evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

//bool MinusExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	if (matchExpression->getType()->equals(this->getType())) {
//		auto matchMinusExpression = dynamic_pointer_cast<MinusExpression>(matchExpression);
//		return this->leftExpression->match(matchMinusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchMinusExpression->rightExpression, context);
//	}
//	else //如果匹配的不是减法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//且自己的左右表达式中只有一个是变量
//		if (evaluatedLeft->getType()->equals(variableType) && !evaluatedRight->getType()->equals(variableType))
//		{
//			return dynamic_pointer_cast<VariableExpression>(evaluatedLeft)->match(shared_ptr<PlusExpression>(new PlusExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType()->equals(variableType) && evaluatedRight->getType()->equals(variableType)) {
//			return dynamic_pointer_cast<VariableExpression>(evaluatedRight)->match(shared_ptr<MinusExpression>(new MinusExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

const std::shared_ptr<TypeExpression> MinusExpression::getType() const
{
	return TypeExpression::MINUS_EXPRESSION;
}

const std::string MinusExpression::toString() const
{
	return this->leftExpression->toString() + "-" + this->rightExpression->toString();
}

std::shared_ptr<NumberExpression> MinusExpression::numberMinusNumber(const std::shared_ptr<NumberExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	shared_ptr<NumberExpression> newNumExpr(new NumberExpression(left->getValue() - right->getValue()));
	return newNumExpr;
}

std::shared_ptr<StringExpression> MinusExpression::stringMinusNumber(const std::shared_ptr<StringExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	string oriString = left->getValue();
	shared_ptr<StringExpression> newStringExpr(new StringExpression(oriString.substr(0, oriString.size() - (size_t)right->getValue())));
	return newStringExpr;
}

//std::shared_ptr<StringExpression> MinusExpression::stringMinusString(const std::shared_ptr<StringExpression>&left, const std::shared_ptr<StringExpression>&right) const
//{
//	shared_ptr<StringExpression> newStringExpr(new StringExpression(this->context, left->getValue() + right->getValue()));
//	return newStringExpr;
//}

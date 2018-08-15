#include <sstream>
#include "DivideExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"

using namespace std;

DivideExpression::DivideExpression()
{
}

DivideExpression::DivideExpression(const std::shared_ptr<TermExpression> &leftExpr, const std::shared_ptr<TermExpression>&rightExpr)
	: DivideExpression()
{
	this->setLeftExpression(leftExpr);
	this->setRightExpression(rightExpr);
}

DivideExpression::~DivideExpression()
{
}

const std::shared_ptr<TermExpression> DivideExpression::evaluate(Context *context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	//开始做除法运算。
	auto numberType = TypeExpression::NUMBER_EXPRESSION;
	auto stringType = TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberDivideNumber(dynamic_pointer_cast<NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<NumberExpression>(evaluatedRightExpr));
		}
	}
	auto newMe = shared_ptr<DivideExpression>(new DivideExpression(evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

//bool DivideExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	if (matchExpression->getType()->equals(this->getType())) {
//		auto matchDivideExpression = dynamic_pointer_cast<DivideExpression>(matchExpression);
//		return this->leftExpression->match(matchDivideExpression->leftExpression, context)
//			&& this->rightExpression->match(matchDivideExpression->rightExpression, context);
//	}
//	else //如果匹配的不是除法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//且自己的左右表达式中只有一个是变量
//		if (evaluatedLeft->getType()->equals(variableType) && !evaluatedRight->getType()->equals(variableType))
//		{
//			return dynamic_pointer_cast<VariableExpression>(evaluatedLeft)->match(shared_ptr<MultiplyExpression>(new MultiplyExpression(evaluatedRight, matchExpression)), context);
//		}
//		else if (!evaluatedLeft->getType()->equals(variableType) && evaluatedRight->getType()->equals(variableType)) {
//			return dynamic_pointer_cast<VariableExpression>(evaluatedRight)->match(shared_ptr<DivideExpression>(new DivideExpression(evaluatedLeft, matchExpression)), context);
//		}
//		else {
//			return false;
//		}
//	}
//}

const std::shared_ptr<TypeExpression> DivideExpression::getType() const
{
	return TypeExpression::DIVIDE_EXPRESSION;
}

const std::string DivideExpression::toString() const
{
	return this->leftExpression->toString() + "/" + this->rightExpression->toString();
}

std::shared_ptr<NumberExpression> DivideExpression::numberDivideNumber(const std::shared_ptr<NumberExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	shared_ptr<NumberExpression> newNumExpr(new NumberExpression(left->getValue() / right->getValue()));
	return newNumExpr;
}
#include <sstream>
#include "MultiplyExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"

using namespace std;

MultiplyExpression::MultiplyExpression(Context * const & context)
	:PolynomialExpression(context)
{
}

MultiplyExpression::MultiplyExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpr, const std::shared_ptr<const Expression>&rightExpr)
	:MultiplyExpression(context)
{
	this->setLeftExpression(leftExpr);
	this->setRightExpression(rightExpr);
}

MultiplyExpression::~MultiplyExpression()
{
}

const std::shared_ptr<const Expression> MultiplyExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(expressionBind);
	auto evaluatedRightExpr = this->rightExpression->evaluate(expressionBind);
	//开始做乘法运算。
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	auto stringType = this->context->findType(TYPENAME_STRING_EXPRESSION, false);

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberMultiplyNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
		}
	}
	else if (evaluatedLeftExpr->getType()->equals(stringType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->stringMultiplyNumber(dynamic_pointer_cast<const StringExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
		}
	}
	auto newMe = shared_ptr<const MultiplyExpression>(new MultiplyExpression(this->context, evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

bool MultiplyExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	if (!matchExpression->getType()->equals(this->getType()))return false;
	auto matchMultiplyExpression = dynamic_pointer_cast<const MultiplyExpression>(matchExpression);
	return this->leftExpression->match(matchMultiplyExpression->leftExpression, outExpressionBind)
		&& this->rightExpression->match(matchMultiplyExpression->rightExpression, outExpressionBind);
}

bool MultiplyExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetMultiplyExpression = dynamic_pointer_cast<const MultiplyExpression>(target);
	return targetMultiplyExpression->leftExpression->equals(this->leftExpression)
		&& targetMultiplyExpression->rightExpression->equals(this->rightExpression);
}

const std::shared_ptr<const TypeExpression> MultiplyExpression::getType() const
{
	return this->context->findType(TYPENAME_MULTIPLY_EXPRESSION, false);
}

const std::shared_ptr<const Expression> MultiplyExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void MultiplyExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> MultiplyExpression::getRightExpression() const
{
	return this->rightExpression;
}

void MultiplyExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

std::shared_ptr<const NumberExpression> MultiplyExpression::numberMultiplyNumber(const std::shared_ptr<const NumberExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	shared_ptr<const NumberExpression> newNumExpr(new NumberExpression(this->context, left->getValue() * right->getValue()));
	return newNumExpr;
}

std::shared_ptr<const StringExpression> MultiplyExpression::stringMultiplyNumber(const std::shared_ptr<const StringExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	string oriString = left->getValue();
	double times = right->getValue();
	stringstream ss;
	for (int i = 0; i < times; i++) {
		ss << oriString;
	}
	string resultStr = ss.str();
	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, resultStr));
	return newStringExpr;
}

#include "MinusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"

using namespace std;

MinusExpression::MinusExpression(Context * const & context)
	:PolynomialExpression(context)
{

}

MinusExpression::MinusExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression)
	: PolynomialExpression(context)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}


MinusExpression::~MinusExpression()
{
}

const std::shared_ptr<const Expression> MinusExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(expressionBind);
	auto evaluatedRightExpr = this->rightExpression->evaluate(expressionBind);
	//开始做减法运算。
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	auto stringType = this->context->findType(TYPENAME_STRING_EXPRESSION, false);

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberMinusNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
		}
	}
	else if (evaluatedLeftExpr->getType()->equals(stringType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->stringMinusNumber(dynamic_pointer_cast<const StringExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
		}
		//TODO 字符串可以减字符串
	/*	else if (evaluatedRightExpr->getType()->equals(stringType)) {
			return this->stringPlusString(dynamic_pointer_cast<const StringExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const StringExpression>(evaluatedRightExpr));
		}*/
	}
	auto newMe = shared_ptr<const MinusExpression>(new MinusExpression(this->context, evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

bool MinusExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	if (!matchExpression->getType()->equals(this->getType()))return false;
	auto matchMinusExpression = dynamic_pointer_cast<const MinusExpression>(matchExpression);
	return this->leftExpression->match(matchMinusExpression->leftExpression, outExpressionBind)
		&& this->rightExpression->match(matchMinusExpression->rightExpression, outExpressionBind);
}

bool MinusExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetMinusExpression = dynamic_pointer_cast<const MinusExpression>(target);
	return targetMinusExpression->leftExpression->equals(this->leftExpression)
		&& targetMinusExpression->rightExpression->equals(this->rightExpression);
}

const std::shared_ptr<const TypeExpression> MinusExpression::getType() const
{
	return this->context->findType(TYPENAME_PLUS_EXPRESSION, false);
}

const std::shared_ptr<const Expression> MinusExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void MinusExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> MinusExpression::getRightExpression() const
{
	return this->rightExpression;
}

void MinusExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

std::shared_ptr<const NumberExpression> MinusExpression::numberMinusNumber(const std::shared_ptr<const NumberExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	shared_ptr<const NumberExpression> newNumExpr(new NumberExpression(this->context, left->getValue() - right->getValue()));
	return newNumExpr;
}

std::shared_ptr<const StringExpression> MinusExpression::stringMinusNumber(const std::shared_ptr<const StringExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	string oriString = left->getValue();
	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, oriString.substr(0, oriString.size() - (size_t)right->getValue())));
	return newStringExpr;
}

//std::shared_ptr<const StringExpression> MinusExpression::stringMinusString(const std::shared_ptr<const StringExpression>&left, const std::shared_ptr<const StringExpression>&right) const
//{
//	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, left->getValue() + right->getValue()));
//	return newStringExpr;
//}

#include <sstream>
#include "DivideExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"

using namespace std;

DivideExpression::DivideExpression(Context * const & context)
	:TermExpression(context)
{
}

DivideExpression::DivideExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpr, const std::shared_ptr<const Expression>&rightExpr)
	: DivideExpression(context)
{
	this->setLeftExpression(leftExpr);
	this->setRightExpression(rightExpr);
}

DivideExpression::~DivideExpression()
{
}

const std::shared_ptr<const Expression> DivideExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(expressionBind);
	auto evaluatedRightExpr = this->rightExpression->evaluate(expressionBind);
	//开始做除法运算。
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	auto stringType = this->context->findType(TYPENAME_STRING_EXPRESSION, false);

	if (evaluatedLeftExpr->getType()->equals(numberType)) {
		if (evaluatedRightExpr->getType()->equals(numberType)) {
			return this->numberDivideNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
		}
	}
	auto newMe = shared_ptr<const DivideExpression>(new DivideExpression(this->context, evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

bool DivideExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	if (matchExpression->getType()->equals(this->getType())) {
		auto matchDivideExpression = dynamic_pointer_cast<const DivideExpression>(matchExpression);
		return this->leftExpression->match(matchDivideExpression->leftExpression, outExpressionBind)
			&& this->rightExpression->match(matchDivideExpression->rightExpression, outExpressionBind);
	}
	else //如果匹配的不是除法表达式
	{
		auto variableType = this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false);
		auto mappedLeft = outExpressionBind->getMappedExpression(this->leftExpression);
		if (mappedLeft == nullptr)mappedLeft = this->leftExpression;
		auto mappedRight = outExpressionBind->getMappedExpression(this->rightExpression);
		if (mappedRight == nullptr)mappedRight = this->rightExpression;
		//且自己的左右表达式中只有一个是变量
		if (mappedLeft->getType()->equals(variableType) && !mappedRight->getType()->equals(variableType))
		{
			outExpressionBind->addExpressionMap(mappedLeft, shared_ptr<const MultiplyExpression>(new MultiplyExpression(this->context, mappedRight, matchExpression)));
			return true;
		}
		else if (!mappedLeft->getType()->equals(variableType) && mappedRight->getType()->equals(variableType)) {
			outExpressionBind->addExpressionMap(mappedRight, shared_ptr<const DivideExpression>(new DivideExpression(this->context, mappedLeft, matchExpression)));
			return true;
		}
		else {
			return false;
		}
	}
}

bool DivideExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetDivideExpression = dynamic_pointer_cast<const DivideExpression>(target);
	return targetDivideExpression->leftExpression->equals(this->leftExpression)
		&& targetDivideExpression->rightExpression->equals(this->rightExpression);
}

const std::shared_ptr<const TypeExpression> DivideExpression::getType() const
{
	return this->context->findType(TYPENAME_DIVIDE_EXPRESSION, false);
}

const std::string DivideExpression::toString() const
{
	return this->leftExpression->toString() + "/" + this->rightExpression->toString();
}

const std::shared_ptr<const Expression> DivideExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void DivideExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> DivideExpression::getRightExpression() const
{
	return this->rightExpression;
}

void DivideExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

std::shared_ptr<const NumberExpression> DivideExpression::numberDivideNumber(const std::shared_ptr<const NumberExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	shared_ptr<const NumberExpression> newNumExpr(new NumberExpression(this->context, left->getValue() / right->getValue()));
	return newNumExpr;
}
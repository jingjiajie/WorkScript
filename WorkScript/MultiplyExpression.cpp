#include <sstream>
#include "MultiplyExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "DivideExpression.h"

using namespace std;

MultiplyExpression::MultiplyExpression(Context * const & context)
	:TermExpression(context)
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
	if (matchExpression->getType()->equals(this->getType())) {
		auto matchMultiplyExpression = dynamic_pointer_cast<const MultiplyExpression>(matchExpression);
		return this->leftExpression->match(matchMultiplyExpression->leftExpression, outExpressionBind)
			&& this->rightExpression->match(matchMultiplyExpression->rightExpression, outExpressionBind);
	}
	else //如果匹配的不是乘法表达式
	{
		auto variableType = this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false);
		shared_ptr<const VariableExpression> myVarExpr;
		shared_ptr<const ValueExpression> myNonVarExpr;
		auto mappedLeft = outExpressionBind->getMappedExpression(this->leftExpression);
		if (mappedLeft == nullptr)mappedLeft = this->leftExpression;
		auto mappedRight = outExpressionBind->getMappedExpression(this->rightExpression);
		if (mappedRight == nullptr)mappedRight = this->rightExpression;
		//且自己的左右表达式中只有一个是变量
		if (mappedLeft->getType()->equals(variableType) && !mappedRight->getType()->equals(variableType))
		{
			myVarExpr = dynamic_pointer_cast<const VariableExpression>(mappedLeft);
			myNonVarExpr = dynamic_pointer_cast<const ValueExpression>(mappedRight);
		}
		else if (!mappedLeft->getType()->equals(variableType) && mappedRight->getType()->equals(variableType)) {
			myNonVarExpr = dynamic_pointer_cast<const ValueExpression>(mappedLeft);
			myVarExpr = dynamic_pointer_cast<const VariableExpression>(mappedRight);
		}
		else {
			return false;
		}
		//将变量表达式绑定为匹配表达式-非变量表达式
		shared_ptr<const DivideExpression> divideExpr(new DivideExpression(this->context, matchExpression, myNonVarExpr));
		return myVarExpr->match(divideExpr, outExpressionBind);
	}
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

const std::string MultiplyExpression::toString() const
{
	return this->leftExpression->toString() + "*" + this->rightExpression->toString();
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

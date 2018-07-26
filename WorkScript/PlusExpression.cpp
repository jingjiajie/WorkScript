#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "ParentheseExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"

using namespace std;

PlusExpression::PlusExpression(Context * const & context)
	:TermExpression(context)
{

}

PlusExpression::PlusExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression)
	: TermExpression(context)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}


PlusExpression::~PlusExpression()
{
}

const std::shared_ptr<const Expression> PlusExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(expressionBind);
	auto evaluatedRightExpr = this->rightExpression->evaluate(expressionBind);
	//开始做加法运算。
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	auto stringType = this->context->findType(TYPENAME_STRING_EXPRESSION, false);

	if (evaluatedLeftExpr->getType()->equals(numberType) && evaluatedRightExpr->getType()->equals(numberType)) {
		return this->numberPlusNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
	}
	else {
		return this->exprPlusExpr(evaluatedLeftExpr, evaluatedRightExpr);
	}
	auto newMe = shared_ptr<const PlusExpression>(new PlusExpression(this->context, evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

bool PlusExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	//如果匹配的是加法表达式，则按左右表达式匹配
	if (matchExpression->getType()->equals(this->getType())) {
		auto matchPlusExpression = dynamic_pointer_cast<const PlusExpression>(matchExpression);
		return this->leftExpression->match(matchPlusExpression->leftExpression, outExpressionBind)
			&& this->rightExpression->match(matchPlusExpression->rightExpression, outExpressionBind);
	}
	else //如果匹配的不是加法表达式
	{
		auto variableType = this->context->findType(TYPENAME_VARIABLE_EXPRESSION,false);
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
		shared_ptr<const MinusExpression> minusExpr(new MinusExpression(this->context, matchExpression, myNonVarExpr));
		outExpressionBind->addExpressionMap(myVarExpr, minusExpr);
		return true;
	}
}

bool PlusExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetPlusExpression = dynamic_pointer_cast<const PlusExpression>(target);
	return targetPlusExpression->leftExpression->equals(this->leftExpression)
		&& targetPlusExpression->rightExpression->equals(this->rightExpression);
}

const std::shared_ptr<const TypeExpression> PlusExpression::getType() const
{
	return this->context->findType(TYPENAME_PLUS_EXPRESSION,false);
}

const std::string PlusExpression::toString() const
{
	return this->leftExpression->toString() + "+" + this->rightExpression->toString();
}

const std::shared_ptr<const Expression> PlusExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void PlusExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> PlusExpression::getRightExpression() const
{
	return this->rightExpression;
}

void PlusExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

std::shared_ptr<const NumberExpression> PlusExpression::numberPlusNumber(const std::shared_ptr<const NumberExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	shared_ptr<const NumberExpression> newNumExpr(new NumberExpression(this->context, left->getValue() + right->getValue()));
	return newNumExpr;
}

std::shared_ptr<const StringExpression> PlusExpression::exprPlusExpr(const std::shared_ptr<const Expression>&left, const std::shared_ptr<const Expression>&right) const
{
	string leftEvaluatedString = left->toString();
	string rightEvaluatedString = right->toString();
	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, leftEvaluatedString + rightEvaluatedString));
	return newStringExpr;
}
#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "MultiTermExpression.h"
#include "IdentifierExpression.h"
#include "ParentheseExpression.h"
#include "MemberEvaluateExpression.h"

using namespace std;

PlusExpression::PlusExpression(Context * const & context)
	:PolynomialExpression(context)
{

}

PlusExpression::PlusExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression)
	: PolynomialExpression(context)
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
	if (!matchExpression->getType()->equals(this->getType()))return false;
	auto matchPlusExpression = dynamic_pointer_cast<const PlusExpression>(matchExpression);
	return this->leftExpression->match(matchPlusExpression->leftExpression,outExpressionBind)
		&& this->rightExpression->match(matchPlusExpression->rightExpression,outExpressionBind);
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
	SPCEXPRESSION toStringExpr(new MultiTermExpression(this->context, { SPCEXPRESSION(new IdentifierExpression(this->context, "toString")), SPCEXPRESSION(new ParentheseExpression(this->context, nullptr)) }));
	SPCEXPRESSION leftToStringEvaluate(new MemberEvaluateExpression(this->context, left, toStringExpr));
	SPCEXPRESSION rightToStringEvaluate(new MemberEvaluateExpression(this->context, right, toStringExpr));
	auto leftEvaluatedStringExpr = dynamic_pointer_cast<const StringExpression>(leftToStringEvaluate->evaluate(ExpressionBind()));
	auto rightEvaluatedStringExpr = dynamic_pointer_cast<const StringExpression>(rightToStringEvaluate->evaluate(ExpressionBind()));
	string leftEvaluatedString = leftEvaluatedStringExpr->getValue();
	string rightEvaluatedString = rightEvaluatedStringExpr->getValue();
	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, leftEvaluatedString + rightEvaluatedString));
	return newStringExpr;
}
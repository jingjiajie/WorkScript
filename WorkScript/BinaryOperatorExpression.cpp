#include "stdafx.h"
#include "BinaryOperatorExpression.h"
#include "TypeExpression.h"
#include "Program.h"

using namespace std;

BinaryOperatorExpression::~BinaryOperatorExpression()
{
}

bool BinaryOperatorExpression::equals(Context *const &context, const Pointer<Expression> &targetExpression) const
{
	if (!targetExpression->getType(context)->equals(context,this->getType(context))) {
		return false;
	}
	auto targetExpressionOfMyType = (const Pointer<BinaryOperatorExpression> &)targetExpression;

	return this->leftExpression->equals(context, targetExpressionOfMyType->leftExpression) 
		&& this->rightExpression->equals(context, targetExpressionOfMyType->rightExpression);
}

void BinaryOperatorExpression::link(LinkContext *const &context)
{
	this->leftExpression->link(context);
	this->rightExpression->link(context);
}
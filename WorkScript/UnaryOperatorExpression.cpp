#include "stdafx.h"
#include "UnaryOperatorExpression.h"
#include "TypeExpression.h"
#include "Context.h"

UnaryOperatorExpression::~UnaryOperatorExpression()
{
}

bool UnaryOperatorExpression::equals(Context * const & context, const Pointer<Expression> &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context)))return false;
	return this->subExpression->equals(context, ((Pointer<UnaryOperatorExpression>)target)->subExpression);
}

void UnaryOperatorExpression::link(LinkContext * const & context)
{
	this->subExpression->link(context);
}

#include "PointerExpression.h"

PointerExpression::~PointerExpression()
{
}

const Pointer<Expression> PointerExpression::evaluate(Context * const & context)
{
	return this->getTargetValue();
}

void PointerExpression::link(LinkContext * const & context)
{
	return;
}

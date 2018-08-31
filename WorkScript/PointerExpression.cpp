#include "PointerExpression.h"

PointerExpression::~PointerExpression()
{
}

Expression * const PointerExpression::evaluate(Context * const & context)
{
	return this->getTargetValue();
}

void PointerExpression::compile(CompileContext * const & context)
{
	return;
}

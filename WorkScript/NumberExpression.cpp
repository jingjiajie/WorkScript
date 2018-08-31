#include "NumberExpression.h"
#include "BooleanExpression.h"
#include "TempExpression.h"

NumberExpression::~NumberExpression()
{
}

void NumberExpression::compile(CompileContext * const & context)
{
	return;
}

bool NumberExpression::equals(Context * const & context, Expression * const & targetExpression) const
{
	TempExpression<BooleanExpression> res(this, this->equals(targetExpression));
	return res->getValue();
}

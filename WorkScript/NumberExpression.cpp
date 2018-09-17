#include "NumberExpression.h"
#include "BooleanExpression.h"

NumberExpression::~NumberExpression()
{
}

void NumberExpression::link(LinkContext * const & context)
{
	return;
}

bool NumberExpression::equals(Context * const & context, const Pointer<Expression> & targetExpression) const
{
	Pointer<BooleanExpression> res =  this->equals(targetExpression);
	return res->getValue();
}

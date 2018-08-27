#include "UnaryOperatorExpression.h"
#include "TypeExpression.h"
#include "Context.h"

UnaryOperatorExpression::~UnaryOperatorExpression()
{
}

bool UnaryOperatorExpression::equals(Context * const & context, Expression * const &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context)))return false;
	return this->subExpression->equals(context, ((UnaryOperatorExpression *)target)->subExpression);
}

void UnaryOperatorExpression::compile(CompileContext * const & context)
{
	this->subExpression->compile(context);
}

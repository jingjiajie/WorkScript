#include "PointerExpression.h"
#include "StringExpression.h"
#include "Context.h"

PointerExpression::~PointerExpression()
{
}

Expression * const PointerExpression::evaluate(Context * const & context)
{
	return this->targetContext->getLocalVariable(this->offset);
}

void PointerExpression::compile(CompileContext * const & context)
{
	return;
}

TypeExpression * const PointerExpression::getType(Context * const & context) const
{
	return &TypeExpression::POINTER_EXPRESSION;
}

StringExpression * const PointerExpression::toString(Context * const & context)
{
	static StringExpression str(L"PointerExpression",StorageLevel::EXTERN);
	return &str;
}

bool PointerExpression::equals(Context * const & context, Expression * const &target) const
{
	if (!target->getType(context)->equals(context,&TypeExpression::POINTER_EXPRESSION))return false;
	auto targetPointerExpr = (PointerExpression *const &)target;
	if (targetPointerExpr->targetContext != this->targetContext)return false;
	if (targetPointerExpr->offset != this->offset)return false;
	return true;
}

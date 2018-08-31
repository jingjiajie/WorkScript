#include "ExpressionPointerExpression.h"
#include "StringExpression.h"
#include "Context.h"

ExpressionPointerExpression::~ExpressionPointerExpression()
{
}

TypeExpression * const ExpressionPointerExpression::getType(Context * const & context) const
{
	return &TypeExpression::EXPRESSION_POINTER_EXPRESSION;
}

StringExpression * const ExpressionPointerExpression::toString(Context * const & context)
{
	static StringExpression str(L"ExpressionPointerExpression",StorageLevel::EXTERN);
	return &str;
}

bool ExpressionPointerExpression::equals(Context * const & context, Expression * const &target) const
{
	if (!target->getType(context)->equals(context,&TypeExpression::EXPRESSION_POINTER_EXPRESSION))return false;
	auto targetPointerExpr = (ExpressionPointerExpression *const &)target;
	return this->ptr == targetPointerExpr->ptr;
}

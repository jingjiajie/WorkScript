#include "stdafx.h"
#include "ExpressionPointerExpression.h"
#include "StringExpression.h"
#include "Context.h"

ExpressionPointerExpression::~ExpressionPointerExpression()
{
}

const Pointer<TypeExpression> ExpressionPointerExpression::getType(Context * const & context) const
{
	return TypeExpression::EXPRESSION_POINTER_EXPRESSION;
}

const Pointer<StringExpression> ExpressionPointerExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> str = new StringExpression(L"ExpressionPointerExpression", ReleaseStrategy::DELETE);
	return str;
}

bool ExpressionPointerExpression::equals(Context * const & context, const Pointer<Expression> &target) const
{
	if (!target->getType(context)->equals(context,TypeExpression::EXPRESSION_POINTER_EXPRESSION))return false;
	auto targetPointerExpr = (const Pointer<ExpressionPointerExpression> &)target;
	return this->ptr == targetPointerExpr->ptr;
}

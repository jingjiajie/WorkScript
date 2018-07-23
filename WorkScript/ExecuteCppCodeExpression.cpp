#include "ExecuteCppCodeExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "UnimplementedException.h"

ExecuteCppCodeExpression::ExecuteCppCodeExpression(Context *const &context, const std::function<const std::shared_ptr<const Expression>(const ExpressionBind&)> &evaluateFunction)
	:PolynomialExpression(context)
{
	this->evaluateFunction = evaluateFunction;
}


ExecuteCppCodeExpression::~ExecuteCppCodeExpression()
{
}

const std::shared_ptr<const Expression> ExecuteCppCodeExpression::evaluate(const ExpressionBind &expressionBind) const
{
	return this->evaluateFunction(expressionBind);
}

bool ExecuteCppCodeExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	throw UnimplementedException();
}

bool ExecuteCppCodeExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	return false;
}

const std::shared_ptr<const TypeExpression> ExecuteCppCodeExpression::getType() const
{
	return this->context->findType(TYPENAME_EXECUTE_CPP_CODE_EXPRESSION, false);
}

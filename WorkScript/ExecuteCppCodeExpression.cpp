#include "ExecuteCppCodeExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "UnimplementedException.h"

ExecuteCppCodeExpression::ExecuteCppCodeExpression(const std::function<const std::shared_ptr<TermExpression>(Context*)> &evaluateFunction)
{
	this->evaluateFunction = evaluateFunction;
}


ExecuteCppCodeExpression::~ExecuteCppCodeExpression()
{
}

const std::shared_ptr<TermExpression> ExecuteCppCodeExpression::evaluate(Context *context)
{
	return this->evaluateFunction(context);
}

//bool ExecuteCppCodeExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	throw UnimplementedException();
//}

const std::shared_ptr<TypeExpression> ExecuteCppCodeExpression::getType() const
{
	return TypeExpression::EXECUTE_CPP_CODE_EXPRESSION;
}

bool ExecuteCppCodeExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	return false;
}

const std::string ExecuteCppCodeExpression::toString() const
{
	return "(Native Code)";
}

void ExecuteCppCodeExpression::compile(CompileContext * context)
{
	return;
}

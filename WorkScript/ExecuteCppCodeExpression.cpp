#include "ExecuteCppCodeExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "UnimplementedException.h"
#include "StringExpression.h"
#include "Program.h"

using namespace std;

ExecuteCppCodeExpression::~ExecuteCppCodeExpression()
{
}

Expression* const ExecuteCppCodeExpression::evaluate(Context *const& context)
{
	return this->evaluateFunction(context);
}

//bool ExecuteCppCodeExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	throw UnimplementedException();
//}

TypeExpression* const ExecuteCppCodeExpression::getType(Context *const& context) const
{
	return &TypeExpression::EXECUTE_CPP_CODE_EXPRESSION;
}

bool ExecuteCppCodeExpression::equals(Context *const &context, Expression* const& targetExpression) const
{
	return false;
}

StringExpression *const ExecuteCppCodeExpression::toString(Context *const& context)
{
	static StringExpression str = StringExpression(L"(Native Code)", StorageLevel::EXTERN);
	return &str;
}

void ExecuteCppCodeExpression::compile(CompileContext *const &context)
{
	return;
}

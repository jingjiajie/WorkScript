#include "stdafx.h"
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

const Pointer<Expression> ExecuteCppCodeExpression::evaluate(Context *const& context)
{
	return this->evaluateFunction(context);
}

//bool ExecuteCppCodeExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	throw UnimplementedException();
//}

const Pointer<TypeExpression> ExecuteCppCodeExpression::getType(Context *const& context) const
{
	return TypeExpression::EXECUTE_CPP_CODE_EXPRESSION;
}

bool ExecuteCppCodeExpression::equals(Context *const &context, const Pointer<Expression> & targetExpression) const
{
	return false;
}

const Pointer<StringExpression> ExecuteCppCodeExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> str = new StringExpression(L"(Native Code)", ReleaseStrategy::DELETE);
	return str;
}

void ExecuteCppCodeExpression::link(LinkContext *const &context)
{
	return;
}

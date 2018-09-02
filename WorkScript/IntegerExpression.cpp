#include "IntegerExpression.h"
#include "DoubleExpression.h"
#include "ByteExpression.h"
#include "BooleanExpression.h"
#include "StringExpression.h"
#include "OperatorWrappers.hpp"

#include <string.h>

OBJECT_POOL_MEMBER_IMPL(IntegerExpression, 1024);

#define INTEGER_COMPARE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<BooleanExpression> IntegerExpression::funcName(const Pointer<Expression> & targetExpression) const \
{ \
	bool result = false; \
	switch (targetExpression->getType(nullptr)->getTypeID()) { \
		case TypeExpression::TYPEID_DOUBLE: \
			result = signWrapper(this->value, ((Pointer<DoubleExpression>)targetExpression)->getValue()); \
			break; \
		case TypeExpression::TYPEID_INTEGER: \
			result = signWrapper(this->value, ((Pointer<IntegerExpression>)targetExpression)->getValue()); \
			break; \
		case TypeExpression::TYPEID_BYTE: \
			result = signWrapper(this->value, ((Pointer<ByteExpression>)targetExpression)->getValue()); \
			break; \
	} \
	return BooleanExpression::newInstance(result); \
} \

#define INTEGER_CALCULATE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<NumberExpression> IntegerExpression::funcName(const Pointer<Expression> & targetExpression) const \
{ \
	Pointer<NumberExpression>result = nullptr; \
	switch (targetExpression->getType(nullptr)->getTypeID()) { \
	case TypeExpression::TYPEID_DOUBLE: \
		result = DoubleExpression::newInstance(signWrapper(this->value, ((Pointer<DoubleExpression>)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_INTEGER: \
		result = IntegerExpression::newInstance(signWrapper(this->value, ((Pointer<IntegerExpression>)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_BYTE: \
		result = IntegerExpression::newInstance(signWrapper(this->value, ((Pointer<ByteExpression>)targetExpression)->getValue())); \
		break; \
	} \
	return result; \
} \

INTEGER_COMPARE_FUNCTION_IMPL(greaterThan, GREATER_THAN_WRAPPER)
INTEGER_COMPARE_FUNCTION_IMPL(greaterThanEquals, GREATER_THAN_EQUALS_WRAPPER)
INTEGER_COMPARE_FUNCTION_IMPL(lessThan, LESS_THAN_WRAPPER)
INTEGER_COMPARE_FUNCTION_IMPL(lessThanEquals, LESS_THAN_EQUALS_WRAPPER)
INTEGER_COMPARE_FUNCTION_IMPL(equals, EQUALS_WRAPPER)

INTEGER_CALCULATE_FUNCTION_IMPL(plus, PLUS_WRAPPER)
INTEGER_CALCULATE_FUNCTION_IMPL(minus, MINUS_WRAPPER)
INTEGER_CALCULATE_FUNCTION_IMPL(multiply, MULTIPLY_WRAPPER)
INTEGER_CALCULATE_FUNCTION_IMPL(divide, DIVIDE_WRAPPER)
INTEGER_CALCULATE_FUNCTION_IMPL(modulus, MODULUS_WRAPPER)


IntegerExpression::~IntegerExpression()
{
}

const Pointer<Expression> IntegerExpression::evaluate(Context * const & context)
{
	return this;
}

const Pointer<StringExpression> IntegerExpression::toString(Context * const & context)
{
	wchar_t buff[32];
	swprintf(buff,32, L"%d", this->value);
	return StringExpression::newInstance(buff);
}

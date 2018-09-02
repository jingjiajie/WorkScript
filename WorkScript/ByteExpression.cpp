#include "ByteExpression.h"
#include "DoubleExpression.h"
#include "IntegerExpression.h"
#include "BooleanExpression.h"
#include "OperatorWrappers.hpp"
#include "StringExpression.h"

OBJECT_POOL_MEMBER_IMPL(ByteExpression,64);

#define BYTE_COMPARE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<BooleanExpression> ByteExpression::funcName(const Pointer<Expression> & targetExpression) const \
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

#define BYTE_CALCULATE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<NumberExpression> ByteExpression::funcName(const Pointer<Expression> & targetExpression) const \
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
		result = ByteExpression::newInstance(signWrapper(this->value, ((Pointer<ByteExpression>)targetExpression)->getValue())); \
		break; \
	} \
	return result; \
} \

BYTE_COMPARE_FUNCTION_IMPL(greaterThan, GREATER_THAN_WRAPPER)
BYTE_COMPARE_FUNCTION_IMPL(greaterThanEquals, GREATER_THAN_EQUALS_WRAPPER)
BYTE_COMPARE_FUNCTION_IMPL(lessThan, LESS_THAN_WRAPPER)
BYTE_COMPARE_FUNCTION_IMPL(lessThanEquals, LESS_THAN_EQUALS_WRAPPER)
BYTE_COMPARE_FUNCTION_IMPL(equals, EQUALS_WRAPPER)

BYTE_CALCULATE_FUNCTION_IMPL(plus, PLUS_WRAPPER)
BYTE_CALCULATE_FUNCTION_IMPL(minus, MINUS_WRAPPER)
BYTE_CALCULATE_FUNCTION_IMPL(multiply, MULTIPLY_WRAPPER)
BYTE_CALCULATE_FUNCTION_IMPL(divide, DIVIDE_WRAPPER)
BYTE_CALCULATE_FUNCTION_IMPL(modulus, MODULUS_WRAPPER)

ByteExpression::~ByteExpression()
{
}

const Pointer<Expression> ByteExpression::evaluate(Context * const & context)
{
	return this;
}

const Pointer<StringExpression> ByteExpression::toString(Context * const & context)
{
	wchar_t buff[4];
	swprintf(buff,4, L"%d", this->value);
	return StringExpression::newInstance(buff);
}

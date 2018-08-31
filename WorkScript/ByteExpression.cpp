#include "ByteExpression.h"
#include "DoubleExpression.h"
#include "IntegerExpression.h"
#include "BooleanExpression.h"
#include "OperatorWrappers.hpp"
#include "StringExpression.h"

OBJECT_POOL_MEMBER_IMPL(ByteExpression,1024);

#define BYTE_COMPARE_FUNCTION_IMPL(funcName, signWrapper) \
BooleanExpression *const ByteExpression::funcName(Expression * const & targetExpression) const \
{ \
	bool result = false; \
	switch (targetExpression->getType(nullptr)->getTypeID()) { \
		case TypeExpression::TYPEID_DOUBLE: \
			result = signWrapper(this->value, ((DoubleExpression*)targetExpression)->getValue()); \
			break; \
		case TypeExpression::TYPEID_INTEGER: \
			result = signWrapper(this->value, ((IntegerExpression*)targetExpression)->getValue()); \
			break; \
		case TypeExpression::TYPEID_BYTE: \
			result = signWrapper(this->value, ((ByteExpression*)targetExpression)->getValue()); \
			break; \
	} \
	return BooleanExpression::newInstance(result); \
} \

#define BYTE_CALCULATE_FUNCTION_IMPL(funcName, signWrapper) \
NumberExpression *const ByteExpression::funcName(Expression* const& targetExpression) const \
{ \
	NumberExpression *result = nullptr; \
	switch (targetExpression->getType(nullptr)->getTypeID()) { \
	case TypeExpression::TYPEID_DOUBLE: \
		result = DoubleExpression::newInstance(signWrapper(this->value, ((DoubleExpression*)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_INTEGER: \
		result = IntegerExpression::newInstance(signWrapper(this->value, ((IntegerExpression*)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_BYTE: \
		result = ByteExpression::newInstance(signWrapper(this->value, ((ByteExpression*)targetExpression)->getValue())); \
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

Expression * const ByteExpression::evaluate(Context * const & context)
{
	return this->storageLevel == StorageLevel::LITERAL ? newInstance(this->value) : this;
}

StringExpression * const ByteExpression::toString(Context * const & context)
{
	wchar_t buff[4];
	swprintf(buff,4, L"%d", this->value);
	return StringExpression::newInstance(buff);
}

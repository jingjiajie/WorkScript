#include "DoubleExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "IntegerExpression.h"
#include "ByteExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"
#include "OperatorWrappers.hpp"

#include <type_traits>

using namespace std;

OBJECT_POOL_MEMBER_IMPL(DoubleExpression, 64);

#define DOUBLE_COMPARE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<BooleanExpression> DoubleExpression::funcName(const Pointer<Expression> & targetExpression) const \
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

#define DOUBLE_CALCULATE_FUNCTION_IMPL(funcName, signWrapper) \
const Pointer<NumberExpression> DoubleExpression::funcName(const Pointer<Expression> & targetExpression) const \
{ \
	Pointer<NumberExpression>result = nullptr; \
	switch (targetExpression->getType(nullptr)->getTypeID()) { \
	case TypeExpression::TYPEID_DOUBLE: \
		result = DoubleExpression::newInstance(signWrapper(this->value, ((Pointer<DoubleExpression>)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_INTEGER: \
		result = DoubleExpression::newInstance(signWrapper(this->value, ((Pointer<IntegerExpression>)targetExpression)->getValue())); \
		break; \
	case TypeExpression::TYPEID_BYTE: \
		result = DoubleExpression::newInstance(signWrapper(this->value, ((Pointer<ByteExpression>)targetExpression)->getValue())); \
		break; \
	} \
	return result; \
} \


DOUBLE_COMPARE_FUNCTION_IMPL(greaterThan, GREATER_THAN_WRAPPER)
DOUBLE_COMPARE_FUNCTION_IMPL(greaterThanEquals, GREATER_THAN_EQUALS_WRAPPER)
DOUBLE_COMPARE_FUNCTION_IMPL(lessThan, LESS_THAN_WRAPPER)
DOUBLE_COMPARE_FUNCTION_IMPL(lessThanEquals, LESS_THAN_EQUALS_WRAPPER)
DOUBLE_COMPARE_FUNCTION_IMPL(equals, EQUALS_WRAPPER)

DOUBLE_CALCULATE_FUNCTION_IMPL(plus, PLUS_WRAPPER)
DOUBLE_CALCULATE_FUNCTION_IMPL(minus, MINUS_WRAPPER)
DOUBLE_CALCULATE_FUNCTION_IMPL(multiply, MULTIPLY_WRAPPER)
DOUBLE_CALCULATE_FUNCTION_IMPL(divide, DIVIDE_WRAPPER)
DOUBLE_CALCULATE_FUNCTION_IMPL(modulus, MODULUS_WRAPPER)

DoubleExpression::~DoubleExpression()
{

}

const Pointer<Expression> DoubleExpression::evaluate(Context *const& context)
{
	return this;
}

//bool DoubleExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

const Pointer<StringExpression> DoubleExpression::toString(Context *const& context)
{
	double number = this->value;
	wstring numberStr;
	if (fabs(number - (int)number) < 1e-8) {
		numberStr = to_wstring((int)number);
	}
	else { //如果是小数，删除末尾0
		numberStr = to_wstring(number);
		size_t lastZeroCount = 0;
		for (size_t i = numberStr.size() - 1; i >= 0; i--) {
			if (numberStr[i] == '0') {
				lastZeroCount++;
			}
			else {
				break;
			}
		}
		numberStr = numberStr.substr(0, numberStr.size() - lastZeroCount);
	}
	return StringExpression::newInstance(numberStr.c_str());
}
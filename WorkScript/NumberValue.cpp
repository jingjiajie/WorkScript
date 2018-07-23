#include "NumberValue.h"

using namespace std;

NumberValue::NumberValue(double number, const TypeInfo &type)
{
	this->number = number;
	this->type = &type;
}

NumberValue::~NumberValue()
{
}

const string NumberValue::toString() const
{
	return to_string(this->number);
}

const TypeInfo & NumberValue::getType() const
{
	return *this->type;
}

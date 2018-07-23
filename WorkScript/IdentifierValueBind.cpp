#include "IdentifierValueBind.h"

const Identifier * IdentifierValueBind::getIdentifier() const
{
	return this->identifier;
}

void IdentifierValueBind::setIdentifier(const Identifier *identifier)
{
	this->identifier = identifier;
}

const Value * IdentifierValueBind::getValue() const
{
	return this->value;
}

void IdentifierValueBind::setValue(const Value *value)
{
	this->value = value;
}

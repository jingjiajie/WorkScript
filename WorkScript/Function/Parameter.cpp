#include "Parameter.h"
#include "InstantialContext.h"
#include "Value.h"

using namespace std;
using namespace WorkScript;

Type * WorkScript::Parameter::getType()
{
	return this->type;
}

Parameter::~Parameter() noexcept
{
	delete this->defaultValue;
}

void Parameter::setDefaultValue(Expression *value) noexcept
{
	delete this->defaultValue;
	this->defaultValue = value;
}
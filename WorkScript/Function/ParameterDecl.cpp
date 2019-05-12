#include "ParameterDecl.h"
#include "InstantialContext.h"
#include "Value.h"

using namespace std;
using namespace WorkScript;

Type * WorkScript::ParameterDecl::getType()
{
	return this->type;
}

ParameterDecl::~ParameterDecl() noexcept
{
	delete this->defaultValue;
}

void ParameterDecl::setDefaultValue(Expression *value) noexcept
{
	delete this->defaultValue;
	this->defaultValue = value;
}
#include "Parameter.h"
#include "InstantialContext.h"
#include "Value.h"

using namespace std;
using namespace WorkScript;

Type * WorkScript::Parameter::getType(InstantialContext *ctx)
{
	if (this->type)return this->type;
	if (!ctx)return nullptr;
	SymbolInfo *info = ctx->getSymbolInfo(this->name);
	if (!info)return nullptr;
	return info->getType();
}

Parameter::~Parameter()
{
	delete this->defaultValue;
}

void Parameter::setDefaultValue(WorkScript::Value *value) noexcept
{
	delete this->defaultValue;
	this->defaultValue = value;
}
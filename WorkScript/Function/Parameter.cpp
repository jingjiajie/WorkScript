#include "Parameter.h"
#include "InstantializeContext.h"
#include "Constant.h"

using namespace std;
using namespace WorkScript;

Type * WorkScript::Parameter::getType(InstantializeContext *ctx)
{
	if (this->type)return this->type;
	if (!ctx)return nullptr;
	SymbolInfo *info = ctx->getSymbolInfo(this->name);
	if (!info)return nullptr;
	return info->getType();
}

Parameter::~Parameter()
{
	if (this->defaultValue)
		delete this->defaultValue;
}

void Parameter::setDefaultValue(WorkScript::Constant *value)
{
	if (this->defaultValue)delete this->defaultValue;
	this->defaultValue = value;
}
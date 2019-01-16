#include "Parameter.h"
#include "InstantializeContext.h"

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

#include "stdafx.h"
#include "OverloadTemplate.h"
#include "FunctionTemplate.h"
#include "BranchOverload.h"
#include "Parameter.h"

using namespace WorkScript;
using namespace std;

WorkScript::OverloadTemplate::~OverloadTemplate()
{
	for (size_t i = 0; i < this->parameters.size(); ++i)
	{
		delete this->parameters[i];
	}
}

bool WorkScript::OverloadTemplate::matchByParameters(const std::vector<Type*> &paramTypes)
{
	size_t paramCount = paramTypes.size();
	if (paramCount != this->parameters.size())return false;
	for (size_t i = 0; i < paramCount; ++i) {
		ParameterTemplate *paramTemplate = this->parameters[i];
		if (paramTemplate->getType() == nullptr) continue;
		else if (paramTemplate->getType() != paramTypes[i]) return false;
	}
	return true;
}

Overload * WorkScript::OverloadTemplate::createOverload(Function *func, const std::vector<Type*>& paramTypes) const
{
	vector<Parameter*> params;
	params.reserve(paramTypes.size());
	for (size_t i = 0; i < params.size(); ++i) {
		Parameter *curParam = new Parameter(this->parameters[i]->getName(), paramTypes[i], this->parameters[i]->getDefaultValue());
		params[i] = curParam;
	}
	Overload *overload = new BranchOverload(func,params,);
}

ParameterTemplate * WorkScript::OverloadTemplate::getThisParameter()
{
	return this->function->getThisParameter();
}

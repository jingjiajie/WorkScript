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

Program * WorkScript::OverloadTemplate::getProgram()
{
	return this->function->getProgram();
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

ParameterTemplate * WorkScript::OverloadTemplate::getThisParameter()
{
	return this->function->getThisParameter();
}

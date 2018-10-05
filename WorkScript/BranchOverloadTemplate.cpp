#include "stdafx.h"
#include "BranchOverloadTemplate.h"
#include "BranchOverload.h"
#include "Parameter.h"
#include "FunctionTemplate.h"
#include "Program.h"

using namespace WorkScript;
using namespace std;

BranchOverloadTemplate::BranchOverloadTemplate()
{
}


BranchOverloadTemplate::~BranchOverloadTemplate()
{
}

Overload * WorkScript::BranchOverloadTemplate::createOverload(Function * func, const std::vector<Type*>& paramTypes) const
{
	vector<Parameter*> params;
	params.reserve(paramTypes.size());
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		params[i] = new Parameter(this->parameters[i]->getName(), paramTypes[i], this->parameters[i]->getDefaultValue());
	}
	Type *retType;
	if (this->branchTemplates.size() == 0)
	{
		retType = this->function->getProgram()->getType(TYPENAME_VOID);
	}
	else {
		auto exprs = this->branchTemplates[0]->getExpressions();
		retType = exprs->at(exprs->size() - 1)->getType();
	}
	Overload *overload = new BranchOverload(func, params, retType);
	return overload;
}

#include "stdafx.h"
#include "BranchOverloadTemplate.h"
#include "BranchOverload.h"
#include "Parameter.h"
#include "FunctionTemplate.h"
#include "VoidType.h"
#include "Program.h"

using namespace WorkScript;
using namespace std;

BranchOverloadTemplate::~BranchOverloadTemplate()
{
	for (auto br : this->branchTemplates)delete br;
}

Overload * WorkScript::BranchOverloadTemplate::createOverload(Function * func, const std::vector<Type*>& paramTypes) const
{
	vector<Parameter*> params;
	params.reserve(paramTypes.size());
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		params.push_back(new Parameter(this->parameters[i]->getName(), paramTypes[i], this->parameters[i]->getDefaultValue()));
	}
	Type *retType;
	if (this->branchTemplates.size() == 0)
	{
		retType = this->function->getProgram()->getVoidType();
	}
	else {
		auto exprs = this->branchTemplates[0]->getExpressions();
		retType = exprs->at(exprs->size() - 1)->getType();
	}
	BranchOverload *overload = new BranchOverload(func, params, retType);
	for (auto br : this->branchTemplates)
	{
		overload->addBranch(br->createOverloadBranch(overload));
	}
	
	return overload;
}

void WorkScript::BranchOverloadTemplate::setBranches(const std::vector<OverloadBranchTemplate*>& branches)
{
	for (auto br : this->branchTemplates)delete br;
	this->branchTemplates = branches;
}

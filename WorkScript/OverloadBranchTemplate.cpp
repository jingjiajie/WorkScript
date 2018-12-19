#include "stdafx.h"
#include "OverloadBranchTemplate.h"
#include "OverloadBranch.h"
#include "InstantializeContext.h"

using namespace WorkScript;
using namespace std;

WorkScript::OverloadBranchTemplate::~OverloadBranchTemplate()
{
	for (auto c : this->conditions) {
		delete c;
	}
	for (auto e : this->expressions) {
		delete e;
	}
}

OverloadBranch * WorkScript::OverloadBranchTemplate::createOverloadBranch(BranchOverload *branchOverload)
{
	InstantializeContext context(this->overload->getSymbolTable());
	size_t condSize = this->conditions.size();
	size_t exprSize = this->expressions.size();
	vector<Expression*> conds, exprs;
	conds.reserve(condSize);
	exprs.reserve(exprSize);
	for (size_t i = 0; i < condSize; ++i) {
		conds.push_back(this->conditions[i]->instantialize(&context));
	}
	for (size_t i = 0; i < exprSize; ++i) {
		exprs.push_back(this->expressions[i]->instantialize(&context));
	}
	OverloadBranch *overloadBranch = new OverloadBranch(branchOverload,location, conds, exprs);
	return overloadBranch;
}

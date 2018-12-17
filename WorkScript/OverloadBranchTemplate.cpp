#include "stdafx.h"
#include "OverloadBranchTemplate.h"
#include "OverloadBranch.h"

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
	size_t condSize = this->conditions.size();
	size_t exprSize = this->expressions.size();
	vector<Expression*> conds, exprs;
	conds.reserve(condSize);
	exprs.reserve(exprSize);
	for (size_t i = 0; i < condSize; ++i) {
		conds.push_back(this->conditions[i]->clone());
	}
	for (size_t i = 0; i < exprSize; ++i) {
		exprs.push_back(this->expressions[i]->clone());
	}
	OverloadBranch *overloadBranch = new OverloadBranch(branchOverload,location, conds, exprs);
	return overloadBranch;
}

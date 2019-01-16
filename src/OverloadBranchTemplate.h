#pragma once
#include <vector>
#include "Expression.h"
#include "OverloadTemplate.h"

namespace WorkScript
{
	class FunctionBranch;
	class BranchFunction;

	class OverloadBranchTemplate
	{
	public:
		inline OverloadBranchTemplate(OverloadTemplate *function, Location loc, const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->location = loc;
			this->conditions = conds;
			this->expressions = codes;
			this->function = function;
		}

		~OverloadBranchTemplate();

		FunctionBranch * createOverloadBranch(BranchFunction *branchOverload);

		inline Program * getProgram() { return this->function->getProgram(); }
		inline std::vector<Expression*> * getExpressions() { return &this->expressions; }
		inline Location getLocation() const { return this->location; };
	private:
		std::vector<Expression*> conditions;
		std::vector<Expression*> expressions;
		OverloadTemplate *function;
		Location location;
	};
}

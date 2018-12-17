#pragma once
#include <vector>
#include "Expression.h"
#include "OverloadTemplate.h"

namespace WorkScript
{
	class OverloadBranch;
	class BranchOverload;

	class OverloadBranchTemplate
	{
	public:
		inline OverloadBranchTemplate(OverloadTemplate *overload, Location loc, const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->location = loc;
			this->conditions = conds;
			this->expressions = codes;
			this->overload = overload;
		}

		~OverloadBranchTemplate();

		OverloadBranch * createOverloadBranch(BranchOverload *branchOverload);

		inline Program * getProgram() { return this->overload->getProgram(); }
		inline std::vector<Expression*> * getExpressions() { return &this->expressions; }
		inline Location getLocation() const { return this->location; };
	private:
		std::vector<Expression*> conditions;
		std::vector<Expression*> expressions;
		OverloadTemplate *overload;
		Location location;
	};
}

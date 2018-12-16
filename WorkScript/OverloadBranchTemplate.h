#pragma once
#include <vector>
#include "Expression.h"
#include "OverloadBranch.h"
#include "OverloadTemplate.h"

namespace WorkScript
{
	class OverloadBranchTemplate
	{
	public:
		inline OverloadBranchTemplate(OverloadTemplate *overload, const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->conditions = conds;
			this->expressions = codes;
			this->overload = overload;
		}

		~OverloadBranchTemplate();

		OverloadBranch * createOverloadBranch();

		inline Program * getProgram() { return this->overload->getProgram(); }
		inline std::vector<Expression*> * getExpressions() { return &this->expressions; }
	private:
		std::vector<Expression*> conditions;
		std::vector<Expression*> expressions;
		OverloadTemplate *overload;
	};
}

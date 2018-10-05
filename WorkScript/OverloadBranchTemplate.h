#pragma once
#include <vector>
#include "Expression.h"
namespace WorkScript
{
	class OverloadBranchTemplate
	{
	public:
		inline OverloadBranchTemplate(const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->setConditions(conds);
			this->setExpressions(codes);
		}

		void setConditions(const std::vector<Expression*> &conds)
		{
			this->conditions = conds;
		}

		void setExpressions(const std::vector<Expression*> codes)
		{
			this->expressions = codes;
		}

		inline std::vector<Expression*> * getExpressions()
		{
			return &this->expressions;
		}
	private:
		std::vector<Expression*> conditions;
		std::vector<Expression*> expressions;
	};
}

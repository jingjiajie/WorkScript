#pragma once
#include "OverloadTemplate.h"
#include "OverloadBranchTemplate.h"

namespace WorkScript {
	class BranchOverloadTemplate : public OverloadTemplate
	{
	public:
		inline BranchOverloadTemplate(FunctionTemplate *func, const std::vector<ParameterTemplate*> &params, Type *returnType = nullptr)
			: OverloadTemplate(func, params, returnType) {}

		virtual ~BranchOverloadTemplate();

		virtual Overload * createOverload(Function *func, const std::vector<Type*> &paramTypes) const override;

	private:
		std::vector<OverloadBranchTemplate*> branchTemplates;
	};
}
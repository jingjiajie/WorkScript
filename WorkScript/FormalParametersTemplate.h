#pragma once
#include <vector>

namespace WorkScript {
	class ParameterTemplate;
	class Expression;
	class OverloadBranchTemplate;

	class FormalParametersTemplate {
	public:
		FormalParametersTemplate(OverloadBranchTemplate *overloadBranch, std::vector<Expression*> declParams);
		inline std::vector<Expression*> getConstraints() { return this->constraints; };
		inline std::vector<ParameterTemplate*> getParameterTemplates() { return this->parameterTemplates; };
	protected:
		std::vector<ParameterTemplate*> parameterTemplates;
		std::vector<Expression*> constraints;
		OverloadBranchTemplate *overloadBranch;
	};
}
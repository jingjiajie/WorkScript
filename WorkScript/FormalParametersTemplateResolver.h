#pragma once
#include <vector>
#include "Expression.h"

namespace WorkScript {
	class ParameterTemplate;
	class Expression;

	class FormalParametersTemplateResolver {
	public:
		class ResolveResult
		{
		public:
			ResolveResult(const std::vector<ParameterTemplate*> &params, const std::vector<Expression*> &constraints, std::vector<Type*> &paramTypes)
				:parameterTemplates(params), constraints(constraints), parameterTypes(paramTypes) {}
			inline std::vector<ParameterTemplate*> getParameterTemplates() const { return this->parameterTemplates; }
			inline std::vector<Expression*> getConstraints() const { return this->constraints; }
			inline std::vector<Type*> getParameterTypes() const { return this->parameterTypes; }
		protected:
			std::vector<ParameterTemplate*> parameterTemplates;
			std::vector<Expression*> constraints;
			std::vector<Type*> parameterTypes;
		};

		static ResolveResult resolve(EXPRESSION_CTOR_FORMAL_PARAMS, std::vector<Expression*> declParams, std::vector<Expression*> constraints);
	};
}
#pragma once
#include <vector>
#include "Expression.h"

namespace WorkScript {
	class ParameterDecl;
	class Expression;

	class FormalParametersResolver {
	public:
		class ResolveResult
		{
		public:
			ResolveResult(const std::vector<ParameterDecl*> &params, const std::vector<Expression*> &constraints, std::vector<Type*> &paramTypes)
				:parameters(params), constraints(constraints), parameterTypes(paramTypes) {}
			inline std::vector<ParameterDecl*> getParameters() const { return this->parameters; }
			inline std::vector<Expression*> getConstraints() const { return this->constraints; }
			inline std::vector<Type*> getParameterTypes() const { return this->parameterTypes; }
		protected:
			std::vector<ParameterDecl*> parameters;
			std::vector<Expression*> constraints;
			std::vector<Type*> parameterTypes;
		};

		static ResolveResult resolve(const ExpressionInfo &exprInfo, std::vector<Type*> paramDeclTypes, std::vector<Expression*> declParams, std::vector<Expression*> constraints);
	};
}
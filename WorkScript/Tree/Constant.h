#pragma once
#include "GenerateResult.h"
#include "GenerateContext.h"
#include "Expression.h"

namespace WorkScript {
    class Type;
    class InstantialContext;

	class Constant : public Expression
	{
	public:
		inline Constant(const ExpressionInfo &exprInfo)
				: Expression(exprInfo)
		{}

		virtual Type *getType() const = 0;
		virtual Type* getType(InstantialContext *context) const override;
		virtual std::wstring toString() const override = 0;
		virtual Constant *clone() const override = 0;
		virtual GenerateResult generateIR(GenerateContext *context) override = 0;
		virtual ExpressionType getExpressionType() const override;

	protected:
		Program *program;
	};
}

#pragma once
#include "Expression.h"
#include "IntegerType.h"

namespace WorkScript {
	class IntegerExpression :
		public Expression
	{
	public:
		inline IntegerExpression(Program *program, IntegerType *type, long long v);

		virtual GenerateResult generateIR(GenerateContext *context);
		virtual ExpressionType getExpressionType() const override;
		virtual Type * getType() const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;

		inline long long getValue() const {
			return this->value;
		}

		inline void setValue(long long value) {
			this->value = value;
		}
	protected:
		long long value;
		IntegerType *type;
	};
}


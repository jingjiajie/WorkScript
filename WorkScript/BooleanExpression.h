#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class BooleanExpression :
		public Expression
	{
	public:
		inline BooleanExpression(const unsigned char value)
		{
			this->value = value;
		}

		virtual GenerateResult generateIR(GenerateContext *context);
		//virtual bool equals(Expression *targetExpression) const override;
		virtual std::wstring toString() const override;
		virtual Type * getType() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;

		inline const unsigned char getValue() const {
			return this->value;
		}

		inline void setValue(unsigned char &value) {
			this->value = value;
		}

	protected:
		unsigned char value;
	public:
		static BooleanExpression TRUE, YES, OK, GOOD, FALSE, NO, BAD;
	};
}

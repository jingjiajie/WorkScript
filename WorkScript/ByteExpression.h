#pragma once
#include "Expression.h"
#include <type_traits>
namespace WorkScript {
	class ByteExpression :
		public Expression
	{
	public:
		inline ByteExpression(unsigned char val):value(val)
		{}

		virtual GenerateResult generateIR(GenerateContext *context);
		virtual ExpressionType getExpressionType() const;
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual Expression * clone() const override;

		inline const unsigned char getValue() const {
			return this->value;
		}

		inline void setValue(const unsigned char &value) {
			this->value = value;
		}
	protected:
		unsigned char value;
	};
}
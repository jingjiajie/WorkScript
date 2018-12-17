#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript {

	class StringExpression :
		public Expression
	{
	public:
		inline StringExpression(EXPRESSION_CTOR_FORMAL_PARAMS, const std::wstring &v)
			:EXPRESSION_CTOR_CALL, value(v) { }

		virtual std::wstring toString() const override;
		virtual Type * getType() const override;
		virtual GenerateResult generateIR(GenerateContext *context);
		virtual ExpressionType getExpressionType() const;
		virtual Expression * clone() const override;

		inline std::wstring& getValue()
		{
			return this->value;
		}

		inline void setValue(const std::wstring &value)
		{
			this->value = value;
		}

		inline size_t getLength() const
		{
			return value.length();
		}

	protected:
		std::wstring value;
	};

}
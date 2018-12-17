#pragma once
#pragma once
#include <string>
#include "Expression.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class VariableExpression :
		public Expression
	{
	public:
		inline VariableExpression(EXPRESSION_CTOR_FORMAL_PARAMS, const std::wstring &name, Type *type = nullptr)
			:EXPRESSION_CTOR_CALL, name(name), type(type){ }

		virtual Expression * instantialize() override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;

		inline const std::wstring & getName() const { return this->name; }

		inline bool isVarargs() { return this->varargs; }
		inline void setVarargs(bool isVarargs) { this->varargs = isVarargs; }
		inline bool isDeclarable() const { return this->declarable; }
		inline void setDeclarable(bool declarable) { this->declarable = declarable; }
	protected:
		SymbolInfo * bindSymbolInfo = nullptr;
		std::wstring name;
		Type *type = nullptr;
		bool varargs = false;
		bool declarable = false; //可声明变量，如果具有此属性，则遇到该变量时可以创建声明。否则提示找不到符号
	};
}
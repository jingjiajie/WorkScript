#pragma once
#include <string>
#include "Expression.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class Variable :
		public Expression
	{
	public:
		Variable(const ExpressionInfo &exprInfo, const std::wstring &name);

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType(InstantialContext *context) const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;

		inline const std::wstring & getName() const { return this->name; }

		inline bool isVarargs() { return this->varargs; }
		inline void setVarargs(bool isVarargs) { this->varargs = isVarargs; }
		inline bool isDeclarable() const { return this->declarable; }
		inline void setDeclarable(bool declarable) { this->declarable = declarable; }
	protected:
		std::wstring name;
		bool varargs = false;
		bool declarable = false; //可声明变量，如果具有此属性，则遇到该变量时可以创建声明。否则提示找不到符号
	};
}
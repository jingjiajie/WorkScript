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

		GenerateResult generateIR(GenerateContext *context) override;
		Type * getType(InstantialContext *context) const override;
		Expression * clone() const override;
		std::wstring toString() const override;
		ExpressionType getExpressionType() const override;

		const Value *getValue(InstantialContext *ctx) const noexcept;
        Value *getValue(InstantialContext *ctx) noexcept;

		inline const std::wstring & getName() const { return this->name; }
		inline bool isDeclarable() const { return this->declarable; }
		inline void setDeclarable(bool declarable) { this->declarable = declarable; }
	protected:
		std::wstring name;
		bool declarable = false; //可声明变量，如果具有此属性，则遇到该变量时可以创建声明。否则提示找不到符号
	};
}
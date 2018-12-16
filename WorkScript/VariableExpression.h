#pragma once
#include <string>
#include "Expression.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class VariableExpression :
		public Expression
	{
	public:
		inline VariableExpression(Program *p, SymbolInfo *symbolInfo)
			:Expression(p)
		{
			this->symbolInfo = symbolInfo;
		}

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;

		inline const std::wstring & getName() const { return this->symbolInfo->getName(); }

		inline bool isVarargs() { return this->varargs; }
		inline void setVarargs(bool isVarargs) { this->varargs = isVarargs; }
		inline bool isDeclarable() const { return this->declarable; }
		inline void setDeclarable(bool declarable) { this->declarable = declarable; }
	protected:
		SymbolInfo *symbolInfo;
		bool varargs = false;
		bool declarable = false; //������������������д����ԣ��������ñ���ʱ���Դ���������������ʾ�Ҳ�������
	};
}
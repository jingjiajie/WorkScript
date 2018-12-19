#pragma once
#pragma once
#include <string>
#include "Expression.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class TemplateVariableExpression :
		public Expression
	{
	public:
		inline TemplateVariableExpression(EXPRESSION_CTOR_FORMAL_PARAMS, const std::wstring &name, SymbolTable *symbolTable, Type *type = nullptr);

		virtual Expression * instantialize(InstantializeContext *context) override;
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
		void promoteType(Type *type);
	protected:
		std::wstring name;
		SymbolTable *bindSymbolTable = nullptr;
		bool varargs = false;
		bool declarable = false; //������������������д����ԣ��������ñ���ʱ���Դ���������������ʾ�Ҳ�������
	};
}
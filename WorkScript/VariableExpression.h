#pragma once
#include <string>
#include "Expression.h"
#include "SymbolTable.h"

namespace WorkScript {
	class VariableExpression :
		public Expression
	{
	public:
		inline VariableExpression(const std::wstring &name)
		{
			this->setName(name);
		}

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		//virtual bool equals(Expression *) const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;

		inline void setType(Type *type)
		{
			this->type = type;
		}

		inline const std::wstring & getName() const
		{
			return this->name;
		}

		inline void setName(const std::wstring &name)
		{
			this->name = name;
		}

		inline bool isVarargs()
		{
			return this->varargs;
		}

		inline void setVarargs(bool isVarargs)
		{
			this->varargs = isVarargs;
		}

		//inline bool isDeclarable() const {
		//	return this->declarable;
		//}

		//inline void setDeclarable(bool declarable) {
		//	this->declarable = declarable;
		//}
	protected:
		std::wstring name;
		Type *type;
		bool varargs = false;
		SymbolTable *symbolTable = nullptr;
		//bool declarable = false; //������������������д����ԣ��������ñ���ʱ���Դ���������������ʾ�Ҳ�������
	};
}
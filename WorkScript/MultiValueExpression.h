#pragma once
#include "Expression.h"
namespace WorkScript {
	class MultiValueExpression :
		public Expression
	{
	public:
		inline MultiValueExpression(Program *p, const std::vector<Expression*> &items)
			:Expression(p)
		{
			this->setItems(items);
		}

		virtual ~MultiValueExpression();

		virtual Type * getType() const;
		std::vector<Type*> getTypes() const;

		virtual std::wstring toString() const override;
		virtual Expression * clone() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;

		std::vector<llvm::Value*> getLLVMArgs(GenerateContext * context) const;

		//virtual bool equals(Expression *) const override;

		inline decltype(auto) getItems() const
		{
			return (this->items);
		}

		inline decltype(auto) getItem(const size_t &index) const
		{
			return this->items[index];
		}

		inline void setItems(const std::vector<Expression*> &items)
		{
			this->items = items;
			//this->flat();
		}

		//void flat();

	protected:
		std::vector<Expression*> items;
	};
}


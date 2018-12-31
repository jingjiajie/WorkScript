#pragma once
#include "Expression.h"
namespace WorkScript {
	class MultiValueExpression :
		public Expression
	{
	public:
		virtual ~MultiValueExpression();

		virtual Type * getType(InstantializeContext *context) const;
		std::vector<Type*> getTypes(InstantializeContext *context) const;

		virtual std::wstring toString() const override;
		virtual MultiValueExpression * clone() const override;
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
		inline MultiValueExpression(const ExpressionInfo &exprInfo, const std::vector<Expression*> &items)
			:Expression(exprInfo)
		{
			this->setItems(items);
		}
	protected:
		std::vector<Expression*> items;
	};
}


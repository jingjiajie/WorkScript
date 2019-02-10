#pragma once
#include "Value.h"
namespace WorkScript {
	class MultiValue :
		public Value
	{
	public:
		inline explicit MultiValue(const ExpressionInfo &exprInfo, const std::vector<Expression*> &items) noexcept
				:Value(exprInfo), items(items)
		{ }

		~MultiValue() noexcept override;

		Type * getType(InstantialContext *context) const override;
		std::vector<Type*> getTypes(InstantialContext *context) const;

		std::wstring toString() const override;
		MultiValue * clone() const override;
		ExpressionType getExpressionType() const override;
		GenerateResult generateIR(GenerateContext *context) override;

		const std::vector<llvm::Value*> & getLLVMValues(GenerateContext *context, const std::vector<Type *> &expectedTypes);

		//virtual bool equals(Expression *) const override;

		inline decltype(auto) getItems() const
		{
			return (this->items);
		}

		inline decltype(auto) getItem(size_t index) const
		{
			return this->items[index];
		}
	protected:
		std::vector<Expression*> items;
		bool hadLLVMValues = false;
		std::vector<llvm::Value*> llvmValues;
	};
}


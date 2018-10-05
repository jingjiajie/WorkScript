#pragma once
#include "Expression.h"
namespace WorkScript {
	class ParameterExpression :
		public Expression
	{
	public:
		inline ParameterExpression(Pointer<Expression> *const& items, const size_t &count)
		{
			this->setItems(items, count);
		}

		virtual ~ParameterExpression();

		virtual Type * getType() const;
		virtual std::wstring toString();
		virtual void link(LinkContext *const& context) override;


		virtual bool equals(Expression *) const override;

		inline Expression * const getItems() const
		{
			return this->items;
		}

		inline Expression * getItem(const size_t &index)const
		{
			return this->items[index];
		}

		inline void setItems(Expression * items, const size_t &count)
		{
			this->items = items;
			this->count = count;
			this->flat();
		}

		inline const size_t getCount() const {
			return this->count;
		}

		void flat();

	protected:
		std::vector<Expression*> items;
		size_t count;
	};
}


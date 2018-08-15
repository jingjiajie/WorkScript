#include <sstream>
#include "ListExpression.h"
#include "TypeExpression.h"

using namespace std;

ListExpression::ListExpression()
{

}


ListExpression::~ListExpression()
{

}


const std::shared_ptr<TypeExpression> ListExpression::getType() const
{
	return TypeExpression::LIST_EXPRESSION;
}

const std::string ListExpression::toString() const
{
	stringstream ss;
	size_t total = this->items.size();
	ss << "[";
	for (size_t i = 0; i < total; i++) {
		ss << this->items[i]->toString();
		if (i != total - 1) {
			ss << ", ";
		}
	}
	ss << "]";
	return ss.str();
}

void ListExpression::compile(CompileContext * context)
{
	for (auto &item : this->items) {
		item->compile(context);
	}
}

const std::shared_ptr<TermExpression> ListExpression::evaluate(Context *context)
{
	vector<shared_ptr<TermExpression>> evaluatedItems;
	for (auto &item : this->items) {
		evaluatedItems.push_back(item->evaluate(context));
	}
	auto newMe = shared_ptr<ListExpression>(new ListExpression());
	newMe->setItems(evaluatedItems);
	return newMe;
}

bool ListExpression::equals(const std::shared_ptr<TermExpression> &target) const
{
	if (!target->getType()->equals(this->getType())) {
		return false;
	}
	auto targetListExpr = dynamic_pointer_cast<ListExpression>(target);
	auto targetItems = targetListExpr->getItems();
	auto myItems = this->items;
	if (myItems.size() != targetItems.size())return false;
	for (size_t i = 0; i < myItems.size(); i++) {
		if (!myItems[i]->equals(targetItems[i]))return false;
	}
	return true;
}

const std::vector<std::shared_ptr<TermExpression>> ListExpression::getItems() const
{
	return this->items;
}

void ListExpression::setItems(const std::vector<std::shared_ptr<TermExpression>>& termExpressions)
{
	this->items = termExpressions;
}

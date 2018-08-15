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
	size_t total = this->count;
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
	for (size_t i = 0; i < count; i++) {
		this->items[i]->compile(context);
	}
}

const std::shared_ptr<TermExpression> ListExpression::evaluate(Context *context)
{
	shared_ptr<TermExpression> *evaluatedItems = new shared_ptr<TermExpression>[this->count];
	for (size_t i = 0; i < this->count; i++) {
		evaluatedItems[i] = this->items[i]->evaluate(context);
	}
	auto newMe = shared_ptr<ListExpression>(new ListExpression());
	for (size_t i = 0; i < this->count; i++) {
		newMe->addItem(evaluatedItems[i]);
	}
	delete[]evaluatedItems;
	return newMe;
}

bool ListExpression::equals(const std::shared_ptr<TermExpression> &target) const
{
	if (!target->getType()->equals(this->getType())) {
		return false;
	}
	auto targetListExpr = dynamic_pointer_cast<ListExpression>(target);
	if (this->count != targetListExpr->count) return false;
	for (size_t i = 0; i < this->count; i++) {
		if (!this->items[i]->equals(targetListExpr->items[i]))return false;
	}
	return true;
}

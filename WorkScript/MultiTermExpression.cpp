#include <vector>
#include "MultiTermExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

MultiTermExpression::MultiTermExpression(Context * const & context, const std::vector<std::shared_ptr<const Expression>>& subExpressions)
	:PolynomialExpression(context)
{
	this->setSubExpressions(subExpressions);
}

MultiTermExpression::~MultiTermExpression()
{
}

const std::vector<std::shared_ptr<const Expression>>& MultiTermExpression::getSubExpressions() const
{
	return this->subExpressions;
}

void MultiTermExpression::setSubExpressions(const std::vector<std::shared_ptr<const Expression>> &subExpressions)
{
	this->subExpressions = subExpressions;
}

const std::shared_ptr<const Expression> MultiTermExpression::evaluate(const ExpressionBind &expressionBind) const
{
	vector<shared_ptr<const Expression>> subExpressionEvaluateResults;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		subExpressionEvaluateResults.push_back(this->subExpressions[i]->evaluate(expressionBind));
	}
	auto newMe = make_shared<const MultiTermExpression>(this->context, subExpressionEvaluateResults);
	auto matchResult = this->matchFirstUpInContextAndEvaluate(newMe);
	if (matchResult != nullptr) {
		return matchResult;
	}
	else {
		return newMe;
	}
}

bool MultiTermExpression::match(const std::shared_ptr<const Expression>& targetExpression, ExpressionBind * outExpressionBind) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
	auto targetMultiValueExpression = (const std::shared_ptr<const MultiTermExpression> &)targetExpression;
	if (this->subExpressions.size() != targetMultiValueExpression->subExpressions.size())return false;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		if (!this->subExpressions[i]->match(targetMultiValueExpression->subExpressions[i], outExpressionBind)) {
			return false;
		}
	}
	return true;
}

bool MultiTermExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
	auto targetMultiValueExpression = (const std::shared_ptr<const MultiTermExpression> &)targetExpression;
	if (this->subExpressions.size() != targetMultiValueExpression->subExpressions.size())return false;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		if (!this->subExpressions[i]->equals(targetMultiValueExpression->subExpressions[i])) {
			return false;
		}
	}
	return true;
}

const std::shared_ptr<const TypeExpression> MultiTermExpression::getType() const
{
	return this->context->findType(TYPENAME_MULTI_TERM_EXPRESSION,false);
}

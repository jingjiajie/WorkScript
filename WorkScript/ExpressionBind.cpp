#include "ExpressionBind.h"
#include "Expression.h"

using namespace std;

ExpressionBind::ExpressionBind()
{
}

ExpressionBind::ExpressionBind(const ExpressionBind &target)
{
	this->expressionMap = target.expressionMap;
}

const ExpressionBind & ExpressionBind::operator=(const ExpressionBind &target)
{
	this->expressionMap = target.expressionMap;
	return *this;
}

void ExpressionBind::addExpressionMap(const shared_ptr<const Expression> &sourceExpression, const shared_ptr<const Expression> &mappedExpression)
{
	for (auto &pair : this->expressionMap) {
		if (pair.first->equals(sourceExpression)) {
			throw new WorkScriptException("duplicate expression mapping");
		}
	}
	this->expressionMap.push_back(std::make_pair(sourceExpression, mappedExpression));
}

const std::shared_ptr<const Expression> ExpressionBind::getMappedExpression(const shared_ptr<const Expression>& sourceExpression) const
{
	for (auto &pair : this->expressionMap) {
		if (pair.first->equals(sourceExpression)) {
			return pair.second;
		}
	}
	return std::shared_ptr<const Expression>(nullptr);
}

#include "ParentheseExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

ParentheseExpression::ParentheseExpression(Context *const &context, const shared_ptr<const Expression> &subExpression)
	:PolynomialExpression(context)
{
	this->setSubExpression(subExpression);
}

ParentheseExpression::~ParentheseExpression()
{

}

const shared_ptr<const Expression> ParentheseExpression::evaluate(const ExpressionBind &expressionBind) const
{
	shared_ptr<const Expression> newSubExpression;
	if (this->subExpression != nullptr) {
		newSubExpression = this->subExpression->evaluate(expressionBind);
	}

	//如果子表达式不为空，则拆括号匹配。如果失败，返回拆括号后的表达式
	//如果子表达式为空，则不拆括号匹配。如果失败，返回自己
	if (newSubExpression != nullptr) {
		auto matchResult = this->matchFirstUpInContextAndEvaluate(newSubExpression);
		return matchResult == nullptr ? newSubExpression : matchResult;
	}
	else {
		auto matchResult = this->matchFirstUpInContextAndEvaluate(this->shared_from_this());
		return matchResult == nullptr ? this->shared_from_this() : matchResult;
	}
}

bool ParentheseExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind *outExpressionBind) const
{
	//类型匹配，若子表达式不为空，则拆括号匹配
	//否则不拆括号匹配
	auto matchType = matchExpression->getType();
	if (this->subExpression == nullptr) {
		if (!matchType->isSubTypeOf(this->context->findType(TYPENAME_PARENTHESE_EXPRESSION, false))) {
			return false;
		}
		auto matchParentheseExpression = (const std::shared_ptr<const ParentheseExpression>&)matchExpression;
		if (matchParentheseExpression->subExpression == nullptr)return true;
		return false;
	}
	else {
		return this->subExpression->match(matchExpression, outExpressionBind);
	}
}

bool ParentheseExpression::equals(const std::shared_ptr<const Expression>& targetExpression) const
{
	//要求类型完全匹配，并且子表达式全部相等
	auto targetType = targetExpression->getType();
	if (!targetType->isSubTypeOf(this->context->findType(TYPENAME_PARENTHESE_EXPRESSION, false))) {
		return false;
	}
	auto targetParentheseExpression = (const std::shared_ptr<const ParentheseExpression>&) targetExpression;
	if (this->subExpression == nullptr && targetParentheseExpression->subExpression == nullptr) {
		return true;
	}
	else {
		if (this->subExpression == nullptr || targetParentheseExpression->subExpression == nullptr) return false;
		return this->subExpression->equals(targetParentheseExpression->subExpression);
	}
}

const std::shared_ptr<const TypeExpression> ParentheseExpression::getType() const
{
	return this->context->findType(TYPENAME_PARENTHESE_EXPRESSION,false);
}

const std::shared_ptr<const Expression>& ParentheseExpression::getSubExpression() const
{
	return this->subExpression;
}

void ParentheseExpression::setSubExpression(const std::shared_ptr<const Expression>& subExpression)
{
	this->subExpression = subExpression;
}
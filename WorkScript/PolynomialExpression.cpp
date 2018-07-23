#include "PolynomialExpression.h"
#include "Context.h"
#include "TypeExpression.h"

PolynomialExpression::PolynomialExpression(Context *const &context)
	:Expression(context)
{
}


PolynomialExpression::~PolynomialExpression()
{
}

const std::shared_ptr<const Expression> PolynomialExpression::matchFirstUpInContextAndEvaluate(const std::shared_ptr<const Expression>& matchExpression) const
{
	const Context *curContext = this->context;
	//逐级Context向上匹配表达式
	while (curContext) {
		//遍历context中所有的Expression
		auto &expressions = curContext->getExpressions();
		for (auto &expression : expressions) {
			if (expression->equals(matchExpression)) continue;
			ExpressionBind newExpressionBind;
			if (!expression->match(matchExpression, &newExpressionBind)) continue;
			auto resultExpr = expression->evaluate(newExpressionBind);
			return resultExpr;
		}
		curContext = curContext->getBaseContext();
	}
	return nullptr;
}

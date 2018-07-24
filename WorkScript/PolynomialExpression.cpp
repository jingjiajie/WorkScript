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
	auto relationType = this->context->findType(TYPENAME_RELATION_EXPRESSION,false);
	//逐级Context向上匹配表达式
	while (curContext) {
		//遍历context中所有的Expression
		auto &expressions = curContext->getExpressions();
		for (auto &expression : expressions) {
			//不匹配自己
			if (expression->equals(matchExpression)) continue;
			//只匹配关系表达式
			//if (!expression->getType()->equals(relationType)) continue;
			ExpressionBind newExpressionBind;
			if (!expression->match(matchExpression, &newExpressionBind)) continue;
			auto resultExpr = expression->evaluate(newExpressionBind);
			return resultExpr;
		}
		curContext = curContext->getBaseContext();
	}
	return nullptr;
}

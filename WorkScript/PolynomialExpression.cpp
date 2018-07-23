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
	//��Context����ƥ����ʽ
	while (curContext) {
		//����context�����е�Expression
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

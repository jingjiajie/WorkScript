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
	//��Context����ƥ����ʽ
	while (curContext) {
		//����context�����е�Expression
		auto &expressions = curContext->getExpressions();
		for (auto &expression : expressions) {
			//��ƥ���Լ�
			if (expression->equals(matchExpression)) continue;
			//ֻƥ���ϵ���ʽ
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

#include "VariableExpression.h"
#include "Context.h"
#include "TypeExpression.h"

VariableExpression::VariableExpression(Context *const &context, const std::string& identifierName)
	:IdentifierExpression(context,identifierName)
{
}


VariableExpression::~VariableExpression()
{
}

const std::shared_ptr<const Expression> VariableExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto mappedExpr = expressionBind.getMappedExpression(this->shared_from_this());
	auto matchResult = this->matchFirstUpInContextAndEvaluate(mappedExpr);
	if (matchResult == nullptr) {
		return mappedExpr;
	}
	else {
		return matchResult;
	}
}

bool VariableExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	//如果同名变量已经被绑定，且本次绑定的值和同名变量绑定的值不相等，则匹配失败
	auto mappedExpression = outExpressionBind->getMappedExpression(this->shared_from_this());
	if (mappedExpression != nullptr && !mappedExpression->equals(matchExpression)) {
		return false;
	}
	//如果Identifier绑定成功，直接返回
	if (IdentifierExpression::match(matchExpression, outExpressionBind)) {
		return true;
	}
	//否则尝试绑定值或表达式
	auto matchType = matchExpression->getType();
	auto valueExpressionType = this->context->findType(TYPENAME_VALUE_EXPRESSION,false);
	if (matchType->isSubTypeOf(valueExpressionType)) {
		outExpressionBind->addExpressionMap(this->shared_from_this(), matchExpression);
		return true;
	}
	return false;
}

bool VariableExpression::equals(const std::shared_ptr<const Expression>& targetExpression) const
{
	auto targetType = targetExpression->getType();
	if (!targetType->equals(this->getType())) {
		return false;
	}
	auto targetVariableExpression = (const std::shared_ptr<const VariableExpression>&)targetExpression;
	return this->identifierName == targetVariableExpression->getIdentifierName();
}

const std::shared_ptr<const TypeExpression> VariableExpression::getType() const
{
	auto ret = this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false);
	return ret;
}

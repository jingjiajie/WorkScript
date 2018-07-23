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
	if (mappedExpr == nullptr) return this->shared_from_this();
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
	//���ͬ�������Ѿ����󶨣��ұ��ΰ󶨵�ֵ��ͬ�������󶨵�ֵ����ȣ���ƥ��ʧ��
	auto mappedExpression = outExpressionBind->getMappedExpression(this->shared_from_this());
	if (mappedExpression != nullptr && !mappedExpression->equals(matchExpression)) {
		return false;
	}
	//���Identifier�󶨳ɹ���ֱ�ӷ���
	if (IdentifierExpression::match(matchExpression, outExpressionBind)) {
		return true;
	}
	//�����԰�ֵ����ʽ�������󶨱�����
	//��Ϊ��ͨ��ֵ���ʽ�����������������һ����֮ǰ��ϵ���ʽ�Ҳ�ƥ��ʧ��ʣ��ı���
	//��ƥ������������ɲ���Ԥ֪���߼�����
	auto matchType = matchExpression->getType();
	auto variableExpressionType = this->getType();
	if (!matchType->equals(variableExpressionType)) {
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

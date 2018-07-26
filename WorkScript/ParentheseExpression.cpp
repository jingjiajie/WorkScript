#include "ParentheseExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

ParentheseExpression::ParentheseExpression(Context *const &context, const shared_ptr<const Expression> &subExpression)
	:TermExpression(context)
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

	//����ӱ��ʽ��Ϊ�գ��������ƥ�䡣���ʧ�ܣ����ز����ź�ı��ʽ
	//����ӱ��ʽΪ�գ��򲻲�����ƥ�䡣���ʧ�ܣ������Լ�
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
	//����ƥ�䣬���ӱ��ʽ��Ϊ�գ��������ƥ��
	//���򲻲�����ƥ��
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
	//������ƥ�䣬���ӱ��ʽ��Ϊ�գ���Ҫ���ӱ��ʽ������ȫƥ�䣬�����ӱ��ʽȫ����ȡ�
	//��������ŵ��ڿ�����
	auto targetType = targetExpression->getType();
	if (this->subExpression == nullptr) {
		if (!targetType->equals(this->context->findType(TYPENAME_PARENTHESE_EXPRESSION, false))) {
			return false;
		}
		auto targetParentheseExpression = (const std::shared_ptr<const ParentheseExpression>&) targetExpression;
		return targetParentheseExpression->subExpression == nullptr;
	}
	else { //�ӱ��ʽ��Ϊ�յ����
		if (targetType->equals(this->context->findType(TYPENAME_PARENTHESE_EXPRESSION, false))) {
			auto targetParentheseExpression = (const std::shared_ptr<const ParentheseExpression>&) targetExpression;
			if (targetParentheseExpression->subExpression == nullptr)return false;
			return this->subExpression->equals(targetParentheseExpression->subExpression);
		}
		else {
			return this->subExpression->equals(targetExpression);
		}
	}
}

const std::shared_ptr<const TypeExpression> ParentheseExpression::getType() const
{
	return this->context->findType(TYPENAME_PARENTHESE_EXPRESSION,false);
}

const std::string ParentheseExpression::toString() const
{
	if (this->subExpression == nullptr) {
		return "()";
	}
	else {
		return "(" + this->subExpression->toString() +")";
	}
}

const std::shared_ptr<const Expression>& ParentheseExpression::getSubExpression() const
{
	return this->subExpression;
}

void ParentheseExpression::setSubExpression(const std::shared_ptr<const Expression>& subExpression)
{
	this->subExpression = subExpression;
}
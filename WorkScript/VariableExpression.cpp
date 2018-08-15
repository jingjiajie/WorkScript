#include "VariableExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

VariableExpression::VariableExpression(const std::string& name)
{
	this->setName(name);
}


VariableExpression::~VariableExpression()
{
}

const std::shared_ptr<TermExpression> VariableExpression::evaluate(Context *context)
{
	Context *targetContext = context;
	for (int i = 0; i < this->variableInfo.upLevel; i++) {
		targetContext = targetContext->getBaseContext();
	}
	auto value = targetContext->getLocalVariable(this->variableInfo.offset);
	if (!value) {
		return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
	}
	else {
		return value;
	}
}

//
//bool VariableExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context * context) const
//{
//	//���ͬ�������Ѿ����󶨣��ұ��ΰ󶨵�ֵ��ͬ�������󶨵�ֵ����ȣ���ƥ��ʧ��
//	auto evaluateResult = this->evaluate(context);
//	if (evaluateResult.get() != this && !evaluateResult->equals(evaluateResult)) {
//		return false;
//	}
//	//���԰�ֵ����ʽ�������󶨱�����
//	//��Ϊ��ͨ��ֵ���ʽ�����������������һ����֮ǰ��ϵ���ʽ�Ҳ�ƥ��ʧ��ʣ��ı���
//	//��ƥ������������ɲ���Ԥ֪���߼�����
//	auto matchType = matchExpression->getType();
//	auto variableExpressionType = this->getType();
//	if (!matchType->equals(variableExpressionType)) {
//		context->setVariable(this->name, matchExpression);
//		return true;
//	}
//	return false;
//}

const std::shared_ptr<TypeExpression> VariableExpression::getType() const
{
	return TypeExpression::VARIABLE_EXPRESSION;
}

bool VariableExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	auto targetVariableExpr = dynamic_pointer_cast<VariableExpression>(targetExpression);
	return targetVariableExpr->name == this->name;
}

const std::string VariableExpression::toString() const
{
	return this->name;
}

void VariableExpression::compile(CompileContext *context)
{
	VariableInfo info = context->getVariableInfo(this->name);
	if (info.found) {
		this->variableInfo = info;
	}
	else {
		this->variableInfo = context->addLocalVariable(this->name);
	}
}

const std::string VariableExpression::getName() const
{
	return this->name;
}

void VariableExpression::setName(const std::string & name)
{
	this->name = name;
}

const VariableInfo VariableExpression::getVariableInfo() const
{
	return this->variableInfo;
}

void VariableExpression::setVariableInfo(const VariableInfo & info)
{
	this->variableInfo = info;
}

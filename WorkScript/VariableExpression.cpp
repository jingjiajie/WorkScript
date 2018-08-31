#include "VariableExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "ExpressionPointerExpression.h"

using namespace std;

VariableExpression::~VariableExpression()
{
	if (this->name)delete[]this->name;
}

Expression* const VariableExpression::evaluate(Context *const& context)
{
	Context *targetContext = context;
	for (int i = 0; i < this->variableInfo.upLevel; ++i) {
		targetContext = targetContext->getBaseContext();
	}
	if (context->getAssignLeft() == true)
	{
		auto ptr = new ExpressionPointerExpression(StorageLevel::TEMP);
		ptr->setTargetAddress(targetContext->getLocalVariableAddress(this->variableInfo.offset));
		return ptr;
	}
	else {
		auto value = targetContext->getLocalVariable(this->variableInfo.offset);
		if (!value) {
			return this;
		}
		else {
			return value;
		}
	}
}

//
//bool VariableExpression::match(Expression* const& matchExpression,Context *const &context) const
//{
//	//���ͬ�������Ѿ����󶨣��ұ��ΰ󶨵�ֵ��ͬ�������󶨵�ֵ����ȣ���ƥ��ʧ��
//	auto evaluateResult = this->evaluate(context);
//	if (evaluateResult.get() != this && !evaluateResult->equals(evaluateResult)) {
//		return false;
//	}
//	//���԰�ֵ����ʽ�������󶨱�����
//	//��Ϊ��ͨ��ֵ���ʽ�����������������һ����֮ǰ��ϵ���ʽ�Ҳ�ƥ��ʧ��ʣ��ı���
//	//��ƥ������������ɲ���Ԥ֪���߼�����
//	auto matchType = matchExpression->getType(context);
//	auto variableExpressionType = this->getType(context);
//	if (!matchType->equals(variableExpressionType)) {
//		context->setVariable(this->name, matchExpression);
//		return true;
//	}
//	return false;
//}

TypeExpression* const VariableExpression::getType(Context *const& context) const
{
	return &TypeExpression::VARIABLE_EXPRESSION;
}

bool VariableExpression::equals(Context *const &context, Expression* const& targetExpression) const
{
	if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetVariableExpr = (VariableExpression *const&)(targetExpression);
	return targetVariableExpr->name == this->name;
}

StringExpression *const VariableExpression::toString(Context *const& context)
{
	return StringExpression::newInstance(this->name);
}

void VariableExpression::compile(CompileContext *const& context)
{
	VariableInfo info = context->getVariableInfo(this->name);
	if (info.found) {
		this->variableInfo = info;
	}
	else {
		this->variableInfo = context->addLocalVariable(this->name);
	}
}

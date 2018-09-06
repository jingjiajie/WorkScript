#include "VariableExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "ExpressionPointerExpression.h"
#include "VariableCompileInfo.h"
#include "StackFrame.h"

using namespace std;

VariableExpression::~VariableExpression()
{
	if (this->name)delete[]this->name;
}

const Pointer<Expression> VariableExpression::evaluate(Context *const& context)
{
	StackFrame *targetFrame = context->getStackFrame()->getBaseStackFrame(this->targetDepth);

	if (context->getAssignLeft() == true)
	{
		auto ptr = new ExpressionPointerExpression();
		ptr->setTargetAddress(targetFrame->getLocalVariableAddress(this->offset));
		return ptr;
	}
	else {
		auto value = targetFrame->getLocalVariable(this->offset);
		if (!value) {
			return this;
		}
		else {
			return value;
		}
	}
}

//
//bool VariableExpression::match(const Pointer<Expression> & matchExpression,Context *const &context) const
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

const Pointer<TypeExpression> VariableExpression::getType(Context *const& context) const
{
	return TypeExpression::VARIABLE_EXPRESSION;
}

bool VariableExpression::equals(Context *const &context, const Pointer<Expression> & targetExpression) const
{
	if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetVariableExpr = (const Pointer<VariableExpression> &)(targetExpression);
	return targetVariableExpr->name == this->name;
}

const Pointer<StringExpression> VariableExpression::toString(Context *const& context)
{
	return StringExpression::newInstance(this->name);
}

void VariableExpression::compile(CompileContext *const& context)
{
	VariableCompileInfo info;
	if (!context->getVariableInfo(this->name, &info)) {
		context->addLocalVariable(this->name, &info);
	}
	this->targetDepth = info.depth;
	this->offset = info.offset;
}

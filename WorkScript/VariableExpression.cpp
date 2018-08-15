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
//	//如果同名变量已经被绑定，且本次绑定的值和同名变量绑定的值不相等，则匹配失败
//	auto evaluateResult = this->evaluate(context);
//	if (evaluateResult.get() != this && !evaluateResult->equals(evaluateResult)) {
//		return false;
//	}
//	//尝试绑定值或表达式，但不绑定变量！
//	//因为普通求值表达式不会产生变量，变量一定是之前关系表达式右部匹配失败剩余的变量
//	//若匹配变量，则会造成不可预知的逻辑错误
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

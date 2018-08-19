#include "FunctionInvocationExpression.h"
#include "ListExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "FunctionExpression.h"
#include "Program.h"
#include "StringExpression.h"
#include <sstream>

using namespace std;

FunctionInvocationExpression::~FunctionInvocationExpression()
{
	if(this->leftExpression) this->leftExpression->releaseLiteral();
	if(this->parameters) this->parameters->releaseLiteral();
}

Expression* const FunctionInvocationExpression::evaluate(Context *const& context)
{
	Expression * finalLeft;
	auto evaluatedLeft = this->leftExpression->evaluate(context);
	auto evaluatedLeftType = evaluatedLeft->getType(context);
	if (evaluatedLeftType->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
		finalLeft = (Expression *const&)evaluatedLeft;
	}
	else if(evaluatedLeftType->equals(context, &TypeExpression::VARIABLE_EXPRESSION)){
		finalLeft = evaluatedLeft->evaluate(context);
		evaluatedLeft->releaseTemp();
	}
	else {
		finalLeft = evaluatedLeft;
	}
	evaluatedLeftType->releaseTemp();

	auto finalLeftType = finalLeft->getType(context);
	if (!finalLeftType->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
		auto leftStrExpr = finalLeft->toString(context);
		finalLeft->releaseTemp();
		string leftName(leftStrExpr->getValue());
		throw UninvocableException(leftName + "不是函数！");
	}

	auto evaluatedParams = (ListExpression* const)this->parameters->evaluate(context);
	//将所有参数设为EXTERN
	auto oriParamLevels = new StorageLevel[evaluatedParams->getCount()];
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		oriParamLevels[i] = evaluatedParams->getItem(i)->getStorageLevel();
		evaluatedParams->getItem(i)->setStorageLevel(StorageLevel::EXTERN);
	}
	//开始调用
	auto ret = ((FunctionExpression* const&)finalLeft)->invoke(evaluatedParams);
	//恢复各个参数的存储级别
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		evaluatedParams[i].setStorageLevel(oriParamLevels[i]);
	}
	delete oriParamLevels;

	if (ret != nullptr) {
		finalLeft->releaseTemp();
		evaluatedParams->releaseTemp();
		return ret;
	}
	else {
		finalLeft->releaseTemp();
		auto newMe = new FunctionInvocationExpression;
		newMe->setLeftExpression(this->leftExpression);
		newMe->setParameters(evaluatedParams);
		return this;
	}
}

bool FunctionInvocationExpression::equals(Context *const &context, Expression* const &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetFunctionInvocationExpression = (FunctionInvocationExpression *const&)(target);
	if (!targetFunctionInvocationExpression->leftExpression->equals(context,this->leftExpression))return false;
	if (!this->parameters->equals(context,targetFunctionInvocationExpression->parameters))return false;
	return true;
}

TypeExpression* const FunctionInvocationExpression::getType(Context *const& context) const
{
	return &TypeExpression::FUNCTION_INVOCATION_EXPRESSION;
}

StringExpression *const FunctionInvocationExpression::toString(Context *const& context)
{
	stringstream ss;
	ss << this->leftExpression->toString(context);
	ss << "(";
	ss << this->parameters->toString(context)->getValue();
	ss << ")";
	return StringExpression::newInstance(ss.str().c_str());
}

void FunctionInvocationExpression::compile(CompileContext *const &context)
{
	this->leftExpression->compile(context);
	this->parameters->compile(context);
}

Expression* const FunctionInvocationExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void FunctionInvocationExpression::setLeftExpression(Expression* const& left)
{
	this->leftExpression = left;
}

ListExpression* const FunctionInvocationExpression::getParameters() const
{
	return this->parameters;
}

void FunctionInvocationExpression::setParameters(ListExpression* const& parameters)
{
	this->parameters = parameters;
}

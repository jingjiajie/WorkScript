#include "FunctionInvocationExpression.h"
#include "ListExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "FunctionExpression.h"
#include "Program.h"
#include "ParameterExpression.h"
#include "StringExpression.h"
#include "TempExpression.h"
#include <sstream>

using namespace std;

FunctionInvocationExpression::~FunctionInvocationExpression()
{
	if(this->leftExpression) this->leftExpression->releaseLiteral();
	if(this->parameters) this->parameters->releaseLiteral();
}

Expression* const FunctionInvocationExpression::evaluate(Context *const& context)
{
	TempExpression<Expression> evaluatedLeft(this->leftExpression, this->leftExpression->evaluate(context));
	if (!evaluatedLeft->getType(context)->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
		TempExpression<StringExpression> leftStrExpr(evaluatedLeft, evaluatedLeft->toString(context));
		string leftName(leftStrExpr->getValue());
		string str = (leftName + "不是函数！");
		throw std::move(UninvocableException(str.c_str()));
	}
	TempExpression<ParameterExpression> evaluatedParams(this->parameters, this->parameters->evaluate(context));
	//将所有小于TRANSFER的参数暂时提升为TRANSFER
	auto oriParamLevels = new StorageLevel[evaluatedParams->getCount()];
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		oriParamLevels[i] = evaluatedParams->getItem(i)->getStorageLevel();
		if (oriParamLevels[i] < StorageLevel::TRANSFER) {
			evaluatedParams->getItem(i)->setStorageLevel(StorageLevel::TRANSFER);
		}
	}
	//开始调用
	auto ret = ((FunctionExpression* const&)evaluatedLeft)->invoke(evaluatedParams);
	//恢复各个参数的存储级别。若有参数高于TRANSFER级别，则不进行恢复。
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		if (evaluatedParams->getItem(i)->getStorageLevel() > StorageLevel::TRANSFER)continue;
		evaluatedParams->getItem(i)->setStorageLevel(oriParamLevels[i]);
	}
	delete oriParamLevels;

	if (ret != nullptr) {
		StorageLevel retLevel = ret->getStorageLevel();
		ret->setStorageLevel(StorageLevel::TRANSFER);
		evaluatedParams.releaseTemp(); //先释放参数列表，此时如果参数列表中包含返回值，不会被释放
		ret->setStorageLevel(retLevel);
		return ret;
	}
	else {
		auto newMe = new FunctionInvocationExpression;
		newMe->setLeftExpression(this->leftExpression);
		newMe->setParameters(evaluatedParams);
		evaluatedParams.setNoRelease();
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
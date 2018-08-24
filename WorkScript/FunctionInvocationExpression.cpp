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
		string str = (leftName + "���Ǻ�����");
		throw std::move(UninvocableException(str.c_str()));
	}
	TempExpression<ParameterExpression> evaluatedParams(this->parameters, this->parameters->evaluate(context));
	//������С��TRANSFER�Ĳ�����ʱ����ΪTRANSFER
	auto oriParamLevels = new StorageLevel[evaluatedParams->getCount()];
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		oriParamLevels[i] = evaluatedParams->getItem(i)->getStorageLevel();
		if (oriParamLevels[i] < StorageLevel::TRANSFER) {
			evaluatedParams->getItem(i)->setStorageLevel(StorageLevel::TRANSFER);
		}
	}
	//��ʼ����
	auto ret = ((FunctionExpression* const&)evaluatedLeft)->invoke(evaluatedParams);
	//�ָ����������Ĵ洢�������в�������TRANSFER�����򲻽��лָ���
	for (size_t i = 0; i < evaluatedParams->getCount(); ++i) {
		if (evaluatedParams->getItem(i)->getStorageLevel() > StorageLevel::TRANSFER)continue;
		evaluatedParams->getItem(i)->setStorageLevel(oriParamLevels[i]);
	}
	delete oriParamLevels;

	if (ret != nullptr) {
		StorageLevel retLevel = ret->getStorageLevel();
		ret->setStorageLevel(StorageLevel::TRANSFER);
		evaluatedParams.releaseTemp(); //���ͷŲ����б���ʱ��������б��а�������ֵ�����ᱻ�ͷ�
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
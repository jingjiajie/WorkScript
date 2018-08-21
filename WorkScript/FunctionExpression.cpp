#include <sstream>
#include <string>
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Context.h"
#include "TempExpression.h"
#include "Program.h"

using namespace std;

FunctionExpression::~FunctionExpression()
{
	for (size_t i = 0; i < this->overloads.size();++i) {
		delete this->overloads[i];
	}
	if (this->name)delete[]this->name;
}

TypeExpression* const FunctionExpression::getType(Context *const& context) const
{
	return &TypeExpression::FUNCTION_EXPRESSION;
}

Expression* const FunctionExpression::evaluate(Context *const &context)
{
	this->declareContext = context;
	auto varExpr = context->getLocalVariable(this->functionVariableInfo.offset);
	if (varExpr == nullptr) { //����������û���������������Ƿ���ڸ����ĺ��������������Ƿ���ڸ������������кϲ�
		context->setLocalVariable(this->functionVariableInfo.offset, (Expression* const&)this);
		return (Expression* const&)this;
	}
	else { //��������ҵ���ͬ����������ϲ�����
		if (!varExpr->getType(context)->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
			throw std::move(DuplicateDeclarationException((string(this->name) + "�Ѿ����������������ظ�������").c_str()));
		}
		auto funcExpr = (FunctionExpression* const&)varExpr;
		for (auto &overload : this->overloads) {
			funcExpr->addOverload(overload);
		}
		this->overloads.clear();
		return funcExpr;
	}
}

bool FunctionExpression::equals(Context *const &context, Expression* const& targetExpression) const
{
	return targetExpression == this;
}

StringExpression *const FunctionExpression::toString(Context *const &context)
{
	return StringExpression::newInstance("FunctionDeclaration");
	//stringstream ss;
	//ss << this->functionName;
	//for (size_t i = 0; i < this->parameters.size(); ++i) {
	//	ss << "(" << this->parameters[i]->toString() << ")";
	//	if (i != subExpressionCount - 1) {
	//		ss << " ";
	//	}
	//}
	//return ss.str();
}

void FunctionExpression::compile(CompileContext *const &context)
{
	//�����������ڵ�ǰ��������
	auto varInfo = context->getVariableInfo(this->name);
	if (varInfo.found == true && varInfo.upLevel > 0) {
		this->baseFunctionVariableInfo = varInfo;
	}
	else if(varInfo.found == true && varInfo.upLevel == 0){
		this->baseFunctionVariableInfo.found = false;
		this->functionVariableInfo = varInfo;
	}
	else {
		this->baseFunctionVariableInfo.found = false;
		this->functionVariableInfo = context->addLocalVariable(this->name);
	}
	//���أ�������Լ����ʵ�֣�����������������
	for (auto &overload : this->overloads) {
		CompileContext subContext(context);
		overload->compile(&subContext);
		overload->setLocalVariableCount(subContext.getLocalVariableCount());
	}
}

Expression* const FunctionExpression::invoke(ParameterExpression *const &params) const
{
	for (auto &overload : this->overloads) {
		Context subContext(this->declareContext, overload->getLocalVariableCount());
		if (overload->match(params, &subContext)) {
			auto ret = overload->invoke(&subContext);
			return ret;
		}
	}
	if (this->baseFunctionVariableInfo.found) {
		Context *targetContext = this->declareContext;
		for (int i = 0; i < this->baseFunctionVariableInfo.upLevel; ++i) {
			targetContext = targetContext->getBaseContext();
		}
		auto expr = targetContext->getLocalVariable(baseFunctionVariableInfo.offset);
		if (!expr->getType(targetContext)->equals(targetContext, &TypeExpression::FUNCTION_EXPRESSION)) {
			throw DuplicateDeclarationException((string(this->name) + "�Ѿ��������������ظ�������").c_str());
		}
		auto funcExpr = (FunctionExpression* const&)expr;
		return funcExpr->invoke(params);
	}
	else {
		return nullptr;
	}
}

FunctionExpression::Overload::~Overload()
{
	if (this->parameterLocalOffsets) {
		delete[]parameterLocalOffsets;
	}
	if (this->constraints) {
		for (size_t i = 0; i < this->constraintCount; ++i) {
			this->constraints[i]->releaseLiteral();
		}
		delete[]this->constraints;
	}

	for (size_t i = 0; i < this->implementCount; ++i)
	{
		if (this->implements[i]) this->implements[i]->releaseLiteral();
	}
	delete[]this->implements;
}

bool FunctionExpression::Overload::match(ParameterExpression* const &params,Context *const &context) const
{
	size_t targetParamCount = params->getCount();
	auto myParamOffsets = this->parameterLocalOffsets;
	size_t myParamCount = this->parameterCount;
	//�����Ƿ�����������ƥ��ʣ�����в������Լ�����������Ԥ�ȷ�������ܵ�ƥ��
	if (this->allowLastMatchRest) {
		if (myParamCount > targetParamCount)return false;
	}
	else {
		if (myParamCount != targetParamCount)return false;
	}

	//���ƥ�����
	for (size_t i = 0; i < myParamCount; ++i) {
		//��������һ���������������ƥ��
		if (i == myParamCount - 1 && i < targetParamCount - 1 && this->allowLastMatchRest) {
			auto restParamList = new ParameterExpression(params->getItems() + i,targetParamCount - myParamCount + 1);
			context->setLocalVariable(myParamOffsets[i], restParamList);
		}
		else {
			//��������Ļ�������Ĳ���Ӧ�ö���EXTERN����
			context->setLocalVariable(myParamOffsets[i], params->getItems()[i]);
		}
	}
	//��֤Լ���Ƿ���ϣ����в�������ƥ��ʧ��
	for (size_t i = 0; i < this->constraintCount;++i) {
		auto res = this->constraints[i]->evaluate(context);
		if (!res->equals(context, &BooleanExpression::YES))
		{
			res->releaseTemp();
			return false;
		}
		res->releaseTemp();
	}
	return true;
}

Expression* const FunctionExpression::Overload::invoke(Context *const &context) const
{
	Expression *ret = nullptr;
	for (size_t i = 0; i < this->implementCount; ++i)
	{
		TempExpression<Expression> res(this->implements[i], this->implements[i]->evaluate(context));
		//���һ�����Ľ����Ϊ����ֵ
		if (i == this->implementCount - 1) {
			ret = res;
			if (ret->getStorageLevel() < StorageLevel::TRANSFER) {
				ret->setStorageLevel(StorageLevel::TRANSFER); //����ֵ����ΪTRANSFER����ֹ�ֲ�ջ֡����ʱ�ͷ�
			}
		}
	}
	return ret;
}

void FunctionExpression::Overload::compile(CompileContext *const &context)
{
	//��������б�
	this->parameterLocalOffsets = new size_t[this->parameterCount]();
	for (size_t i = 0; i < this->parameterCount; ++i) {
		this->parameterLocalOffsets[i] = context->addLocalVariable(this->parameterNames[i]).offset;
	}
	//����Լ���б�
	for (size_t i = 0; i < this->constraintCount; ++i) {
		this->constraints[i]->compile(context);
	}
	//����ʵ��
	for (size_t i = 0; i < this->implementCount; ++i) {
		this->implements[i]->compile(context);
	}
}
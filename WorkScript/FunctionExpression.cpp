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
#include "WorkScriptException.h"
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
			throw std::move(DuplicateDeclarationException((wstring(this->name) + L"�Ѿ����������������ظ�������").c_str()));
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
	return StringExpression::newInstance(L"FunctionDeclaration");
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
	Context subContext(this->declareContext);
	for (auto &overload : this->overloads) {
		subContext.releaseAndResetLocalVariableCount(overload->getLocalVariableCount());
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
			throw DuplicateDeclarationException((wstring(this->name) + L"�Ѿ��������������ظ�������").c_str());
		}
		auto funcExpr = (FunctionExpression* const&)expr;
		return funcExpr->invoke(params);
	}
	else {
		return nullptr;
	}
}

bool Overload::match(ParameterExpression* const &params,Context *const &context) const
{
	size_t targetParamCount = params->getCount();
	size_t myParamCount = this->parameterCount;

	//���ƥ��������������ͬ�����������һ��ͬ�����������֮ǰ��ֵ��ȣ�����ƥ��ʧ��
	//���Ŀ���������������������û���趨Ĭ��ֵ
	for (size_t i = 0; i < myParamCount; ++i) {
		//�����ǰ�β��Ѿ�����ʵ�θ��������ж��Ƿ���Ĭ��ֵ
		if (i + 1 > targetParamCount) { //ע�⣬����ֻ��i+1�������ұ�-1����Ϊsize_t�޷���
			Expression *defaultValue = this->parameters[i].getDefaultValue();
			if (!defaultValue)return false;
			context->setLocalVariable(this->parameters[i].getOffset(), defaultValue->evaluate(context));
		}
		//��������һ���������ҿ�����̰��ƥ�䣬��ƥ�����
		else if (i == myParamCount - 1 && i < targetParamCount - 1 && this->allowLastMatchRest) {
			auto restParamList = new ParameterExpression(params->getItems() + i,targetParamCount - myParamCount + 1);
			context->setLocalVariable(this->parameters[i].getOffset(), restParamList);
			Expression *prev = nullptr;
			if ((prev = context->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, restParamList))return false;
			}
		}
		else {
			Expression *prev = nullptr;
			if ((prev = context->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, params->getItems()[i]))return false;
			}
			//��������Ļ�������Ĳ���Ӧ�ö���EXTERN����
			context->setLocalVariable(this->parameters[i].getOffset(), params->getItems()[i]);
		}
	}
	//��֤Լ���Ƿ���ϣ����в�������ƥ��ʧ��
	try {
		for (size_t i = 0; i < this->constraintCount; ++i) {
			TempExpression<Expression> res(this->constraints[i], this->constraints[i]->evaluate(context));
			if (!res->equals(context, &BooleanExpression::VAL_YES))
			{
				return false;
			}
		}
	}
	catch (const WorkScriptException&) {
		return false;
	}
	return true;
}

Expression* const Overload::invoke(Context *const &context) const
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

void Overload::compile(CompileContext *const &context)
{
	//��������б�
	for (size_t i = 0; i < this->parameterCount; ++i) {
		auto curVarName = this->parameters[i].getParameterName();
		auto info = context->getLocalVariableInfo(curVarName);
		if (info.found) {
			this->parameters[i].setOffset(info.offset);
		}
		else {
			this->parameters[i].setOffset(context->addLocalVariable(this->parameters[i].getParameterName()).offset);
		}
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
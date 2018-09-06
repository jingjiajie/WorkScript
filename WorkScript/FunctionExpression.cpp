#include <sstream>
#include <string>
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Context.h"
#include "WorkScriptException.h"
#include "Program.h"

using namespace std;

FunctionExpression::~FunctionExpression()
{
	for (size_t i = 0; i < this->overloads->size();++i) {
		delete (*this->overloads)[i];
	}
	delete this->overloads;
	if (this->name)delete[]this->name;
}

const Pointer<TypeExpression> FunctionExpression::getType(Context *const& context) const
{
	return TypeExpression::FUNCTION_EXPRESSION;
}

const Pointer<Expression> FunctionExpression::evaluate(Context *const &context)
{
	this->declareContext = context;
	Context *targetContext = context->getBaseContext(this->functionVariableInfo.depth);
	if (this->name != nullptr) {
		auto varExpr = targetContext->getLocalVariable(this->functionVariableInfo.offset);
		if (varExpr == nullptr) { //����������û���������������Ƿ���ڸ����ĺ��������������Ƿ���ڸ������������кϲ�
			targetContext->setLocalVariable(this->functionVariableInfo.offset, (const Pointer<Expression>&)this);
			return this;
		}
		else { //��������ҵ���ͬ����������ϲ�����
			if (!varExpr->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_EXPRESSION)) {
				throw std::move(DuplicateDeclarationException((wstring(this->name) + L"�Ѿ����������������ظ�������").c_str()));
			}
			auto funcExpr = (const Pointer<FunctionExpression>&)varExpr;
			for (auto &overload : *this->overloads) {
				funcExpr->addOverload(overload);
			}
			this->overloads->clear();
			return funcExpr;
		}
	}
	else {
		return this;
	}
}

bool FunctionExpression::equals(Context *const &context, const Pointer<Expression>& targetExpression) const
{
	return targetExpression == this;
}

const Pointer<StringExpression> FunctionExpression::toString(Context *const &context)
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
	if (this->name != nullptr) {
		//�����������ڵ�ǰ��������
		if (!context->getLocalVariableInfo(this->name, &this->functionVariableInfo)) {
			context->addLocalVariable(this->name, &this->functionVariableInfo);
		}
		this->hasBaseFunction = context->getBaseVariableInfo(this->name, &this->baseFunctionVariableInfo);
	}
	//���أ�������Լ����ʵ�֣�����������������
	for (auto &overload : *this->overloads) {
		CompileContext subContext(context);
		overload->compile(&subContext);
	}
}

Overload *const FunctionExpression::getMatchedOverload(const Pointer<ParameterExpression>& params, Context *const context) const
{
	for (auto &overload : *this->overloads) {
		context->resetLocalVariableCount(overload->getLocalVariableCount());
		if (overload->match(params, context)) {
			return overload;
		}
	}
	return nullptr;
}

const Pointer<Expression> FunctionExpression::invoke(const Pointer<ParameterExpression> &params) const
{
	Context subContext(this->declareContext);
	Overload *matchedOverload = this->getMatchedOverload(params, &subContext);
	if (matchedOverload != nullptr) {
		return matchedOverload->invoke(&subContext);
	}
	else {
		if (this->hasBaseFunction) {
			Context *targetContext = this->declareContext->getBaseContext(this->baseFunctionVariableInfo.depth);
			auto expr = targetContext->getLocalVariable(baseFunctionVariableInfo.offset);
			if (!expr->getType(targetContext)->equals(targetContext, TypeExpression::FUNCTION_EXPRESSION)) {
				throw DuplicateDeclarationException((wstring(this->name) + L"�Ѿ��������������ظ�������").c_str());
			}
			auto funcExpr = (const Pointer<FunctionExpression>&)expr;
			return funcExpr->invoke(params);
		}
		else {
			return nullptr;
		}
	}
}

bool Overload::match(const Pointer<ParameterExpression> &params,Context *const &context) const
{
	size_t targetParamCount = params->getCount();
	size_t myParamCount = this->parameterCount;

	//���ƥ��������������ͬ�����������һ��ͬ�����������֮ǰ��ֵ��ȣ�����ƥ��ʧ��
	//���Ŀ���������������������û���趨Ĭ��ֵ
	for (size_t i = 0; i < myParamCount; ++i) {
		//�����ǰ�β��Ѿ�����ʵ�θ��������ж��Ƿ���Ĭ��ֵ
		if (i + 1 > targetParamCount) { //ע�⣬����ֻ��i+1�������ұ�-1����Ϊsize_t�޷���
			Pointer<Expression>defaultValue = this->parameters[i].getDefaultValue();
			if (!defaultValue)return false;
			context->setLocalVariable(this->parameters[i].getOffset(), defaultValue->evaluate(context));
		}
		//��������һ���������ҿ�����̰��ƥ�䣬��ƥ�����
		else if (i == myParamCount - 1 && i < targetParamCount - 1 && this->allowLastMatchRest) {
			size_t restParamCount = targetParamCount - myParamCount + 1;
			Pointer<Expression> *restParamItems = new Pointer<Expression>[restParamCount];
			for (size_t i = 0; i < restParamCount; ++i)
			{
				restParamItems[i] = params->getItem(myParamCount - 1 + i);
			}
			auto restParamList = new ParameterExpression(restParamItems,restParamCount);
			context->setLocalVariable(this->parameters[i].getOffset(), restParamList);
			Pointer<Expression> prev = nullptr;
			if ((prev = context->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, restParamList))return false;
			}
		}
		else {
			Pointer<Expression> prev = nullptr;
			if ((prev = context->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, params->getItems()[i]))return false;
			}
			context->setLocalVariable(this->parameters[i].getOffset(), params->getItems()[i]);
		}
	}
	//��֤Լ���Ƿ���ϣ����в�������ƥ��ʧ��
	try {
		for (size_t i = 0; i < this->constraintCount; ++i) {
			Pointer<Expression> res =  this->constraints[i]->evaluate(context);
			if (!res->equals(context, BooleanExpression::VAL_YES))
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

const Pointer<Expression> Overload::invoke(Context *context) const
{
	Context *targetContext = context;
	INVOKE_START:
	for (size_t i = 0; i < this->implementCount-1; ++i)
	{
		this->implements[i]->evaluate(targetContext);
	}
	//���һ�����Ľ����Ϊ����ֵ
	Pointer<Expression> lastImpl = this->implements[implementCount - 1];
	if (lastImpl->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_INVOCATION_EXPRESSION)) {
		auto invocation = ((Pointer<FunctionInvocationExpression>)lastImpl);
		auto func = invocation->getFunctionExpression(targetContext);
		auto params = invocation->getEvaluatedParameters(targetContext);
		//�����µ�Context�Թ�����
		if (func != this->functionExpression)
		{
			targetContext = new Context(func->getDeclareContext());
		}
		//getMatchedOverload()�Ѿ���ƥ���ʵ��д�뵽context�С�
		Overload *matchedOverload = func->getMatchedOverload(params, targetContext);
		if (matchedOverload == this) {	//β�ݹ��Ż�
			goto INVOKE_START;
		}
		else {
			return matchedOverload->invoke(targetContext);
		}
	}
	else {
		return lastImpl->evaluate(targetContext);
	}
}

void Overload::compile(CompileContext *const &context)
{
	//��������б�
	VariableCompileInfo info;
	for (size_t i = 0; i < this->parameterCount; ++i) {
		auto curVarName = this->parameters[i].getParameterName();
		if (context->getLocalVariableInfo(curVarName, &info)) {
			this->parameters[i].setOffset(info.offset);
		}
		else {
			context->addLocalVariable(this->parameters[i].getParameterName(),&info);
			this->parameters[i].setOffset(info.offset);
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
	this->localVariableCount = context->getLocalVariableCount();
}
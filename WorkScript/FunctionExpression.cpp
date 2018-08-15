#include <sstream>
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "ListExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"

using namespace std;

FunctionExpression::FunctionExpression()
{

}


FunctionExpression::~FunctionExpression()
{
}

const std::shared_ptr<TypeExpression> FunctionExpression::getType() const
{
	return TypeExpression::FUNCTION_EXPRESSION;
}

const std::shared_ptr<TermExpression> FunctionExpression::evaluate(Context * context)
{
	this->declareContext = context;
	auto varExpr = context->getLocalVariable(this->functionVariableInfo.offset);
	if (varExpr == nullptr) { //����������û���������������Ƿ���ڸ����ĺ��������������Ƿ���ڸ������������кϲ�
		context->setLocalVariable(this->functionVariableInfo.offset, (const std::shared_ptr<TermExpression>&)this->shared_from_this());
		return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
	}
	else { //��������ҵ���ͬ����������ϲ�����
		if (!varExpr->getType()->equals(TypeExpression::FUNCTION_EXPRESSION)) {
			throw DuplicateDeclarationException(this->functionName + "�Ѿ����������������ظ�������");
		}
		auto funcExpr = (const shared_ptr<FunctionExpression>&)varExpr;
		for (auto &overload : this->overloads) {
			funcExpr->addOverload(overload);
		}
		return funcExpr;
	}
}

bool FunctionExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	return targetExpression.get() == this;
}

const std::string FunctionExpression::toString() const
{
	return "FunctionDeclaration";
	//stringstream ss;
	//ss << this->functionName;
	//for (size_t i = 0; i < this->parameters.size(); i++) {
	//	ss << "(" << this->parameters[i]->toString() << ")";
	//	if (i != subExpressionCount - 1) {
	//		ss << " ";
	//	}
	//}
	//return ss.str();
}

void FunctionExpression::compile(CompileContext * context)
{
	//�����������ڵ�ǰ��������
	auto varInfo = context->getVariableInfo(this->functionName);
	if (varInfo.found == true && varInfo.upLevel > 0) {
		this->baseFunctionVariableInfo = varInfo;
	}
	else if(varInfo.found == true && varInfo.upLevel == 0){
		this->baseFunctionVariableInfo.found = false;
		this->functionVariableInfo = varInfo;
	}
	else {
		this->baseFunctionVariableInfo.found = false;
		this->functionVariableInfo = context->addLocalVariable(this->functionName);
	}
	//���أ�������Լ����ʵ�֣�����������������
	CompileContext subContext(context);
	for (auto &overload : this->overloads) {
		overload->compile(&subContext);
	}
	this->localVariableCount = subContext.getLocalVariableCount();
}

const std::shared_ptr<TermExpression> FunctionExpression::invoke(const shared_ptr<ListExpression> &params) const
{
	Context *subContext = new Context(localVariableCount);
	subContext->setBaseContext(this->declareContext);
	for (auto &overload : this->overloads) {
		if (overload->match(params, subContext)) {
			auto ret = overload->invoke(subContext);
			delete subContext;
			return ret;
		}
	}
	delete subContext;
	if (this->baseFunctionVariableInfo.found) {
		Context *targetContext = this->declareContext;
		for (int i = 0; i < this->baseFunctionVariableInfo.upLevel; i++) {
			targetContext = targetContext->getBaseContext();
		}
		auto expr = targetContext->getLocalVariable(baseFunctionVariableInfo.offset);
		if (!expr->getType()->equals(TypeExpression::FUNCTION_EXPRESSION)) {
			throw DuplicateDeclarationException(this->functionName+"�Ѿ��������������ظ�������");
		}
		auto funcExpr = (const shared_ptr<FunctionExpression>&)expr;
		return funcExpr->invoke(params);
	}
	else {
		return nullptr;
	}
}

bool FunctionExpression::Overload::match(const shared_ptr<ListExpression> &params, Context * context) const
{
	auto targetParamList = params->getItems();
	size_t targetParamCount = targetParamList.size();
	auto myParamOffsets = this->parameterLocalOffsets;
	size_t myParamCount = myParamOffsets.size();
	//�����Ƿ�����������ƥ��ʣ�����в������Լ�����������Ԥ�ȷ�������ܵ�ƥ��
	if (this->allowLastMatchRest) {
		if (myParamCount > targetParamCount)return false;
	}
	else {
		if (myParamCount != targetParamCount)return false;
	}

	//���ƥ�����
	for (size_t i = 0; i < myParamCount; i++) {
		//��������һ���������������ƥ��
		if (i == myParamCount - 1 && i < targetParamCount - 1 && this->allowLastMatchRest) {
			shared_ptr<ListExpression> restParamList(new ListExpression());
			restParamList->setItems(vector<shared_ptr<TermExpression>>(targetParamList.begin() + i, targetParamList.end()));
		}
		else {
			context->setLocalVariable(myParamOffsets[i], targetParamList[i]);
		}
	}
	//��֤Լ���Ƿ���ϣ����в�������ƥ��ʧ��
	for (auto &constraint : this->constraints) {
		if (!constraint->evaluate(context)->equals(BooleanExpression::YES))return false;
	}
	return true;
}

const std::shared_ptr<TermExpression> FunctionExpression::Overload::invoke(Context * context) const
{
	return this->implement->evaluate(context);
}

void FunctionExpression::Overload::compile(CompileContext * context)
{
	for (auto &paramName : this->parameterNames) {
		this->parameterLocalOffsets.push_back(context->addLocalVariable(paramName).offset);
	}

	for (auto &constraint : this->constraints) {
		constraint->compile(context);
	}
	this->implement->compile(context);
}

const std::vector<std::string> FunctionExpression::Overload::getParameterNames() const
{
	return this->parameterNames;
}

void FunctionExpression::Overload::setParameterNames(const std::vector<std::string>& parameters)
{
	this->parameterNames = parameters;
}

const std::vector<std::shared_ptr<TermExpression>> FunctionExpression::Overload::getConstraints() const
{
	return this->constraints;
}

void FunctionExpression::Overload::setConstraints(const std::vector<std::shared_ptr<TermExpression>>& constraints)
{
	this->constraints = constraints;
}

const bool FunctionExpression::Overload::getAllowLastMatchRest() const
{
	return allowLastMatchRest;
}

void FunctionExpression::Overload::setAllowLastMatchRest(const bool & allowLastMatchRest)
{
	this->allowLastMatchRest = allowLastMatchRest;
}

const std::string FunctionExpression::getFunctionName() const
{
	return this->functionName;
}

void FunctionExpression::setFunctionName(const std::string & funcName)
{
	this->functionName = funcName;
}

const std::vector<std::shared_ptr<FunctionExpression::Overload>> FunctionExpression::getOverloads() const
{
	return this->overloads;
}

void FunctionExpression::addOverload(const std::shared_ptr<Overload>& overload)
{
	this->overloads.push_back(overload);
}

const std::shared_ptr<TermExpression> FunctionExpression::Overload::getImplement() const
{
	return this->implement;
}

void FunctionExpression::Overload::setImplement(const std::shared_ptr<TermExpression>& implement)
{
	this->implement = implement;
}

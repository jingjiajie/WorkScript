#include <sstream>
#include <string>
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

FunctionExpression::~FunctionExpression()
{
	for (size_t i = 0; i < this->overloads.size();i++) {
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
	if (varExpr == nullptr) { //如果本层变量没有搜索到，搜索是否存在父级的函数声明。无论是否存在父级，都不进行合并
		context->setLocalVariable(this->functionVariableInfo.offset, (Expression* const&)this);
		return (Expression* const&)this;
	}
	else { //如果本层找到了同名函数，则合并重载
		if (!varExpr->getType(context)->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
			throw std::move(DuplicateDeclarationException((string(this->name) + "已经被声明过，请勿重复声明！").c_str()));
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
	//for (size_t i = 0; i < this->parameters.size(); i++) {
	//	ss << "(" << this->parameters[i]->toString() << ")";
	//	if (i != subExpressionCount - 1) {
	//		ss << " ";
	//	}
	//}
	//return ss.str();
}

void FunctionExpression::compile(CompileContext *const &context)
{
	//函数名编译在当前作用域中
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
	//重载（参数，约束，实现）编译在子作用域中
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
		for (int i = 0; i < this->baseFunctionVariableInfo.upLevel; i++) {
			targetContext = targetContext->getBaseContext();
		}
		auto expr = targetContext->getLocalVariable(baseFunctionVariableInfo.offset);
		if (!expr->getType(targetContext)->equals(targetContext, &TypeExpression::FUNCTION_EXPRESSION)) {
			throw DuplicateDeclarationException((string(this->name) + "已经被声明，请勿重复声明！").c_str());
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
		for (size_t i = 0; i < this->constraintCount; i++) {
			this->constraints[i]->releaseLiteral();
		}
		delete[]this->constraints;
	}

	//TODO implement应该改成数组
	if (this->implement) this->implement->releaseLiteral();
}

bool FunctionExpression::Overload::match(ParameterExpression* const &params,Context *const &context) const
{
	size_t targetParamCount = params->getCount();
	auto myParamOffsets = this->parameterLocalOffsets;
	size_t myParamCount = this->parameterCount;
	//根据是否允许最后变量匹配剩余所有参数，以及参数个数，预先否决不可能的匹配
	if (this->allowLastMatchRest) {
		if (myParamCount > targetParamCount)return false;
	}
	else {
		if (myParamCount != targetParamCount)return false;
	}

	//逐个匹配参数
	for (size_t i = 0; i < myParamCount; i++) {
		//如果是最后一个变量，则视情况匹配
		if (i == myParamCount - 1 && i < targetParamCount - 1 && this->allowLastMatchRest) {
			ParameterExpression * restParamList(new ParameterExpression(targetParamCount - myParamCount + 1));
			for (size_t targetPos = i, newPos = 0; targetPos < targetParamCount; ++targetPos, ++newPos) {
				restParamList->setItem(newPos, params->getItem(targetPos));
			}
		}
		else {
			//不出意外的话，传入的参数应该都是EXTERN级别
			context->setLocalVariable(myParamOffsets[i], params->getItem(i));
		}
	}
	//验证约束是否符合，若有不符合则匹配失败
	for (size_t i = 0; i < this->constraintCount;i++) {
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
	auto ret = this->implement->evaluate(context);
	if (ret->getStorageLevel() < StorageLevel::TRANSFER) {
		ret->setStorageLevel(StorageLevel::TRANSFER); //返回值提升为TRANSFER，防止局部栈帧销毁时释放
	}
	return ret;
}

void FunctionExpression::Overload::compile(CompileContext *const &context)
{
	//编译参数列表
	this->parameterLocalOffsets = new size_t[this->parameterCount]();
	for (size_t i = 0; i < this->parameterCount;i++) {
		this->parameterLocalOffsets[i] = context->addLocalVariable(this->parameterNames[i]).offset;
	}
	//编译约束列表
	for (size_t i = 0; i < this->constraintCount; i++) {
		this->constraints[i]->compile(context);
	}
	//编译实现
	this->implement->compile(context);

	this->localVariableCount = context->getLocalVariableCount();
}

const std::vector<std::string> FunctionExpression::Overload::getParameterNames() const
{
	return this->parameterNames;
}

void FunctionExpression::Overload::setParameterNames(const std::vector<std::string>& parameters)
{
	this->parameterCount = parameters.size();
	this->parameterNames = parameters;
}

Expression **const FunctionExpression::Overload::getConstraints() const
{
	return this->constraints;
}

void FunctionExpression::Overload::setConstraints(Expression **const& constraints, size_t count)
{
	this->constraintCount = count;
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

const std::vector<FunctionExpression::Overload*> FunctionExpression::getOverloads() const
{
	return this->overloads;
}

void FunctionExpression::addOverload(Overload* const& overload)
{
	this->overloads.push_back(overload);
}

Expression* const FunctionExpression::Overload::getImplement() const
{
	return this->implement;
}

void FunctionExpression::Overload::setImplement(Expression* const& implement)
{
	this->implement = implement;
}

const size_t FunctionExpression::Overload::getLocalVariableCount() const
{
	return this->localVariableCount;
}

void FunctionExpression::Overload::setLocalVariableCount(const size_t & count)
{
	this->localVariableCount = count;
}

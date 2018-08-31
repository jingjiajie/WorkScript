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
	if (varExpr == nullptr) { //如果本层变量没有搜索到，搜索是否存在父级的函数声明。无论是否存在父级，都不进行合并
		context->setLocalVariable(this->functionVariableInfo.offset, (Expression* const&)this);
		return (Expression* const&)this;
	}
	else { //如果本层找到了同名函数，则合并重载
		if (!varExpr->getType(context)->equals(context, &TypeExpression::FUNCTION_EXPRESSION)) {
			throw std::move(DuplicateDeclarationException((wstring(this->name) + L"已经被声明过，请勿重复声明！").c_str()));
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
			throw DuplicateDeclarationException((wstring(this->name) + L"已经被声明，请勿重复声明！").c_str());
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

	//逐个匹配参数。如果存在同名参数，则后一个同名参数必须和之前的值相等，否则匹配失败
	//如果目标参数不够，看看参数有没有设定默认值
	for (size_t i = 0; i < myParamCount; ++i) {
		//如果当前形参已经超过实参个数，则判断是否有默认值
		if (i + 1 > targetParamCount) { //注意，这里只能i+1，不能右边-1，因为size_t无符号
			Expression *defaultValue = this->parameters[i].getDefaultValue();
			if (!defaultValue)return false;
			context->setLocalVariable(this->parameters[i].getOffset(), defaultValue->evaluate(context));
		}
		//如果是最后一个变量，且开启了贪婪匹配，则匹配多项
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
			//不出意外的话，传入的参数应该都是EXTERN级别
			context->setLocalVariable(this->parameters[i].getOffset(), params->getItems()[i]);
		}
	}
	//验证约束是否符合，若有不符合则匹配失败
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
		//最后一条语句的结果视为返回值
		if (i == this->implementCount - 1) {
			ret = res;
			if (ret->getStorageLevel() < StorageLevel::TRANSFER) {
				ret->setStorageLevel(StorageLevel::TRANSFER); //返回值提升为TRANSFER，防止局部栈帧销毁时释放
			}
		}
	}
	return ret;
}

void Overload::compile(CompileContext *const &context)
{
	//编译参数列表
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
	//编译约束列表
	for (size_t i = 0; i < this->constraintCount; ++i) {
		this->constraints[i]->compile(context);
	}
	//编译实现
	for (size_t i = 0; i < this->implementCount; ++i) {
		this->implements[i]->compile(context);
	}
}
#include <sstream>
#include <string>
#include "FunctionExpression.h"
#include "FunctionInvocationExpression.h"
#include "BooleanExpression.h"
#include "DuplicateDeclarationException.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Context.h"
#include "CallStack.h"
#include "StackFrame.h"
#include "WorkScriptException.h"
#include "UninvocableException.h"
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
	this->declareStackFrame = context->getStackFrame();
	this->declareStack = context->getCallStack();
	StackFrame *targetFrame = this->declareStackFrame->getBaseStackFrame(this->functionVariableInfo.depth);
	if (this->name != nullptr) {
		auto varExpr = targetFrame->getLocalVariable(this->functionVariableInfo.offset);
		if (varExpr == nullptr) { //如果本层变量没有搜索到，搜索是否存在父级的函数声明。无论是否存在父级，都不进行合并
			targetFrame->setLocalVariable(this->functionVariableInfo.offset, (const Pointer<Expression>&)this);
			return this;
		}
		else { //如果本层找到了同名函数，则合并重载
			if (!varExpr->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_EXPRESSION)) {
				throw std::move(DuplicateDeclarationException((wstring(this->name) + L"已经被声明过，请勿重复声明！").c_str()));
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
		//函数名编译在当前作用域中
		if (!context->getLocalVariableInfo(this->name, &this->functionVariableInfo)) {
			context->addLocalVariable(this->name, &this->functionVariableInfo);
		}
		this->hasBaseFunction = context->getBaseVariableInfo(this->name, &this->baseFunctionVariableInfo);
	}
	//重载（参数，约束，实现）编译在子作用域中
	for (auto &overload : *this->overloads) {
		CompileContext subContext(context);
		overload->compile(&subContext);
	}
}

Overload *const FunctionExpression::getMatchedOverload(const Pointer<ParameterExpression>& params, Context *const context) const
{
	StackFrame *frame = context->getStackFrame();
	for (auto &overload : *this->overloads) {
		frame->resetLocalVariableCount(overload->getLocalVariableCount());
		if (overload->match(params, context)) {
			return overload;
		}
	}
	return nullptr;
}

const Pointer<Expression> FunctionExpression::invoke(const Pointer<ParameterExpression> &params) const
{
	StackFrame *newFrame = this->declareStack->newStackFrame(this->declareStackFrame, 0);
	Context subContext(this->declareStack, newFrame);
	Overload *matchedOverload = this->getMatchedOverload(params, &subContext);
	if (matchedOverload != nullptr) {
		auto ret = matchedOverload->invoke(&subContext);
		this->declareStack->popStackFrame();
		return ret;
	}
	else {
		this->declareStack->popStackFrame();
		if (this->hasBaseFunction) {
			StackFrame *targetFrame = this->declareStackFrame->getBaseStackFrame(this->baseFunctionVariableInfo.depth);
			auto expr = targetFrame->getLocalVariable(baseFunctionVariableInfo.offset);
			if (!expr->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_EXPRESSION)) {
				throw DuplicateDeclarationException((wstring(this->name) + L"已经被声明，请勿重复声明！").c_str());
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
	StackFrame *frame = context->getStackFrame();

	//如果不是变参函数，且实参多于形参，则直接匹配失败
	if (targetParamCount > myParamCount && this->parameters[myParamCount - 1].isVarargs() == false) {
		return false;
	}

	//逐个匹配参数。如果存在同名参数，则后一个同名参数必须和之前的值相等，否则匹配失败
	//如果目标参数不够，看看参数有没有设定默认值
	for (size_t i = 0; i < myParamCount; ++i) {
		//如果当前形参已经超过实参个数，则判断是否有默认值
		if (i + 1 > targetParamCount) { //注意，这里只能i+1，不能右边-1，因为size_t无符号
			Pointer<Expression>defaultValue = this->parameters[i].getDefaultValue();
			if (!defaultValue)return false;
			frame->setLocalVariable(this->parameters[i].getOffset(), defaultValue->evaluate(context));
		}
		//如果是最后一个变量，由于前面已经判断过，这里实参个数一定大于等于形参个数。
		//如果实参多于形参，则匹配变参函数。否则普通处理
		else if (i == myParamCount - 1 
			&& i < targetParamCount - 1
			&& this->parameters[i].isVarargs()) {
			size_t restParamCount = targetParamCount - myParamCount + 1;
			Pointer<Expression> *restParamItems = new Pointer<Expression>[restParamCount];
			for (size_t i = 0; i < restParamCount; ++i)
			{
				restParamItems[i] = params->getItem(myParamCount - 1 + i);
			}
			auto restParamList = new ParameterExpression(restParamItems,restParamCount);
			frame->setLocalVariable(this->parameters[i].getOffset(), restParamList);
			Pointer<Expression> prev = nullptr;
			if ((prev = frame->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, restParamList))return false;
			}
		}
		else {
			Pointer<Expression> prev = nullptr;
			if ((prev = frame->getLocalVariable(this->parameters[i].getOffset())) != nullptr) {
				if (!prev->equals(context, params->getItems()[i]))return false;
			}
			frame->setLocalVariable(this->parameters[i].getOffset(), params->getItems()[i]);
		}
	}
	//验证约束是否符合，若有不符合则匹配失败
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
	INVOKE_START:
	for (size_t i = 0; i < this->implementCount-1; ++i)
	{
		this->implements[i]->evaluate(context);
	}
	//最后一条语句的结果视为返回值
	Pointer<Expression> lastImpl = this->implements[implementCount - 1];
	if (lastImpl->getType(nullptr)->equals(nullptr, TypeExpression::FUNCTION_INVOCATION_EXPRESSION)) {
		auto invocation = ((Pointer<FunctionInvocationExpression>)lastImpl);
		auto func = invocation->getFunctionExpression(context); //目标函数
		auto params = invocation->getEvaluatedParameters(context); //实参
		//getMatchedOverload()已经将匹配的实参写入到context中。
		if (func->getDeclareStackFrame() == context->getStackFrame()) {
			StackFrame *newFrame = context->getCallStack()->newStackFrame(context->getStackFrame(), 0);
			context->setStackFrame(newFrame);
		}
		else {
			context->getStackFrame()->setBaseStackFrame(func->getDeclareStackFrame());
		}
		Overload *matchedOverload = func->getMatchedOverload(params, context);
		if (matchedOverload == nullptr) {
			throw std::move(UninvocableException((L"未找到匹配的" + wstring(func->getName()) + L"函数！").c_str()));
		}
		else if (matchedOverload == this) {	//尾递归优化
			goto INVOKE_START;
		}
		else {
			auto ret = matchedOverload->invoke(context);
			//if (createdNewFrame) targetContext->getCallStack()->popStackFrame();
			return ret;
		}
	}
	else {
		return lastImpl->evaluate(context);
	}
}

void Overload::compile(CompileContext *const &context)
{
	//编译参数列表
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
	//编译约束列表
	for (size_t i = 0; i < this->constraintCount; ++i) {
		this->constraints[i]->compile(context);
	}
	//编译实现
	for (size_t i = 0; i < this->implementCount; ++i) {
		this->implements[i]->compile(context);
	}
	this->localVariableCount = context->getLocalVariableCount();
}
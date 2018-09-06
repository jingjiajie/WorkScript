#pragma once
#include <vector>
#include <string.h>
#include <wchar.h>
#include "Expression.h"
#include "TypeExpression.h"

class FunctionInvocationExpression;
class FunctionExpression;
class VariableExpression;
class ParameterExpression;
class StackFrame;
class CallStack;

class ParameterInfo
{
public:
	inline ParameterInfo() {}

	inline ParameterInfo(const wchar_t *const &name) {
		this->setParameterName(name);
	}

	inline ParameterInfo(const wchar_t *const &name,const Pointer<Expression> &defaultValue) {
		this->setParameterName(name);
		this->setDefaultValue(defaultValue);
	}

	inline ParameterInfo(const wchar_t *const &name, const size_t &offset) {
		this->setParameterName(name);
		this->setOffset(offset);
	}

	inline ~ParameterInfo() {
		if (this->parameterName) {
			delete[]this->parameterName;
		}
	}

	inline const wchar_t *const getParameterName()const {
		return this->parameterName;
	}

	inline void setParameterName(const wchar_t *const &name) {
		if (this->parameterName) {
			delete[]this->parameterName;
		}
		size_t len = wcslen(name);
		this->parameterName = new wchar_t[len + 1];
		wcscpy(this->parameterName, name);
		this->parameterName[len] = 0;
	}

	inline const size_t getOffset()const {
		return this->offset;
	}

	inline void setOffset(const size_t &offset) {
		this->offset = offset;
	}

	inline const Pointer<Expression> getDefaultValue()const	{
		return this->defaultValue;
	}

	inline void setDefaultValue(const Pointer<Expression> &value) {
		this->defaultValue = value;
	}

private:
	wchar_t *parameterName = nullptr;
	Pointer<Expression> defaultValue = nullptr;
	size_t offset;
};


class Overload {
public:
	inline ~Overload()
	{
		if (this->parameters) {
			delete[]this->parameters;
		}

		if (this->constraints) {
			delete[]this->constraints;
		}

		delete[]this->implements;
	}

	virtual bool match(const Pointer<ParameterExpression> &params, Context *const& context) const;
	virtual const Pointer<Expression> invoke(Context *context) const;
	virtual void compile(CompileContext *const& context);

	inline const ParameterInfo *const getParameterInfos() const
	{
		return this->parameters;
	}

	inline void setParameterInfos(ParameterInfo *const &params, size_t count)
	{
		this->parameterCount = count;
		if (this->parameters) {
			delete[]this->parameters;
		}
		this->parameters = params;
	}

	inline Pointer<Expression> *const getConstraints() const
	{
		return this->constraints;
	}

	inline void setConstraints(Pointer<Expression> *const &constraints, const size_t &count)
	{
		this->constraintCount = count;
		this->constraints = constraints;
	}

	inline const bool getAllowLastMatchRest()const
	{
		return this->allowLastMatchRest;
	}

	inline void setAllowLastMatchRest(const bool& allowLastMatchRest)
	{
		this->allowLastMatchRest = allowLastMatchRest;
	}

	inline Pointer<Expression> *const getImplements() const
	{
		return this->implements;
	}

	inline void setImplements(Pointer<Expression> *const &impls, const size_t &count)
	{
		this->implementCount = count;
		this->implements = impls;
	}

	inline void setImplement(Pointer<Expression> impl)
	{
		this->implementCount = 1;
		this->implements = new Pointer<Expression>[1]{ impl };
	}

	inline const size_t getLocalVariableCount() const
	{
		return this->localVariableCount;
	}
	inline void setLocalVariableCount(const size_t &count)
	{
		this->localVariableCount = count;
	}

	inline FunctionExpression *getFunctionExpression()const
	{
		return this->functionExpression;
	}

	inline void setFunctionExpression(FunctionExpression *functionExpression)
	{
		this->functionExpression = functionExpression;
	}

protected:
	bool allowLastMatchRest = true;
	ParameterInfo *parameters = nullptr;
	size_t parameterCount = 0;

	Pointer<Expression> *constraints = nullptr;
	size_t constraintCount = 0;
	Pointer<Expression> *implements = nullptr;
	size_t implementCount = 0;

	size_t localVariableCount = 0; //编译时存储局部变量个数，用于运行时分配局部变量空间
	FunctionExpression *functionExpression = nullptr;
};


class FunctionExpression :
	public Expression
{
public:
	inline FunctionExpression()
	{
		this->overloads = new std::vector<Overload*>();
	}
	virtual ~FunctionExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual bool equals(Context *const &context, const Pointer<Expression>& targetExpression) const;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	virtual const Pointer<Expression> invoke(const Pointer<ParameterExpression> &params) const;

	inline const wchar_t *const getName()const
	{
		return name;
	}

	inline void setName(const wchar_t *const &funcName)
	{
		if (this->name)delete[]this->name;
		if (funcName == nullptr) {
			this->name = nullptr;
		}
		else {
			this->name = new wchar_t[wcslen(funcName) + 1];
			wcscpy(this->name, funcName);
		}
	}

	inline 	const std::vector<Overload *>* getOverloads()const
	{
		return this->overloads;
	}

	inline void addOverload(Overload* const &overload)
	{
		overload->setFunctionExpression(this);
		this->overloads->push_back(overload);
	}

	Overload *const getMatchedOverload(const Pointer<ParameterExpression>& params, Context *const context) const;

	inline StackFrame *getDeclareStackFrame()const
	{
		return this->declareStackFrame;
	}

	inline void setDeclareStackFrame(StackFrame *frame)
	{
		this->declareStackFrame = frame;
	}
protected:
	StackFrame * declareStackFrame = nullptr;
	CallStack *declareStack = nullptr;
	wchar_t *name;
	VariableCompileInfo functionVariableInfo;
	std::vector<Overload *> *overloads;
	VariableCompileInfo baseFunctionVariableInfo;
	bool hasBaseFunction = false;
};
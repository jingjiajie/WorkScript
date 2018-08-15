#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "WorkScriptException.h"
#include "TypeInfo.h"
#include "CompileContext.h"

class TermExpression;
class TypeExpression;
class Context;

class Expression : public std::enable_shared_from_this<Expression>
{
public:
	Expression();
	virtual ~Expression();
	//需要实现的接口函数
	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) = 0;
	virtual void compile(CompileContext *context) = 0;
	virtual const std::shared_ptr<TypeExpression> getType() const = 0;
	virtual const std::string toString() const = 0;

	////已经实现的函数
	//virtual const std::vector<std::shared_ptr<TypeMemberExpression>> getInstantialExpressions() const;
	//virtual void addInstantialExpressions(const std::shared_ptr<TypeMemberExpression> &expr);
protected:
	//std::vector<std::shared_ptr<TypeMemberExpression>> instantialExpressions;
};
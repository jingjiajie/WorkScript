#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "WorkScriptException.h"
#include "TypeInfo.h"
#include "ExpressionBind.h"

class Context;
class TypeExpression;
class TypeMemberExpression;

class Expression : public std::enable_shared_from_this<Expression>
{
public:
	Expression(Context *const &context);
	virtual ~Expression();
	//需要实现的接口函数
	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const = 0;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const = 0;
	virtual bool equals(const std::shared_ptr<const Expression> &) const = 0;
	virtual const std::shared_ptr<const TypeExpression> getType() const = 0;
	virtual const std::string toString() const = 0;

	//已经实现的函数
	virtual const Context *const & getContext() const;
	virtual void setContext(Context *const &context);
	virtual const std::vector<std::shared_ptr<const TypeMemberExpression>> getInstantialExpressions() const;
	virtual void addInstantialExpressions(const std::shared_ptr<const TypeMemberExpression> &expr);
protected:
	Context *context = nullptr;
	std::vector<std::shared_ptr<const TypeMemberExpression>> instantialExpressions;
};
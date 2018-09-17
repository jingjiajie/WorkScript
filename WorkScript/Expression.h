#pragma once
#include <iostream>
#include "Defines.h"
#include "WorkScriptException.h"
#include "TypeInfo.h"
#include "LinkContext.h"
#include "Pointer.h"

class Context;
class TypeExpression;
class StringExpression;

class Expression : public EnablePointer
{
public:
	inline Expression() {};
	virtual ~Expression();
	//需要实现的接口函数
	virtual const Pointer<Expression> evaluate(Context *const& context) = 0;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const = 0;
	virtual const Pointer<StringExpression> toString(Context *const& context) = 0;
	virtual void link(LinkContext *const& context) = 0;
	virtual bool equals(Context *const &context, const Pointer<Expression>&) const = 0;

protected:
};
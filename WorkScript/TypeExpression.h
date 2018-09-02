#pragma once
#include <vector>
#include <string.h>
#include <wchar.h>
#include "Expression.h"

//class TypeMemberExpression;

class TypeExpression : public Expression
{
public:

	inline TypeExpression(const wchar_t *const &name, const Pointer<TypeExpression> &baseType,const unsigned char typeID = TYPEID_CUSTOM)
	{
		this->setBaseType(baseType);
		this->setName(name);
		
		this->setTypeID(typeID);
	}

	virtual ~TypeExpression();
	//继承成员
	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	//virtual bool match(const Pointer<Expression> &matchExpression, Context *newContext) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	inline virtual bool equals(Context *const &context, const Pointer<Expression> &target) const override
	{
		return target == this;
	}

	//类名
	inline const wchar_t *const getName() const
	{
		return this->name;
	}

	inline void setName(const wchar_t *const &name)
	{
		if (this->name)delete[]this->name;
		this->name = new wchar_t[wcslen(name) + 1];
		wcscpy(this->name, name);
	}

	inline const unsigned char getTypeID()const {
		return this->typeID;
	}

	inline void setTypeID(const unsigned char typeID) {
		this->typeID = typeID;
	}
	//基类
	bool isSubTypeOf(Context *const &context, const Pointer<TypeExpression>&) const;
	const Pointer<TypeExpression> & getBaseType() const;
	void setBaseType(const Pointer<TypeExpression> &);
	////成员表达式
	//const std::vector<Pointer<TypeMemberExpression>> getMemberExpressions() const;
	//void addMemberExpression(const Pointer<TypeMemberExpression> &memberExpression);
	//const Pointer<TypeMemberExpression> matchStaticMemberExpression(const Pointer<Expression> &matchExpression, ExpressionBind *outExpressionBind) const;

private:
	wchar_t *name = nullptr;
	Pointer<TypeExpression> baseType;
	unsigned char typeID = TYPEID_CUSTOM;
	//std::vector<Pointer<TypeMemberExpression>> memberExpressions;

public:
	enum TypeID{
		TYPEID_BYTE = 0,
		TYPEID_INTEGER,
		TYPEID_DOUBLE,
		TYPEID_CUSTOM
	};

	static Pointer<TypeExpression>
		OBJECT,
		EXPRESSION,
		TYPE_EXPRESSION,
		TYPE_MEMBER_EXPRESSION,
		ASSIGNMENT_EXPRESSION,
		EXPRESSION_POINTER_EXPRESSION,
		FUNCTION_EXPRESSION,
		FUNCTION_INVOCATION_EXPRESSION,
		PARAMETER_EXPRESSION,
		BINARY_COMPARE_EXPRESSION,
		GREATER_THAN_EXPRESSION,
		GREATER_THAN_EQUAL_EXPRESSION,
		LESS_THAN_EXPRESSION,
		LESS_THAN_EQUAL_EXPRESSION,
		EQUALS_EXPRESSION,
		PLUS_EXPRESSION,
		MINUS_EXPRESSION,
		MULTIPLY_EXPRESSION,
		DIVIDE_EXPRESSION,
		MODULUS_EXPRESSION,
		NEGATIVE_EXPRESSION,
		EXECUTE_CPP_CODE_EXPRESSION,
		PRINT_EXPRESSION,
		THIS_EXPRESSION,
		MEMBER_EVALUATE_EXPRESSION,
		GET_TYPE_EXPRESSION,
		VARIABLE_EXPRESSION,
		STRING_EXPRESSION,
		NUMBER_EXPRESSION,
		DOUBLE_EXPRESSION,
		INTEGER_EXPRESSION,
		BYTE_EXPRESSION,
		BOOLEAN_EXPRESSION,
		LIST_EXPRESSION
		;
};
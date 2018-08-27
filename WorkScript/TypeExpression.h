#pragma once
#include <vector>
#include <string.h>
#include "Expression.h"

//class TypeMemberExpression;

class TypeExpression : public Expression
{
public:
	inline TypeExpression(const char *const &name, TypeExpression* const &baseType, const std::vector<TypeExpression *>& genericTypes, const StorageLevel level = StorageLevel::TEMP)
		:TypeExpression(name, baseType,level)
	{
		this->_isGenericType = true;
		this->setGenericTypes(genericTypes);
	}

	inline TypeExpression(const char *const &name, TypeExpression* const &baseType, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setBaseType(baseType);
		this->setName(name);
		this->setStorageLevel(level);
	}
	virtual ~TypeExpression();
	//继承成员
	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *newContext) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	inline virtual bool equals(Context *const &context, Expression* const &target) const override
	{
		return target == this;
	}

	//类名
	inline const char *const getName() const
	{
		return this->name;
	}

	inline void setName(const char *const &name)
	{
		if (this->name)delete[]this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	//基类
	bool isSubTypeOf(Context *const &context, TypeExpression* const&) const;
	TypeExpression* const & getBaseType() const;
	void setBaseType(TypeExpression* const &);
	//泛型
	const std::vector<TypeExpression *>& getGenericTypes() const;
	void setGenericTypes(const std::vector<TypeExpression *>&);
	void addGenericType(TypeExpression* const &typeInfo);
	bool isGenericType() const;
	////成员表达式
	//const std::vector<TypeMemberExpression *> getMemberExpressions() const;
	//void addMemberExpression(TypeMemberExpression* const &memberExpression);
	//TypeMemberExpression* const matchStaticMemberExpression(Expression* const &matchExpression, ExpressionBind *outExpressionBind) const;

private:
	char *name = nullptr;
	TypeExpression * baseType;
	bool _isGenericType = false;
	std::vector<TypeExpression *> genericTypes;
	//std::vector<TypeMemberExpression *> memberExpressions;

public:
	static TypeExpression 
		OBJECT,
		EXPRESSION,
		TYPE_EXPRESSION,
		TYPE_MEMBER_EXPRESSION,
		ASSIGNMENT_EXPRESSION,
		POINTER_EXPRESSION,
		FUNCTION_EXPRESSION,
		FUNCTION_INVOCATION_EXPRESSION,
		PARAMETER_EXPRESSION,
		COMPARE_EXPRESSION,
		GREATER_THAN_EXPRESSION,
		GREATER_THAN_EQUAL_EXPRESSION,
		LESS_THAN_EXPRESSION,
		LESS_THAN_EQUAL_EXPRESSION,
		EQUALS_EXPRESSION,
		PLUS_EXPRESSION,
		MINUS_EXPRESSION,
		MULTIPLY_EXPRESSION,
		DIVIDE_EXPRESSION,
		NEGATIVE_EXPRESSION,
		EXECUTE_CPP_CODE_EXPRESSION,
		PRINT_EXPRESSION,
		THIS_EXPRESSION,
		MEMBER_EVALUATE_EXPRESSION,
		GET_TYPE_EXPRESSION,
		VARIABLE_EXPRESSION,
		STRING_EXPRESSION,
		NUMBER_EXPRESSION,
		BOOLEAN_EXPRESSION,
		LIST_EXPRESSION
		;
};
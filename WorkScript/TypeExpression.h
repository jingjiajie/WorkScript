#pragma once
#include <vector>
#include <string.h>
#include <wchar.h>
#include "Expression.h"

//class TypeMemberExpression;

class TypeExpression : public Expression
{
public:
	inline TypeExpression(const wchar_t *const &name, TypeExpression* const &baseType, const std::vector<TypeExpression *>& genericTypes, const StorageLevel level = StorageLevel::TEMP)
		:TypeExpression(name, baseType,level)
	{
		this->_isGenericType = true;
		this->setGenericTypes(genericTypes);
	}

	inline TypeExpression(const wchar_t *const &name, TypeExpression* const &baseType, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setBaseType(baseType);
		this->setName(name);
		this->setStorageLevel(level);
	}

	inline TypeExpression(const wchar_t *const &name, TypeExpression* const &baseType,const unsigned char typeID = TYPEID_CUSTOM, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setBaseType(baseType);
		this->setName(name);
		this->setStorageLevel(level);
		this->setTypeID(typeID);
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
	wchar_t *name = nullptr;
	TypeExpression * baseType;
	bool _isGenericType = false;
	unsigned char typeID = TYPEID_CUSTOM;
	std::vector<TypeExpression *> genericTypes;
	//std::vector<TypeMemberExpression *> memberExpressions;

public:
	enum TypeID{
		TYPEID_BYTE = 0,
		TYPEID_INTEGER,
		TYPEID_DOUBLE,
		TYPEID_CUSTOM
	};

	static TypeExpression 
		OBJECT,
		EXPRESSION,
		TYPE_EXPRESSION,
		TYPE_MEMBER_EXPRESSION,
		ASSIGNMENT_EXPRESSION,
		EXPRESSION_POINTER_EXPRESSION,
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
		DOUBLE_EXPRESSION,
		INTEGER_EXPRESSION,
		BYTE_EXPRESSION,
		BOOLEAN_EXPRESSION,
		LIST_EXPRESSION
		;
};
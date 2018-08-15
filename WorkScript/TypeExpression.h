#pragma once
#include <string>
#include <vector>
#include "TermExpression.h"

class TypeMemberExpression;

class TypeExpression : public TermExpression
{
public:
	TypeExpression(const std::string &typeName, const std::shared_ptr<TypeExpression> &baseType, const std::vector<std::shared_ptr<TypeExpression>>& genericTypes);
	TypeExpression(const std::string &typeName, const std::shared_ptr<TypeExpression> &baseType);
	//继承成员
	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *newContext) const override;
	virtual bool equals(const std::shared_ptr<TermExpression> &) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	//类名
	const std::string& getName() const;
	void setName(const std::string&);
	//基类
	bool isSubTypeOf(const std::shared_ptr<TypeExpression>&) const;
	const std::shared_ptr<TypeExpression> & getBaseType() const;
	void setBaseType(const std::shared_ptr<TypeExpression> &);
	//泛型
	const std::vector<std::shared_ptr<TypeExpression>>& getGenericTypes() const;
	void setGenericTypes(const std::vector<std::shared_ptr<TypeExpression>>&);
	void addGenericType(const std::shared_ptr<TypeExpression> &typeInfo);
	bool isGenericType() const;
	//成员表达式
	const std::vector<std::shared_ptr<TypeMemberExpression>> getMemberExpressions() const;
	void addMemberExpression(const std::shared_ptr<TypeMemberExpression> &memberExpression);
	//const std::shared_ptr<TypeMemberExpression> matchStaticMemberExpression(const std::shared_ptr<Expression> &matchExpression, ExpressionBind *outExpressionBind) const;

private:
	std::string name;
	std::shared_ptr<TypeExpression> baseType;
	bool _isGenericType = false;
	std::vector<std::shared_ptr<TypeExpression>> genericTypes;
	std::vector<std::shared_ptr<TypeMemberExpression>> memberExpressions;

public:
	static std::shared_ptr<TypeExpression>
		OBJECT,
		EXPRESSION,
		TYPE_EXPRESSION,
		TYPE_MEMBER_EXPRESSION,
		TERM_EXPRESSION,
		FUNCTION_EXPRESSION,
		FUNCTION_INVOCATION_EXPRESSION,
		GREATER_THAN_EXPRESSION,
		GREATER_THAN_EQUAL_EXPRESSION,
		LESS_THAN_EXPRESSION,
		LESS_THAN_EQUAL_EXPRESSION,
		EQUAL_EXPRESSION,
		PLUS_EXPRESSION,
		MINUS_EXPRESSION,
		MULTIPLY_EXPRESSION,
		DIVIDE_EXPRESSION,
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
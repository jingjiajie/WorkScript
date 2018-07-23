#pragma once
#include <string>
#include <vector>
#include "Expression.h"

typedef std::shared_ptr<const Expression> SPCEXPRESSION;
typedef std::shared_ptr<const TypeExpression> SPCTYPEEXPRESSION;
typedef std::shared_ptr<TypeExpression> SPTYPEEXPRESSION;
typedef std::shared_ptr<const TypeMemberExpression> SPCTYPEMEMBEREXPRESSION;

const std::string TYPENAME_OBJECT = "Object";
const std::string TYPENAME_EXPRESSION = "Expression";
const std::string TYPENAME_TYPE_EXPRESSION = "TypeExpression";
const std::string TYPENAME_TYPE_MEMBER_EXPRESSION = "TypeMemberExpression";
const std::string TYPENAME_RELATION_EXPRESSION = "RelationExpression";
const std::string TYPENAME_POLYNOMIAL_EXPRESSION = "PolynomialExpression";
const std::string TYPENAME_MULTIPLY_EXPRESSION = "MultiplyExpression";
const std::string TYPENAME_DIVIDE_EXPRESSION = "DivideExpression";
const std::string TYPENAME_PLUS_EXPRESSION = "PlusExpression";
const std::string TYPENAME_MINUS_EXPRESSION = "MinusExpression";
const std::string TYPENAME_EXECUTE_CPP_CODE_EXPRESSION = "ExecuteCppCodeExpression";
const std::string TYPENAME_PRINT_EXPRESSION = "PrintExpression";
const std::string TYPENAME_THIS_EXPRESSION = "ThisExpression";
const std::string TYPENAME_MEMBER_EVALUATE_EXPRESSION = "MemberEvaluateExpression";
const std::string TYPENAME_GET_TYPE_EXPRESSION = "GetTypeExpression";
const std::string TYPENAME_MULTI_TERM_EXPRESSION = "MultiTermExpression";
const std::string TYPENAME_IDENTIFIER_EXPRESSION = "Identifier";
const std::string TYPENAME_VARIABLE_EXPRESSION = "Variable";
const std::string TYPENAME_RAW_VALUE_EXPRESSION = "RawValueExpression";
const std::string TYPENAME_PARENTHESE_EXPRESSION = "ParentheseExpression";
const std::string TYPENAME_STRING_EXPRESSION = "String";
const std::string TYPENAME_NUMBER_EXPRESSION = "Number";

class Context;
class TypeMemberExpression;

class TypeExpression : public Expression
{
public:
	TypeExpression(Context *const &context,const std::shared_ptr<const TypeExpression> &baseType,const std::vector<std::shared_ptr<const TypeExpression>>& genericTypes);
	TypeExpression(Context *const &context,const std::shared_ptr<const TypeExpression> &baseType);
	//继承成员
	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;

	//类名
	const std::string& getName() const;
	std::shared_ptr<TypeExpression> setName(const std::string&);
	//基类
	bool isSubTypeOf(const std::shared_ptr<const TypeExpression>&) const;
	const std::shared_ptr<const TypeExpression> & getBaseType() const;
	void setBaseType(const std::shared_ptr<const TypeExpression> &);
	//泛型
	const std::vector<std::shared_ptr<const TypeExpression>>& getGenericTypes() const;
	void setGenericTypes(const std::vector<std::shared_ptr<const TypeExpression>>&);
	void addGenericType(const std::shared_ptr<const TypeExpression> &typeInfo);
	bool isGenericType() const;
	//成员表达式
	const std::vector<std::shared_ptr<const TypeMemberExpression>> getMemberExpressions() const;
	void addMemberExpression(const std::shared_ptr<const TypeMemberExpression> &memberExpression);
	const std::shared_ptr<const TypeMemberExpression> matchStaticMemberExpression(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const;

	std::string toString() const;
private:
	std::string name;
	std::shared_ptr<const TypeExpression> baseType;
	bool _isGenericType = false;
	std::vector<std::shared_ptr<const TypeExpression>> genericTypes;
	std::vector<std::shared_ptr<const TypeMemberExpression>> memberExpressions;
};
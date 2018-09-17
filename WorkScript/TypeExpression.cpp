#include "TypeExpression.h"
#include "Expression.h"
#include "UnimplementedException.h"
#include "Context.h"
#include "Program.h"
#include "TypeMemberExpression.h"
#include "StringExpression.h"

Pointer<TypeExpression> TypeExpression::OBJECT(new TypeExpression(L"Object", nullptr));
Pointer<TypeExpression> TypeExpression::EXPRESSION(new TypeExpression(L"Expression", OBJECT));
Pointer<TypeExpression> TypeExpression::TYPE_EXPRESSION(new TypeExpression(L"TypeExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::TYPE_MEMBER_EXPRESSION(new TypeExpression(L"TypeMemberExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::ASSIGNMENT_EXPRESSION(new TypeExpression(L"AssignmentExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::EXPRESSION_POINTER_EXPRESSION(new TypeExpression(L"ExpressionPointerExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::VARIABLE_EXPRESSION(new TypeExpression(L"VariableExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::FUNCTION_EXPRESSION(new TypeExpression(L"FunctionExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::FUNCTION_INVOCATION_EXPRESSION(new TypeExpression(L"FunctionInvocationExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::PARAMETER_EXPRESSION(new TypeExpression(L"ParameterExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::BINARY_COMPARE_EXPRESSION(new TypeExpression(L"BinaryCompareExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::GREATER_THAN_EXPRESSION(new TypeExpression(L"GreaterThanExpression", BINARY_COMPARE_EXPRESSION));
Pointer<TypeExpression> TypeExpression::GREATER_THAN_EQUAL_EXPRESSION(new TypeExpression(L"GreaterThanEqualExpression", BINARY_COMPARE_EXPRESSION));
Pointer<TypeExpression> TypeExpression::LESS_THAN_EXPRESSION(new TypeExpression(L"LessThanExpression", BINARY_COMPARE_EXPRESSION));
Pointer<TypeExpression> TypeExpression::LESS_THAN_EQUAL_EXPRESSION(new TypeExpression(L"LessThanEqualExpression", BINARY_COMPARE_EXPRESSION));
Pointer<TypeExpression> TypeExpression::EQUALS_EXPRESSION(new TypeExpression(L"EqualsExpression", BINARY_COMPARE_EXPRESSION));
Pointer<TypeExpression> TypeExpression::PLUS_EXPRESSION(new TypeExpression(L"PlusExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::MINUS_EXPRESSION(new TypeExpression(L"MinusExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::MULTIPLY_EXPRESSION(new TypeExpression(L"MultiplyExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::DIVIDE_EXPRESSION(new TypeExpression(L"DivideExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::MODULUS_EXPRESSION(new TypeExpression(L"ModulusExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::NEGATIVE_EXPRESSION(new TypeExpression(L"NegativeExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::EXECUTE_CPP_CODE_EXPRESSION(new TypeExpression(L"ExecuteCppCodeExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::PRINT_EXPRESSION(new TypeExpression(L"PrintExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::THIS_EXPRESSION(new TypeExpression(L"ThisExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::MEMBER_EVALUATE_EXPRESSION(new TypeExpression(L"MemberEvaluateExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::GET_TYPE_EXPRESSION(new TypeExpression(L"GetTypeExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::STRING_EXPRESSION(new TypeExpression(L"StringExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::NUMBER_EXPRESSION(new TypeExpression(L"NumberExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::DOUBLE_EXPRESSION(new TypeExpression(L"DoubleExpression", NUMBER_EXPRESSION, TypeExpression::TYPEID_DOUBLE));
Pointer<TypeExpression> TypeExpression::INTEGER_EXPRESSION(new TypeExpression(L"IntegerExpression", NUMBER_EXPRESSION, TypeExpression::TYPEID_INTEGER));
Pointer<TypeExpression> TypeExpression::BYTE_EXPRESSION(new TypeExpression(L"ByteExpression", NUMBER_EXPRESSION,TypeExpression::TYPEID_BYTE));
Pointer<TypeExpression> TypeExpression::BOOLEAN_EXPRESSION(new TypeExpression(L"BooleanExpression", EXPRESSION));
Pointer<TypeExpression> TypeExpression::LIST_EXPRESSION(new TypeExpression(L"ListExpression", EXPRESSION));

TypeExpression::~TypeExpression()
{
	if (this->name)delete[]this->name;
}

const Pointer<Expression> TypeExpression::evaluate(Context *const& context)
{
	return this;
}

const Pointer<TypeExpression> TypeExpression::getType(Context *const& context) const
{
	return TypeExpression::TYPE_EXPRESSION;
}

const Pointer<TypeExpression> &  TypeExpression::getBaseType() const
{
	return this->baseType;
}

void TypeExpression::setBaseType(const Pointer<TypeExpression> &lpBaseType)
{
	this->baseType = lpBaseType;
}

bool TypeExpression::isSubTypeOf(Context *const &context, const Pointer<TypeExpression> &type) const
{
	const TypeExpression *curType = this;
	while (curType) {
		if (curType->equals(context, type)) {
			return true;
		}
		if (curType->baseType != nullptr && curType->baseType != curType) {
			curType = curType->baseType.get();
		}
		else {
			return false;
		}
	}
	return false;
}

//
//const std::vector<Pointer<TypeMemberExpression>> TypeExpression::getMemberExpressions() const
//{
//	return this->memberExpressions;
//}
//
//void TypeExpression::addMemberExpression(const Pointer<TypeMemberExpression>& memberExpression)
//{
//	this->memberExpressions.push_back(memberExpression);
//}

//const Pointer<TypeMemberExpression> TypeExpression::matchStaticMemberExpression(const Pointer<Expression>& matchExpression, ExpressionBind * outExpressionBind) const
//{
//	//在本类型中匹配，如果匹配成功则返回
//	for (auto &memberExpression : this->memberExpressions) {
//		if (memberExpression->match(matchExpression, outExpressionBind)) {
//			return memberExpression;
//		}
//	}
//	//如果匹配不到，则进入父类型进行匹配
//	if (this->baseType != nullptr && !this->baseType->equals(this)) {
//		return this->baseType->matchStaticMemberExpression(matchExpression,outExpressionBind);
//	}
//	else { //没有父类，则返回nullptr
//		return nullptr;
//	}
//}

const Pointer<StringExpression> TypeExpression::toString(Context *const& context)
{
	//TODO 泛型参数
	return StringExpression::newInstance(this->name);
}

void TypeExpression::link(LinkContext *const &context)
{
	return;
}

#include "TypeExpression.h"
#include "Expression.h"
#include "UnimplementedException.h"
#include "Context.h"
#include "Program.h"
#include "TypeMemberExpression.h"
#include "StringExpression.h"

TypeExpression TypeExpression::OBJECT(L"Object", nullptr, StorageLevel::EXTERN);
TypeExpression TypeExpression::EXPRESSION(L"Expression", &OBJECT, StorageLevel::EXTERN);
TypeExpression TypeExpression::TYPE_EXPRESSION(L"TypeExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::TYPE_MEMBER_EXPRESSION(L"TypeMemberExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::ASSIGNMENT_EXPRESSION(L"AssignmentExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::EXPRESSION_POINTER_EXPRESSION(L"ExpressionPointerExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::VARIABLE_EXPRESSION(L"VariableExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::FUNCTION_EXPRESSION(L"FunctionExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::FUNCTION_INVOCATION_EXPRESSION(L"FunctionInvocationExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::PARAMETER_EXPRESSION(L"ParameterExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::COMPARE_EXPRESSION(L"CompareExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::GREATER_THAN_EXPRESSION(L"GreaterThanExpression", &COMPARE_EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::GREATER_THAN_EQUAL_EXPRESSION(L"GreaterThanEqualExpression", &COMPARE_EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::LESS_THAN_EXPRESSION(L"LessThanExpression", &COMPARE_EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::LESS_THAN_EQUAL_EXPRESSION(L"LessThanEqualExpression", &COMPARE_EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::EQUALS_EXPRESSION(L"EqualsExpression", &COMPARE_EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::PLUS_EXPRESSION(L"PlusExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::MINUS_EXPRESSION(L"MinusExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::MULTIPLY_EXPRESSION(L"MultiplyExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::DIVIDE_EXPRESSION(L"DivideExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::NEGATIVE_EXPRESSION(L"NegativeExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::EXECUTE_CPP_CODE_EXPRESSION(L"ExecuteCppCodeExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::PRINT_EXPRESSION(L"PrintExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::THIS_EXPRESSION(L"ThisExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::MEMBER_EVALUATE_EXPRESSION(L"MemberEvaluateExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::GET_TYPE_EXPRESSION(L"GetTypeExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::STRING_EXPRESSION(L"StringExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::NUMBER_EXPRESSION(L"NumberExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::DOUBLE_EXPRESSION(L"DoubleExpression", &NUMBER_EXPRESSION, TypeExpression::TYPEID_DOUBLE, StorageLevel::EXTERN);
TypeExpression TypeExpression::INTEGER_EXPRESSION(L"IntegerExpression", &NUMBER_EXPRESSION, TypeExpression::TYPEID_INTEGER, StorageLevel::EXTERN);
TypeExpression TypeExpression::BYTE_EXPRESSION(L"ByteExpression", &NUMBER_EXPRESSION,TypeExpression::TYPEID_BYTE, StorageLevel::EXTERN);
TypeExpression TypeExpression::BOOLEAN_EXPRESSION(L"BooleanExpression", &EXPRESSION, StorageLevel::EXTERN);
TypeExpression TypeExpression::LIST_EXPRESSION(L"ListExpression", &EXPRESSION, StorageLevel::EXTERN);

TypeExpression::~TypeExpression()
{
	if (this->name)delete[]this->name;
}

Expression* const TypeExpression::evaluate(Context *const& context)
{
	return (Expression* const&)this;
}

TypeExpression* const TypeExpression::getType(Context *const& context) const
{
	return &TypeExpression::TYPE_EXPRESSION;
}

TypeExpression* const &  TypeExpression::getBaseType() const
{
	return this->baseType;
}

void TypeExpression::setBaseType(TypeExpression* const &lpBaseType)
{
	this->baseType = lpBaseType;
}

const std::vector<TypeExpression *>& TypeExpression::getGenericTypes() const
{
	return this->genericTypes;
}

void TypeExpression::setGenericTypes(const std::vector<TypeExpression *>& vecGenericTypes)
{
	this->genericTypes = vecGenericTypes;
}

void TypeExpression::addGenericType(TypeExpression* const &typeInfo)
{
	this->genericTypes.push_back(typeInfo);
}

bool TypeExpression::isSubTypeOf(Context *const &context, TypeExpression* const &type) const
{
	auto curType = this;
	while (curType) {
		if (curType->equals(context, type)) {
			return true;
		}
		if (curType->baseType != nullptr && curType->baseType != curType) {
			curType = curType->baseType;
		}
		else {
			return false;
		}
	}
	return false;
}

bool TypeExpression::isGenericType() const
{
	return this->_isGenericType;
}
//
//const std::vector<TypeMemberExpression *> TypeExpression::getMemberExpressions() const
//{
//	return this->memberExpressions;
//}
//
//void TypeExpression::addMemberExpression(TypeMemberExpression* const& memberExpression)
//{
//	this->memberExpressions.push_back(memberExpression);
//}

//TypeMemberExpression* const TypeExpression::matchStaticMemberExpression(Expression* const& matchExpression, ExpressionBind * outExpressionBind) const
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

StringExpression *const TypeExpression::toString(Context *const& context)
{
	//TODO 泛型参数
	return StringExpression::newInstance(this->name);
}

void TypeExpression::compile(CompileContext *const &context)
{
	
}

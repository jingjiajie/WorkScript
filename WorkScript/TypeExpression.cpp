#include "TypeExpression.h"
#include "Expression.h"
#include "UnimplementedException.h"
#include "Context.h"
#include "TypeMemberExpression.h"
#include <sstream>
#include <string>
using namespace std;

shared_ptr<TypeExpression> TypeExpression::OBJECT(new TypeExpression("Object", nullptr));
shared_ptr<TypeExpression> TypeExpression::EXPRESSION(new TypeExpression("Expression",TypeExpression::OBJECT));
shared_ptr<TypeExpression> TypeExpression::TYPE_EXPRESSION(new TypeExpression("TypeExpression", TypeExpression::EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::TYPE_MEMBER_EXPRESSION(new TypeExpression("TypeMemberExpression", TypeExpression::EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::TERM_EXPRESSION(new TypeExpression("TermExpression", TypeExpression::EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::FUNCTION_EXPRESSION(new TypeExpression("FunctionExpression",TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::FUNCTION_INVOCATION_EXPRESSION(new TypeExpression("FunctionInvocationExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::GREATER_THAN_EXPRESSION(new TypeExpression("GreaterThanExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::GREATER_THAN_EQUAL_EXPRESSION(new TypeExpression("GreaterThanEqualExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::LESS_THAN_EXPRESSION(new TypeExpression("LessThanExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::LESS_THAN_EQUAL_EXPRESSION(new TypeExpression("LessThanEqualExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::EQUAL_EXPRESSION(new TypeExpression("EqualExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::PLUS_EXPRESSION(new TypeExpression("PlusExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::MINUS_EXPRESSION(new TypeExpression("MinusExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::MULTIPLY_EXPRESSION(new TypeExpression("MultiplyExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::DIVIDE_EXPRESSION(new TypeExpression("DivideExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::EXECUTE_CPP_CODE_EXPRESSION(new TypeExpression("ExecuteCppCodeExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::PRINT_EXPRESSION(new TypeExpression("PrintExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::THIS_EXPRESSION(new TypeExpression("ThisExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::MEMBER_EVALUATE_EXPRESSION(new TypeExpression("MemberEvaluateExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::GET_TYPE_EXPRESSION(new TypeExpression("GetTypeExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::VARIABLE_EXPRESSION(new TypeExpression("VariableExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::STRING_EXPRESSION(new TypeExpression("StringExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::NUMBER_EXPRESSION(new TypeExpression("NumberExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::BOOLEAN_EXPRESSION(new TypeExpression("BooleanExpression", TypeExpression::TERM_EXPRESSION));
shared_ptr<TypeExpression> TypeExpression::LIST_EXPRESSION(new TypeExpression("ListExpression", TypeExpression::TERM_EXPRESSION));

TypeExpression::TypeExpression(const std::string &typeName,const std::shared_ptr<TypeExpression> &baseType)
{
	this->setBaseType(baseType);
	this->setName(typeName);

	//auto toStringRight = SPCEXPRESSION(new ExecuteCppCodeExpression(this, [this](const ExpressionBind &expressionBind) {
	//	SPCEXPRESSION thisExpression(new ThisExpression(this));
	//	auto expr = dynamic_pointer_cast<Expression>(thisExpression->evaluate(expressionBind));
	//	return SPCEXPRESSION(new StringExpression(this, expr->toString()));
	//}));
	//shared_ptr<RelationExpression> relation(new RelationExpression(this, toStringExpression, toStringRight));
	//auto memberExpression = shared_ptr<TypeMemberExpression>(new TypeMemberExpression(typeExpr, Authority::PUBLIC, relation));
	//typeExpr->addMemberExpression(memberExpression);
}

const std::shared_ptr<TermExpression> TypeExpression::evaluate(Context *context)
{
	return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
}

TypeExpression::TypeExpression(const std::string &typeName,const std::shared_ptr<TypeExpression> &baseType, const std::vector<std::shared_ptr<TypeExpression>>& genericTypes)
	:TypeExpression(typeName,baseType)
{
	this->_isGenericType = true;
	this->setGenericTypes(genericTypes);
}

bool TypeExpression::equals(const std::shared_ptr<TermExpression> & target) const
{
	//判断地址是否相同。也就是说同一个类型必须对应同一个TypeExpression
	return (decltype(this))target.get() == this;
}

const std::shared_ptr<TypeExpression> TypeExpression::getType() const
{
	return TypeExpression::TYPE_EXPRESSION;
}

const std::string & TypeExpression::getName() const
{
	return this->name;
}

void TypeExpression::setName(const std::string &name)
{
	this->name = name;
}

const std::shared_ptr<TypeExpression> &  TypeExpression::getBaseType() const
{
	return this->baseType;
}

void TypeExpression::setBaseType(const std::shared_ptr<TypeExpression> &lpBaseType)
{
	this->baseType = lpBaseType;
}

const std::vector<std::shared_ptr<TypeExpression>>& TypeExpression::getGenericTypes() const
{
	return this->genericTypes;
}

void TypeExpression::setGenericTypes(const std::vector<std::shared_ptr<TypeExpression>>& vecGenericTypes)
{
	this->genericTypes = vecGenericTypes;
}

void TypeExpression::addGenericType(const std::shared_ptr<TypeExpression> &typeInfo)
{
	this->genericTypes.push_back(typeInfo);
}

bool TypeExpression::isSubTypeOf(const std::shared_ptr<TypeExpression> &type) const
{
	auto curType = dynamic_pointer_cast<const TypeExpression> (this->shared_from_this());
	while (curType) {
		if (curType->equals(type)) {
			return true;
		}
		if (curType->baseType != curType) {
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

const std::vector<std::shared_ptr<TypeMemberExpression>> TypeExpression::getMemberExpressions() const
{
	return this->memberExpressions;
}

void TypeExpression::addMemberExpression(const std::shared_ptr<TypeMemberExpression>& memberExpression)
{
	this->memberExpressions.push_back(memberExpression);
}

//const std::shared_ptr<TypeMemberExpression> TypeExpression::matchStaticMemberExpression(const std::shared_ptr<Expression>& matchExpression, ExpressionBind * outExpressionBind) const
//{
//	//在本类型中匹配，如果匹配成功则返回
//	for (auto &memberExpression : this->memberExpressions) {
//		if (memberExpression->match(matchExpression, outExpressionBind)) {
//			return memberExpression;
//		}
//	}
//	//如果匹配不到，则进入父类型进行匹配
//	if (this->baseType != nullptr && !this->baseType->equals(this->shared_from_this())) {
//		return this->baseType->matchStaticMemberExpression(matchExpression,outExpressionBind);
//	}
//	else { //没有父类，则返回nullptr
//		return nullptr;
//	}
//}

const std::string TypeExpression::toString() const
{
	stringstream ss;
	ss << (this->name);
	if (this->isGenericType()) {
		ss << "<";
		for (auto &genericType : this->genericTypes) {
			ss << (genericType->getName());
		}
		ss << ">";
	}
	return ss.str();
}

void TypeExpression::compile(CompileContext * context)
{
	
}

#include "TypeExpression.h"
#include "Expression.h"
#include "UnimplementedException.h"
#include "Context.h"
#include "TypeMemberExpression.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "ParentheseExpression.h"
#include "RelationExpression.h"
#include <sstream>
#include <string>
using namespace std;


TypeExpression::TypeExpression( Context *const &context, const std::shared_ptr<const TypeExpression> &baseType)
	:Expression(context)
{
	this->setBaseType(baseType);
}

TypeExpression::TypeExpression(Context *const &context, const std::shared_ptr<const TypeExpression> &baseType, const std::vector<std::shared_ptr<const TypeExpression>>& genericTypes)
	:TypeExpression(context,baseType)
{
	this->_isGenericType = true;
	this->setGenericTypes(genericTypes);
}

bool TypeExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	throw UnimplementedException();
}

bool TypeExpression::equals(const std::shared_ptr<const Expression> & target) const
{
	auto targetType = target->getType();
	if (targetType->getName() != TYPENAME_TYPE_EXPRESSION) {
		return false;
	}
	auto targetTypeExpression = (const std::shared_ptr<const TypeExpression> &)target;
	if (this->name != targetTypeExpression->name)return false;
	if (this->context != targetTypeExpression->context)return false;
	if (this->isGenericType() != targetTypeExpression->isGenericType())return false;
	if (this->isGenericType()) {
		if (this->genericTypes.size() != targetTypeExpression->genericTypes.size())return false;
		for (size_t i = 0; i < this->genericTypes.size(); i++) {
			auto curGenericType = (shared_ptr<const TypeExpression>)this->genericTypes[i];
			auto curTargetGenericType = dynamic_pointer_cast<const Expression> (targetTypeExpression->genericTypes[i]);
			if (!curGenericType->equals(curTargetGenericType)) {
				return false;
			}
		}
	}
	return true;
}

const std::shared_ptr<const Expression> TypeExpression::evaluate(const ExpressionBind &) const
{
	throw UnimplementedException();
}

const std::shared_ptr<const TypeExpression> TypeExpression::getType() const
{
	return this->context->findType(TYPENAME_TYPE_EXPRESSION, false);
}

const std::string & TypeExpression::getName() const
{
	return this->name;
}

shared_ptr<TypeExpression> TypeExpression::setName(const std::string &name)
{
	//this->memberExpressions.insert(this->memberExpressions.begin(),
	//	shared_ptr<const TypeMemberExpression>(new TypeMemberExpression(this->context,dynamic_pointer_cast<const TypeExpression>( this->shared_from_this()), Authority::PUBLIC,
	//		shared_ptr<const RelationExpression>(new RelationExpression(this->context,
	//			shared_ptr<const IdentifierExpression>(new IdentifierExpression(this->context, "name")),
	//				shared_ptr<const RawValueExpression<string>>(new RawValueExpression<string>(this->context, this->context->findType(TYPENAME_STRING_EXPRESSION,false), name)))))));
	this->name = name;
	return dynamic_pointer_cast<TypeExpression>(this->shared_from_this());
}

const std::shared_ptr<const TypeExpression> &  TypeExpression::getBaseType() const
{
	return this->baseType;
}

void TypeExpression::setBaseType(const std::shared_ptr<const TypeExpression> &lpBaseType)
{
	this->baseType = lpBaseType;
}

const std::vector<std::shared_ptr<const TypeExpression>>& TypeExpression::getGenericTypes() const
{
	return this->genericTypes;
}

void TypeExpression::setGenericTypes(const std::vector<std::shared_ptr<const TypeExpression>>& vecGenericTypes)
{
	this->genericTypes = vecGenericTypes;
}

void TypeExpression::addGenericType(const std::shared_ptr<const TypeExpression> &typeInfo)
{
	this->genericTypes.push_back(typeInfo);
}

bool TypeExpression::isSubTypeOf(const std::shared_ptr<const TypeExpression> &type) const
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

const std::vector<std::shared_ptr<const TypeMemberExpression>> TypeExpression::getMemberExpressions() const
{
	return this->memberExpressions;
}

void TypeExpression::addMemberExpression(const std::shared_ptr<const TypeMemberExpression>& memberExpression)
{
	this->memberExpressions.push_back(memberExpression);
}

const std::shared_ptr<const TypeMemberExpression> TypeExpression::matchStaticMemberExpression(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	//在本类型中匹配，如果匹配成功则返回
	for (auto &memberExpression : this->memberExpressions) {
		if (memberExpression->match(matchExpression, outExpressionBind)) {
			return memberExpression;
		}
	}
	//如果匹配不到，则进入父类型进行匹配
	if (this->baseType != nullptr && !this->baseType->equals(this->shared_from_this())) {
		return this->baseType->matchStaticMemberExpression(matchExpression,outExpressionBind);
	}
	else { //没有父类，则返回nullptr
		return nullptr;
	}
}

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

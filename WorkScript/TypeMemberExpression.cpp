#include <sstream>

#include "TypeMemberExpression.h"
#include "Context.h"
#include "AccessDeniedException.h"
#include "UnimplementedException.h"

using namespace std;

TypeMemberExpression::TypeMemberExpression(Context * const & context, const std::shared_ptr<const TypeExpression>& belongType, const Authority & authority, const std::shared_ptr<const Expression>& expression)
	:Expression(context)
{
	this->setBelongType(belongType);
	this->setAuthority(authority);
	this->setExpression(expression);
}

TypeMemberExpression::~TypeMemberExpression()
{
}

const std::shared_ptr<const Expression> TypeMemberExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto accessType = this->context->getCurrentExpression()->getType();
	if (!this->canAccess(accessType)) {
		throw AccessDeniedException();
	}
	auto result = this->expression->evaluate(expressionBind);
	return result;
}

bool TypeMemberExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	auto accessType = this->context->getCurrentExpression()->getType();
	if (!this->canAccess(accessType))return false;
	bool ifSuccess = this->expression->match(matchExpression, outExpressionBind);
	return ifSuccess;
}

bool TypeMemberExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	throw UnimplementedException();
}

const std::shared_ptr<const TypeExpression> TypeMemberExpression::getType() const
{
	return this->context->findType(TYPENAME_TYPE_MEMBER_EXPRESSION, false);
}

const std::string TypeMemberExpression::toString() const
{
	stringstream ss;
	if (this->authority == Authority::PUBLIC) {
		ss << "public ";
	}else if(this->authority == Authority::PROTECTED){
		ss << "protected ";
	}
	else {
		ss << "private ";
	}
	ss << this->expression->toString();
	return ss.str();
}

const std::shared_ptr<const TypeExpression> TypeMemberExpression::getBelongType() const
{
	return this->belongType;
}

void TypeMemberExpression::setBelongType(const std::shared_ptr<const TypeExpression> &belongType)
{
	this->belongType = belongType;
}

const std::shared_ptr<const Expression> TypeMemberExpression::getExpression() const
{
	return this->expression;
}

void TypeMemberExpression::setExpression(const std::shared_ptr<const Expression>&expression)
{
	this->expression = expression;
}

const Authority TypeMemberExpression::getAuthority() const
{
	return this->authority;
}

void TypeMemberExpression::setAuthority(const Authority &authority)
{
	this->authority = authority;
}

bool TypeMemberExpression::canAccess(const std::shared_ptr<const TypeExpression>& accessType) const
{
	//如果是公有，不用说了，直接访问
	if (this->authority == Authority::PUBLIC) {
		return true;
	}//如果是私有，只有同类型能访问
	else if (this->authority == Authority::PRIVATE) {
		if (accessType == nullptr)return false;
		if (accessType->equals(this->getBelongType()))return true;
		return false;
	}//如果是保护，只有同类型或者子类可以访问
	else if (this->authority == Authority::PROTECTED) {
		if (accessType == nullptr)return false;
		if (accessType->equals(this->getBelongType()))return true;
		if (accessType->isSubTypeOf(this->getBelongType()))return true;
		return false;
	}
	return false;
}

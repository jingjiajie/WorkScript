//#include <sstream>
//#include "TypeMemberExpression.h"
//#include "Context.h"
//#include "AccessDeniedException.h"
//#include "UnimplementedException.h"
//#include "Program.h"
//
//using namespace std;
//
//TypeMemberExpression::TypeMemberExpression(const Pointer<TypeExpression> & belongType, const Authority & authority, const Pointer<Expression> & expression)
//{
//	this->setBelongType(belongType);
//	this->setAuthority(authority);
//	this->setExpression(expression);
//}
//
//TypeMemberExpression::~TypeMemberExpression()
//{
//}
//
////const Pointer<Expression> TypeMemberExpression::evaluate(const ExpressionBind &expressionBind) const
////{
////	auto accessType = this->context->getCurrentExpression()->getType(context);
////	if (!this->canAccess(accessType)) {
////		throw AccessDeniedException();
////	}
////	auto result = this->expression->evaluate(expressionBind);
////	return result;
////}
////
////bool TypeMemberExpression::match(const Pointer<Expression> & matchExpression, ExpressionBind * outExpressionBind) const
////{
////	auto accessType = this->context->getCurrentExpression()->getType(context);
////	if (!this->canAccess(accessType))return false;
////	bool ifSuccess = this->expression->match(matchExpression, outExpressionBind);
////	return ifSuccess;
////}
//
//const Pointer<TypeExpression> TypeMemberExpression::getType(Context *const& context) const
//{
//	return TypeExpression::TYPE_MEMBER_EXPRESSION;
//}
//
//const Pointer<StringExpression> TypeMemberExpression::toString(Context *const& context)
//{
//	stringstream ss;
//	if (this->authority == Authority::PUBLIC) {
//		ss << "public ";
//	}else if(this->authority == Authority::PROTECTED){
//		ss << "protected ";
//	}
//	else {
//		ss << "private ";
//	}
//	ss << this->expression->toString(context);
//	return ss.str();
//}
//
//void TypeMemberExpression::link(LinkContext *const &context)
//{
//	return;
//}
//
//const Pointer<TypeExpression> TypeMemberExpression::getBelongType() const
//{
//	return this->belongType;
//}
//
//void TypeMemberExpression::setBelongType(const Pointer<TypeExpression> &belongType)
//{
//	this->belongType = belongType;
//}
//
//const Pointer<Expression> TypeMemberExpression::getExpression() const
//{
//	return this->expression;
//}
//
//void TypeMemberExpression::setExpression(const Pointer<Expression> &expression)
//{
//	this->expression = expression;
//}
//
//const Authority TypeMemberExpression::getAuthority() const
//{
//	return this->authority;
//}
//
//void TypeMemberExpression::setAuthority(const Authority &authority)
//{
//	this->authority = authority;
//}
//
//bool TypeMemberExpression::canAccess(Context *const &context, const Pointer<TypeExpression> & accessType) const
//{
//	//如果是公有，不用说了，直接访问
//	if (this->authority == Authority::PUBLIC) {
//		return true;
//	}//如果是私有，只有同类型能访问
//	else if (this->authority == Authority::PRIVATE) {
//		if (accessType == nullptr)return false;
//		if (accessType->equals(context,this->getBelongType()))return true;
//		return false;
//	}//如果是保护，只有同类型或者子类可以访问
//	else if (this->authority == Authority::PROTECTED) {
//		if (accessType == nullptr)return false;
//		if (accessType->equals(context,this->getBelongType()))return true;
//		if (accessType->isSubTypeOf(context,this->getBelongType()))return true;
//		return false;
//	}
//	return false;
//}

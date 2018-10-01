#include "stdafx.h"
//#include "MemberEvaluateExpression.h"
//#include "TypeExpression.h"
//#include "TypeMemberExpression.h"
//#include "Context.h"
//
//using namespace std;
//
//MemberEvaluateExpression::MemberEvaluateExpression(const Pointer<Expression> &objExpr, const Pointer<Expression> &memberExpr)
//{
//	this->setObjectExpression(objExpr);
//	this->setMemberExpression(memberExpr);
//}
//
//
//MemberEvaluateExpression::~MemberEvaluateExpression()
//{
//}
//
//const Pointer<Expression> MemberEvaluateExpression::evaluate(Context *const& context)
//{
//	auto prevExpr = this->context->getCurrentExpression();
//	auto evaluatedObjExpression = this->objectExpression->evaluate(expressionBind);
//	auto evaluatedMemberExpression = this->memberExpression->evaluate(expressionBind);
//	auto evaluatedObjType = evaluatedObjExpression->getType(context);
//	this->context->setCurrentExpression(evaluatedObjExpression); //设定当前表达式为ObjectExpression
//	ExpressionBind tmpExpressionBind;
//	Pointer<Expression>  result;
//	//先匹配实例表达式，若匹配失败尝试匹配类静态表达式
//	bool matchedInstantialExpr = false;
//	for (auto &expr : evaluatedObjExpression->getInstantialExpressions()) {
//		if (expr->match(evaluatedMemberExpression, &tmpExpressionBind)) {
//			matchedInstantialExpr = true;
//			result = expr->evaluate(tmpExpressionBind);
//			break;
//		}
//	}
//	if (!matchedInstantialExpr) {
//		auto matchedMember = evaluatedObjType->matchStaticMemberExpression(evaluatedMemberExpression, &tmpExpressionBind);
//		if (matchedMember == nullptr) {
//			auto newMe = Pointer<MemberEvaluateExpression>(new MemberEvaluateExpression(context, evaluatedObjExpression, evaluatedMemberExpression));
//			result = newMe;
//		}
//		else {
//			result = matchedMember->evaluate(tmpExpressionBind);
//		}
//	}
//	this->context->setCurrentExpression(prevExpr); //恢复当前表达式
//	return result;
//}
////
////bool MemberEvaluateExpression::match(const Pointer<Expression> & matchExpression, ExpressionBind * outExpressionBind) const
////{
////	auto matchType = matchExpression->getType(context);
////	if (!matchType->equals(this))return false;
////	auto matchMemberEvaluateExpression = (const Pointer<MemberEvaluateExpression> &)matchExpression;
////	ExpressionBind tmpExpressionBind;
////	if (!this->objectExpression->match(matchMemberEvaluateExpression->objectExpression, &tmpExpressionBind))return false;
////	if (!this->memberExpression->match(matchMemberEvaluateExpression->memberExpression, &tmpExpressionBind))return false;
////	*outExpressionBind = ExpressionBind(tmpExpressionBind);
////	return true;
////}
//
//bool MemberEvaluateExpression::equals(Context *const &context, const Pointer<Expression> & targetExpression) const
//{
//	if (!targetExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	auto targetMemberEvaluateExpr = (const Pointer<MemberEvaluateExpression> &)(targetExpression);
//	return targetMemberEvaluateExpr->objectExpression->equals(this->objectExpression)
//		&& targetMemberEvaluateExpr->memberExpression->equals(this->memberExpression);
//}
//
//const Pointer<TypeExpression> MemberEvaluateExpression::getType(Context *const& context) const
//{
//	return TypeExpression::TYPE_MEMBER_EVALUATE_EXPRESSION;
//}
//
//const Pointer<StringExpression> MemberEvaluateExpression::toString(Context *const& context)
//{
//	return this->objectExpression->toString() + "." + this->objectExpression->toString();
//}
//
//const Pointer<Expression> MemberEvaluateExpression::getObjectExpression() const
//{
//	return this->objectExpression;
//}
//
//void MemberEvaluateExpression::setObjectExpression(const Pointer<Expression> &expr)
//{
//	this->objectExpression = expr;
//}
//
//const Pointer<Expression> MemberEvaluateExpression::getMemberExpression() const
//{
//	return this->memberExpression;
//}
//
//void MemberEvaluateExpression::setMemberExpression(const Pointer<Expression> &expr)
//{
//	this->memberExpression = expr;
//}

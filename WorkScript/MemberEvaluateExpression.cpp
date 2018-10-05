#include "stdafx.h"
//#include "MemberEvaluateExpression.h"
//#include "Type.h"
//#include "TypeMemberExpression.h"
//#include "Context.h"
//
//using namespace std;
//
//MemberEvaluateExpression::MemberEvaluateExpression(Expression *objExpr, Expression *memberExpr)
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
//Expression * MemberEvaluateExpression::evaluate(Context *const& context)
//{
//	auto prevExpr = this->context->getCurrentExpression();
//	auto evaluatedObjExpression = this->objectExpression->evaluate(expressionBind);
//	auto evaluatedMemberExpression = this->memberExpression->evaluate(expressionBind);
//	auto evaluatedObjType = evaluatedObjExpression->getType(context);
//	this->context->setCurrentExpression(evaluatedObjExpression); //�趨��ǰ���ʽΪObjectExpression
//	ExpressionBind tmpExpressionBind;
//	Pointer<Expression>  result;
//	//��ƥ��ʵ�����ʽ����ƥ��ʧ�ܳ���ƥ���ྲ̬���ʽ
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
//	this->context->setCurrentExpression(prevExpr); //�ָ���ǰ���ʽ
//	return result;
//}
////
////bool MemberEvaluateExpression::match(Expression * matchExpression, ExpressionBind * outExpressionBind) const
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
//bool MemberEvaluateExpression::equals(Context *const &context, Expression * targetExpression) const
//{
//	if (!targetExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	auto targetMemberEvaluateExpr = (const Pointer<MemberEvaluateExpression> &)(targetExpression);
//	return targetMemberEvaluateExpr->objectExpression->equals(this->objectExpression)
//		&& targetMemberEvaluateExpr->memberExpression->equals(this->memberExpression);
//}
//
//const Type * MemberEvaluateExpression::getType() const
//{
//	return Type::TYPE_MEMBER_EVALUATE_EXPRESSION;
//}
//
//std::wstring MemberEvaluateExpression::toString()
//{
//	return this->objectExpression->toString() + "." + this->objectExpression->toString();
//}
//
//Expression * MemberEvaluateExpression::getObjectExpression() const
//{
//	return this->objectExpression;
//}
//
//void MemberEvaluateExpression::setObjectExpression(Expression *expr)
//{
//	this->objectExpression = expr;
//}
//
//Expression * MemberEvaluateExpression::getMemberExpression() const
//{
//	return this->memberExpression;
//}
//
//void MemberEvaluateExpression::setMemberExpression(Expression *expr)
//{
//	this->memberExpression = expr;
//}

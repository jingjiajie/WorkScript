//#include "MemberEvaluateExpression.h"
//#include "TypeExpression.h"
//#include "TypeMemberExpression.h"
//#include "Context.h"
//
//using namespace std;
//
//MemberEvaluateExpression::MemberEvaluateExpression(Expression* const &objExpr, Expression* const &memberExpr)
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
//Expression* const MemberEvaluateExpression::evaluate(Context *const& context)
//{
//	auto prevExpr = this->context->getCurrentExpression();
//	auto evaluatedObjExpression = this->objectExpression->evaluate(expressionBind);
//	auto evaluatedMemberExpression = this->memberExpression->evaluate(expressionBind);
//	auto evaluatedObjType = evaluatedObjExpression->getType(context);
//	this->context->setCurrentExpression(evaluatedObjExpression); //设定当前表达式为ObjectExpression
//	ExpressionBind tmpExpressionBind;
//	Expression * result;
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
//			auto newMe = MemberEvaluateExpression *(new MemberEvaluateExpression(context, evaluatedObjExpression, evaluatedMemberExpression));
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
////bool MemberEvaluateExpression::match(Expression* const& matchExpression, ExpressionBind * outExpressionBind) const
////{
////	auto matchType = matchExpression->getType(context);
////	if (!matchType->equals(this))return false;
////	auto matchMemberEvaluateExpression = (MemberEvaluateExpression* const&)matchExpression;
////	ExpressionBind tmpExpressionBind;
////	if (!this->objectExpression->match(matchMemberEvaluateExpression->objectExpression, &tmpExpressionBind))return false;
////	if (!this->memberExpression->match(matchMemberEvaluateExpression->memberExpression, &tmpExpressionBind))return false;
////	*outExpressionBind = ExpressionBind(tmpExpressionBind);
////	return true;
////}
//
//bool MemberEvaluateExpression::equals(Context *const &context, Expression* const& targetExpression) const
//{
//	if (!targetExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	auto targetMemberEvaluateExpr = (MemberEvaluateExpression *const&)(targetExpression);
//	return targetMemberEvaluateExpr->objectExpression->equals(this->objectExpression)
//		&& targetMemberEvaluateExpr->memberExpression->equals(this->memberExpression);
//}
//
//TypeExpression* const MemberEvaluateExpression::getType(Context *const& context) const
//{
//	return &TypeExpression::TYPE_MEMBER_EVALUATE_EXPRESSION;
//}
//
//StringExpression *const MemberEvaluateExpression::toString(Context *const& context)
//{
//	return this->objectExpression->toString() + "." + this->objectExpression->toString();
//}
//
//Expression* const MemberEvaluateExpression::getObjectExpression() const
//{
//	return this->objectExpression;
//}
//
//void MemberEvaluateExpression::setObjectExpression(Expression* const &expr)
//{
//	this->objectExpression = expr;
//}
//
//Expression* const MemberEvaluateExpression::getMemberExpression() const
//{
//	return this->memberExpression;
//}
//
//void MemberEvaluateExpression::setMemberExpression(Expression* const &expr)
//{
//	this->memberExpression = expr;
//}

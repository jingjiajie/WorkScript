//#include "MemberEvaluateExpression.h"
//#include "TypeExpression.h"
//#include "TypeMemberExpression.h"
//#include "Context.h"
//
//using namespace std;
//
//MemberEvaluateExpression::MemberEvaluateExpression(const std::shared_ptr<TermExpression> &objExpr, const std::shared_ptr<TermExpression> &memberExpr)
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
//const std::shared_ptr<Expression> MemberEvaluateExpression::evaluate(Context *context)
//{
//	auto prevExpr = this->context->getCurrentExpression();
//	auto evaluatedObjExpression = this->objectExpression->evaluate(expressionBind);
//	auto evaluatedMemberExpression = this->memberExpression->evaluate(expressionBind);
//	auto evaluatedObjType = evaluatedObjExpression->getType();
//	this->context->setCurrentExpression(evaluatedObjExpression); //设定当前表达式为ObjectExpression
//	ExpressionBind tmpExpressionBind;
//	shared_ptr<Expression> result;
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
//			auto newMe = shared_ptr<MemberEvaluateExpression>(new MemberEvaluateExpression(context, evaluatedObjExpression, evaluatedMemberExpression));
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
////bool MemberEvaluateExpression::match(const std::shared_ptr<Expression>& matchExpression, ExpressionBind * outExpressionBind) const
////{
////	auto matchType = matchExpression->getType();
////	if (!matchType->equals(this->shared_from_this()))return false;
////	auto matchMemberEvaluateExpression = (const std::shared_ptr<MemberEvaluateExpression>&)matchExpression;
////	ExpressionBind tmpExpressionBind;
////	if (!this->objectExpression->match(matchMemberEvaluateExpression->objectExpression, &tmpExpressionBind))return false;
////	if (!this->memberExpression->match(matchMemberEvaluateExpression->memberExpression, &tmpExpressionBind))return false;
////	*outExpressionBind = ExpressionBind(tmpExpressionBind);
////	return true;
////}
//
//bool MemberEvaluateExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
//{
//	if (!targetExpression->getType()->equals(this->getType())) {
//		return false;
//	}
//	auto targetMemberEvaluateExpr = dynamic_pointer_cast<MemberEvaluateExpression>(targetExpression);
//	return targetMemberEvaluateExpr->objectExpression->equals(this->objectExpression)
//		&& targetMemberEvaluateExpr->memberExpression->equals(this->memberExpression);
//}
//
//const std::shared_ptr<TypeExpression> MemberEvaluateExpression::getType() const
//{
//	return TypeExpression::MEMBER_EVALUATE_EXPRESSION;
//}
//
//const std::string MemberEvaluateExpression::toString() const
//{
//	return this->objectExpression->toString() + "." + this->objectExpression->toString();
//}
//
//const std::shared_ptr<TermExpression> MemberEvaluateExpression::getObjectExpression() const
//{
//	return this->objectExpression;
//}
//
//void MemberEvaluateExpression::setObjectExpression(const std::shared_ptr<TermExpression> &expr)
//{
//	this->objectExpression = expr;
//}
//
//const std::shared_ptr<TermExpression> MemberEvaluateExpression::getMemberExpression() const
//{
//	return this->memberExpression;
//}
//
//void MemberEvaluateExpression::setMemberExpression(const std::shared_ptr<TermExpression> &expr)
//{
//	this->memberExpression = expr;
//}

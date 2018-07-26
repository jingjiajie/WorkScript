#include "MemberEvaluateExpression.h"
#include "TypeExpression.h"
#include "TypeMemberExpression.h"
#include "Context.h"

using namespace std;

MemberEvaluateExpression::MemberEvaluateExpression(Context *const &context, const std::shared_ptr<const Expression> &objExpr, const std::shared_ptr<const Expression> &memberExpr)
	:TermExpression(context)
{
	this->setObjectExpression(objExpr);
	this->setMemberExpression(memberExpr);
}


MemberEvaluateExpression::~MemberEvaluateExpression()
{
}

const std::shared_ptr<const Expression> MemberEvaluateExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto prevExpr = this->context->getCurrentExpression();
	auto evaluatedObjExpression = this->objectExpression->evaluate(expressionBind);
	auto evaluatedMemberExpression = this->memberExpression->evaluate(expressionBind);
	auto evaluatedObjType = evaluatedObjExpression->getType();
	this->context->setCurrentExpression(evaluatedObjExpression); //设定当前表达式为ObjectExpression
	ExpressionBind tmpExpressionBind;
	shared_ptr<const Expression> result;
	//先匹配实例表达式，若匹配失败尝试匹配类静态表达式
	bool matchedInstantialExpr = false;
	for (auto &expr : evaluatedObjExpression->getInstantialExpressions()) {
		if (expr->match(evaluatedMemberExpression, &tmpExpressionBind)) {
			matchedInstantialExpr = true;
			result = expr->evaluate(tmpExpressionBind);
			break;
		}
	}
	if (!matchedInstantialExpr) {
		auto matchedMember = evaluatedObjType->matchStaticMemberExpression(evaluatedMemberExpression, &tmpExpressionBind);
		if (matchedMember == nullptr) {
			auto newMe = shared_ptr<const MemberEvaluateExpression>(new MemberEvaluateExpression(context, evaluatedObjExpression, evaluatedMemberExpression));
			result = newMe;
		}
		else {
			result = matchedMember->evaluate(tmpExpressionBind);
		}
	}
	this->context->setCurrentExpression(prevExpr); //恢复当前表达式
	return result;
}

bool MemberEvaluateExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	auto matchType = matchExpression->getType();
	if (!matchType->equals(this->shared_from_this()))return false;
	auto matchMemberEvaluateExpression = (const std::shared_ptr<const MemberEvaluateExpression>&)matchExpression;
	ExpressionBind tmpExpressionBind;
	if (!this->objectExpression->match(matchMemberEvaluateExpression->objectExpression, &tmpExpressionBind))return false;
	if (!this->memberExpression->match(matchMemberEvaluateExpression->memberExpression, &tmpExpressionBind))return false;
	*outExpressionBind = ExpressionBind(tmpExpressionBind);
	return true;
}

bool MemberEvaluateExpression::equals(const std::shared_ptr<const Expression>&target) const
{
	if (!target->getType()->equals(this->getType())) {
		return false;
	}
	auto targetMemberEvaluateExpression = (const std::shared_ptr<const MemberEvaluateExpression>&)target;
	return this->objectExpression->equals(targetMemberEvaluateExpression->objectExpression)
		&& this->memberExpression->equals(targetMemberEvaluateExpression->memberExpression);
}

const std::shared_ptr<const TypeExpression> MemberEvaluateExpression::getType() const
{
	return this->context->findType(TYPENAME_MEMBER_EVALUATE_EXPRESSION, false);
}

const std::string MemberEvaluateExpression::toString() const
{
	return this->objectExpression->toString() + "." + this->objectExpression->toString();
}

const std::shared_ptr<const Expression> MemberEvaluateExpression::getObjectExpression() const
{
	return this->objectExpression;
}

void MemberEvaluateExpression::setObjectExpression(const std::shared_ptr<const Expression> &expr)
{
	this->objectExpression = expr;
}

const std::shared_ptr<const Expression> MemberEvaluateExpression::getMemberExpression() const
{
	return this->memberExpression;
}

void MemberEvaluateExpression::setMemberExpression(const std::shared_ptr<const Expression> &expr)
{
	this->memberExpression = expr;
}

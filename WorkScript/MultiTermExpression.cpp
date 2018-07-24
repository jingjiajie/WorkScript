#include <vector>
#include "MultiTermExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "TypeExpression.h"

using namespace std;

MultiTermExpression::MultiTermExpression(Context * const & context, const std::vector<std::shared_ptr<const Expression>>& subExpressions)
	:PolynomialExpression(context)
{
	this->setSubExpressions(subExpressions);
}

MultiTermExpression::~MultiTermExpression()
{
}

const std::vector<std::shared_ptr<const Expression>>& MultiTermExpression::getSubExpressions() const
{
	return this->subExpressions;
}

void MultiTermExpression::setSubExpressions(const std::vector<std::shared_ptr<const Expression>> &subExpressions)
{
	this->subExpressions = subExpressions;
}

const std::shared_ptr<const Expression> MultiTermExpression::evaluate(const ExpressionBind &expressionBind) const
{
	vector<shared_ptr<const Expression>> subExpressionEvaluateResults;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		subExpressionEvaluateResults.push_back(this->subExpressions[i]->evaluate(expressionBind));
	}
	auto newMe = make_shared<const MultiTermExpression>(this->context, subExpressionEvaluateResults);
	auto matchResult = this->matchFirstUpInContextAndEvaluate(newMe);
	if (matchResult != nullptr) {
		return matchResult;
	}
	else {
		return newMe;
	}
}

bool MultiTermExpression::match(const std::shared_ptr<const Expression>& targetExpression, ExpressionBind * outExpressionBind) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
 	auto targetMultiValueExpression = (const std::shared_ptr<const MultiTermExpression> &)targetExpression;
	//���Ŀ����ӱ��ʽ����С���Լ����ӱ��ʽ��������ƥ��ʧ��
	if (targetMultiValueExpression->subExpressions.size() < this->subExpressions.size()) {
		return false;
	}		//���Ŀ����ʽ�ĸ��������Լ����ӱ��ʽ������������ƥ��
	else if (targetMultiValueExpression->subExpressions.size() == this->subExpressions.size()) {
		for (size_t i = 0; i < this->subExpressions.size(); i++) {
			if (!this->subExpressions[i]->match(targetMultiValueExpression->subExpressions[i], outExpressionBind)) {
				return false;
			}
		}
		return true;
	}
	else { //���Ŀ����ʽ���ӱ��ʽ���������Լ����ӱ��ʽ���������Լ������һ���ӱ��ʽ�Ǳ�������������ƥ��Ŀ��ʣ�������ӱ��ʽ
		size_t mySubExprCount = this->subExpressions.size();
		size_t targetSubExprCount = targetMultiValueExpression->subExpressions.size();
		auto myLastExpr = this->subExpressions[mySubExprCount - 1];
		if (!myLastExpr->getType()->equals(this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false)))return false;
		//��Ŀ����ʽ��ʣ��������µ�MultiTermExpression
		vector<shared_ptr<const Expression>> restExpressions;
		for (size_t i = mySubExprCount - 1; i < targetSubExprCount; i++) {
			restExpressions.push_back(targetMultiValueExpression->subExpressions[i]);
		}
		shared_ptr<MultiTermExpression> restMultiTermExpression(new MultiTermExpression(this->context, restExpressions));
		auto myLastVariable = dynamic_pointer_cast<const VariableExpression>(myLastExpr);
		myLastVariable->match(restMultiTermExpression, outExpressionBind);
		
		for (size_t i = 0; i < mySubExprCount - 1; i++) {
			if (!this->subExpressions[i]->match(targetMultiValueExpression->subExpressions[i], outExpressionBind)) {
				return false;
			}
		}
		return true;
	}
	return true;
}

bool MultiTermExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
	auto targetMultiValueExpression = (const std::shared_ptr<const MultiTermExpression> &)targetExpression;
	if (this->subExpressions.size() != targetMultiValueExpression->subExpressions.size())return false;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		if (!this->subExpressions[i]->equals(targetMultiValueExpression->subExpressions[i])) {
			return false;
		}
	}
	return true;
}

const std::shared_ptr<const TypeExpression> MultiTermExpression::getType() const
{
	return this->context->findType(TYPENAME_MULTI_TERM_EXPRESSION,false);
}

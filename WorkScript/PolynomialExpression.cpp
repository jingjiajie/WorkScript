#include <vector>
#include <sstream>
#include "PolynomialExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "TypeExpression.h"

using namespace std;

PolynomialExpression::PolynomialExpression(Context * const & context, const std::vector<std::shared_ptr<const Expression>>& subExpressions)
	:ValueExpression(context)
{
	this->setSubExpressions(subExpressions);
}

PolynomialExpression::PolynomialExpression(Context * const & context)
	:ValueExpression(context)
{
}

PolynomialExpression::~PolynomialExpression()
{
}

const std::vector<std::shared_ptr<const Expression>>& PolynomialExpression::getSubExpressions() const
{
	return this->subExpressions;
}

void PolynomialExpression::setSubExpressions(const std::vector<std::shared_ptr<const Expression>> &subExpressions)
{
	this->subExpressions = subExpressions;
}

std::shared_ptr<PolynomialExpression> PolynomialExpression::newInstance() const
{
	return make_shared<PolynomialExpression>(this->context);
}

const std::shared_ptr<const Expression> PolynomialExpression::evaluate(const ExpressionBind &expressionBind) const
{
	vector<shared_ptr<const Expression>> subExpressionEvaluateResults;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		subExpressionEvaluateResults.push_back(this->subExpressions[i]->evaluate(expressionBind));
	}
	auto newMe = this->newInstance();
	newMe->setSubExpressions(subExpressionEvaluateResults);
	auto matchResult = this->matchFirstUpInContextAndEvaluate(newMe);
	if (matchResult != nullptr) {
		return matchResult;
	}
	else {
		return newMe;
	}
}

bool PolynomialExpression::match(const std::shared_ptr<const Expression>& targetExpression, ExpressionBind * outExpressionBind) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
 	auto targetPolynomialExpression = (const std::shared_ptr<const PolynomialExpression> &)targetExpression;
	//���Ŀ����ӱ��ʽ����С���Լ����ӱ��ʽ��������ƥ��ʧ��
	if (targetPolynomialExpression->subExpressions.size() < this->subExpressions.size()) {
		return false;
	}		//���Ŀ����ʽ�ĸ��������Լ����ӱ��ʽ������������ƥ��
	else if (targetPolynomialExpression->subExpressions.size() == this->subExpressions.size()) {
		for (size_t i = 0; i < this->subExpressions.size(); i++) {
			if (!this->subExpressions[i]->match(targetPolynomialExpression->subExpressions[i], outExpressionBind)) {
				return false;
			}
		}
		return true;
	}
	else if(this->allowLastVariableMatchRests){ //Ŀ����ʽ���ӱ��ʽ���������Լ����ӱ��ʽ���������ҿ��������һ�����ƥ������ʣ����ʽ���������Լ������һ���ӱ��ʽ�Ǳ�������������ƥ��Ŀ��ʣ�������ӱ��ʽ
		size_t mySubExprCount = this->subExpressions.size();
		size_t targetSubExprCount = targetPolynomialExpression->subExpressions.size();
		auto myLastExpr = this->subExpressions[mySubExprCount - 1];
		if (!myLastExpr->getType()->equals(this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false)))return false;
		//��Ŀ����ʽ��ʣ��������µ�PolynomialExpression
		vector<shared_ptr<const Expression>> restExpressions;
		for (size_t i = mySubExprCount - 1; i < targetSubExprCount; i++) {
			restExpressions.push_back(targetPolynomialExpression->subExpressions[i]);
		}
		shared_ptr<PolynomialExpression> restMultiTermExpression(new PolynomialExpression(this->context, restExpressions));
		auto myLastVariable = dynamic_pointer_cast<const VariableExpression>(myLastExpr);
		myLastVariable->match(restMultiTermExpression, outExpressionBind);
		
		for (size_t i = 0; i < mySubExprCount - 1; i++) {
			if (!this->subExpressions[i]->match(targetPolynomialExpression->subExpressions[i], outExpressionBind)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool PolynomialExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
	auto targetMultiValueExpression = (const std::shared_ptr<const PolynomialExpression> &)targetExpression;
	if (this->subExpressions.size() != targetMultiValueExpression->subExpressions.size())return false;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		if (!this->subExpressions[i]->equals(targetMultiValueExpression->subExpressions[i])) {
			return false;
		}
	}
	return true;
}

const std::shared_ptr<const TypeExpression> PolynomialExpression::getType() const
{
	return this->context->findType(TYPENAME_POLYNOMIAL_EXPRESSION,false);
}

const std::string PolynomialExpression::toString() const
{
	stringstream ss;
	for (size_t i = 0; i < this->subExpressions.size(); i++) {
		auto &subStr = this->subExpressions[i];
		ss << subStr->toString();
		if (i != this->subExpressions.size() - 1) {
			ss << " ";
		}
	}
	return ss.str();
}

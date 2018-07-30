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
	auto flattedTargetSubExpressions = this->flatPolynomial(targetPolynomialExpression);

	vector<shared_ptr<const Expression>> cacheExpressions; //如果有的子表达式算出来是个多项式，则将多出来的项暂存在这里
	size_t mySubExprPos = 0;
	size_t targetSubExprPos = 0;
	bool isLastExpr = false;
	auto polynomialType = this->context->findType(TYPENAME_POLYNOMIAL_EXPRESSION, false);
	while ((mySubExprPos < this->subExpressions.size() || cacheExpressions.size() > 0)
		&& targetSubExprPos < flattedTargetSubExpressions.size()) {
		shared_ptr<const Expression> myNextEvaluatedSubExpr; //下一个要匹配的表达式
		shared_ptr<const Expression> targetNextSubExpr = flattedTargetSubExpressions[targetSubExprPos];
		if (cacheExpressions.size() > 0) {
			myNextEvaluatedSubExpr = cacheExpressions[0];
			cacheExpressions.erase(cacheExpressions.begin());
			if (cacheExpressions.size() == 0 && mySubExprPos == this->subExpressions.size() - 1) {
				isLastExpr = true;
			}
		}
		else {
			auto evaluatedExpr = subExpressions[mySubExprPos]->evaluate(*outExpressionBind);
			//如果子表达式计算得到多项式，则展开作为多个子表达式匹配
			if (evaluatedExpr->getType()->equals(polynomialType) || evaluatedExpr->getType()->isSubTypeOf(polynomialType)) {
				auto evaluatedPolynomialExpr = dynamic_pointer_cast<const PolynomialExpression>(evaluatedExpr);
				auto flattedEvaluatedPolynomialSubExpressions = flatPolynomial(evaluatedPolynomialExpr);
				myNextEvaluatedSubExpr = flattedEvaluatedPolynomialSubExpressions[0];
				if (flattedEvaluatedPolynomialSubExpressions.size() > 1) {
					for (size_t j = 1; j < flattedEvaluatedPolynomialSubExpressions.size(); j++) {
						cacheExpressions.push_back(flattedEvaluatedPolynomialSubExpressions[j]);
					}
				}
			}
			else {
				myNextEvaluatedSubExpr = evaluatedExpr;
			}
			if (mySubExprPos == this->subExpressions.size() - 1 && cacheExpressions.size() == 0) {
				isLastExpr = true;
			}
			mySubExprPos++;
		}

		//如果开启了最后一项变量匹配剩余所有表达式，则如果符合此条件，进行相应匹配
		if (this->allowLastVariableMatchRests 
			&& isLastExpr
			&& flattedTargetSubExpressions.size() - targetSubExprPos > 1
			&& myNextEvaluatedSubExpr->getType()->equals(this->context->findType(TYPENAME_VARIABLE_EXPRESSION, false))) {
			auto myLastVar = myNextEvaluatedSubExpr;
			vector<shared_ptr<const Expression>> restTargetExpressions;
			for (; targetSubExprPos < flattedTargetSubExpressions.size(); targetSubExprPos++) {
				restTargetExpressions.push_back(flattedTargetSubExpressions[targetSubExprPos]);
			}
			shared_ptr<PolynomialExpression> newLastPolynomial(new PolynomialExpression(this->context, restTargetExpressions));
			return myLastVar->match(newLastPolynomial, outExpressionBind);
		}
		else if (!myNextEvaluatedSubExpr->match(flattedTargetSubExpressions[targetSubExprPos], outExpressionBind)) {
			return false;
		}
		targetSubExprPos++;
	}
	return true;
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

const std::vector<std::shared_ptr<const Expression>> PolynomialExpression::flatPolynomial(const std::shared_ptr<const PolynomialExpression> &polynomialExpr) const
{
	vector<shared_ptr<const Expression>> resultExpressions;
	for (auto &curSubExpr : polynomialExpr->subExpressions) {
		if (curSubExpr->getType()->equals(this->context->findType(TYPENAME_POLYNOMIAL_EXPRESSION, false))) {
			auto flatResults = flatPolynomial(dynamic_pointer_cast<const PolynomialExpression>(curSubExpr));
			for (auto &flatResult : flatResults) {
				resultExpressions.push_back(flatResult);
			}
		}
		else {
			resultExpressions.push_back(curSubExpr);
		}
	}
	return resultExpressions;
}

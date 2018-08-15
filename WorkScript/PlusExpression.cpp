#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"

using namespace std;

PlusExpression::PlusExpression()
{

}

PlusExpression::PlusExpression(const std::shared_ptr<TermExpression> &leftExpression, const std::shared_ptr<TermExpression> &rightExpression)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}


PlusExpression::~PlusExpression()
{
}

const std::shared_ptr<TermExpression> PlusExpression::evaluate(Context *context)
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
	//��ʼ���ӷ����㡣
	auto numberType = TypeExpression::NUMBER_EXPRESSION;
	auto stringType = TypeExpression::STRING_EXPRESSION;

	if (evaluatedLeftExpr->getType()->equals(numberType) && evaluatedRightExpr->getType()->equals(numberType)) {
		return this->numberPlusNumber(dynamic_pointer_cast<NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<NumberExpression>(evaluatedRightExpr));
	}
	else {
		return this->exprPlusExpr(evaluatedLeftExpr, evaluatedRightExpr);
	}
	auto newMe = shared_ptr<PlusExpression>(new PlusExpression(evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

//bool PlusExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	//���ƥ����Ǽӷ����ʽ�������ұ��ʽƥ��
//	if (matchExpression->getType()->equals(this->getType())) {
//		auto matchPlusExpression = dynamic_pointer_cast<PlusExpression>(matchExpression);
//		return this->leftExpression->match(matchPlusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchPlusExpression->rightExpression, context);
//	}
//	else //���ƥ��Ĳ��Ǽӷ����ʽ
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		shared_ptr<VariableExpression> myVarExpr;
//		shared_ptr<TermExpression> myNonVarExpr;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//���Լ������ұ��ʽ��ֻ��һ���Ǳ���
//		if (evaluatedLeft->getType()->equals(variableType) && !evaluatedRight->getType()->equals(variableType))
//		{
//			myVarExpr = dynamic_pointer_cast<VariableExpression>(evaluatedLeft);
//			myNonVarExpr = dynamic_pointer_cast<TermExpression>(evaluatedRight);
//		}
//		else if (!evaluatedLeft->getType()->equals(variableType) && evaluatedRight->getType()->equals(variableType)) {
//			myNonVarExpr = dynamic_pointer_cast<TermExpression>(evaluatedLeft);
//			myVarExpr = dynamic_pointer_cast<VariableExpression>(evaluatedRight);
//		}
//		else {
//			return false;
//		}
//		//���������ʽ��Ϊƥ����ʽ-�Ǳ������ʽ
//		shared_ptr<MinusExpression> minusExpr(new MinusExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(minusExpr,context);
//	}
//}

const std::shared_ptr<TypeExpression> PlusExpression::getType() const
{
	return TypeExpression::PLUS_EXPRESSION;
}

const std::string PlusExpression::toString() const
{
	return this->leftExpression->toString() + "+" + this->rightExpression->toString();
}

std::shared_ptr<NumberExpression> PlusExpression::numberPlusNumber(const std::shared_ptr<NumberExpression>&left, const std::shared_ptr<NumberExpression>&right) const
{
	shared_ptr<NumberExpression> newNumExpr(new NumberExpression(left->getValue() + right->getValue()));
	return newNumExpr;
}

std::shared_ptr<StringExpression> PlusExpression::exprPlusExpr(const std::shared_ptr<Expression>&left, const std::shared_ptr<Expression>&right) const
{
	string leftEvaluatedString = left->toString();
	string rightEvaluatedString = right->toString();
	shared_ptr<StringExpression> newStringExpr(new StringExpression(leftEvaluatedString + rightEvaluatedString));
	return newStringExpr;
}
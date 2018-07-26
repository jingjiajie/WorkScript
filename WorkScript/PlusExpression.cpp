#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "NumberExpression.h"
#include "StringExpression.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "ParentheseExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"

using namespace std;

PlusExpression::PlusExpression(Context * const & context)
	:TermExpression(context)
{

}

PlusExpression::PlusExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression)
	: TermExpression(context)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}


PlusExpression::~PlusExpression()
{
}

const std::shared_ptr<const Expression> PlusExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto evaluatedLeftExpr = this->leftExpression->evaluate(expressionBind);
	auto evaluatedRightExpr = this->rightExpression->evaluate(expressionBind);
	//��ʼ���ӷ����㡣
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	auto stringType = this->context->findType(TYPENAME_STRING_EXPRESSION, false);

	if (evaluatedLeftExpr->getType()->equals(numberType) && evaluatedRightExpr->getType()->equals(numberType)) {
		return this->numberPlusNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeftExpr), dynamic_pointer_cast<const NumberExpression>(evaluatedRightExpr));
	}
	else {
		return this->exprPlusExpr(evaluatedLeftExpr, evaluatedRightExpr);
	}
	auto newMe = shared_ptr<const PlusExpression>(new PlusExpression(this->context, evaluatedLeftExpr, evaluatedRightExpr));
	return newMe;
}

bool PlusExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	//���ƥ����Ǽӷ����ʽ�������ұ��ʽƥ��
	if (matchExpression->getType()->equals(this->getType())) {
		auto matchPlusExpression = dynamic_pointer_cast<const PlusExpression>(matchExpression);
		return this->leftExpression->match(matchPlusExpression->leftExpression, outExpressionBind)
			&& this->rightExpression->match(matchPlusExpression->rightExpression, outExpressionBind);
	}
	else //���ƥ��Ĳ��Ǽӷ����ʽ
	{
		auto variableType = this->context->findType(TYPENAME_VARIABLE_EXPRESSION,false);
		shared_ptr<const VariableExpression> myVarExpr;
		shared_ptr<const ValueExpression> myNonVarExpr;
		auto mappedLeft = outExpressionBind->getMappedExpression(this->leftExpression);
		if (mappedLeft == nullptr)mappedLeft = this->leftExpression;
		auto mappedRight = outExpressionBind->getMappedExpression(this->rightExpression);
		if (mappedRight == nullptr)mappedRight = this->rightExpression;
		//���Լ������ұ��ʽ��ֻ��һ���Ǳ���
		if (mappedLeft->getType()->equals(variableType) && !mappedRight->getType()->equals(variableType))
		{
			myVarExpr = dynamic_pointer_cast<const VariableExpression>(mappedLeft);
			myNonVarExpr = dynamic_pointer_cast<const ValueExpression>(mappedRight);
		}
		else if (!mappedLeft->getType()->equals(variableType) && mappedRight->getType()->equals(variableType)) {
			myNonVarExpr = dynamic_pointer_cast<const ValueExpression>(mappedLeft);
			myVarExpr = dynamic_pointer_cast<const VariableExpression>(mappedRight);
		}
		else {
			return false;
		}
		//���������ʽ��Ϊƥ����ʽ-�Ǳ������ʽ
		shared_ptr<const MinusExpression> minusExpr(new MinusExpression(this->context, matchExpression, myNonVarExpr));
		outExpressionBind->addExpressionMap(myVarExpr, minusExpr);
		return true;
	}
}

bool PlusExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetPlusExpression = dynamic_pointer_cast<const PlusExpression>(target);
	return targetPlusExpression->leftExpression->equals(this->leftExpression)
		&& targetPlusExpression->rightExpression->equals(this->rightExpression);
}

const std::shared_ptr<const TypeExpression> PlusExpression::getType() const
{
	return this->context->findType(TYPENAME_PLUS_EXPRESSION,false);
}

const std::string PlusExpression::toString() const
{
	return this->leftExpression->toString() + "+" + this->rightExpression->toString();
}

const std::shared_ptr<const Expression> PlusExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void PlusExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> PlusExpression::getRightExpression() const
{
	return this->rightExpression;
}

void PlusExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

std::shared_ptr<const NumberExpression> PlusExpression::numberPlusNumber(const std::shared_ptr<const NumberExpression>&left, const std::shared_ptr<const NumberExpression>&right) const
{
	shared_ptr<const NumberExpression> newNumExpr(new NumberExpression(this->context, left->getValue() + right->getValue()));
	return newNumExpr;
}

std::shared_ptr<const StringExpression> PlusExpression::exprPlusExpr(const std::shared_ptr<const Expression>&left, const std::shared_ptr<const Expression>&right) const
{
	string leftEvaluatedString = left->toString();
	string rightEvaluatedString = right->toString();
	shared_ptr<const StringExpression> newStringExpr(new StringExpression(this->context, leftEvaluatedString + rightEvaluatedString));
	return newStringExpr;
}
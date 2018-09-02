#include "PlusExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"
#include "Program.h"

using namespace std;

PlusExpression::~PlusExpression()
{
}

//const Pointer<Expression> PlusExpression::evaluate(Context *const& context)
//{
//	Pointer<Expression> evaluatedLeftExpr =  this->leftExpression->evaluate(context);
//	Pointer<Expression> evaluatedRightExpr =  this->rightExpression->evaluate(context);
//	auto leftType = evaluatedLeftExpr->getType(context);
//	auto rightType = evaluatedRightExpr->getType(context);
//	//��ʼ���ӷ����㡣
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = TypeExpression::STRING_EXPRESSION;
//
//	if (leftType->isSubTypeOf(context, numberType) && rightType->isSubTypeOf(context, numberType)) {
//		return ((const Pointer<NumberExpression>)evaluatedLeftExpr)->plus((const Pointer<NumberExpression>)evaluatedRightExpr);
//	}
//	else {
//		return this->exprPlusExpr(context, evaluatedLeftExpr, evaluatedRightExpr);
//	}
//}

//bool PlusExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	//���ƥ����Ǽӷ����ʽ�������ұ��ʽƥ��
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchPlusExpression = (const Pointer<PlusExpression> &)(matchExpression);
//		return this->leftExpression->match(matchPlusExpression->leftExpression, context)
//			&& this->rightExpression->match(matchPlusExpression->rightExpression, context);
//	}
//	else //���ƥ��Ĳ��Ǽӷ����ʽ
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		Pointer<VariableExpression> myVarExpr;
//		Pointer<Expression>  myNonVarExpr;
//		auto evaluatedLeft = this->leftExpression->evaluate(context);
//		auto evaluatedRight = this->rightExpression->evaluate(context);
//		//���Լ������ұ��ʽ��ֻ��һ���Ǳ���
//		if (evaluatedLeft->getType(context)->equals(variableType) && !evaluatedRight->getType(context)->equals(variableType))
//		{
//			myVarExpr = (const Pointer<VariableExpression> &)(evaluatedLeft);
//			myNonVarExpr = (const Pointer<Expression> &)(evaluatedRight);
//		}
//		else if (!evaluatedLeft->getType(context)->equals(variableType) && evaluatedRight->getType(context)->equals(variableType)) {
//			myNonVarExpr = (const Pointer<Expression> &)(evaluatedLeft);
//			myVarExpr = (const Pointer<VariableExpression> &)(evaluatedRight);
//		}
//		else {
//			return false;
//		}
//		//���������ʽ��Ϊƥ����ʽ-�Ǳ������ʽ
//		Pointer<MinusExpression> minusExpr(new MinusExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(minusExpr,context);
//	}
//}

const Pointer<TypeExpression> PlusExpression::getType(Context *const& context) const
{
	return TypeExpression::PLUS_EXPRESSION;
}

const Pointer<StringExpression> PlusExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> sign(new StringExpression(L"+", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<NumberExpression> PlusExpression::numberCalcNumber(Context * const context, const Pointer<NumberExpression> & left, const Pointer<NumberExpression> & right) const
{
	return left->plus(right);
}

const Pointer<Expression> PlusExpression::expressionCalcExpression(Context * context, const Pointer<Expression>& left, const Pointer<Expression>& right)
{
	Pointer<StringExpression> leftEvaluatedString = left->toString(context);
	Pointer<StringExpression> rightEvaluatedString = right->toString(context);
	Pointer<StringExpression>exprs[] = { leftEvaluatedString,rightEvaluatedString };
	auto result = StringExpression::combine(exprs, 2);
	return result;
}
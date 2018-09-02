#include <sstream>
#include "MultiplyExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "Context.h"
#include "VariableExpression.h"
#include "DivideExpression.h"
#include "Program.h"

using namespace std;

MultiplyExpression::~MultiplyExpression()
{
}

//const Pointer<Expression> MultiplyExpression::evaluate(Context *const& context)
//{
//	auto evaluatedLeftExpr = this->leftExpression->evaluate(context);
//	auto evaluatedRightExpr = this->rightExpression->evaluate(context);
//	//开始做乘法运算。
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	auto stringType = TypeExpression::STRING_EXPRESSION;
//
//	if (evaluatedLeftExpr->getType(context)->isSubTypeOf(context, numberType) && evaluatedRightExpr->getType(context)->isSubTypeOf(context, numberType)) {
//			return this->numberMultiplyNumber(context, (const Pointer<DoubleExpression>&)(evaluatedLeftExpr), (const Pointer<DoubleExpression>&)(evaluatedRightExpr));
//	}
//	//else if (evaluatedLeftExpr->getType(context)->equals(context, stringType)) {
//	//	if (evaluatedRightExpr->getType(context)->equals(context, numberType)) {
//	//		return this->stringMultiplyNumber(context, (const Pointer<StringExpression>&)(evaluatedLeftExpr), (const Pointer<DoubleExpression>&)(evaluatedRightExpr));
//	//	}
//	//}
//	auto newMe = new MultiplyExpression(evaluatedLeftExpr, evaluatedRightExpr);
//	return newMe;
//}
//
//bool MultiplyExpression::match(const Pointer<Expression>& matchExpression, Context *const& context) const
//{
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchMultiplyExpression = (const Pointer<MultiplyExpression>&)(matchExpression);
//		return this->leftExpression->match(matchMultiplyExpression->leftExpression, context)
//			&& this->rightExpression->match(matchMultiplyExpression->rightExpression, context);
//	}
//	else //如果匹配的不是乘法表达式
//	{
//		auto variableType = TypeExpression::VARIABLE_EXPRESSION;
//		Pointer<VariableExpression> myVarExpr;
//		Pointer<Expression>  myNonVarExpr;
//		//且自己的左右表达式中只有一个是变量
//		if (this->leftExpression->getType(context)->equals(variableType) && !this->rightExpression->getType(context)->equals(variableType))
//		{
//			myVarExpr = (const Pointer<VariableExpression>&)(this->leftExpression);
//			myNonVarExpr = (const Pointer<Expression>&)(this->rightExpression);
//		}
//		else if (!this->leftExpression->getType(context)->equals(variableType) && this->rightExpression->getType(context)->equals(variableType)) {
//			myNonVarExpr = (const Pointer<Expression>&)(this->leftExpression);
//			myVarExpr = (const Pointer<VariableExpression>&)(this->rightExpression);
//		}
//		else {
//			return false;
//		}
//		//将变量表达式绑定为匹配表达式-非变量表达式
//		Pointer<DivideExpression> divideExpr(new DivideExpression(matchExpression, myNonVarExpr));
//		return myVarExpr->match(divideExpr, context);
//	}
//}

const Pointer<TypeExpression> MultiplyExpression::getType(Context *const& context) const
{
	return TypeExpression::MULTIPLY_EXPRESSION;
}

const Pointer<StringExpression> MultiplyExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> sign(new StringExpression(L"*", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<NumberExpression> MultiplyExpression::numberCalcNumber(Context *const context, const Pointer<NumberExpression>&left, const Pointer<NumberExpression>&right)const
{
	return left->multiply(right);
}

//Pointer<StringExpression> MultiplyExpression::stringMultiplyNumber(Context *const &context, const Pointer<StringExpression>&left, const Pointer<DoubleExpression>&right) const
//{
//	auto oriString = left->getValue();
//	double times = right->getValue();
//	wstringstream ss;
//	for (int i = 0; i < times; ++i) {
//		ss << oriString;
//	}
//	wstring resultStr = ss.str();
//	return StringExpression::newInstance(resultStr.c_str());
//}

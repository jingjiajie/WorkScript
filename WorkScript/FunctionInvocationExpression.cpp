#include "FunctionInvocationExpression.h"
#include "ListExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "Program.h"
#include "ParameterExpression.h"
#include "StringExpression.h"
#include "FunctionExpression.h"
#include <sstream>
#include <boost/locale.hpp>

using namespace std;

FunctionInvocationExpression::~FunctionInvocationExpression()
{
}

const Pointer<Expression> FunctionInvocationExpression::evaluate(Context *const& context)
{
	Pointer<Expression> evaluatedLeft = this->getFunctionExpression(context);
	Pointer<ParameterExpression> evaluatedParams = this->getEvaluatedParameters(context);

	//开始调用
	auto ret = ((const Pointer<FunctionExpression>)evaluatedLeft)->invoke(evaluatedParams);
	return ret;
}

bool FunctionInvocationExpression::equals(Context *const &context, const Pointer<Expression> &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetFunctionInvocationExpression = (const Pointer<FunctionInvocationExpression> &)(target);
	if (!targetFunctionInvocationExpression->leftExpression->equals(context,this->leftExpression))return false;
	if (!this->parameters->equals(context,targetFunctionInvocationExpression->parameters))return false;
	return true;
}

const Pointer<FunctionExpression> FunctionInvocationExpression::getFunctionExpression(Context *const context) const
{
	Pointer<Expression> evaluatedLeft = this->leftExpression->evaluate(context);
	if (!evaluatedLeft->getType(context)->equals(context, TypeExpression::FUNCTION_EXPRESSION)) {
		Pointer<StringExpression> leftStrExpr = evaluatedLeft->toString(context);
		wstring leftName(leftStrExpr->getValue());
		wstring str = (leftName + L"不是函数！");
		throw std::move(UninvocableException(str.c_str()));
	}
	return evaluatedLeft;
}

const Pointer<ParameterExpression> FunctionInvocationExpression::getEvaluatedParameters(Context * const context)
{
	return this->parameters->evaluate(context);
}

const Pointer<TypeExpression> FunctionInvocationExpression::getType(Context *const& context) const
{
	return TypeExpression::FUNCTION_INVOCATION_EXPRESSION;
}

const Pointer<StringExpression> FunctionInvocationExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> leftParenthese(new StringExpression(L"(", ReleaseStrategy::DELETE));
	static Pointer<StringExpression> rightParenthese(new StringExpression(L")", ReleaseStrategy::DELETE));
	Pointer<StringExpression> leftStr =  this->leftExpression->toString(context);
	Pointer<StringExpression> paramStr =  this->parameters->toString(context);
	Pointer<StringExpression>strs[] = { leftStr,leftParenthese,paramStr,rightParenthese };
	return StringExpression::combine(strs, 4);
}

void FunctionInvocationExpression::compile(CompileContext *const &context)
{
	this->leftExpression->compile(context);
	this->parameters->compile(context);
}
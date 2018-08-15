#include "FunctionInvocationExpression.h"
#include "ListExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "FunctionExpression.h"
#include <sstream>

using namespace std;

FunctionInvocationExpression::FunctionInvocationExpression()
{
}


FunctionInvocationExpression::~FunctionInvocationExpression()
{
}

const std::shared_ptr<TermExpression> FunctionInvocationExpression::evaluate(Context *context)
{
	shared_ptr<TermExpression> finalLeft;
	auto evaluatedLeft = this->leftExpression->evaluate(context);
	if (evaluatedLeft->getType()->equals(TypeExpression::FUNCTION_EXPRESSION)) {
		finalLeft = evaluatedLeft;
	}
	else if(evaluatedLeft->getType()->equals(TypeExpression::VARIABLE_EXPRESSION)){
		auto leftVar = (const shared_ptr<VariableExpression>&)evaluatedLeft;
		finalLeft = leftVar->evaluate(context);
	}
	else {
		finalLeft = evaluatedLeft;
	}
	
	if (!finalLeft->getType()->equals(TypeExpression::FUNCTION_EXPRESSION)) {
		throw UninvocableException(finalLeft->toString() + "²»ÊÇº¯Êý£¡");
	}
	auto funcExpr = (const shared_ptr<FunctionExpression>&)finalLeft;
	auto evaluatedParams = (const shared_ptr<ListExpression>&)this->parameters->evaluate(context);
	auto ret = funcExpr->invoke(evaluatedParams);
	
	if (ret != nullptr) {
		return ret;
	}
	else {
		auto newMe = shared_ptr<FunctionInvocationExpression>(new FunctionInvocationExpression());
		newMe->setLeftExpression(finalLeft);
		newMe->setParameters((const shared_ptr<ListExpression>&)this->parameters->evaluate(context));
		return (const shared_ptr<FunctionInvocationExpression>&)this->shared_from_this();
	}
}

bool FunctionInvocationExpression::equals(const std::shared_ptr<TermExpression> &target) const
{
	if (!target->getType()->equals(this->getType())) {
		return false;
	}
	auto targetFunctionInvocationExpression = dynamic_pointer_cast<FunctionInvocationExpression>(target);
	if (!targetFunctionInvocationExpression->leftExpression->equals(this->leftExpression))return false;
	if (!this->parameters->equals(targetFunctionInvocationExpression->parameters))return false;
	return true;
}

const std::shared_ptr<TypeExpression> FunctionInvocationExpression::getType() const
{
	return TypeExpression::FUNCTION_INVOCATION_EXPRESSION;
}

const std::string FunctionInvocationExpression::toString() const
{
	stringstream ss;
	ss << this->leftExpression->toString();
	ss << "(";
	ss << this->parameters->toString();
	ss << ")";
	return ss.str();
}

void FunctionInvocationExpression::compile(CompileContext * context)
{
	this->leftExpression->compile(context);
	this->parameters->compile(context);
}

const std::shared_ptr<TermExpression> FunctionInvocationExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void FunctionInvocationExpression::setLeftExpression(const std::shared_ptr<TermExpression>& left)
{
	this->leftExpression = left;
}

const std::shared_ptr<ListExpression> FunctionInvocationExpression::getParameters() const
{
	return this->parameters;
}

void FunctionInvocationExpression::setParameters(const std::shared_ptr<ListExpression>& parameters)
{
	this->parameters = parameters;
}

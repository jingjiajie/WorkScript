#include "BinaryOperatorExpression.h"
#include "TypeExpression.h"
#include "Program.h"

using namespace std;

BinaryOperatorExpression::~BinaryOperatorExpression()
{
	if (this->leftExpression) this->leftExpression->releaseLiteral();
	if (this->rightExpression) this->rightExpression->releaseLiteral();
}

bool BinaryOperatorExpression::equals(Context *const &context, Expression* const &targetExpression) const
{
	if (!targetExpression->getType(context)->equals(context,this->getType(context))) {
		return false;
	}
	auto targetExpressionOfMyType = (BinaryOperatorExpression *const&)targetExpression;

	return this->leftExpression->equals(context, targetExpressionOfMyType->leftExpression) 
		&& this->rightExpression->equals(context, targetExpressionOfMyType->rightExpression);
}

void BinaryOperatorExpression::compile(CompileContext *const &context)
{
	this->leftExpression->compile(context);
	this->rightExpression->compile(context);
}
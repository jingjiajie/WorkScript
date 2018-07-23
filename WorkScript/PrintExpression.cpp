#include "PrintExpression.h"
#include "Context.h"
#include "TypeExpression.h"
#include "MemberEvaluateExpression.h"
#include "MultiTermExpression.h"
#include "UnimplementedException.h"
#include "IdentifierExpression.h"
#include "ParentheseExpression.h"
#include "StringExpression.h"
#include "Context.h"

using namespace std;

PrintExpression::PrintExpression(Context *const &context)
	:PolynomialExpression(context)
{
}

PrintExpression::PrintExpression(Context * const &context, const std::shared_ptr<const Expression> &expression)
	:PolynomialExpression(context)
{
	this->setExpression(expression);
}

PrintExpression::~PrintExpression()
{
}

const std::shared_ptr<const Expression> PrintExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto mappedExpression = expressionBind.getMappedExpression(this->expression);
	if (mappedExpression == nullptr) {
		mappedExpression = this->expression;
	}
	shared_ptr<const MultiTermExpression> toStringFunctionExpression(new MultiTermExpression(this->context, { shared_ptr<const Expression>(new IdentifierExpression(this->context, "toString")), shared_ptr<const ParentheseExpression>(new ParentheseExpression(this->context, nullptr)) }));
	shared_ptr<const MemberEvaluateExpression> objToStringEvaluateExpression(new MemberEvaluateExpression(this->context, mappedExpression, toStringFunctionExpression));
	auto result = (shared_ptr<const StringExpression>&)objToStringEvaluateExpression->evaluate(expressionBind);
	cout << result->getValue();
	shared_ptr<const PrintExpression> newMe(new PrintExpression(this->context,mappedExpression));
	return newMe;
}

bool PrintExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	throw UnimplementedException();
}

bool PrintExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetPrintExression = (const std::shared_ptr<const Expression> &)target;
	return this->expression->equals(targetPrintExression);
}

const std::shared_ptr<const TypeExpression> PrintExpression::getType() const
{
	return this->context->findType(TYPENAME_PRINT_EXPRESSION,false);
}

const std::shared_ptr<const Expression> PrintExpression::getExpression() const
{
	return this->expression;
}
 
void PrintExpression::setExpression(const std::shared_ptr<const Expression> &expr)
{
	this->expression = expr;
}

#include "GetTypeExpression.h"
#include "TypeExpression.h"
#include "Context.h"

using namespace std;

GetTypeExpression::GetTypeExpression(Context *const &context, const std::shared_ptr<const Expression> &expression)
	:TermExpression(context)
{
	this->setExpression(expression);
}


GetTypeExpression::~GetTypeExpression()
{
}

const std::shared_ptr<const Expression> GetTypeExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto mappedExpression = expressionBind.getMappedExpression(this->expression);
	if (mappedExpression == nullptr) {
		mappedExpression = this->expression;
	}
	return mappedExpression->evaluate(expressionBind)->getType();
}

bool GetTypeExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	return this->expression->match(matchExpression,outExpressionBind);
}

bool GetTypeExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetGetTypeExpression = (const std::shared_ptr<const GetTypeExpression> &)target;
	return this->expression->equals(targetGetTypeExpression->expression);
}

const std::shared_ptr<const TypeExpression> GetTypeExpression::getType() const
{
	auto ret = this->context->findType(TYPENAME_GET_TYPE_EXPRESSION,false);
	return ret;
}

const std::string GetTypeExpression::toString() const
{
	return "GetTypeExpression(" + this->expression->toString() + ")";
}

const std::shared_ptr<const Expression> GetTypeExpression::getExpression() const
{
	return this->expression;
}

void GetTypeExpression::setExpression(const std::shared_ptr<const Expression> &expr)
{
	this->expression = expr;
}

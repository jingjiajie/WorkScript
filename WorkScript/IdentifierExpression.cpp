#include "IdentifierExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

IdentifierExpression::IdentifierExpression(Context *const &context,const std::string& identifierName)
	:PolynomialExpression(context)
{
	this->setIdentifierName(identifierName);
}

IdentifierExpression::~IdentifierExpression()
{

}

const std::string & IdentifierExpression::getIdentifierName() const
{
	return this->identifierName;
}

void IdentifierExpression::setIdentifierName(const std::string & name)
{
	this->identifierName = name;
}

bool IdentifierExpression::match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const
{
	auto matchType = matchExpression->getType();
	auto identifierExpressionType = this->context->findType(TYPENAME_IDENTIFIER_EXPRESSION,false);
	if (matchType->equals(identifierExpressionType)) {
		const IdentifierExpression *const &matchIdentifierExpression = (const IdentifierExpression *const &)matchExpression;
		if (matchIdentifierExpression->getIdentifierName() != this->identifierName) return false;
		else return true;
	}
	return false;
}

bool IdentifierExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	const IdentifierExpression *const &targetIdentifierExpression = (const IdentifierExpression *const &)targetExpression;
	return targetIdentifierExpression->getIdentifierName() == this->identifierName;
}

const std::shared_ptr<const TypeExpression> IdentifierExpression::getType() const
{
	auto ret = this->context->findType(TYPENAME_IDENTIFIER_EXPRESSION, false);
	return ret;
}

const shared_ptr<const Expression> IdentifierExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto result = this->matchFirstUpInContextAndEvaluate(this->shared_from_this());
	if (result == nullptr) {
		return this->shared_from_this();
	}
	else {
		return result;
	}
}

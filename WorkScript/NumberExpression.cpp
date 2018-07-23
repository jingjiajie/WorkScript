#include "NumberExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "MultiTermExpression.h"
#include "IdentifierExpression.h"
#include "RelationExpression.h"
#include "ParentheseExpression.h"

using namespace std;

NumberExpression::NumberExpression(Context *const &context)
	:PolynomialExpression(context)
{

}

NumberExpression::NumberExpression(Context * const & context, const double & value)
	:NumberExpression(context)
{
	this->setValue(value);
}


NumberExpression::~NumberExpression()
{
}

const std::shared_ptr<const Expression> NumberExpression::evaluate(const ExpressionBind &) const
{
	return this->shared_from_this();
}

bool NumberExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	return this->equals(matchExpression);
}

bool NumberExpression::equals(const std::shared_ptr<const Expression>&matchExpression) const
{
	//如果类型不同，匹配失败
	if (!matchExpression->getType()->equals(this->getType())) {
		return false;
	}
	//类型相同，比较值是否相同
	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
	return matchValueExpression->getValue() == this->getValue();
}

const std::shared_ptr<const TypeExpression> NumberExpression::getType() const
{
	return this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
}

const double NumberExpression::getValue() const
{
	return this->value;
}

void NumberExpression::setValue(const double &value)
{
	//SPCEXPRESSION toStringLeft(new MultiTermExpression(this->context, { SPCEXPRESSION(new IdentifierExpression(this->context, "toString")), SPCEXPRESSION(new ParentheseExpression(this->context, nullptr)) }));
	//this->instantialExpressions.insert(this->instantialExpressions.begin(),
	//	SPCEXPRESSION(new TypeMemberExpression(this->context, this->getType(), Authority::PUBLIC,
	//		SPCEXPRESSION(new RelationExpression(this->context,
	//			toStringLeft,
	//			SPCEXPRESSION(new StringExpression(this->context))->setValue(to_string(value)))
	//		))));
	this->value = value;
}

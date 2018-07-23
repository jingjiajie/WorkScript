#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "MultiTermExpression.h"
#include "IdentifierExpression.h"
#include "RelationExpression.h"
#include "ParentheseExpression.h"

using namespace std;

StringExpression::StringExpression(Context *const &context)
	:PolynomialExpression(context)
{

}

StringExpression::StringExpression(Context * const & context, const std::string & value)
	:StringExpression(context)
{
	this->setValue(value);
}


StringExpression::~StringExpression()
{
}

const std::shared_ptr<const Expression> StringExpression::evaluate(const ExpressionBind &) const
{
	return this->shared_from_this();
}

bool StringExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	return this->equals(matchExpression);
}

bool StringExpression::equals(const std::shared_ptr<const Expression>&matchExpression) const
{
	//如果类型不同，匹配失败
	if (!matchExpression->getType()->equals(this->getType())) {
		return false;
	}
	//类型相同，比较值是否相同
	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
	return matchValueExpression->getValue() == this->getValue();
}

const std::shared_ptr<const TypeExpression> StringExpression::getType() const
{
	return this->context->findType(TYPENAME_STRING_EXPRESSION,false);
}

const std::string StringExpression::getValue() const
{
	return this->value;
}

void StringExpression::setValue(const std::string & value)
{
	//SPCEXPRESSION toStringLeft(new MultiTermExpression(this->context, { SPCEXPRESSION(new IdentifierExpression(this->context, "toString")), SPCEXPRESSION(new ParentheseExpression(this->context, nullptr)) }));
	//this->instantialExpressions.insert(this->instantialExpressions.begin(),
	//	SPCEXPRESSION(new TypeMemberExpression(this->context, this->getType(), Authority::PUBLIC,
	//		SPCEXPRESSION(new RelationExpression(this->context,
	//			toStringLeft,
	//			this->shared_from_this())
	//))));
	//
	this->value = value;
}

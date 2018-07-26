#include <sstream>
#include "FunctionExpression.h"

using namespace std;

FunctionExpression::FunctionExpression(Context *const &context,bool direct, const std::vector<std::shared_ptr<const Expression>> &subExpressions)
	:FunctionExpression(context,direct)
{
	this->setSubExpressions(subExpressions);
}

FunctionExpression::FunctionExpression(Context * const & context, bool direct)
	:PolynomialExpression(context)
{
	this->direct = direct;
	this->allowLastVariableMatchRests = false;
}


FunctionExpression::~FunctionExpression()
{
}

std::shared_ptr<PolynomialExpression> FunctionExpression::newInstance() const
{
	return shared_ptr<FunctionExpression>(new FunctionExpression(this->context, this->direct));
}

const std::string FunctionExpression::toString() const
{
	stringstream ss;
	size_t subExpressionCount = this->subExpressions.size();
	for (size_t i = 0; i < subExpressionCount; i++) {
		if (i == 0 && this->direct) {
			ss << this->subExpressions[i]->toString();
		}
		else {
			ss << "(" << this->subExpressions[i]->toString() << ")";
		}

		if (i != subExpressionCount - 1) {
			ss << " ";
		}
	}
	return ss.str();
}

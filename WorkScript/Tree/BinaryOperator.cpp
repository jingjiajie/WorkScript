#include "BinaryOperator.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "Function.h"

using namespace std;
using namespace WorkScript;

BinaryOperator::~BinaryOperator()
{
	delete this->leftExpression;
	delete this->rightExpression;
}

std::wstring WorkScript::BinaryOperator::toString() const
{
	auto left = this->leftExpression->toString();
	auto right = this->rightExpression->toString();
	return left + this->getOperatorString() + right;
}

#include "stdafx.h"
#include "BinaryOperatorExpression.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "Function.h"
#include "IntegerExpression.h"
#include "FloatExpression.h"

using namespace std;
using namespace WorkScript;

BinaryOperatorExpression::~BinaryOperatorExpression()
{
	delete this->leftExpression;
	delete this->rightExpression;
}

std::wstring WorkScript::BinaryOperatorExpression::toString() const
{
	auto left = this->leftExpression->toString();
	auto right = this->rightExpression->toString();
	return left + this->getOperatorString() + right;
}

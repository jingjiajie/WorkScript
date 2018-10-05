#include "stdafx.h"
#include "BinaryCompareExpression.h"
#include "BooleanExpression.h"
#include "UncomparableException.h"

using namespace std;
using namespace WorkScript;

BinaryCompareExpression::~BinaryCompareExpression()
{
}

Type * WorkScript::BinaryCompareExpression::getType() const
{
	return &Type::BOOLEAN;
}
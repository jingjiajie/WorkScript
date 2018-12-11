#include "stdafx.h"
#include "BinaryCompareExpression.h"
#include "UncomparableException.h"

using namespace std;
using namespace WorkScript;

BinaryCompareExpression::~BinaryCompareExpression()
{
}

Type * WorkScript::BinaryCompareExpression::getType() const
{
	return program->getType(TYPENAME_BOOLEAN);
}
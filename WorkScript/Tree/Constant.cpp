#include "Constant.h"

using namespace std;
using namespace WorkScript;

Type* Constant::getType(WorkScript::InstantializeContext *context) const
{
    return this->getType();
}

ExpressionType Constant::getExpressionType() const
{
    return ExpressionType::CONSTANT_EXPRESSION;
}
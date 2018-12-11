#include "stdafx.h"
#include "UnaryOperatorExpression.h"
#include "Type.h"
#include "Overload.h"
#include "Function.h"

using namespace WorkScript;

UnaryOperatorExpression::~UnaryOperatorExpression()
{
	delete this->subExpression;
}

//bool UnaryOperatorExpression::equals(Expression *target) const
//{
//	return target == this;
//}

std::wstring WorkScript::UnaryOperatorExpression::toString() const
{
	return this->getOperatorString() + this->subExpression->toString();
}

Type * WorkScript::UnaryOperatorExpression::getType() const
{
	Type *subExprType = this->subExpression->getType();
	return subExprType->inferReturnType(this->getOperatorFunctionName(), {});
}

GenerateResult WorkScript::UnaryOperatorExpression::generateIR(GenerateContext * context)
{
	Type *subType = this->subExpression->getType();
	Function *func = subType->getMemberFunction(this->getOperatorFunctionName());
	Overload *overload = func->getOverload({ });
	auto builder = context->getIRBuilder();
	return builder->CreateCall(overload->getLLVMFunction(context), {}, "tmp");
}

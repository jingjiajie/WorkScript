#include "stdafx.h"
#include "BooleanExpression.h"
#include "StringExpression.h"
#include "Type.h"
#include "Program.h"
#include "IllegalValueException.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "Utils.h"

using namespace WorkScript;
using namespace std;


//真值
BooleanExpression BooleanExpression::TRUE(1);
BooleanExpression BooleanExpression::YES(3);
BooleanExpression BooleanExpression::OK(5);
BooleanExpression BooleanExpression::GOOD(7);
//假值
BooleanExpression BooleanExpression::FALSE(0);
BooleanExpression BooleanExpression::NO(2);
BooleanExpression BooleanExpression::BAD(4);

GenerateResult BooleanExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt8Ty(*context->getLLVMContext()), llvm::APInt(8, this->value));
}

//bool BooleanExpression::match(Expression * matchExpression,Context *const &context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

//bool BooleanExpression::equals(Expression  *targetExpression) const
//{
//	//if (targetExpression == this)return true;
//	//if (!targetExpression->getType()->equals(this->getType())) {
//	//	return false;
//	//}
//	//auto targetExpressionOfMyType = (const Pointer<BooleanExpression> &)targetExpression;
//	////偶数为假，奇数为真
//	//return targetExpressionOfMyType->value % 2 == this->value % 2;
//	return targetExpression == this;
//}

std::wstring BooleanExpression::toString() const
{
	switch (this->value) {
	case 0:return L"false";
	case 2:return L"no";
	case 4:return L"bad";
	case 1:return L"true";
	case 3:return L"yes";
	case 5:return L"ok";
	case 7:return L"good";
	default:return L"unknown_bool";
	}
}

Type * WorkScript::BooleanExpression::getType() const
{
	return program->getType(TYPENAME_BOOLEAN);
}

ExpressionType BooleanExpression::getExpressionType() const
{
	return ExpressionType::BOOLEAN_EXPRESSION;
}

Expression * WorkScript::BooleanExpression::clone() const
{
	return new thistype(this->value);
}

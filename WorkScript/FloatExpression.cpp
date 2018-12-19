#include "stdafx.h"
#include "FloatExpression.h"
#include "FloatType.h"
#include "Program.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

std::wstring FloatExpression::toString() const
{
	double number = this->value;
	wchar_t buff[32];
	swprintf(buff, 32, L"%.20lf", number);
	wstring numberStr = buff;
	//如果是小数，删除末尾0，如果小数点后全是0，删除小数点
	size_t removeCharCount = 0;
	for (size_t i = numberStr.size() - 1; i >= 0; i--) {
		if (numberStr[i] == '0') {
			removeCharCount++;
		}
		else if (numberStr[i] == '.') {
			removeCharCount++;
			break;
		}
		else {
			break;
		}
	}
	numberStr = numberStr.substr(0, numberStr.size() - removeCharCount);
	return numberStr;
}

Expression * WorkScript::FloatExpression::clone() const
{
	return new thistype(EXPRESSION_MEMBERS, type, this->value);
}

GenerateResult FloatExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantFP::get(this->type->getLLVMType(context), this->value);
}

inline WorkScript::FloatExpression::FloatExpression(EXPRESSION_CTOR_FORMAL_PARAMS, FloatType * type, double v)
	:EXPRESSION_CTOR_CALL
{
	this->type = type;
	this->value = v;
}

ExpressionType FloatExpression::getExpressionType() const
{
	return ExpressionType::FLOAT_EXPRESSION;
}

Expression * WorkScript::FloatExpression::instantialize(InstantializeContext *context)
{
	return this->clone();
}

Type * WorkScript::FloatExpression::getType() const
{
	return this->type;
}

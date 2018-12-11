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
	return new thistype(program, type, this->value);
}

GenerateResult FloatExpression::generateIR(GenerateContext * context)
{
	auto len = this->type->getLength();
	switch (len)
	{
	case 4:
		return (llvm::Value*)llvm::ConstantFP::get(llvm::Type::getFloatTy(*context->getLLVMContext()), this->value);
	case 8:
		return (llvm::Value*)llvm::ConstantFP::get(llvm::Type::getDoubleTy(*context->getLLVMContext()), this->value);
	default:
		throw WorkScriptException(L"不支持的浮点数长度：" + to_wstring(len));
	}
}

inline WorkScript::FloatExpression::FloatExpression(Program * p, FloatType * type, double v)
	:Expression(p)
{
	this->type = type;
	this->value = v;
}

ExpressionType FloatExpression::getExpressionType() const
{
	return ExpressionType::FLOAT_EXPRESSION;
}

Type * WorkScript::FloatExpression::getType() const
{
	return this->type;
}

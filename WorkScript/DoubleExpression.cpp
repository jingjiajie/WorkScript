#include "stdafx.h"
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "IntegerExpression.h"
#include "ByteExpression.h"
#include "Type.h"
#include "Program.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

std::wstring DoubleExpression::toString() const
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

Expression * WorkScript::DoubleExpression::clone() const
{
	return new thistype(this->value);
}

GenerateResult DoubleExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantFP::get(*context->getLLVMContext(), llvm::APFloat(this->value));
}

ExpressionType DoubleExpression::getExpressionType() const
{
	return ExpressionType::DOUBLE_EXPRESSION;
}

Type * WorkScript::DoubleExpression::getType() const
{
	return program->getType(TYPENAME_DOUBLE);
}

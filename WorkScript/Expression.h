#pragma once
#include "Defines.h"
#include "WorkScriptException.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "Location.h"
#include "Program.h"
#include "ExpressionInfo.h"

namespace WorkScript {
	class Type;
	class InstantializeContext;

	class Expression
	{
	public:
		inline Expression(const ExpressionInfo &exprInfo) :expressionInfo(exprInfo) {}

		//����LLVM�ֽ���Ľӿں���
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//��Ҫʵ�ֵĽӿں���
		virtual Type* getType(InstantializeContext *context) const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		virtual Expression * clone() const = 0;

		inline Location getLocation() const { return this->expressionInfo.getLocation(); };
		inline Program * getProgram() const { return this->expressionInfo.getProgram(); }
	protected:
		ExpressionInfo expressionInfo;
	};
}
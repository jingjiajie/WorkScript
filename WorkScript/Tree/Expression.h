#pragma once
#include "Defines.h"
#include "Report.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "DebugInfo.h"
#include "Program.h"
#include "ExpressionInfo.h"

namespace WorkScript {
	class Type;
	class InstantialContext;

	class Expression
	{
	public:
		inline Expression(const ExpressionInfo &exprInfo) :expressionInfo(exprInfo) {}
		virtual ~Expression(){}
		//生成LLVM字节码的接口函数
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//需要实现的接口函数
		virtual Type* getType(InstantialContext *context) const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		virtual Expression * clone() const = 0;

		inline Program * getProgram() const { return this->expressionInfo.getProgram(); }
		inline const DebugInfo & getDebugInfo() const{return this->expressionInfo.getDebugInfo();}
	protected:
		ExpressionInfo expressionInfo;
	};
}
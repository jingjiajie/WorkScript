#pragma once

#include "NonCopyable.h"
#include "Defines.h"
#include "Report.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "DebugInfo.h"
#include "Program.h"
#include "ExpressionInfo.h"
#include "DeducedInfo.h"

namespace WorkScript {
	class InstantialContext;

	class Expression : public NonCopyable
	{
	public:
		inline explicit Expression(const ExpressionInfo &exprInfo) noexcept :expressionInfo(exprInfo) {}
		virtual ~Expression() noexcept = default;
		//生成LLVM字节码的接口函数
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//需要实现的接口函数
		virtual DeducedInfo deduce(InstantialContext *context) const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		virtual Expression * clone() const = 0;

		inline Program * getProgram() const noexcept{ return this->expressionInfo.getProgram(); }
		inline const DebugInfo & getDebugInfo() const noexcept{return this->expressionInfo.getDebugInfo();}
	protected:
		ExpressionInfo expressionInfo;
	};
}
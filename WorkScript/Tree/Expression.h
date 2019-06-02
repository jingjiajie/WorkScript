#pragma once

#include "NonCopyable.h"
#include "Defines.h"
#include "Report.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "DebugInfo.h"
#include "Module.h"
#include "ExpressionInfo.h"
#include "DeducedInfo.h"
//#include "VisitResult.h"

namespace WorkScript{

	class InstantialContext;
	class Visitor;

	class Expression : public NonCopyable
	{
	public:
		inline explicit Expression(const ExpressionInfo &exprInfo) noexcept :expressionInfo(exprInfo) {}
		virtual ~Expression() noexcept = default;

//		virtual VisitResult visit(Visitor *) const = 0;
		//生成LLVM字节码的接口函数
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//需要实现的接口函数
		virtual DeducedInfo deduce(InstantialContext *context) const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		virtual Expression * clone() const = 0;

		inline Module * getModule() const noexcept{ return this->expressionInfo.getModule(); }
		inline const DebugInfo & getDebugInfo() const noexcept{return this->expressionInfo.getDebugInfo();}
	protected:
		ExpressionInfo expressionInfo;
	};
}

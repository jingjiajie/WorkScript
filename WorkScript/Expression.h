#pragma once
#include "Defines.h"
#include "WorkScriptException.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "Program.h"

namespace WorkScript {
	class Type;

	class Expression
	{
	public:
		inline Expression() {};
		virtual ~Expression();
		//����LLVM�ֽ���Ľӿں���
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//��Ҫʵ�ֵĽӿں���
		virtual Type* getType() const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		//virtual bool equals(Expression *) const = 0;
		virtual Expression * clone() const = 0;
		Program *program;
	};

}
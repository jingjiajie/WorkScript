#pragma once
#include "Defines.h"
#include "WorkScriptException.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "ExpressionType.h"
#include "Location.h"
#include "Program.h"

#define EXPRESSION_CTOR_FORMAL_PARAMS Program *program, Location location
#define EXPRESSION_MEMBERS program, location
#define EXPRESSION_CTOR_CALL Expression(EXPRESSION_MEMBERS)

namespace WorkScript {
	class Type;
	class InstantializeContext;

	class Expression
	{
	public:
		inline Expression(EXPRESSION_CTOR_FORMAL_PARAMS) :program(program), location(location) {}

		//ģ��ʵ����
		virtual Expression * instantialize(InstantializeContext *context);
		//����LLVM�ֽ���Ľӿں���
		virtual GenerateResult generateIR(GenerateContext *context) = 0;
		//��Ҫʵ�ֵĽӿں���
		virtual Type* getType() const = 0;
		virtual ExpressionType getExpressionType() const = 0;
		virtual std::wstring toString() const = 0;
		virtual Expression * clone() const = 0;

		inline Location getLocation() const { return this->location; };
	protected:
		Program * program;
		Location location;
	};

	//class GenericExpression : public Expression{
	//public:
	//	inline GenericExpression(EXPRESSION_CTOR_FORMAL_PARAMS): EXPRESSION_CTOR_CALL { }
	//	//����LLVM�ֽ���Ľӿں���
	//	virtual GenerateResult generateIR(GenerateContext *context) = 0;
	//};
}
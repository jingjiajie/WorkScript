#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class IntegerExpression;
	class FloatExpression;
	class StringExpression;

	class BinaryOperatorExpression :
		public Expression
	{
	public:
		inline BinaryOperatorExpression(Program *p) : Expression(p)
		{
		}

		inline BinaryOperatorExpression(Program *p, Expression *left, Expression *right) : Expression(p)
		{
			this->setLeftExpression(left);
			this->setRightExpression(right);
		}

		virtual ~BinaryOperatorExpression();

		virtual GenerateResult generateIR(GenerateContext *context);
		virtual std::wstring toString() const override;

		inline Expression * getLeftExpression() const
		{
			return this->leftExpression;
		}

		inline void setLeftExpression(Expression *left)
		{
			this->leftExpression = left;
		}

		inline Expression * getRightExpression() const
		{
			return this->rightExpression;
		}

		inline void setRightExpression(Expression *right)
		{
			this->rightExpression = right;
		}
	protected:
		Expression *leftExpression;
		Expression *rightExpression;

		virtual std::wstring getOperatorString() const = 0;

		const Type * getUpperType(const Type *left, const Type *right) const;

		void adjustIntegerInteger(const IntegerExpression *left, const IntegerExpression *right, IntegerExpression *outLeft, IntegerExpression *outRight);
		void adjustIntegerFloat(const IntegerExpression *left, const IntegerExpression *right, IntegerExpression *outLeft, IntegerExpression *outRight);
		void adjustFloatInteger(const IntegerExpression *left, const IntegerExpression *right, IntegerExpression *outLeft, IntegerExpression *outRight);
		void adjustFloatFloat(const IntegerExpression *left, const IntegerExpression *right, IntegerExpression *outLeft, IntegerExpression *outRight);

		virtual GenerateResult generateLLVMIRIntegerInteger(GenerateContext *context, IntegerExpression *left, IntegerExpression *right) const = 0;
		virtual GenerateResult generateLLVMIRIntegerFloat(GenerateContext *context, IntegerExpression *left, FloatExpression *right) const = 0;
		virtual GenerateResult generateLLVMIRFloatInteger(GenerateContext *context, FloatExpression *left, IntegerExpression *right) const = 0;
		virtual GenerateResult generateLLVMIRFloatFloat(GenerateContext *context, FloatExpression *left, FloatExpression *right) const = 0;
	};

}
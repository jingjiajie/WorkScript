#pragma once
#include "GenerateResult.h"
#include "GenerateContext.h"

namespace WorkScript {
	class Type;
	class Program;

	class Constant {
	public:
		virtual ~Constant(){};
		virtual Type * getType() = 0;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) = 0;
		virtual std::wstring toString() const = 0;
		virtual Constant * clone() const = 0;

	protected:
		Program * program;
	};
}
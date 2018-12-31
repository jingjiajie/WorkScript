#pragma once
#include "Function.h"

namespace WorkScript {
	class NativeFunction : public Function {
	public:
		typedef GenerateResult(*TFuncGenerateIR)(NativeFunction *, GenerateContext*);

		inline NativeFunction(Program *program, const std::wstring &name, const std::vector<Type*> &paramTypes, Type *returnType, TFuncGenerateIR f)
			: Function(program,name, paramTypes, returnType), funcGenerateIR(f) {}
		
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;
	private:
		TFuncGenerateIR funcGenerateIR;
	};
}
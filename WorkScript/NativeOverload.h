#pragma once
#include "Overload.h"

namespace WorkScript {
	class NativeOverload : public Overload {
	public:
		typedef GenerateResult(*TFuncGenerateIR)(NativeOverload *, GenerateContext*);

		inline NativeOverload(Function *func, const std::vector<Parameter*> &params, Type *returnType, TFuncGenerateIR f)
			: Overload(func, params, returnType), funcGenerateIR(f) {}

		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;
	private:
		TFuncGenerateIR funcGenerateIR;
	};
}
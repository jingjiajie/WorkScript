#pragma once
#include "Overload.h"

namespace WorkScript {
	class NativeOverload : public Overload {
	public:
		typedef GenerateResult(*TFuncGenerateIR)(NativeOverload *, GenerateContext*);

		template<size_t paramCount>
		inline NativeOverload(Function *func, Parameter *const (&params)[paramCount], Type *returnType, TFuncGenerateIR f)
			: Overload(func, params, returnType), funcGenerateIR(f) {}

		virtual GenerateResult generateIR(GenerateContext *context);
	private:
		TFuncGenerateIR funcGenerateIR;
	};
}
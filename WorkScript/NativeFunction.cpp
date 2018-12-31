#include "stdafx.h"
#include "NativeFunction.h"


GenerateResult WorkScript::NativeFunction::generateLLVMIR(GenerateContext * context)
{
	return this->funcGenerateIR(this, context);
}

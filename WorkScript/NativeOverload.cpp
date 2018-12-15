#include "stdafx.h"
#include "NativeOverload.h"

GenerateResult WorkScript::NativeOverload::generateLLVMIR(GenerateContext * context)
{
	return this->funcGenerateIR(this, context);
}

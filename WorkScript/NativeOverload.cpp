#include "stdafx.h"
#include "NativeOverload.h"

void WorkScript::NativeOverload::bindSymbols()
{
}

GenerateResult WorkScript::NativeOverload::generateLLVMIR(GenerateContext * context)
{
	return this->funcGenerateIR(this, context);
}

#include "stdafx.h"
#include "NativeOverload.h"

GenerateResult WorkScript::NativeOverload::generateIR(GenerateContext * context)
{
	return this->funcGenerateIR(this, context);
}

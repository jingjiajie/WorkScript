#include "stdafx.h"
#include "Function.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::Function::generateLLVMIR(GenerateContext * context)
{
	for (auto overload : this->overloads) {
		overload->generateLLVMIR(context);
	}
	return GenerateResult();
}

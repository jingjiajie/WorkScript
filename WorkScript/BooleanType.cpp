#include "stdafx.h"
#include "Type.h"
#include "Initializer.h"
#include "Function.h"
#include "Program.h"
#include "NativeOverload.h"

using namespace std;

namespace WorkScript {
	extern void initBooleanType(Program *p)
	{
		Type *booleanType = new Type(p, TYPENAME_BOOLEAN);
		booleanType->setFGetLLVMType(&fGetBoolLLVMType);
		p->addType(booleanType);
	}

	static llvm::Type * fGetBoolLLVMType(Type *pthis, GenerateContext* context)
	{
		return llvm::Type::getInt8Ty(*context->getLLVMContext());
	}
}
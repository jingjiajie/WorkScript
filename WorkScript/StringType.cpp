#include "stdafx.h"
#include "Type.h"
#include "Initializer.h"
#include "Function.h"
#include "NativeOverload.h"
#include "Program.h"

using namespace std;

namespace WorkScript {
	static llvm::Type * fGetStringLLVMType(Type *pthis, GenerateContext* context)
	{
		return llvm::Type::getInt8PtrTy(*context->getLLVMContext());
	}

	extern void WorkScript::initStringType(Program *p)
	{
		Type *strType = new Type(p, TYPENAME_STRING);
		strType->setFGetLLVMType(&fGetStringLLVMType);
		p->addType(strType);
	}
}
#include "stdafx.h"
#include "Type.h"
#include "Initializer.h"
#include "Function.h"
#include "NativeOverload.h"
#include "Program.h"

using namespace std;
using namespace WorkScript;

namespace WorkScript {
	extern void WorkScript::initByteType(Program *p)
	{
		Type *byteType = new Type(p, TYPENAME_BYTE);
		p->addType(byteType);
		initOperatorPlus(p, byteType);
		initOperatorMinus(p, byteType);
		initOperatorMultiply(p, byteType);
		initOperatorDivide(p, byteType);
		initOperatorModulus(p, byteType);
	}
	static inline void initOperatorPlus(Program *p, Type *byteType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_PLUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_BYTE)));
		p->getType(TYPENAME_BYTE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_INTEGER), operatorFunc<&TIRBuilder::CreateAdd, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_BYTE), operatorFunc<&TIRBuilder::CreateAdd>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFAdd, &TIRBuilder::CreateUIToFP>));
	}

	static inline void initOperatorMinus(Program *p, Type *byteType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MINUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_BYTE)));
		p->getType(TYPENAME_BYTE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_INTEGER), operatorFunc<&TIRBuilder::CreateSub, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_BYTE), operatorFunc<&TIRBuilder::CreateSub>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFSub, &TIRBuilder::CreateUIToFP>));
	}

	static inline void initOperatorMultiply(Program *p, Type *byteType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MULTIPLY_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_BYTE)));
		p->getType(TYPENAME_BYTE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_INTEGER), operatorFunc<&TIRBuilder::CreateMul, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_BYTE), operatorFunc<&TIRBuilder::CreateMul>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFMul, &TIRBuilder::CreateUIToFP>));
	}

	static inline void initOperatorDivide(Program *p, Type *byteType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_DIVIDE_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_BYTE)));
		p->getType(TYPENAME_BYTE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateUIToFP, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateUIToFP, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateUIToFP>));
	}

	static inline void initOperatorModulus(Program *p, Type *byteType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MODULUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_BYTE)));
		p->getType(TYPENAME_BYTE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_INTEGER), operatorFunc<&TIRBuilder::CreateSRem, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_BYTE), operatorFunc<&TIRBuilder::CreateURem>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFRem, &TIRBuilder::CreateUIToFP>));
	}

	template<
		auto fCreateOperator, //运算符
		auto fCreateConvMe = nullptr, //将自己转换
		auto fCreateConvParam = nullptr //将参数转换
	>
		static GenerateResult operatorFunc(NativeOverload *overload, GenerateContext *context)
	{
		llvm::Function *func = overload->makeLLVMFunction(context);
		llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", func);
		auto builder = context->getIRBuilder();
		builder->SetInsertPoint(entry);
		llvm::Value *convedMe = func->args.begin() + 1, *convedParam = func->args.begin();
		if (fCreateConvMe) {
			convedMe = builder->*fCreateConvMe(func->args.begin() + 1, overload->getReturnType()->getLLVMType());
		}
		if (fCreateConvParam) {
			convedParam = builder->*fCreateConvParam(func->args.begin(), overload->getReturnType()->getLLVMType());
		}
		llvm::Value *res = builder->*fCreateOperator(convedParam, convedMe, "res");
		builder->CreateRet(res);
		llvm::verifyFunction(*func);
		return (llvm::Value*)func;
	}
}
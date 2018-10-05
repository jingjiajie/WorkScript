#include "stdafx.h"
#include "Type.h"
#include "Initializer.h"
#include "Function.h"
#include "NativeOverload.h"
#include "Program.h"

using namespace std;
namespace WorkScript {
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

	static inline void initOperatorPlus(Program *p, Type *integerType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_PLUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", integerType));
		integerType->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",integerType) }, integerType, operatorFunc<&TIRBuilder::CreateAdd>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, integerType, operatorFunc<&TIRBuilder::CreateAdd, nullptr, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateAdd, &TIRBuilder::CreateSIToFP, nullptr>));
	}

	static inline void initOperatorMinus(Program *p, Type *integerType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MINUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", integerType));
		integerType->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",integerType) }, integerType, operatorFunc<&TIRBuilder::CreateSub>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, integerType, operatorFunc<&TIRBuilder::CreateSub, nullptr, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFSub, &TIRBuilder::CreateSIToFP, nullptr>));
	}

	static inline void initOperatorMultiply(Program *p, Type *integerType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MULTIPLY_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", integerType));
		integerType->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",integerType) }, integerType, operatorFunc<&TIRBuilder::CreateMul>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, integerType, operatorFunc<&TIRBuilder::CreateMul, nullptr, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFMul, &TIRBuilder::CreateSIToFP, nullptr>));
	}

	static inline void initOperatorDivide(Program *p, Type *integerType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_DIVIDE_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", integerType));
		integerType->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",integerType) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateSIToFP, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateSIToFP, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, &TIRBuilder::CreateSIToFP, nullptr>));
	}

	static inline void initOperatorModulus(Program *p, Type *integerType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MODULUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", integerType));
		integerType->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",integerType) }, integerType, operatorFunc<&TIRBuilder::CreateSRem>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, integerType, operatorFunc<&TIRBuilder::CreateSRem, nullptr, &TIRBuilder::CreateZExt>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFRem, &TIRBuilder::CreateSIToFP, nullptr>));
	}

	static llvm::Type * fGetIntegerLLVMType(Type *pthis, GenerateContext* context)
	{
		return llvm::Type::getInt32Ty(*context->getLLVMContext());
	}
	extern void WorkScript::initIntegerType(Program *p)
	{
		Type *integerType = new Type(p, TYPENAME_INTEGER);
		integerType->setFGetLLVMType(&fGetIntegerLLVMType);
		p->addType(integerType);
		initOperatorPlus(p, integerType);
		initOperatorMinus(p, integerType);
		initOperatorMultiply(p, integerType);
		initOperatorDivide(p, integerType);
		initOperatorModulus(p, integerType);
	}
}
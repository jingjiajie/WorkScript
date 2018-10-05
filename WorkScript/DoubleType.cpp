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

	extern void WorkScript::initDoubleType(Program *p)
	{
		Type *doubleType = new Type(p, TYPENAME_DOUBLE);
		p->addType(doubleType);
		initOperatorPlus(p, doubleType);
		initOperatorMinus(p, doubleType);
		initOperatorMultiply(p, doubleType);
		initOperatorDivide(p, doubleType);
		initOperatorModulus(p, doubleType);
	}

	static inline void initOperatorPlus(Program *p, Type *doubleType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_PLUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_DOUBLE)));
		p->getType(TYPENAME_DOUBLE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFAdd, nullptr, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFAdd, nullptr, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFAdd>));
	}

	static inline void initOperatorMinus(Program *p, Type *doubleType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MINUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_DOUBLE)));
		p->getType(TYPENAME_DOUBLE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFSub, nullptr, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFSub, nullptr, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFSub>));
	}

	static inline void initOperatorMultiply(Program *p, Type *doubleType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MULTIPLY_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_DOUBLE)));
		p->getType(TYPENAME_DOUBLE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFMul, nullptr, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFMul, nullptr, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFMul>));
	}

	static inline void initOperatorDivide(Program *p, Type *doubleType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_DIVIDE_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_DOUBLE)));
		p->getType(TYPENAME_DOUBLE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFDiv, nullptr, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFDiv, nullptr, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFDiv>));
	}

	static inline void initOperatorModulus(Program *p, Type *doubleType)
	{
		typedef llvm::IRBuilder<> TIRBuilder;
		Function *func = new Function(OPERATOR_MODULUS_FUNCTION_NAME);
		func->setThisParameter(new Parameter(L"this", p->getType(TYPENAME_DOUBLE)));
		p->getType(TYPENAME_DOUBLE)->addMemberFunction(func);
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_INTEGER)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFRem, nullptr, &TIRBuilder::CreateSIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_BYTE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc<&TIRBuilder::CreateFRem, nullptr, &TIRBuilder::CreateUIToFP>));
		func->addOverload(new NativeOverload(func, { new Parameter(L"x",p->getType(TYPENAME_DOUBLE)) }, p->getType(TYPENAME_DOUBLE), operatorFunc < &TIRBuilder::CreateFRem>));
	}
}
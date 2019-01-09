#pragma once
#include "stdafx.h"
#include "SymbolTable.h"
#include <unordered_map>
#include "FunctionType.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "VoidType.h"
#include "FunctionCache.h"
#include "AbstractContext.h"

namespace WorkScript {
	class Function;

	class Program final
	{
	public:
		Program();
		~Program();

		Type * getType(const std::wstring &name, size_t pointerLevel = 0);
		void addType(const std::wstring &name, Type *type);

		void generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule);

		inline SymbolTable * getGlobalSymbolTable() { return this->globalAbstractContext.getAbstractSymbolTable(); }
		inline CommonAbstractContext * getGlobalAbstractContext() { return &this->globalAbstractContext; }
		void addFunction(Function *func);
		Function* getFirstFunction(const std::wstring &name, std::vector<Type*> paramTypes);
		std::vector<Function*> getFunctions(const std::wstring &name, std::vector<Type*> paramTypes, bool compromise = false);
		std::vector<Function*> getFunctions(const std::wstring &name);
		inline FunctionCache *getFunctionCache() { return &this->functionCache; }

		FunctionType * getFunctionType(std::vector<Type*> paramTypes, Type *returnType);
		PointerType * getPointerType(Type *targetType, size_t pointerLevel);
		inline static VoidType * getVoidType() { return &voidType; }
		inline static IntegerType * getSInt8Type() { return &sint8; }
		inline static IntegerType * getSInt16Type() { return &sint16; }
		inline static IntegerType * getSInt32Type() { return &sint32; }
		inline static IntegerType * getSInt64Type() { return &sint64; }
		inline static IntegerType * getUInt1Type() { return &uint1; }
		inline static IntegerType * getUInt8Type() { return &uint8; }
		inline static IntegerType * getUInt16Type() { return &uint16; }
		inline static IntegerType * getUInt32Type() { return &uint32; }
		inline static IntegerType * getUInt64Type() { return &uint64; }
		inline static FloatType * getFloat32Type() { return &float32; }
		inline static FloatType * getFloat64Type() { return &float64; }
		inline static PointerType * getSInt8PtrType() { return &sint8ptr; }
		inline static PointerType * getSInt16PtrType() { return &sint16ptr; }
		inline static PointerType * getSInt32PtrType() { return &sint32ptr; }
		inline static PointerType * getSInt64PtrType() { return &sint64ptr; }
		inline static PointerType * getUInt1PtrType() { return &uint1ptr; }
		inline static PointerType * getUInt8PtrType() { return &uint8ptr; }
		inline static PointerType * getUInt16PtrType() { return &uint16ptr; }
		inline static PointerType * getUInt32PtrType() { return &uint32ptr; }
		inline static PointerType * getUInt64PtrType() { return &uint64ptr; }
		inline static PointerType * getFloat32PtrType() { return &float32ptr; }
		inline static PointerType * getFloat64PtrType() { return &float64ptr; }

	protected:
		void initPrimitiveTypes();

		CommonAbstractContext globalAbstractContext;
		FunctionCache functionCache;
		std::unordered_map<std::wstring, Type*> types;
		std::unordered_map<std::wstring, std::vector<Function*>> functions;

		static IntegerType sint8, sint16, sint32, sint64, uint1, uint8, uint16, uint32, uint64;
		static FloatType float32, float64;
		static PointerType sint8ptr, sint16ptr, sint32ptr, sint64ptr, uint1ptr, uint8ptr, uint16ptr, uint32ptr, uint64ptr, float32ptr, float64ptr;
		static VoidType voidType;
	};
}

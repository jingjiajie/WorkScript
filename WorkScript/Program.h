#pragma once
#include "stdafx.h"
#include "SymbolTable.h"

namespace WorkScript {
	class Function;
	class FunctionTemplate;
	class Overload;
	class VoidType;
	class IntegerType;
	class FloatType;
	class IntegerPointerType;
	class FloatPointerType;
	class Type;

	//struct pair_hash {
	//	template <class T1, class T2>
	//	std::size_t operator()(const std::pair<T1, T2> &p) const
	//	{
	//		auto h1 = std::hash<T1>()(p.first);
	//		auto h2 = std::hash<T2>()(p.second);
	//		return h1 ^ h2;
	//	}
	//};

	class Program final
	{
	public:
		Program();
		~Program();

		Overload * getFunctionOverload(const std::wstring &funcName, const std::vector<Type*> &paramTypes);
		void addFunction(Function *func);
		FunctionTemplate * getFunctionTemplate(const std::wstring & funcName) const;
		void addFunctionTemplate(FunctionTemplate *funcTemplate, Type *type = nullptr);
		//Type * getType(const std::wstring &name) const;
		//void addType(Type *type);

		void generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule);

		inline SymbolTable * getSymbolTable() { return &this->symbolTable; }

		inline VoidType * getVoidType() const { return &voidType; }
		inline IntegerType * getSInt8Type() const { return &sint8; }
		inline IntegerType * getSInt16Type() const { return &sint16; }
		inline IntegerType * getSInt32Type() const { return &sint32; }
		inline IntegerType * getSInt64Type() const { return &sint64; }
		inline IntegerType * getUInt1Type() const { return &uint1; }
		inline IntegerType * getUInt8Type() const { return &uint8; }
		inline IntegerType * getUInt16Type() const { return &uint16; }
		inline IntegerType * getUInt32Type() const { return &uint32; }
		inline IntegerType * getUInt64Type() const { return &uint64; }
		inline FloatType * getFloat32Type() const { return &float32; }
		inline FloatType * getFloat64Type() const { return &float64; }
		inline IntegerPointerType * getSInt8PtrType() const { return &sint8ptr; }
		inline IntegerPointerType * getSInt16PtrType() const { return &sint16ptr; }
		inline IntegerPointerType * getSInt32PtrType() const { return &sint32ptr; }
		inline IntegerPointerType * getSInt64PtrType() const { return &sint64ptr; }
		inline IntegerPointerType * getUInt1PtrType() const { return &uint1ptr; }
		inline IntegerPointerType * getUInt8PtrType() const { return &uint8ptr; }
		inline IntegerPointerType * getUInt16PtrType() const { return &uint16ptr; }
		inline IntegerPointerType * getUInt32PtrType() const { return &uint32ptr; }
		inline IntegerPointerType * getUInt64PtrType() const { return &uint64ptr; }
		inline FloatPointerType * getFloat32PtrType() const { return &float32ptr; }
		inline FloatPointerType * getFloat64PtrType() const { return &float64ptr; }
	protected:

		std::unordered_map<std::wstring, Function*> functions;
		std::unordered_map<std::wstring, FunctionTemplate*> functionTemplates;

		SymbolTable symbolTable;

		static IntegerType sint8, sint16, sint32, sint64, uint1, uint8, uint16, uint32, uint64;
		static IntegerPointerType sint8ptr, sint16ptr, sint32ptr, sint64ptr, uint1ptr, uint8ptr, uint16ptr, uint32ptr, uint64ptr;
		static FloatType float32, float64;
		static FloatPointerType float32ptr, float64ptr;
		static VoidType voidType;
	};
}

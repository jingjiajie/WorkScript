#pragma once
#include "Type.h"
#include "Utils.h"
#include <vector>

namespace WorkScript {
	class Program;

	class FunctionType : public Type {
	public:
		inline FunctionType(const std::vector<Type*> &paramTypes, Type *returnType, bool isRumtimeVarargs = false, bool isStaticVarargs = false, bool isConst = false, bool isVolatile = false)
			:Type(isConst,isVolatile),
			paramTypes(paramTypes), returnType(returnType),rumtimeVarargs(isRumtimeVarargs),staticVarargs(isStaticVarargs) {}


		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;
		virtual std::wstring getName() const override;
		virtual std::wstring getIdentifierString() const override;
		static std::wstring getIdentifierString(const std::vector<Type*>& paramTypes, Type * returnType, bool isRuntimeVarargs, bool isStaticVarargs, bool isConst = false, bool isVolatile = false);
		inline std::vector<Type *> getParameterTypes() const { return this->paramTypes; }
		inline size_t getParameterCount() const { return this->paramTypes.size(); }
		inline Type * getReturnType() { return this->returnType; }
		inline bool isRumtimeVarargs() const { return this->rumtimeVarargs; }
		inline bool isStaticVarargs() const { return this->staticVarargs; }

		static FunctionType * get(std::vector<Type*> paramTypes, Type *returnType, bool isRuntimeVarargs = false, bool isStaticVarargs = false, bool isConst = false, bool isVolatile = false);
	protected:
		std::vector<Type*> paramTypes;
		bool rumtimeVarargs = false;
		bool staticVarargs = false;
		Type *returnType = nullptr;
		static std::unordered_map<std::wstring, FunctionType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
	};
}
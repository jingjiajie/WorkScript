#pragma once
#include "Type.h"
#include "Utils.h"
#include "FunctionQuery.h"
#include <vector>
#include <unordered_map>

namespace WorkScript {
	class Program;

	class FunctionType : public Type {
	public:
		inline FunctionType(const std::vector<Type*> &paramTypes, Type *returnType, bool isRumtimeVarargs, bool isConst) noexcept
			:_const(isConst),
			paramTypes(paramTypes),rumtimeVarargs(isRumtimeVarargs), returnType(returnType){}


		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;
		std::wstring getName() const noexcept override;
		std::wstring getIdentifierString() const noexcept override;
		static std::wstring getIdentifierString(const std::vector<Type*>& paramTypes, Type * returnType, bool isRuntimeVarargs, bool isConst) noexcept;
		inline std::vector<Type *> getParameterTypes() const noexcept{ return this->paramTypes; }
		inline size_t getParameterCount() const noexcept{ return this->paramTypes.size(); }
		inline Type * getReturnType() noexcept{ return this->returnType; }
		inline bool isRumtimeVarargs() const noexcept{ return this->rumtimeVarargs; }
		inline bool isConst() const noexcept{return this->_const;}
		bool match(const DebugInfo &d, const FunctionTypeQuery &query)const noexcept;
		static bool match(const DebugInfo &d,const FunctionType *declType, const FunctionTypeQuery &query)noexcept;

		static FunctionType * get(const std::vector<Type*> &paramTypes, Type *returnType, bool isRuntimeVarargs, bool isConst) noexcept;
	protected:
		std::vector<Type*> paramTypes;
		bool rumtimeVarargs = false;
		bool _const = false;
		Type *returnType = nullptr;
		static std::unordered_map<std::wstring, FunctionType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
	};
}
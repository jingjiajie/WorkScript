#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class ReferenceType : public Type {
	public:
        ReferenceType(Type *targetType) noexcept
        : targetType(targetType){}

		std::wstring getName()const noexcept override;
		std::wstring getMangledName()const noexcept;
		static std::wstring getMangledName(Type *targetType) noexcept;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;
		Type* getTargetType() noexcept;

        static ReferenceType *get(Type *targetType) noexcept;
        static llvm::Value *getTargetPointer(GenerateContext *context, llvm::Value *ref) noexcept;
        static void setTargetPointer(GenerateContext *context, llvm::Value *ref, llvm::Value *target) noexcept;
        static llvm::Value *getLocalheapPointer(GenerateContext *context, llvm::Value *ref) noexcept;
        static void setLocalheapPointer(GenerateContext *context, llvm::Value *ref, llvm::Value *localheap) noexcept;

	protected:
		Type * targetType = nullptr;
		static std::unordered_map<std::wstring, ReferenceType*> types;
		static Finalizer staticFinalizer;

		static void releaseTypes() noexcept;
	};
}
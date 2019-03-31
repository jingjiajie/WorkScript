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

        ReferenceType *get(Type *targetType, const std::vector<size_t> &lenOfEachDimension) noexcept;
	protected:
		Type * targetType = nullptr;
		static std::unordered_map<std::wstring, ReferenceType*> types;
		static Finalizer staticFinalizer;

		static void releaseTypes() noexcept;
	};
}
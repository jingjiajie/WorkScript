#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class ArrayType : public Type {
	public:
		ArrayType(Type *targetType, const std::vector<size_t> &lenOfEachDimension) noexcept;

		std::wstring getName()const noexcept override;
		std::wstring getIdentifierString()const noexcept override;
		static std::wstring getIdentifierString(Type *targetType, const std::vector<size_t> &lenOfEachDimension) noexcept;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;

		inline size_t getLength(size_t dimension) const noexcept{ return this->lengthOfEachDimension[dimension]; }
		ArrayType *get(Type *targetType, const std::vector<size_t> &lenOfEachDimension) noexcept;
	protected:
		Type * targetType = nullptr;
		std::vector<size_t> lengthOfEachDimension;
		static std::unordered_map<std::wstring, ArrayType*> types;
		static Finalizer staticFinalizer;

		static void releaseTypes() noexcept;
	};
}
#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class ArrayType : public Type {
	public:
		ArrayType(Type *targetType, const std::vector<size_t> &lenOfEachDimension);

		virtual std::wstring getName()const override;
		virtual std::wstring getIdentifierString()const override;
		static std::wstring getIdentifierString(Type *targetType, const std::vector<size_t> &lenOfEachDimension);
		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		inline size_t getLength(size_t dimension) const { return this->lengthOfEachDimension[dimension]; }
		ArrayType *get(Type *targetType, const std::vector<size_t> &lenOfEachDimension);
	protected:
		Type * targetType = nullptr;
		std::vector<size_t> lengthOfEachDimension;
		static std::unordered_map<std::wstring, ArrayType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
	};
}
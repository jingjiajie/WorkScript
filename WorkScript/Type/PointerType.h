#pragma once
#include "Type.h"
#include "Utils.h"
#include <unordered_map>

namespace WorkScript {
	class Program;

	class PointerType : public Type {
	public:
		std::wstring getName() const override;
		std::wstring getIdentifierString()const override;
		TypeClassification getClassification() const override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const override;

		inline Type * getTargetType() const { return this->targetType; }
		inline size_t getLevel() const { return this->level; }

		static std::wstring getIdentifierString(Type *targetType, size_t level, bool isConst = false, bool isVolatile = false);
		static PointerType * get(Type *targetType, size_t pointerLevel, bool isConst = false, bool isVolatile = false);
	protected:
		Type * targetType = nullptr;
		size_t level = 1;
		static std::unordered_map<std::wstring, PointerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
		PointerType(Type *targetType, size_t level = 1, bool isConst = false, bool isVolatile = false);
	};
}
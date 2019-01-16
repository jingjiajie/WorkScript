#pragma once
#include "Type.h"
#include "Utils.h"
#include <unordered_map>

namespace WorkScript {
	class Program;

	class PointerType : public Type {
	public:
		PointerType(Type *targetType, unsigned int level = 1, bool isConst = false, bool isVolatile = false);

		virtual std::wstring getName() const override;
		virtual std::wstring getIdentifierString()const override;
		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		Type * getTargetType() const { return this->targetType; }

		static std::wstring getIdentifierString(Type *targetType, size_t level, bool isConst = false, bool isVolatile = false);
		static PointerType * get(Type *targetType, size_t pointerLevel, bool isConst = false, bool isVolatile = false);
	protected:
		Type * targetType = nullptr;
		unsigned int level = 1;
		static std::unordered_map<std::wstring, PointerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
	};
}
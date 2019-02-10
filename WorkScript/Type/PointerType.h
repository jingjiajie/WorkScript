#pragma once
#include "Type.h"
#include "Utils.h"
#include <unordered_map>

namespace WorkScript {
	class Program;

	class PointerType : public Type {
	public:
		std::wstring getName() const noexcept override;
		std::wstring getIdentifierString()const noexcept override;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;
		inline bool isConst() const noexcept{ return this->_const; }
		inline bool isVolatile() const noexcept{ return this->_volatile; }
		inline Type * getTargetType() const noexcept{ return this->targetType; }
		inline size_t getLevel() const noexcept{ return this->level; }

		static std::wstring getIdentifierString(Type *targetType, size_t level, bool isConst = false, bool isVolatile = false) noexcept;
		static PointerType * get(Type *targetType, size_t pointerLevel, bool isConst = false, bool isVolatile = false) noexcept;
	protected:
		Type * targetType = nullptr;
		size_t level = 1;
		bool _const = false;
		bool _volatile = false;

		static std::unordered_map<std::wstring, PointerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
		PointerType(Type *targetType, size_t level = 1, bool isConst = false, bool isVolatile = false) noexcept;
	};
}
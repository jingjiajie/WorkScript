#pragma once
#include "Type.h"

namespace WorkScript {
	class FloatType : public Type {
	public:
		std::wstring getName()const noexcept override;
		std::wstring getIdentifierString()const noexcept override;
		static std::wstring getIdentifierString(unsigned char length, bool isConst, bool isVolatile) noexcept;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;

		inline unsigned char getLength() const noexcept{ return this->length; }
		inline bool isConst() const noexcept{ return this->_const; }
		inline bool isVolatile() const noexcept{ return this->_volatile; }

		static FloatType * get(unsigned char length = 32, bool isConst = false, bool isVolatile = false) noexcept;
	protected:
		unsigned char length;
		bool _const = false;
		bool _volatile = false;
		static std::unordered_map<std::wstring, FloatType*> types;
        static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
		FloatType(unsigned char length, bool isConst, bool isVolatile) noexcept;
	};
}
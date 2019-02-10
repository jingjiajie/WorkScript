#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class Program;

	class IntegerType : public Type {
	public:
		static IntegerType * get(unsigned char length = 32, bool isSigned = true, bool isConst = false, bool isVolatile = false) noexcept;

		std::wstring getName() const noexcept override;
		std::wstring getIdentifierString()const noexcept override;
		static std::wstring getIdentifierString(unsigned char length, bool isSigned, bool isConst, bool isVolatile) noexcept;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;

		inline bool isConst() const noexcept{ return this->_const; }
		inline bool isVolatile() const noexcept{ return this->_volatile; }
		inline unsigned char getLength() const noexcept{ return this->length; }
		inline bool isSigned() const noexcept{ return this->_signed; }

	protected:
		unsigned char length;
		bool _signed = true;
		bool _const = false;
		bool _volatile = false;
		static std::unordered_map<std::wstring, IntegerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
		IntegerType(unsigned char length = 4, bool isSigned = true, bool isConst = false, bool isVolatile = false) noexcept;
	};
}
#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class Module;

	enum class IntegerTypeClassification{
	    BOOL, CHAR, SHORT, INT, LONG, LONG_LONG
	};

	class IntegerType : public Type {
	public:
		static IntegerType * get(IntegerTypeClassification cls, bool isSigned = true, bool isConst = false, bool isVolatile = false) noexcept;

		std::wstring getName() const noexcept override;
		TypeClassification getClassification() const noexcept override;
		std::wstring getMangledName() const noexcept override;
		static std::wstring getMangledName(IntegerTypeClassification cls, bool isSigned, bool isConst, bool isVolatile) noexcept;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;
        unsigned getLength() const noexcept;

		inline bool isConst() const noexcept{ return this->_const; }
		inline bool isVolatile() const noexcept{ return this->_volatile; }
		inline bool isSigned() const noexcept{ return this->_signed; }

	protected:
        IntegerTypeClassification classification;
		bool _signed = true;
		bool _const = false;
		bool _volatile = false;
		static std::unordered_map<std::wstring, IntegerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
		IntegerType(IntegerTypeClassification cls, bool isSigned = true, bool isConst = false, bool isVolatile = false) noexcept;
	};
}
#pragma once
#include "Type.h"

namespace WorkScript {
	class Program;

	class IntegerType : public Type {
	public:
		IntegerType(const std::wstring &name, unsigned char length = 4, bool isSigned = true, bool isConst = false, bool isVolatile = false);

		virtual std::wstring getName() const override;
		virtual std::wstring getIdentifierString()const override;
		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		inline unsigned char getLength() const { return this->length; }
		inline bool isSigned() const { return this->_signed; }

		inline static IntegerType * getSInt8Type() { return &sint8; }
		inline static IntegerType * getSInt16Type() { return &sint16; }
		inline static IntegerType * getSInt32Type() { return &sint32; }
		inline static IntegerType * getSInt64Type() { return &sint64; }
		inline static IntegerType * getUInt1Type() { return &uint1; }
		inline static IntegerType * getUInt8Type() { return &uint8; }
		inline static IntegerType * getUInt16Type() { return &uint16; }
		inline static IntegerType * getUInt32Type() { return &uint32; }
		inline static IntegerType * getUInt64Type() { return &uint64; }
	protected:
		unsigned char length;
		bool _signed = true;
		std::wstring name;

		static IntegerType sint8, sint16, sint32, sint64, uint1, uint8, uint16, uint32, uint64;
	};
}
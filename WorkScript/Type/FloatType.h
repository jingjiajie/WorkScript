#pragma once
#include "Type.h"

namespace WorkScript {
	class FloatType : public Type {
	public:
		FloatType(const std::wstring &name, unsigned char length = 4, bool isConst = false, bool isVolatile = false);

		virtual std::wstring getName()const override{ return this->name; }
		virtual std::wstring getIdentifierString()const override;
		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		inline unsigned char getLength() const { return this->length; }

		inline static FloatType * getFloat32Type() { return &float32; }
		inline static FloatType * getFloat64Type() { return &float64; }
	protected:
		unsigned char length;
		std::wstring name;

		static FloatType float32, float64;
	};
}
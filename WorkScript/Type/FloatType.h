#pragma once
#include "Type.h"

namespace WorkScript {
	class FloatType : public Type {
	public:
		std::wstring getName()const override;
		std::wstring getIdentifierString()const override;
		static std::wstring getIdentifierString(unsigned char length, bool isConst, bool isVolatile);
		TypeClassification getClassification() const override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const override;

		inline unsigned char getLength() const { return this->length; }

		static FloatType * get(unsigned char length = 32, bool isConst = false, bool isVolatile = false);
	protected:
		unsigned char length;
		static std::unordered_map<std::wstring, FloatType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
		FloatType(unsigned char length, bool isConst, bool isVolatile);
	};
}
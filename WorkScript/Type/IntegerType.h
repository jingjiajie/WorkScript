#pragma once
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript {
	class Program;

	class IntegerType : public Type {
	public:
		static IntegerType * get(unsigned char length = 32, bool isSigned = true, bool isConst = false, bool isVolatile = false);

		std::wstring getName() const override;
		std::wstring getIdentifierString()const override;
		static std::wstring getIdentifierString(unsigned char length, bool isSigned, bool isConst, bool isVolatile);
		TypeClassification getClassification() const override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const override;

		inline unsigned char getLength() const { return this->length; }
		inline bool isSigned() const { return this->_signed; }

	protected:
		unsigned char length;
		bool _signed = true;
		static std::unordered_map<std::wstring, IntegerType*> types;
		static Finalizer staticFinalizer;
		static void releaseTypes();
		IntegerType(unsigned char length = 4, bool isSigned = true, bool isConst = false, bool isVolatile = false);
	};
}
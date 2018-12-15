#pragma once
#include "Type.h"

namespace WorkScript {
	class Program;

	class IntegerPointerType : public Type {
	public:
		IntegerPointerType(Program *program, const std::wstring &name, unsigned char length = 4, bool isSigned = true);

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		inline unsigned char getLength() const
		{
			return this->length;
		}

		inline bool isSigned() const
		{
			return this->_signed;
		}
	protected:
		unsigned char length;
		bool _signed = true;
	};
}
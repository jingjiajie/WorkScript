#pragma once
#include "Type.h"

namespace WorkScript {
	class Program;

	class FloatPointerType : public Type {
	public:
		FloatPointerType(Program *program, const std::wstring &name, unsigned char length = 4);

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		inline unsigned char getLength() const
		{
			return this->length;
		}
	protected:
		unsigned char length;
	};
}
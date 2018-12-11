#pragma once
#include "Type.h"

namespace WorkScript {
	class FloatType : public Type {
	public:
		FloatType(Program *program, const std::wstring &name, unsigned char length = 4);

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;

		inline unsigned char getLength() const
		{
			return this->length;
		}
	protected:
		unsigned char length;
	};
}
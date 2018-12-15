#pragma once
#include "Type.h"

namespace WorkScript {
	class VoidType : public Type {
	public:
		VoidType(Program *program):Type(program, L"void") {};

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
	};
}
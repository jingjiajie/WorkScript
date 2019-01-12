#pragma once
#include "Type.h"

namespace WorkScript {
	class VoidType : public Type {
	public:
		VoidType() :Type(false, false) {};

		virtual std::wstring getName() const override;
		virtual std::wstring getIdentifierString()const override;
		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;

		static VoidType * get() { return &type; }

	protected:
		static VoidType type;
	};
}
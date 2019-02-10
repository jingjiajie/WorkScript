#pragma once
#include "Type.h"

namespace WorkScript {
	class VoidType : public Type {
	public:
		VoidType() noexcept = default;

		std::wstring getName() const noexcept override;
		std::wstring getIdentifierString()const noexcept override;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;
		static VoidType * get() noexcept { return &type; }

	protected:
		static VoidType type;
	};
}
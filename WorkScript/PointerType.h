#pragma once
#include "Type.h"

namespace WorkScript {
	class Program;

	class PointerType : public Type {
	public:
		PointerType(Program *program, const std::wstring &name, Type *targetType, unsigned int level = 1);

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;

		Type * getTargetType() const { return this->targetType; }
	protected:
		Type * targetType = nullptr;
		unsigned int level = 1;
	};
}
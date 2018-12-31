#pragma once
#include "Type.h"
#include <vector>

namespace WorkScript {
	class Program;

	class FunctionType : public Type {
	public:
		inline FunctionType(Program *program, const std::vector<Type*> &paramTypes, Type *returnType)
			:Type(program, FunctionType::getName(paramTypes, returnType)), paramTypes(paramTypes), returnType(returnType) {}

		virtual TypeClassification getClassification() const override;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const override;
		virtual bool equals(const Type *type) const override;
		using Type::getName;
		static std::wstring getName(const std::vector<Type*>& paramTypes, Type * returnType);
		inline std::vector<Type *> getParameterTypes() const { return this->paramTypes; }
		inline size_t getParameterCount() const { return this->paramTypes.size(); }
		inline Type * getReturnType() { return this->returnType; }
	protected:
		std::vector<Type*> paramTypes;
		Type *returnType = nullptr;
	};
}
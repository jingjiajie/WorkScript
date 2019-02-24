#pragma once
#include "Type.h"

namespace WorkScript {
    enum class FloatTypeClassification{
        FLOAT, DOUBLE
    };

	class FloatType : public Type {
	public:
		std::wstring getName()const noexcept override;
		std::wstring getMangledName()const noexcept override;
		static std::wstring getMangledName(FloatTypeClassification cls, bool isConst, bool isVolatile) noexcept;
		TypeClassification getClassification() const noexcept override;
		llvm::Type* getLLVMType(GenerateContext *context) const override;
		bool equals(const Type *type) const noexcept override;

		unsigned getLength() const noexcept;

		inline bool isConst() const noexcept{ return this->_const; }
		inline bool isVolatile() const noexcept{ return this->_volatile; }

		static FloatType * get(FloatTypeClassification cls, bool isConst = false, bool isVolatile = false) noexcept;
	protected:
        FloatTypeClassification classification;
		bool _const = false;
		bool _volatile = false;
		static std::unordered_map<std::wstring, FloatType*> types;
        static Finalizer staticFinalizer;
		static void releaseTypes() noexcept;
		FloatType(FloatTypeClassification cls, bool isConst, bool isVolatile) noexcept;
	};
}
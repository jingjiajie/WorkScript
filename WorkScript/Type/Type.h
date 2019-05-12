#pragma once
#include "TypeClassification.h"
#include "DebugInfo.h"
#include "GenerateResult.h"

namespace WorkScript {
	class Expression;
	class Program;
	class GenerateContext;

	class LinkageType
	{
	public:
		enum class Classification: unsigned char{
			INTERNAL, EXTERNAL
		};

		explicit LinkageType(LinkageType::Classification cls) noexcept
		: classification(cls) {}

		const std::wstring &toString() const noexcept;
		inline bool equals(const LinkageType &lt) const noexcept {return this->classification == lt.classification;}
		inline Classification getClassification() const noexcept {return this->classification;}

		static const LinkageType INTERNAL, EXTERNAL;
	private:
		LinkageType::Classification classification;
	};


	class Type
	{
	public:
		Type() noexcept = default;

		virtual ~Type() noexcept = default;
		virtual std::wstring getName() const noexcept = 0;
		virtual std::wstring toString() const noexcept;
		virtual bool equals(const Type *type) const noexcept = 0;
		virtual std::wstring getMangledName() const noexcept = 0;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const = 0;

		static Type * getPromotedType(const DebugInfo &d, Type *type1, Type *type2);
		virtual TypeClassification getClassification() const noexcept = 0;
	};
}

#pragma once
#include <vector>
#include <unordered_map>
#include "Type.h"
#include "Utils.h"

namespace WorkScript
{
    class MultiValueType : public Type {
    public:
        explicit MultiValueType(const std::vector<Type*> &itemTypes) noexcept;

        std::wstring getName()const noexcept override;
        inline std::vector<Type*> &getItemTypes() noexcept{return this->itemTypes;}
        std::wstring getMangledName() const noexcept override;
        static std::wstring getMangledName(const std::vector<Type *> &itemTypes) noexcept;
        TypeClassification getClassification() const noexcept override;
        llvm::Type* getLLVMType(GenerateContext *context) const override;
        bool equals(const Type *type) const noexcept override;

        static MultiValueType *get(const std::vector<Type *> &itemTypes) noexcept;
    protected:
        std::vector<Type*> itemTypes;
        static std::unordered_map<std::wstring, MultiValueType*> types;
        static Finalizer staticFinalizer;

        static void releaseTypes() noexcept;
    };
}
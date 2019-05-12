#pragma once

#include "DebugInfo.h"
#include "GenerateResult.h"

#include <llvm/IR/Value.h>

namespace WorkScript
{
    class Type;
    class Expression;
    class Value;
    class GenerateContext;

    enum class ValueKind{
        VARIABLE = 0x00, VALUE = 0x01
    };

    class ValueDescriptor
    {
    public:
        ValueDescriptor() = default;

        explicit ValueDescriptor(Type *t, ValueKind k, Value *val = nullptr, llvm::Value *llvmVal = nullptr)
            :type(t), kind(k), value(val), llvmValue(llvmVal){}

        static bool convertableTo(const DebugInfo &d, const ValueDescriptor &src, const ValueDescriptor &target);
        static GenerateResult generateLLVMConvert(const DebugInfo &d, GenerateContext *context, Expression *srcVal, const ValueDescriptor &targetDesc);

        bool equals(const ValueDescriptor &target) const noexcept;
        llvm::Value * getLLVMValue(const DebugInfo &d, GenerateContext *context) noexcept;

        ValueKind getKind() const noexcept{
            return this->kind;
        }

        void setKind(ValueKind kind) noexcept{
            this->kind = kind;
        }

        Type *getType() noexcept{
            return this->type;
        }

        const Type *getType() const noexcept{
            return this->type;
        }
    protected:
        Type *type = nullptr;
        Value *value = nullptr;
        ValueKind kind = ValueKind::VARIABLE;
        llvm::Value *llvmValue = nullptr;

        static llvm::Value * generateLLVMKindConvert(const DebugInfo &d, GenerateContext *context,
                                                     llvm::Value *srcLLVMVal, ValueKind srcKind,
                                                     ValueKind targetKind);
    };
}

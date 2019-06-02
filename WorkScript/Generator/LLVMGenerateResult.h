#pragma once

#include <vector>
#include <llvm/IR/Value.h>
#include <Visitor/Visitor.h>

namespace WorkScript
{
    class LLVMGenerateResult : public VisitResult
    {
    public:
        LLVMGenerateResult(llvm::Value *value) noexcept
        {
            this->values.push_back(value);
        }

        LLVMGenerateResult(const std::vector<llvm::Value *> &values) noexcept
                : values(values)
        {}

        ~LLVMGenerateResult() noexcept = default;

        llvm::Value *getValue() const noexcept
        {
            if (this->values.empty()) return nullptr;
            else return this->values[0];
        }

        std::vector<llvm::Value *> &getValues() noexcept
        {
            return this->values;
        }

        operator llvm::Value *()
        {
            return this->getValue();
        }

    protected:
        std::vector<llvm::Value *> values;
    };
}
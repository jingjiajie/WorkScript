#pragma once

#include <unordered_map>
#include <llvm/IR/Value.h>

namespace WorkScript{
    class StringCache{
    public:
        void cacheLLVMStringPtr(const std::wstring &str, llvm::Value *v) noexcept;
        llvm::Value * getCachedLLVMStringPtr(const std::wstring &str) const noexcept;
    private:
        std::unordered_map<std::wstring, llvm::Value*> cachedString;
    };
}
#include "StringCache.h"

using namespace std;
using namespace WorkScript;

llvm::Value* StringCache::getCachedLLVMStringPtr(const std::wstring &str) const noexcept
{
    auto it = this->cachedString.find(str);
    if(it != this->cachedString.end()){
        return it->second;
    }
    return nullptr;
}

void StringCache::cacheLLVMStringPtr(const std::wstring &str, llvm::Value *v) noexcept
{
    this->cachedString[str] = v;
}
#pragma once

namespace WorkScript{
    class NonCopyable{
    public:
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable(NonCopyable&&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
        NonCopyable& operator=(NonCopyable&&) = delete;
    protected:
        NonCopyable(){}
        ~NonCopyable(){}
    };
};
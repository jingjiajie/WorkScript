#pragma once
#include "Value.h"

namespace WorkScript
{
    class Type;

    class InstantialContext;

    class Constant : public Value
    {
    public:
        explicit inline Constant(const ExpressionInfo &exprInfo) noexcept
                : Value(exprInfo)
        {}
    };
}

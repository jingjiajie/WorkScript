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

        virtual Type *getType() const noexcept = 0;

        Type *getType(InstantialContext *ctx) const override
        { return this->getType(); }
    };
}

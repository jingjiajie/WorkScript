#pragma once
#include "Type.h"

namespace WorkScript {
    class TypeWrapper
    {
    public:
        inline TypeWrapper(Type *t) noexcept
                :type(t) {	}

        inline TypeWrapper(const TypeWrapper &wrapper) noexcept
                :type(wrapper.type) {	}

        inline Type * getType() const
        {
            return this->type;
        }

        inline void setType(Type * t)
        {
            this->type = t;
        }

        operator Type*() {
            return this->type;
        }
    protected:
        Type * type;
    };

}
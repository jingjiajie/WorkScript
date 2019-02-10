#pragma once
#include <optional>
#include "Type.h"

namespace WorkScript
{
    class TypeWrapper
    {
    public:
        inline TypeWrapper(Type *t, const std::optional<LinkageType> &lt = std::nullopt) noexcept
                : type(t), linkageType(lt)
        {}

        inline TypeWrapper(const TypeWrapper &wrapper) noexcept
                : type(wrapper.type), linkageType(wrapper.linkageType)
        {}

        inline Type *getType() const
        {
            return this->type;
        }

        inline void setType(Type *t)
        {
            this->type = t;
        }

        operator Type *()
        {
            return this->type;
        }

        inline const std::optional<LinkageType> &getLinkageType() const
        {
            return linkageType;
        }

        inline void setLinkageType(LinkageType linkageType)
        {
            TypeWrapper::linkageType = linkageType;
        }

    protected:
        Type *type = nullptr;
        std::optional<LinkageType> linkageType = std::nullopt;
    };
}
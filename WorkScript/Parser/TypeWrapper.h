#pragma once

#include "Type.h"

namespace WorkScript
{
    class TypeWrapper
    {
    public:
        inline TypeWrapper(Type *t, StorageType st, LinkageType lt) noexcept
                : type(t), storageType(st), linkageType(lt)
        {}

        inline TypeWrapper(const TypeWrapper &wrapper) noexcept
                : type(wrapper.type)
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

        inline StorageType getStorageType() const
        {
            return storageType;
        }

        inline void setStorageType(StorageType storageType)
        {
            TypeWrapper::storageType = storageType;
        }

        inline LinkageType getLinkageType() const
        {
            return linkageType;
        }

        inline void setLinkageType(LinkageType linkageType)
        {
            TypeWrapper::linkageType = linkageType;
        }

    protected:
        Type *type;
        StorageType storageType = StorageType::DEFAULT;
        LinkageType linkageType = LinkageType::DEFAULT;
    };
}
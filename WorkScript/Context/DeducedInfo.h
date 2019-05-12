#pragma once

#include "ValueDescriptor.h"
#include "Exception.h"
#include <vector>

namespace WorkScript
{
    class Type;

    class DeducedInfo
    {
    public:
        DeducedInfo(const ValueDescriptor &v)
        {
            valueDescriptors.push_back(v);
        }

        DeducedInfo(const std::vector<ValueDescriptor> &v)
        :valueDescriptors(v) { }

        std::vector<Type*> getTypes() const noexcept;

        bool isSingle() const noexcept
        {
            return this->valueDescriptors.size() == 1;
        }

        ValueDescriptor &getValueDescriptor() noexcept
        {
            return this->valueDescriptors[0];
        }

        std::vector<ValueDescriptor> &getValueDescriptors() noexcept
        {
            return this->valueDescriptors;
        }

        operator Type *()
        {
            if (this->valueDescriptors.size() == 0) return nullptr;
            return this->valueDescriptors[0].getType();
        }

        operator ValueDescriptor &()
        {
            if (this->valueDescriptors.empty()) {
                throw InternalException(L"DeducedInfo::operator ValueDescriptor&() 不包含任何ValueDescriptor");
            }else if (this->valueDescriptors.size() > 1) {
                throw InternalException(L"DeducedInfo::operator ValueDescriptor&() 包含多个ValueDescriptor");
            }
            return this->valueDescriptors[0];
        }

    protected:
        std::vector<ValueDescriptor> valueDescriptors;
    };
}

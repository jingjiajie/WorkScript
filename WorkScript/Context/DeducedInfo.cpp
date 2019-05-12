#include "DeducedInfo.h"

using namespace WorkScript;
using namespace std;

std::vector<Type*> DeducedInfo::getTypes() const noexcept
{
    vector<Type*> types;
    types.reserve(this->valueDescriptors.size());
    for(size_t i=0; i<this->valueDescriptors.size(); ++i) {
        types.push_back((Type*)this->valueDescriptors[i].getType());
    }
    return types;
}
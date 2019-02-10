#include "FunctionQuery.h"
#include "Type.h"
#include <sstream>
#include <string>

using namespace std;
using namespace WorkScript;

std::wstring FunctionQuery::toString() const noexcept
{
    wstringstream ss;
    ss << this->name;
    ss << L"(";
    auto &paramTypes = this->functionTypeQuery.getParameterTypes();
    for(size_t i=0;i<paramTypes.size(); ++i)
    {
        if(i != 0){
            ss << L", ";
        }
        ss << paramTypes[i]->getName();
    }
    ss << L")";
    if(this->functionTypeQuery.mustConst()){
        ss << L" const";
    }
}
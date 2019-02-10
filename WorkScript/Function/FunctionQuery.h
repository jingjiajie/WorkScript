#pragma once
#include <string>
#include <vector>

namespace WorkScript{
    class Type;

    class FunctionTypeQuery{
    public:
        FunctionTypeQuery(const std::vector<Type*> &parameterTypes, bool mustConst)
        : parameterTypes(parameterTypes), _mustConst(mustConst)
        {}

        inline const std::vector<Type*> &getParameterTypes() const{return this->parameterTypes;}
        inline bool mustConst() const{return this->_mustConst;}
    private:
        std::vector<Type *> parameterTypes;
        bool _mustConst = false;
    };

    class FunctionQuery {
    public:
        inline FunctionQuery(const std::wstring &name,const std::vector<Type *> &paramTypes, bool mustConst)
        : name(name), functionTypeQuery(paramTypes, mustConst)
        { }

        std::wstring toString() const noexcept;
        inline const std::wstring &getName() const noexcept{return this->name;}
        inline const std::vector<Type*> &getParameterTypes() const noexcept{return this->functionTypeQuery.getParameterTypes();}
        inline bool isConst() const noexcept{return this->functionTypeQuery.mustConst();}
        inline const FunctionTypeQuery& getFunctionTypeQuery() const noexcept{return this->functionTypeQuery;}
    private:
        std::wstring name;
        FunctionTypeQuery functionTypeQuery;
    };
}
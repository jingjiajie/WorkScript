#pragma once
#include <string>
#include <vector>

namespace WorkScript{
    class Type;

    class FunctionTypeQuery{
    public:
        FunctionTypeQuery(const std::vector<Type*> &parameterTypes, bool isConst, bool isRuntimeVarargs, bool strict = false)
        : parameterTypes(parameterTypes), _const(isConst), _runtimeVarargs(isRuntimeVarargs), _strict(strict) { }

        inline const std::vector<Type*> &getParameterTypes() const noexcept{return this->parameterTypes;}
        inline bool isStrict() const noexcept{return this->_strict;}
        inline bool isConst() const noexcept{return this->_const;}
        inline bool isRuntimeVarargs() const noexcept{return this->_runtimeVarargs;}
    private:
        std::vector<Type *> parameterTypes;
        bool _const = false;
        bool _runtimeVarargs = false;
        bool _strict = false;
    };

    class FunctionQuery {
    public:
        inline FunctionQuery(const std::wstring &name,const std::vector<Type *> &paramTypes, bool mustConst, bool strict = false)
        : name(name), functionTypeQuery(paramTypes, mustConst, strict)
        { }

        std::wstring toString() const noexcept;
        inline const std::wstring &getName() const noexcept{return this->name;}
        inline const std::vector<Type*> &getParameterTypes() const noexcept{return this->functionTypeQuery.getParameterTypes();}
        inline bool isConst() const noexcept{return this->functionTypeQuery.isConst();}
        inline bool isStrict() const noexcept{ return this->functionTypeQuery.isStrict();}
        inline const FunctionTypeQuery& getFunctionTypeQuery() const noexcept{return this->functionTypeQuery;}
    private:
        std::wstring name;
        FunctionTypeQuery functionTypeQuery;
    };
}
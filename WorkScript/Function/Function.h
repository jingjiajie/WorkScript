#pragma once
#include <vector>

#include "Parameter.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "SymbolTable.h"

namespace WorkScript
{
    class FunctionType;
    class FunctionFragment;

    class ParamTypesAndLLVMFunction
    {
    public:
        ParamTypesAndLLVMFunction(const std::vector<Type *> &paramTypes, llvm::Function *func)
                : parameterTypes(paramTypes), llvmFunction(func)
        {}

        bool match(const std::vector<Type *> &paramTypes) noexcept;

        inline llvm::Function *getLLVMFunction() noexcept
        { return this->llvmFunction; }

    protected:
        std::vector<Type *> parameterTypes;
        llvm::Function *llvmFunction;
    };


    class Function
    {
    public:
        Function(AbstractContext *baseContext,
                 const std::wstring &name,
                 FunctionType *declType,
                 LinkageType lt = LinkageType::EXTERNAL) noexcept;

        std::wstring getMangledFunctionName(const DebugInfo &d, const std::vector<Type*> &paramTypes) const noexcept;
        static std::wstring getMangledFunctionName(const DebugInfo &d, AbstractContext *ctx, const std::wstring &name, const std::vector<Type*> &paramTypes) noexcept;
        llvm::Function *
        getLLVMFunction(const DebugInfo &d, GenerateContext *context,const std::vector<Type*> &paramTypes, bool declareOnly = false);

        Type *getReturnType(const DebugInfo &d, InstantialContext *instCtx, const std::vector<Type*> &paramTypes);

        inline FunctionType *getType() noexcept
        { return this->type; }

        inline void setReturnType(Type *type) noexcept
        {
            this->type = FunctionType::get(this->type->getParameterTypes(), type, this->type->isRumtimeVarargs(),
                                           this->type->isConst());
        }

        bool match(const DebugInfo &d, const FunctionQuery &query) noexcept;

        inline const LinkageType &getLinkageType() const noexcept
        { return this->linkageType; }

        inline void setLinkageType(const LinkageType &lt) noexcept
        {
            this->linkageType = lt;
        }

        inline Program *getProgram() const noexcept
        { return this->program; }

        inline size_t getParameterCount() const noexcept
        { return this->type->getParameterCount(); }

//		std::vector<Type*> getParameterTypes(const DebugInfo &d, InstantialContext *context,  const std::vector<Type*> &realParamTypes) const;
        inline std::wstring getName() const noexcept
        { return this->name; }

        inline AbstractContext *getBaseContext() noexcept
        { return this->baseContext; }

        void addFragment(FunctionFragment *fragment) noexcept;

        void addFragments(const std::vector<FunctionFragment *> &fragments) noexcept;

        size_t getFragmentCount() const noexcept
        { return this->fragments.size(); }

    protected:
        std::wstring name;
        Program *program = nullptr;
        std::vector<ParamTypesAndLLVMFunction> llvmFunctions;
        FunctionType *type;
        LinkageType linkageType;
        AbstractContext *baseContext;
        std::vector<FunctionFragment *> fragments;

        GenerateResult
        generateLLVMIR(const DebugInfo &d, GenerateContext *context, const std::vector<Type*> &paramTypes);
    };
}

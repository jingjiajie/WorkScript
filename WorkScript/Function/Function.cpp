#include <sstream>
#include "Function.h"
#include "Locales.h"
#include "InstantialContext.h"
#include "FunctionType.h"
#include "FunctionBranch.h"
#include "Exception.h"

using namespace std;
using namespace WorkScript;

Function::Function(
        AbstractContext *baseContext,
        const std::wstring &name,
        const std::vector<Type *> &paramTypes,
        Type *returnType,
        bool declaredReturnType,
        bool isRuntimeVarargs,
        bool isStaticVarargs,
        LinkageType lt)
        : name(name), declaredReturnType(declaredReturnType), linkageType(lt), runtimeVarargs(isRuntimeVarargs),
          staticVarargs(isStaticVarargs), baseContext(baseContext)
{
    FunctionType *funcType = FunctionType::get(paramTypes, returnType);
    this->abstractType = funcType;
}

WorkScript::Function::~Function()
{
    for (auto br : this->branches)
    {
        delete br;
    }
}

std::wstring WorkScript::Function::getStdParameterName(size_t paramIndex)
{
    return L"@" + to_wstring(paramIndex);
}

std::wstring Function::getMangledFunctionName(const DebugInfo &d, InstantialContext *ctx) const
{
    wstringstream ss;
    ss << this->getName();
    for (auto paramType : this->getParameterTypes(d, ctx))
    {
        ss << L"@" << paramType->getName();
    }
    return ss.str();
}

llvm::Function *Function::getLLVMFunction(const DebugInfo &d, GenerateContext *context, bool declareOnly)
{
    InstantialContext *outerInstCtx = context->getInstantialContext();
    auto paramTypes = this->getParameterTypes(d, outerInstCtx);
    llvm::Function *matchedFunc = nullptr;
    for (size_t i = 0; i < this->llvmFunctions.size(); ++i)
    {
        if (this->llvmFunctions[i].match(paramTypes)) matchedFunc = this->llvmFunctions[i].getLLVMFunction();
    }
    //如果没找到，则新生成一个LLVM Function
    if (!matchedFunc)
    {
        //生成函数类型
        vector<llvm::Type *> llvmParamTypes;
        llvmParamTypes.reserve(this->getParameterCount() + 1);
        for (size_t i = 0; i < this->getParameterCount(); ++i)
        {
            Type *paramType = paramTypes[i];
            llvmParamTypes.push_back(paramType->getLLVMType(context));
        }
        Type *myReturnType = this->getReturnType(d, outerInstCtx);
        llvm::FunctionType *funcType = llvm::FunctionType::get(myReturnType->getLLVMType(context), llvmParamTypes,
                                                               this->runtimeVarargs);
        //创建函数声明
        wstring funcName;
        if (this->baseContext->getFunctions(this->name).size() > 1)
        {
            funcName = this->getMangledFunctionName(d, outerInstCtx);
        } else
        {
            funcName = this->name;
        }
        llvm::Function::LinkageTypes linkageType;
        switch(this->linkageType){
            case LinkageType::DEFAULT:
            case LinkageType::EXTERNAL:
                linkageType = llvm::Function::LinkageTypes::ExternalLinkage;
                break;
            case LinkageType::INTERNAL:
                linkageType = llvm::Function::LinkageTypes::InternalLinkage;
                break;
        }

        llvm::Function *func =
                llvm::Function::Create(funcType,
                                       linkageType,
                                       Locales::fromWideChar(Encoding::ANSI, funcName),
                                       context->getLLVMModule()
                );
        //添加函数参数名
        //参数名为@0,@1...
        auto itArg = func->arg_begin();
        for (size_t i = 0; i < llvmParamTypes.size(); ++i)
        {
            itArg->setName(Locales::fromWideChar(Encoding::ANSI, L"@" + to_wstring(i)));
            ++itArg;
        }
        this->llvmFunctions.emplace_back(paramTypes, func);
        matchedFunc = func;
        if (!declareOnly)this->generateLLVMIR(d, context);
    }
    return matchedFunc;
}

void WorkScript::Function::setReturnType(Type *returnType)
{
    this->abstractType = FunctionType::get(this->abstractType->getParameterTypes(), returnType);
}

MatchResult WorkScript::Function::matchByParameters(const DebugInfo &d, const std::vector<Type *> &declParamTypes,
                                                    const std::vector<Type *> &realParamTypes, bool isRuntimeVarargs,
                                                    bool isStaticVarargs)
{
    bool compromised = false;
    size_t declParamCount = declParamTypes.size();
    //TODO 需要考虑参数默认值
    if (realParamTypes.size() < declParamCount)return MISMATCHED;
    if (declParamCount != realParamTypes.size()
        && !isRuntimeVarargs
        && !isStaticVarargs)
        return MISMATCHED;
    for (size_t i = 0; i < declParamCount; ++i)
    {
        Type *formalParamType = declParamTypes[i];
        if (!realParamTypes[i])continue;
        if (formalParamType && !formalParamType->equals(realParamTypes[i]))
        {
            if (Type::convertableTo(d, realParamTypes[i], formalParamType)) compromised = true;
            else return MISMATCHED;
        }
    }
    return compromised ? COMPROMISE_MATCHED : MATCHED;
}

MatchResult WorkScript::Function::matchByParameters(const DebugInfo &d, const std::vector<Type *> &paramTypes)
{
    auto declParamTypes = this->abstractType->getParameterTypes();
    return Function::matchByParameters(d, declParamTypes, paramTypes, this->runtimeVarargs, this->staticVarargs);
}

inline std::vector<Type *> WorkScript::Function::getParameterTypes(const DebugInfo &d, InstantialContext *context) const
{
    auto declParamTypes = this->abstractType->getParameterTypes();
    if (!context)return declParamTypes;
    vector<Type *> realParamTypes;
    size_t paramCount = this->getParameterCount();
    realParamTypes.reserve(paramCount);
    for (size_t i = 0; i < paramCount; ++i)
    {
        wstring curParamName = Function::getStdParameterName(i);
        SymbolInfo *info = context->getSymbolInfo(curParamName);
        if (!info)
        {
            if (i == 0)
            {
                realParamTypes = declParamTypes;
                break;
            } else
            {
                d.getReport()->error(TypeMismatchedError(d, L"参数不匹配！"), ErrorBehavior::CANCEL_EXPRESSION);
            }
        } else
        {
            realParamTypes.push_back(info->getType());
        }
    }

    std::vector<Type *> result;
    result.reserve(paramCount);
    for (size_t i = 0; i < paramCount; ++i)
    {
        if (declParamTypes[i] == nullptr)
        {
            result.push_back(realParamTypes[i]);
        } else if (realParamTypes[i]->convertableTo(d, declParamTypes[i]))
        {
            result.push_back(declParamTypes[i]);
        } else
        {
            d.getReport()->error(TypeMismatchedError(d, L"参数类型不匹配！"), ErrorBehavior::CANCEL_EXPRESSION);
        }
    }
    return result;
}

bool WorkScript::ParamTypesAndLLVMFunction::match(std::vector<Type *> paramTypes)
{
    for (size_t i = 0; i < this->parameterTypes.size(); ++i)
    {
        if (!this->parameterTypes[i]->equals(paramTypes[i]))return false;
    }
    return true;
}

Type *Function::getReturnType(const DebugInfo &d, InstantialContext *instCtx)
{
    /*	推导返回值：
    *	如果声明了返回值类型，则以声明为准
    *	否则，遍历所有函数分支，忽略所有nullptr（未知）的返回值
    *	取所有可推导返回值中类型最高的作为函数返回值，	其他分支在返回时视情况做相应的类型转换
    *	如果所有分支返回值都为nullptr（未知），则函数返回值为nullptr
    */
    if (this->abstractType->getReturnType())
    {
        return this->abstractType->getReturnType();
    }
    SymbolTable instSymbolTable;
    auto paramTypes = this->getParameterTypes(d, instCtx);
    for (size_t i = 0; i < this->getParameterCount(); ++i)
    {
        SymbolInfo *curInfo = instSymbolTable.setSymbol(d, L"@" + to_wstring(i), paramTypes[i], LinkageType::DEFAULT);
    }
    auto prevTable = instCtx->getInstanceSymbolTable();
    instCtx->setInstanceSymbolTable(&instSymbolTable);
    Type *returnType = nullptr;
    if (!instCtx->getFunctionTypeCache(d, this, paramTypes, this->runtimeVarargs, this->staticVarargs, &returnType))
    {
        instCtx->setFunctionTypeCache(d, this, paramTypes, this->runtimeVarargs, this->staticVarargs, nullptr);
        //推导每个分支的返回值，取最高类型
        for (size_t i = 0; i < this->branches.size(); ++i)
        {

            Type *curReturnType = this->branches[i]->getReturnType(d, instCtx);
            if (!curReturnType) continue;
            returnType = Type::getPromotedType(d, curReturnType, returnType);
        }
    }
    instCtx->setInstanceSymbolTable(prevTable);
    instCtx->setFunctionTypeCache(d, this, paramTypes, this->runtimeVarargs, this->staticVarargs, returnType);
    return returnType;
}

GenerateResult WorkScript::Function::generateLLVMIR(const DebugInfo &d, GenerateContext *context)
{
    llvm::Function *llvmFunc = this->getLLVMFunction(d, context, true);
    //如果没有实现，则只生成函数声明，且不进行命名粉碎
    if (this->branches.size() > 0)
    {
        llvmFunc = this->getLLVMFunction(d, context, true);
        InstantialContext *outerInstCtx = context->getInstantialContext();
        auto prevTable = outerInstCtx->getInstanceSymbolTable();
        llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", llvmFunc);
        llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", llvmFunc);
        llvm::IRBuilder<> builder(entry);
        context->setIRBuilder(&builder);
        //生成参数的LLVM Value
        SymbolTable instSymbolTable;
        auto paramTypes = this->getParameterTypes(d, outerInstCtx);
        llvm::Argument *itArg = llvmFunc->arg_begin();
        for (size_t i = 0; i < this->getParameterCount(); ++i)
        {
            SymbolInfo *curInfo = instSymbolTable.setSymbol(d, L"@" + to_wstring(i), paramTypes[i], LinkageType::DEFAULT);
            curInfo->setLLVMValue(itArg);
            ++itArg;
        }
        outerInstCtx->setInstanceSymbolTable(&instSymbolTable);
        size_t branchCount = this->branches.size();
        llvm::BasicBlock *prevBlock = notMatched;
        //遍历分支，为每个分支生成代码
        for (size_t i = 0; i < this->branches.size(); ++i)
        {
            FunctionBranch *curBranch = this->branches[branchCount - 1 - i];
            try
            {
                prevBlock = curBranch->generateBlock(context, llvmFunc, prevBlock);
            }catch (const BlockCanceledException&){
                continue;
            }
        }
        builder.SetInsertPoint(entry);
        builder.CreateBr(prevBlock);
        //如果全部匹配失败，则返回未定义值
        builder.SetInsertPoint(notMatched);
        builder.CreateRet(llvm::UndefValue::get(this->getReturnType(d, outerInstCtx)->getLLVMType(context)));
        context->setIRBuilder(prevBuilder);
        outerInstCtx->setInstanceSymbolTable(prevTable);
    }
    llvm::verifyFunction(*llvmFunc);
    return (llvm::Value *) llvmFunc;
}

size_t WorkScript::Function::addBranch(FunctionBranch *branch)
{
    auto params = branch->getParameters();
    if (params.size() != this->getParameterCount())
    {
        branch->getDebugInfo().getReport()->error(TypeMismatchedError(branch->getDebugInfo(), L"函数参数不匹配！"), ErrorBehavior::CONTINUE);
    }
    this->branches.push_back(branch);
    return this->branches.size() - 1;
}

LinkageType Function::getLinkageType() const
{
    return linkageType;
}

void Function::setLinkageType(LinkageType linkageType)
{
    Function::linkageType = linkageType;
}



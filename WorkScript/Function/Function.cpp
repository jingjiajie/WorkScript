#include <sstream>
#include "Function.h"
#include "Locales.h"
#include "InstantialContext.h"
#include "FunctionType.h"
#include "FunctionFragment.h"
#include "Exception.h"
#include "FunctionCache.h"

using namespace std;
using namespace WorkScript;

Function::Function(
        AbstractContext *baseContext,
        const std::wstring &name,
        FunctionType *declType,
        LinkageType lt) noexcept
        : name(name), type(declType), linkageType(lt), baseContext(baseContext)
{

}

std::wstring Function::getMangledFunctionName(const DebugInfo &d, const std::vector<Type*> &paramTypes) const noexcept
{
    return Function::getMangledFunctionName(d, this->getName(), paramTypes, false);
}

std::wstring Function::getMangledFunctionName(const DebugInfo &d, const wstring &name, const vector<Type *> &paramTypes, bool isRuntimeVarargs) noexcept
{
    if(name == L"main") return name; //对main不做命名粉碎
    wstringstream ss;
    ss << L"_Z" << name.size() << name;
    if(paramTypes.empty()){
        ss << VoidType::get()->getMangledName();
    }else
    {
        for (size_t i = 0; i < paramTypes.size(); ++i)
        {
            ss << paramTypes[i]->getMangledName();
        }
    }
    if(isRuntimeVarargs){
        ss << L"z";
    }
    return ss.str();
}

llvm::Function *Function::getLLVMFunction(const DebugInfo &d, GenerateContext *context, const std::vector<Type*> &paramTypes, bool declareOnly)
{
    InstantialContext *outerInstCtx = context;
    llvm::Function *matchedFunc = nullptr;
    for (size_t i = 0; i < this->llvmFunctions.size(); ++i)
    {
        if (this->llvmFunctions[i].match(paramTypes)) matchedFunc = this->llvmFunctions[i].getLLVMFunction();
    }

    Type *myReturnType = nullptr;
    try
    { //获取返回值类型，如果遇到CanceledException，则不管是不是SFINAE，都抛错
        myReturnType = this->getReturnType(d, outerInstCtx, paramTypes);
    }
    catch (const CancelException &ex)
    {
        ex.rethrowAbove(CancelScope::FUNCTION);
        throw CancelException(CancelScope::EXPRESSION);
    }
    //如果没找到，则新生成一个LLVM Function
    if (!matchedFunc)
    {
        wstring funcName;
        funcName = this->getMangledFunctionName(d, paramTypes);
        llvm::Function::LinkageTypes linkageType;
        switch (this->linkageType.getClassification())
        {
            case LinkageType::Classification::EXTERNAL:
                linkageType = llvm::Function::LinkageTypes::ExternalLinkage;
                break;
            case LinkageType::Classification::INTERNAL:
                linkageType = llvm::Function::LinkageTypes::InternalLinkage;
                break;
        }

        llvm::Type *llvmReturnType = myReturnType->getLLVMType(context);
        llvm::Function *func = nullptr;
        //创建函数
        //生成函数类型
        vector<llvm::Type *> llvmParamTypes;
        llvmParamTypes.reserve(paramTypes.size() + 1);
        for (size_t i = 0; i < paramTypes.size(); ++i)
        {
            Type *paramType = paramTypes[i];
            llvmParamTypes.push_back(paramType->getLLVMType(context));
        }
        llvm::FunctionType *funcType = llvm::FunctionType::get(llvmReturnType, llvmParamTypes,
                                                               this->type->isRumtimeVarargs());
        func = llvm::Function::Create(funcType,
                                      linkageType,
                                      Locales::fromWideChar(Encoding::ANSI, funcName),
                                      context->getLLVMModule()
        );
        //参数名为@0,@1...
        auto itArg = func->arg_begin();
        for (size_t i = 0; i < llvmParamTypes.size(); ++i)
        {
            itArg->setName(Locales::fromWideChar(Encoding::ANSI, L"@" + to_wstring(i)));
            ++itArg;
        }
        this->llvmFunctions.push_back(ParamTypesAndLLVMFunction(paramTypes, func));
        matchedFunc = func;
        if (!declareOnly) this->generateLLVMIR(d, context, paramTypes);
    }
    return matchedFunc;
}

bool WorkScript::Function::match(const DebugInfo &d, const FunctionQuery &query) noexcept
{
    if(query.getName() != this->name)return false;
    return FunctionType::matchCall(d, this->type, query.getFunctionTypeQuery());
}

bool ParamTypesAndLLVMFunction::match(const std::vector<Type *> &paramTypes) noexcept
{
	size_t expectedParamCount = paramTypes.size();
	size_t myParamCount = this->parameterTypes.size();
	if(expectedParamCount != myParamCount) return false;
    for (size_t i = 0; i < myParamCount; ++i)
    {
        if (!this->parameterTypes[i]->equals(paramTypes[i]))return false;
    }
    return true;
}

Type *Function::getReturnType(const DebugInfo &d, InstantialContext *instCtx,const std::vector<Type*> &paramTypes)
{
    /*	推导返回值：
    *	如果声明了返回值类型，则以声明为准
    *	否则，遍历所有函数分支，忽略所有nullptr（未知）的返回值
    *	取所有可推导返回值中类型最高的作为函数返回值，	其他分支在返回时视情况做相应的类型转换
    *	如果所有分支返回值都为nullptr（未知），则函数返回值为nullptr
    */
    if (this->type->getReturnType())
    {
        return this->type->getReturnType();
    }
    FunctionType *cachedFuncType = nullptr;
    Type *returnType = nullptr;
    FunctionType *queryType = FunctionType::get(paramTypes, nullptr, this->type->isRumtimeVarargs(), this->type->isConst());
    if (!instCtx->getCachedFunctionType(d, this, FunctionTypeQuery(paramTypes,this->type->isConst(), this->type->isRumtimeVarargs()), &cachedFuncType))
    {
        instCtx->cacheFunctionType(d, this, queryType);
		size_t fragmentCanceledCount = 0;
        //推导每个Fragment的返回值，取最高类型
        for (size_t i = 0; i < this->fragments.size(); ++i)
        {
			try {
				Type *curReturnType = this->fragments[i]->getReturnType(d, instCtx, paramTypes);
				if (!curReturnType) continue;
				returnType = Type::getPromotedType(d, curReturnType, returnType);
			} /*如果在SFINAE模式下，遇到Fragment返回值抛出Cancel异常，则忽略此Fragment，
			  非SFINAE模式下直接抛ExpressionCanceled*/
			catch (const CancelException &ex) {
			    ex.rethrowAbove(CancelScope::FUNCTION);
				if (this->fragments[i]->isStaticVarargs()) {
					++fragmentCanceledCount;
					continue;
				}
				else {
					CancelException ex(CancelScope::EXPRESSION);
                    instCtx->getFunctionCache()->cacheFunctionType(d, this, queryType, ex);
                    throw ex;
				}
			}
        }
		/*如果所有分支都被取消了，则函数被取消（肯定是SFINAE，如果不是SFINAE则当时就抛错了）*/
		if (fragmentCanceledCount == this->fragments.size()) {
            CancelException ex(CancelScope::EXPRESSION);
		    instCtx->getFunctionCache()->cacheFunctionType(d, this, queryType, ex);
            throw ex;
		}
    }else{
        returnType = cachedFuncType->getReturnType();
    }
    instCtx->cacheFunctionType(d, this,FunctionType::get(paramTypes, returnType, this->type->isRumtimeVarargs(), this->type->isConst()));
	return returnType;
}

GenerateResult Function::generateLLVMIR(const DebugInfo &d, GenerateContext *context, const std::vector<Type*> &paramTypes)
{
	llvm::Function *llvmFunc = nullptr;
	try {
		llvmFunc = this->getLLVMFunction(d, context, paramTypes, true);
	}
	catch (const CancelException &ex) {
	    ex.rethrowAbove(CancelScope::FUNCTION);
        throw CancelException(CancelScope::EXPRESSION);
	}
    //如果没有实现，则只生成函数声明
    if (!this->fragments.empty())
    {
		Type *returnType = this->getReturnType(d, context, paramTypes);
        InstantialContext *outerInstCtx = context;
        llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", llvmFunc);
        llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", llvmFunc);
        llvm::IRBuilder<> builder(entry);
        context->setIRBuilder(&builder);
        size_t branchCount = this->fragments.size();
        llvm::BasicBlock *prevBlock = notMatched;
        //遍历分支，为每个分支生成代码
        for (size_t i = 0; i < this->fragments.size(); ++i)
        {
            FunctionFragment *curBranch = this->fragments[branchCount - 1 - i];
            try
            {
                prevBlock = curBranch->generateBlock(context, paramTypes, returnType, llvmFunc, prevBlock);
            }catch (const CancelException &ex){
                ex.rethrowAbove(CancelScope::FUNCTION);
                continue;
            }
        }
        builder.SetInsertPoint(entry);
        builder.CreateBr(prevBlock);
        //如果全部匹配失败，则返回未定义值
        builder.SetInsertPoint(notMatched);
        Type *myReturnType = this->getReturnType(d, outerInstCtx, paramTypes);
        builder.CreateRet(llvm::UndefValue::get(myReturnType->getLLVMType(context)));
        context->setIRBuilder(prevBuilder);
    }
    llvm::verifyFunction(*llvmFunc);
    return (llvm::Value *) llvmFunc;
}

void WorkScript::Function::addFragment(FunctionFragment *fragment) noexcept
{
    this->addFragments({fragment});
}


void Function::addFragments(const std::vector<FunctionFragment *> &fragments) noexcept
{
    this->fragments.insert(this->fragments.end(), fragments.begin(), fragments.end());
}

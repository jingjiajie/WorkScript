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

std::wstring Function::getMangledFunctionName(const DebugInfo &d) const noexcept
{
    wstringstream ss;
    ss << this->getName();
    for (auto paramType : this->type->getParameterTypes())
    {
        ss << L"@" << paramType->getName();
    }
    return ss.str();
}

llvm::Function *Function::getLLVMFunction(const DebugInfo &d, GenerateContext *context, bool declareOnly)
{
    InstantialContext *outerInstCtx = context->getInstantialContext();
    llvm::Function *matchedFunc = nullptr;
    for (size_t i = 0; i < this->llvmFunctions.size(); ++i)
    {
        if (this->llvmFunctions[i].match(this->type->getParameterTypes())) matchedFunc = this->llvmFunctions[i].getLLVMFunction();
    }

	Type *myReturnType = nullptr;
	try { //获取返回值类型，如果遇到CanceledException，则不管是不是SFINAE，都抛错
		myReturnType = this->getReturnType(d, outerInstCtx);
	}
	catch (const CanceledException&) {
		throw ExpressionCanceledException();
	}
    //如果没找到，则新生成一个LLVM Function
    if (!matchedFunc)
    {
        //生成函数类型
        vector<llvm::Type *> llvmParamTypes;
        llvmParamTypes.reserve(this->getParameterCount() + 1);
        for (size_t i = 0; i < this->getParameterCount(); ++i)
        {
            Type *paramType = this->type->getParameterTypes()[i];
            llvmParamTypes.push_back(paramType->getLLVMType(context));
        }
        llvm::FunctionType *funcType = llvm::FunctionType::get(myReturnType->getLLVMType(context), llvmParamTypes,
                                                               this->type->isRumtimeVarargs());
        //创建函数声明
        wstring funcName;
        if (this->baseContext->getFunctions(d, this->name).size() > 1)
        {
            funcName = this->getMangledFunctionName(d);
        } else
        {
            funcName = this->name;
        }
        llvm::Function::LinkageTypes linkageType;
        switch(this->linkageType.getClassification()){
            case LinkageType::Classification::EXTERNAL:
                linkageType = llvm::Function::LinkageTypes::ExternalLinkage;
                break;
            case LinkageType::Classification::INTERNAL:
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
        this->llvmFunctions.emplace_back(this->type->getParameterTypes(), func);
        matchedFunc = func;
        if(!declareOnly) this->generateLLVMIR(d, context);
    }
    return matchedFunc;
}

bool WorkScript::Function::match(const DebugInfo &d, const FunctionQuery &query) noexcept
{
    if(query.getName() != this->name)return false;
    return FunctionType::match(d, this->type, query.getFunctionTypeQuery());
}
//
//inline std::vector<Type *> Function::getParameterTypes(const DebugInfo &d, InstantialContext *context, const FunctionTypeQuery &query) const
//{
//    auto declParamTypes = this->type->getParameterTypes();
//    if (!context)return declParamTypes;
//    vector<Type *> realParamTypes;
//    size_t paramCount = this->getParameterCount();
//    realParamTypes.reserve(paramCount);
//    for (size_t i = 0; i < paramCount; ++i)
//    {
//        wstring curParamName = Function::getStdParameterName(i);
//        SymbolInfo *info = context->getSymbolInfo(curParamName);
//        if (!info)
//        {
//            if (i == 0)
//            {
//                realParamTypes = declParamTypes;
//                break;
//            } else
//            {
//                d.getReport()->error(TypeMismatchedError(d, L"参数不匹配！"), ErrorBehavior::CANCEL_EXPRESSION);
//            }
//        } else
//        {
//            realParamTypes.push_back(info->getType());
//        }
//    }
//
//    std::vector<Type *> result;
//    result.reserve(paramCount);
//    for (size_t i = 0; i < paramCount; ++i)
//    {
//        if (declParamTypes[i] == nullptr)
//        {
//            result.push_back(realParamTypes[i]);
//        } else if (realParamTypes[i]->convertableTo(d, declParamTypes[i]))
//        {
//            result.push_back(declParamTypes[i]);
//        } else
//        {
//            d.getReport()->error(TypeMismatchedError(d, L"参数类型不匹配！"), ErrorBehavior::CANCEL_EXPRESSION);
//        }
//    }
//    return result;
//}

bool WorkScript::ParamTypesAndLLVMFunction::match(std::vector<Type *> paramTypes) noexcept
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
    if (this->type->getReturnType())
    {
        return this->type->getReturnType();
    }
    FunctionType *cachedFuncType = nullptr;
    Type *returnType = nullptr;
    if (!instCtx->getCachedFunctionType(d, this, FunctionTypeQuery(this->type->getParameterTypes(),this->type->isConst()), &cachedFuncType))
    {
        instCtx->cacheFunctionType(d, this, this->type);
		size_t fragmentCanceledCount = 0;
        //推导每个Fragment的返回值，取最高类型
        for (size_t i = 0; i < this->fragments.size(); ++i)
        {
			try {
				Type *curReturnType = this->fragments[i]->getReturnType(d, instCtx, this->type->getParameterTypes());
				if (!curReturnType) continue;
				returnType = Type::getPromotedType(d, curReturnType, returnType);
			} /*如果在SFINAE模式下，遇到Fragment返回值抛出Cancel异常，则忽略此Fragment，
			  非SFINAE模式下直接抛ExpressionCanceled*/
			catch (const CanceledException &) {
				if (instCtx->getBlockAttribute(BlockAttribute::SFINAE)) {
					++fragmentCanceledCount;
					continue;
				}
				else {
					throw ExpressionCanceledException();
				}
			}
        }
		/*如果所有分支都被取消了，则函数被取消（肯定是SFINAE，如果不是SFINAE则当时就抛错了）*/
		if (fragmentCanceledCount == this->fragments.size()) {
			throw ExpressionCanceledException();
		}
    }else{
        returnType = cachedFuncType->getReturnType();
    }
    instCtx->cacheFunctionType(d, this,FunctionType::get(this->type->getParameterTypes(), returnType, this->type->isRumtimeVarargs(), this->type->isConst()));
	return returnType;
}

GenerateResult Function::generateLLVMIR(const DebugInfo &d, GenerateContext *context)
{
	llvm::Function *llvmFunc = nullptr;
	try {
		this->getLLVMFunction(d, context, true);
	}
	catch (const CanceledException&) {
		throw ExpressionCanceledException();
	}
    //如果没有实现，则只生成函数声明，且不进行命名粉碎
    if (!this->fragments.empty())
    {
		Type *returnType = this->getReturnType(d, context->getInstantialContext());
        const auto &paramTypes = this->type->getParameterTypes();
        InstantialContext *outerInstCtx = context->getInstantialContext();
        llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", llvmFunc);
        llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", llvmFunc);
        llvm::IRBuilder<> builder(entry);
        context->setIRBuilder(&builder);
        //生成参数的LLVM Value
        SymbolTable instSymbolTable;
		InstantialContext innerInstCtx(outerInstCtx, &instSymbolTable);
        size_t branchCount = this->fragments.size();
        llvm::BasicBlock *prevBlock = notMatched;
        //遍历分支，为每个分支生成代码
        for (size_t i = 0; i < this->fragments.size(); ++i)
        {
            FunctionFragment *curBranch = this->fragments[branchCount - 1 - i];
            try
            {
                prevBlock = curBranch->generateBlock(context, paramTypes, returnType, llvmFunc, prevBlock);
            }catch (const CanceledException&){
                continue;
            }
        }
        builder.SetInsertPoint(entry);
        builder.CreateBr(prevBlock);
        //如果全部匹配失败，则返回未定义值
        builder.SetInsertPoint(notMatched);
        Type *myReturnType = this->getReturnType(d, outerInstCtx);
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

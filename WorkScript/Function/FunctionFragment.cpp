#include "Variable.h"
#include "FunctionFragment.h"
#include "InstantialContext.h"
#include "Parameter.h"
#include "Locales.h"
#include "Exception.h"
#include "Function.h"
#include "MultiValueType.h"
#include "MultiValue.h"

using namespace WorkScript;
using namespace std;

FunctionFragment::FunctionFragment(const DebugInfo &d,
		AbstractContext *ctx,
		const std::wstring &name,
		const std::vector<Parameter*> &params,
		bool isConst,
		bool isRuntimeVarargs,
		const std::optional<std::wstring> &staticVarargsName,
		const LinkageType &lt,
		const std::vector<Expression*>& constraints,
		const std::vector<Expression*>& implements,
		Type *declReturnType) noexcept
	:name(name), context(d, ctx, ctx->getFunctionFragmentCount()),parameters(params),declReturnType(declReturnType),
	_staticVarargs(staticVarargsName.has_value()), staticVarargsName(staticVarargsName.value_or(L"")), _runtimeVarargs(isRuntimeVarargs),
	_const(isConst), linkageType(lt), constraints(constraints), implements(implements)
{
}

WorkScript::FunctionFragment::~FunctionFragment() noexcept
{
	for (auto expr : this->constraints) {
		delete expr;
	}
	for (auto expr : this->implements) {
		delete expr;
	}
}

Type * FunctionFragment::getReturnType(const DebugInfo &d, InstantialContext * ctx, const std::vector<Type*> &paramTypes)
{
    if(this->declReturnType) return this->declReturnType;
	size_t implCount = this->implements.size();
	if (implCount == 0)return VoidType::get();
    InstantialContext innerCtx(ctx, to_wstring(this->context.getBlockID()));
    if(this->_staticVarargs) innerCtx.setBlockAttribute(BlockAttributeItem::SFINAE, true);
    auto &instSymbolTable = *innerCtx.getInstanceSymbolTable();
	for (size_t i = 0; i < this->parameters.size(); ++i)
	{
		Type *curParamType = paramTypes[i];
		//获取当前分支参数的符号信息，加入符号表
		Parameter *myParam = this->parameters[i];
		instSymbolTable.setSymbol(d, myParam->getName(), curParamType, LinkageType::INTERNAL);
	}
	//处理可能的变参情况，注意参数个数相等的情况也要处理变参，此时变参匹配数量为0
	if (this->_staticVarargs)
	{
		if(this->parameters.size() > paramTypes.size())
		{
			throw InternalException(L"参数个数匹配错误");
		}
		size_t varargLen = paramTypes.size() - this->parameters.size();
		vector<Type *> varargItemTypes;
		varargItemTypes.insert(varargItemTypes.end(), paramTypes.begin() + (paramTypes.size() - varargLen),
							   paramTypes.end());
		MultiValueType *type = MultiValueType::get(varargItemTypes);
		instSymbolTable.setSymbol(d, this->staticVarargsName, type, LinkageType::INTERNAL);
	} else if (this->_runtimeVarargs)
	{
		/*什么都不用做*/
	} else if(this->parameters.size() != paramTypes.size())
	{
		throw InternalException(L"参数个数匹配错误");
	}

	try {
	    //TODO 推导返回值类型没必要把每条语句都推导一次, 应该记录下来各个变量的声明语句，在推导返回值类型需要变量时，直接推导声明语句即可
	    for(size_t i=0; i<implCount-1; ++i) {
            this->implements[i]->getType(&innerCtx);
        }
		return this->implements[implCount - 1]->getType(&innerCtx);
	}
	catch (const CancelException &ex)
    {
        ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
        throw CancelException(CancelScope::EXPRESSION);
    }
}

llvm::BasicBlock * FunctionFragment::generateBlock(GenerateContext * outerCtx,
		const std::vector<Type*> &paramTypes,
		Type *returnType,
		llvm::Function *llvmFunc,
		llvm::BasicBlock *falseBlock)
{
    GenerateContext innerCtx(outerCtx, to_wstring(this->getBlockID()));
    if (this->_staticVarargs) innerCtx.setBlockAttribute(BlockAttributeItem::SFINAE, true);
    SymbolTable &instSymbolTable = *innerCtx.getInstanceSymbolTable();
    size_t realParamCount = paramTypes.size();
    size_t myParamCount = this->parameters.size();

    /*开始创建LLVM对象*/
    llvm::BasicBlock *fragmentBlock = llvm::BasicBlock::Create(*outerCtx->getLLVMContext(), "branch", llvmFunc);
    llvm::IRBuilder<> &builder = *innerCtx.getIRBuilder();
    builder.SetInsertPoint(fragmentBlock);

    //将具名实参加入符号表
    auto itLLVMArg = llvmFunc->arg_begin();
    for (size_t i = 0; i < myParamCount; ++i)
    {
        Parameter *myParam = this->parameters[i];
        if(i >= realParamCount) {
            Type *defaultValueType = myParam->getType();
            if(!defaultValueType) defaultValueType = myParam->getDefaultValue()->getType(&innerCtx);
            SymbolInfo *myParamInfo = instSymbolTable.setSymbol(this->getDebugInfo(), myParam->getName(), defaultValueType,
                                                                LinkageType::INTERNAL);
        }else {
            //获取参数的LLVM Argument
            llvm::Argument *llvmArg = itLLVMArg;
            SymbolInfo *myParamInfo = instSymbolTable.setSymbol(this->getDebugInfo(), myParam->getName(), paramTypes[i],
                                                                LinkageType::INTERNAL);
            //生成llvm赋值，将标准参数赋值到当前分支参数
            llvm::Value *myLLVMParamPtr = myParamInfo->getLLVMValuePtr(this->getDebugInfo(), &innerCtx);
            builder.CreateStore(llvmArg, myLLVMParamPtr);
            ++itLLVMArg;
        }
    }

    /*动态变参的处理：
     * fragment的constraint部分生成在父级Block里，为fragment的implements单独生成一个stub函数。
     * 若constraint匹配成功，则生成impl的Block，在block里插入一行call，调用并返回stub函数的结果。
     * 在生成stub函数之前，将有名字的形参对应的实参加入符号表。然后将所有的implements都生成在stub函数里。
     * */
    bool isNative = this->isNative();
    if (this->_runtimeVarargs || isNative)
    {
        if (realParamCount < myParamCount)
        {
            throw InternalException(L"参数个数匹配错误");
        }
        return this->generateStubBlock(outerCtx, &innerCtx, paramTypes, returnType, llvmFunc, fragmentBlock, falseBlock, isNative);
    } else
    /*======================不是动态变参（静态变参或者无变参的处理）=======================*/
    {
        if (this->_staticVarargs)    //如果是静态变参，将多余的实参组合成MultiValue，放进符号表里。
        {
            if (realParamCount < myParamCount)
            {
                throw InternalException(L"参数个数匹配错误");
            }
            //将变参的参数放进符号表里，使用Variable进行引用
            vector<Expression *> varargs;
            size_t i = 0;
            while (itLLVMArg != llvmFunc->arg_end())
            {
                llvm::Argument *llvmArg = itLLVMArg++;
                wstring curArgName = Locales::toWideChar(Encoding::ANSI, llvmArg->getName());
                SymbolInfo *info = instSymbolTable.setSymbol(this->getDebugInfo(), curArgName,
                                                             paramTypes[myParamCount + i],
                                                             LinkageType::INTERNAL);
                info->setLLVMValue(llvmArg);
                auto *cur = new Variable(
                        ExpressionInfo(this->context.getProgram(), this->getDebugInfo(), &this->context), curArgName);
                varargs.push_back(cur);
                ++i;
            }

            auto *multiValue = new MultiValue(
                    ExpressionInfo(this->context.getProgram(), this->getDebugInfo(), &this->context),
                    varargs);
            SymbolInfo *info = instSymbolTable.setSymbol(this->getDebugInfo(), this->staticVarargsName,
                                                         multiValue->getType(&innerCtx), LinkageType::INTERNAL);
            info->setValue(multiValue);
        }

        llvm::BasicBlock *implBlock = nullptr;
        try
        {
            this->generateConstraints(&innerCtx, llvmFunc, falseBlock, &implBlock);
            if (!implBlock) implBlock = fragmentBlock;
            this->generateImplements(&innerCtx, implBlock, returnType);
        }
        catch (const CancelException &ex)
        {
            ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
            if (implBlock != fragmentBlock)
            {
                implBlock->removeFromParent();
                implBlock->deleteValue();
            }
            fragmentBlock->removeFromParent();
            fragmentBlock->deleteValue();
            throw CancelException(CancelScope::EXPRESSION);
        }
        return fragmentBlock;
    }
}

bool FunctionFragment::match(const DebugInfo &d, const FunctionQuery &query) noexcept
{
    const vector<Type *> &realParamTypes = query.getParameterTypes();
    size_t declParamCount = this->parameters.size();
    size_t realParamCount = realParamTypes.size();
    if (!this->_const && query.isConst()) return false;
    if (realParamTypes.size() > declParamCount && !this->_runtimeVarargs && !this->_staticVarargs) return false;
    for (size_t i = 0; i < declParamCount; ++i) {
        Type *declParamType = this->parameters[i]->getType();
        if(i >= realParamCount) {
            if(this->parameters[i]->getDefaultValue()) continue;
            else return false;
        }
        if (!realParamTypes[i]) return false;
        if (declParamType && !Type::convertableTo(d, realParamTypes[i], declParamType)) return false;
    }
    return true;
}

void FunctionFragment::generateConstraints(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock, llvm::BasicBlock **outMatchedBlock)
{
    auto &builder = *context->getIRBuilder();
    size_t condCount = this->constraints.size();
    if (condCount > 0)
    {
        llvm::BasicBlock *matchedBlock = llvm::BasicBlock::Create(*context->getLLVMContext(), "matched", llvmFunc);
        *outMatchedBlock = matchedBlock;
        for (size_t i = 0; i < this->constraints.size(); ++i)
        {
            try
            {
                llvm::Value *res = this->constraints[i]->generateIR(context).getValue();
                builder.CreateCondBr(res, matchedBlock, falseBlock);
            }
            catch (const CancelException &ex)
            {
                ex.rethrowAbove(CancelScope::EXPRESSION);
                continue;
            }
        }
    }else{
        *outMatchedBlock = nullptr;
    }
}

void FunctionFragment::generateImplements(GenerateContext *context, llvm::BasicBlock *block, Type *returnType)
{
    auto &builder = *context->getIRBuilder();
    builder.SetInsertPoint(block);
    size_t codeCount = this->implements.size();
    for (size_t i = 0; i < codeCount; ++i)
    {
        Expression *curExpr = this->implements[i];
        try
        {
            llvm::Value *res = curExpr->generateIR(context).getValue();
            if (i == codeCount - 1)
            {
                //如果分支返回值类型与函数返回值类型不同，则生成类型转换
                Type *branchReturnType = curExpr->getType(context);
                if (!branchReturnType->equals(returnType))
                {
                    res = Type::generateLLVMTypeConvert(curExpr->getDebugInfo(), context, curExpr,
                                                        returnType).getValue();
                }
                builder.CreateRet(res);
            }
        }
        catch (const CancelException &ex)
        {
            ex.rethrowAbove(CancelScope::EXPRESSION);
            continue;
        }
    }
}

bool FunctionFragment::canBeNative() const noexcept
{
    if (!this->declReturnType) return false;
    if(this->_staticVarargs) return false;
    if (!this->linkageType.equals(LinkageType::EXTERNAL)) return false;
    for (size_t i = 0; i < this->parameters.size(); ++i)
    {
        if (!this->parameters[i]->getType()) return false;
    }
    return true;
}

/*如果当前块中只有自己一个函数canBeNative，则isNative*/
bool FunctionFragment::isNative() noexcept
{
    if(!this->canBeNative()) return false;
    auto fragmentsOfSameName = this->context.getBaseContext()->getLocalFunctionFragments(this->getDebugInfo(), this->name);
    for(FunctionFragment *fragment : fragmentsOfSameName){
        if(fragment == this) continue;
        if(fragment->canBeNative()) return false;
    }
    return true;
}

llvm::BasicBlock* FunctionFragment::generateStubBlock(
        GenerateContext *outerCtx,
        GenerateContext *innerCtx,
        const std::vector<Type*> &paramTypes,
        Type *returnType,
        llvm::Function *llvmFunc,
        llvm::BasicBlock *fragmentBlock,
        llvm::BasicBlock *falseBlock,
        bool isNative)
{
    size_t stubParamCount = this->_runtimeVarargs ? this->parameters.size() : paramTypes.size();
    vector<Type*> stubParamTypes(paramTypes.begin(), paramTypes.begin()+stubParamCount);
    llvm::Function *stubFunc = nullptr;
    FunctionCache *functionCache = outerCtx->getFunctionCache();
    if(!functionCache->getCachedStub(this->getDebugInfo(),this,FunctionTypeQuery(stubParamTypes,false,this->isRuntimeVarargs()), &stubFunc))
    {
        wstring stubFuncName;
        if (isNative)
        {
            stubFuncName = this->context.getBaseContext()->getBlockPrefix() + this->name;
        } else {
            stubFuncName = Function::getMangledFunctionName(this->getDebugInfo(), this->name, stubParamTypes,
                                                            this->_runtimeVarargs) + L"@.stub";
        }

        vector<llvm::Type *> llvmParamTypes;
        llvmParamTypes.reserve(stubParamCount);
        for (size_t i = 0; i < stubParamCount; ++i)
        {
            llvmParamTypes.push_back(llvmFunc->getFunctionType()->getParamType(i));
        }

        auto llvmReturnType = llvmFunc->getReturnType();
        stubFunc = llvm::Function::Create(llvm::FunctionType::get(llvmReturnType, llvmParamTypes, this->_runtimeVarargs),
                                      llvm::Function::ExternalLinkage,
                                      Locales::fromWideChar(Encoding::ANSI, stubFuncName), outerCtx->getLLVMModule());
        llvm::BasicBlock *stubEntry = nullptr;
        try
        {
            if (!this->implements.empty())
            {
                stubEntry = llvm::BasicBlock::Create(*outerCtx->getLLVMContext(), "entry", stubFunc);
                this->generateImplements(innerCtx, stubEntry, returnType);
            }
            functionCache->cacheStub(this->getDebugInfo(), this,
                                     FunctionType::get(stubParamTypes, returnType, this->isRuntimeVarargs(),
                                                       this->isConst()), stubFunc);
        }
        catch (const CancelException &ex)
        {
            ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
            fragmentBlock->removeFromParent();
            fragmentBlock->deleteValue();
            if (stubFunc){
                stubFunc->removeFromParent();
                stubFunc->deleteValue();
            }
            if (stubEntry){
                stubEntry->removeFromParent();
                stubEntry->deleteValue();
            }
            throw CancelException(CancelScope::EXPRESSION);
        }
    }

    auto &builder = *outerCtx->getIRBuilder();
    builder.SetInsertPoint(fragmentBlock);
    llvm::BasicBlock *implBlock = nullptr;
    try
    {
        this->generateConstraints(innerCtx, llvmFunc, falseBlock, &implBlock);
    }catch (const CancelException &ex){
        ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
        fragmentBlock->removeFromParent();
        fragmentBlock->deleteValue();
        if(implBlock){
            implBlock->removeFromParent();
            implBlock->deleteValue();
        }
    }
    if (!implBlock) implBlock = fragmentBlock;
    builder.SetInsertPoint(implBlock);

    //将所有实参都加进llvmArgs，用来生成stub
    vector<llvm::Value *> llvmArgs;
    llvmArgs.reserve(paramTypes.size());
    auto it = llvmFunc->arg_begin();
    for (size_t i = 0; i < paramTypes.size(); ++i, ++it)
    {
        //获取参数的LLVM Argument
        llvm::Argument *llvmArg = it;
        llvmArgs.push_back(llvmArg);
    }

    llvm::Value *stubRet = builder.CreateCall(stubFunc, llvmArgs);
    builder.CreateRet(stubRet);
    return fragmentBlock;
}
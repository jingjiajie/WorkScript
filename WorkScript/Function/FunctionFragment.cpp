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
		const std::vector<Expression*>& implements) noexcept
	:name(name), context(d, ctx, ctx->getFunctionFragmentCount()),parameters(params),
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
		d.getReport()->error(UnimplementedError(d, L"尚未实现运行时变参"), ErrorBehavior::CANCEL_EXPRESSION);
	} else if(this->parameters.size() != paramTypes.size())
	{
		throw InternalException(L"参数个数匹配错误");
	}

	try {
		return this->implements[implCount - 1]->getType(&innerCtx);
	}
	catch (const CancelException &ex)
    {
        ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
        throw CancelException(CancelScope::EXPRESSION);
    }
}

llvm::BasicBlock * FunctionFragment::generateBlock(GenerateContext * context,
		const std::vector<Type*> &paramTypes,
		Type *returnType,
		llvm::Function *llvmFunc,
		llvm::BasicBlock *falseBlock)
{
    auto outerInstCtx = context->getInstantialContext();
    InstantialContext innerInstCtx(outerInstCtx, to_wstring(this->getBlockID()));
    if (this->_staticVarargs) innerInstCtx.setBlockAttribute(BlockAttributeItem::SFINAE, true);
    context->setInstantialContext(&innerInstCtx);
    SymbolTable &instSymbolTable = *innerInstCtx.getInstanceSymbolTable();
    size_t realParamCount = paramTypes.size();
    size_t myParamCount = this->parameters.size();

    /*开始创建LLVM对象*/
    llvm::BasicBlock *llvmBlock = llvm::BasicBlock::Create(*context->getLLVMContext(), "branch", llvmFunc);
    llvm::IRBuilder<> &builder = *context->getIRBuilder();
    builder.SetInsertPoint(llvmBlock);
    auto itLLVMArg = llvmFunc->arg_begin();
    for (size_t i = 0; i < myParamCount; ++i, ++itLLVMArg)
    {
        //获取参数的LLVM Argument
        llvm::Argument *llvmArg = itLLVMArg;
        //获取当前分支参数的符号信息，加入符号表
        Parameter *myParam = this->parameters[i];
        SymbolInfo *myParamInfo = instSymbolTable.setSymbol(this->getDebugInfo(), myParam->getName(), paramTypes[i],
                                                            LinkageType::INTERNAL);
        //生成llvm赋值，将标准参数赋值到当前分支参数
        llvm::Value *myLLVMParamPtr = myParamInfo->getLLVMValuePtr(this->getDebugInfo(), context);
        builder.CreateStore(llvmArg, myLLVMParamPtr);
    }

    if (this->_runtimeVarargs)
    {
        else if (this->_runtimeVarargs)
        {
            if (realParamCount < myParamCount)
            {
                throw InternalException(L"参数个数匹配错误");
            }
            this->context.getProgram()->getReport()->error(UnimplementedError(this->getDebugInfo(), L"运行时变参尚未实现"),
                                                           ErrorBehavior::CANCEL_EXPRESSION);
        }
    } else
    { //不是动态变参
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
                                                         multiValue->getType(&innerInstCtx), LinkageType::INTERNAL);
            info->setValue(multiValue);
        }



        llvm::BasicBlock *ret = nullptr;
        try
        {
            this->generateConstraints(builder, llvmFunc, falseBlock);
            this->generateImplements(builder, &innerInstCtx, returnType);
        }
        catch (const CancelException &ex)
        {
            ex.rethrowAbove(CancelScope::FUNCTION_FRAGMENT);
            llvmBlock->removeFromParent();
            llvmBlock->deleteValue();
            throw CancelException(CancelScope::EXPRESSION);
        }
        ret = llvmBlock;
        context->setInstantialContext(outerInstCtx);
        return ret;
    }
}

bool FunctionFragment::match(const DebugInfo &d, const FunctionQuery &query) noexcept
{
	vector<Type *> declParamTypes;
	declParamTypes.reserve(this->parameters.size());
	for (Parameter *param : this->parameters)
	{
		declParamTypes.push_back(param->getType());
	}
	FunctionType *myDeclType = FunctionType::get(declParamTypes, nullptr, this->_runtimeVarargs, this->_const);
	if(FunctionType::match(d, myDeclType, query.getFunctionTypeQuery()))
	{
		return true;
	}else if(this->_staticVarargs && declParamTypes.size() < query.getParameterTypes().size()){
		return true;
	}
	return false;
}

void FunctionFragment::generateConstraints(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock)
{
    size_t condCount = this->constraints.size();
    if (condCount > 0)
    {
        llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "matched", llvmFunc);
        for (size_t i = 0; i < this->constraints.size(); ++i)
        {
            try
            {
                llvm::Value *res = this->constraints[i]->generateIR(context).getValue();
                builder.CreateCondBr(res, matched, falseBlock);
            }
            catch (const CancelException &ex)
            {
                ex.rethrowAbove(CancelScope::EXPRESSION);
                continue;
            }
        }
        builder.SetInsertPoint(matched);
    }
}

void FunctionFragment::generateImplements(GenerateContext *context, Type *returnType)
{
    size_t codeCount = this->implements.size();
    for (size_t i = 0; i < this->implements.size(); ++i)
    {
        Expression *curExpr = this->implements[i];
        try
        {
            llvm::Value *res = curExpr->generateIR(context).getValue();
            if (i == this->implements.size() - 1)
            {
                //如果分支返回值类型与函数返回值类型不同，则生成类型转换
                Type *branchReturnType = curExpr->getType(&innerInstCtx);
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
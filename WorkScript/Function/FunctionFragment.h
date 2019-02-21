#pragma once
#include <vector>
#include <optional>
#include "Expression.h"
#include "AbstractContext.h"

namespace WorkScript {
	class Parameter;

	class FunctionFragment
	{
	public:
		FunctionFragment(const DebugInfo &d,
		        AbstractContext *ctx,
		        const std::wstring &name,
		        const std::vector<Parameter*> &params,
		        bool isConst,
		        bool isRuntimeVarargs,
		        const std::optional<std::wstring> &staticVarargsName,
		        const LinkageType &lt,
		        const std::vector<Expression*> &constraints,
		        const std::vector<Expression*> &implements) noexcept;

		~FunctionFragment() noexcept;

		bool match(const DebugInfo &d, const FunctionQuery &query) noexcept;
		Type *getReturnType(const DebugInfo &d, InstantialContext *instCtx, const std::vector<Type*> &paramTypes);
		llvm::BasicBlock * generateBlock(GenerateContext *context,
										 const std::vector<Type*> &paramTypes,
										 Type *returnType,
										 llvm::Function *llvmFunc,
										 llvm::BasicBlock *falseBlock);

        inline const std::wstring &getName() const noexcept{return this->name;}
		inline const DebugInfo & getDebugInfo() const noexcept{ return this->context.getDebugInfo(); };
		inline Parameter * getParameter(size_t index) noexcept{ return this->parameters[index]; }
		inline const std::vector<Parameter*> & getParameters() const noexcept{ return this->parameters; }
		inline size_t getBlockID() const noexcept{ return this->context.getBlockID(); }
		inline AbstractContext * getContext() noexcept{ return &this->context; }
		inline const LinkageType & getLinkageType() const noexcept{return this->linkageType;}
		inline bool isConst() const noexcept{return this->_const;}
		inline bool isStaticVarargs() const noexcept{return this->_staticVarargs;}
	private:
	    std::wstring name;
		std::vector<Parameter*> parameters;
		bool _staticVarargs = false;
		std::wstring staticVarargsName;
		bool _runtimeVarargs = false;
		bool _const = false;
		LinkageType linkageType;
		std::vector<Expression*> constraints;
		std::vector<Expression*> implements;
		AbstractContext context;

		void generateConstraints(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock);
		void generateImplements(GenerateContext *context, InstantialContext *innerInstCtx, Type *returnType);
	};
}
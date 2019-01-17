#pragma once
#include "SymbolTable.h"
#include <unordered_map>
#include "FunctionType.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "VoidType.h"
#include "FunctionCache.h"
#include "AbstractContext.h"

namespace WorkScript {
	class Function;

	class Program final
	{
	public:
		Program();
		~Program();

		void generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule);

		inline AbstractContext * getGlobalAbstractContext() { return &this->globalAbstractContext; }
		inline FunctionCache *getFunctionCache() { return &this->functionCache; }
	protected:
		AbstractContext globalAbstractContext;
		FunctionCache functionCache;
	};
}

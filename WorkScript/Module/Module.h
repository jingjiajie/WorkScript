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
#include "Report.h"

namespace WorkScript
{
	class Function;

	class Module final
	{
	public:
		Module()
		 :globalAbstractContext(DebugInfo(),this)
		{ }
		bool load(const std::string &fileName);

		inline AbstractContext *getGlobalAbstractContext() noexcept
		{ return &this->globalAbstractContext; }

		inline Report *getReport() noexcept
		{ return &this->report; }

		void generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule);
	protected:
		FunctionCache functionCache;
		AbstractContext globalAbstractContext;
		Report report;
	};
}

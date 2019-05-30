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

	class Program final
	{
	public:
		Program(const std::string &filePath);

		~Program() noexcept;

		void generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule);

		inline AbstractContext *getGlobalAbstractContext() noexcept
		{ return &this->globalAbstractContext; }

		inline FunctionCache *getFunctionCache() noexcept
		{ return &this->functionCache; }

		inline Report *getReport() noexcept
		{ return &this->report; }

	protected:
		AbstractContext globalAbstractContext;
		FunctionCache functionCache;
		Report report;

		void parseFile(const std::string &fileName);
	};
}

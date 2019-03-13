#pragma once
#include <wchar.h>
#include <llvm/IR/LLVMContext.h>

namespace WorkScript {
	class Program;

	class WorkScriptCompiler
	{
	public:
		int compile(int argc, const char* argv[]);

//		void run(const char *fileName);
	};

}

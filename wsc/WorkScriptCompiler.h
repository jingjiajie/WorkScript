#pragma once
#include <wchar.h>
#include <llvm/IR/LLVMContext.h>

namespace WorkScript {
	class Program;

	class WorkScriptCompiler
	{
	public:
		WorkScriptCompiler();
		void run();

	private:
		int compile(std::vector<std::string> *outObjFilePaths);
		void link(const std::vector<std::string> &objFilePaths);
	};
}

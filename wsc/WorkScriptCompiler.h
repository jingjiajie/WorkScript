#pragma once
#include <wchar.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/ADT/Triple.h>

namespace WorkScript {
	class Program;

	class WorkScriptCompiler
	{
	public:
		WorkScriptCompiler(int argc, const char **argv);
		void run();

	private:
		int argc = 0;
		const char **argv;

		int compile(std::vector<std::string> &outObjFilePaths);
		void link(const std::vector<std::string> &objFilePaths);
	};

}

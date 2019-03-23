#pragma once
#include <vector>
#include <string>
#include "CmdArg.h"

namespace WorkScript {
	class Program;

	enum class CompileResult{
	    OK = 0, ERROR = 1
	};

	class WorkScriptCompiler
	{
	public:
		CompileResult compile(const std::vector<std::wstring> &files);
	};
}

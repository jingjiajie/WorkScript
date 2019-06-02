#pragma once
#include <vector>
#include <string>
#include "CmdArgs.h"

namespace WorkScript {
	class Module;

	enum class CompileResult{
	    OK = 0, ERROR = 1
	};

	class WorkScriptCompiler
	{
	public:
		CompileResult compile(const CmdArgs &args);
	};
}

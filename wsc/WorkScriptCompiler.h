#pragma once
#include <wchar.h>
#include "CmdArg.h"

namespace WorkScript {
	class Program;

	enum class CompileResult{
	    OK, ERROR
	};

	class WorkScriptCompiler
	{
	public:
		CompileResult compile(const CmdArgs &args);
	};
}

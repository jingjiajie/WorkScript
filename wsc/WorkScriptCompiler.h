#pragma once
#include <wchar.h>

namespace WorkScript {
	class Program;

	enum class CompileResult{
	    OK, ERROR
	};

	class WorkScriptCompiler
	{
	public:
		CompileResult compile();
	};
}

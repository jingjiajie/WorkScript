#pragma once
#include <wchar.h>

namespace WorkScript {
	class Program;

	class WorkScriptEngine
	{
	public:
		WorkScriptEngine();
		~WorkScriptEngine();

		void run(const char *fileName);
	};

}

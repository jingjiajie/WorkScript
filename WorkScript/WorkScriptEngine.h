#pragma once
#include <wchar.h>

namespace WorkScript {
	class Program;
	class LinkContext;
	class Context;

	class WorkScriptEngine
	{
	public:
		WorkScriptEngine();
		~WorkScriptEngine();

		void run(const char *fileName);

	private:
		void parseFile(const wchar_t *fileName, Program *outProgram);
	};

}

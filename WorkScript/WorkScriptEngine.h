#pragma once
#include <wchar.h>

class Program;
class CompileContext;
class Context;

class WorkScriptEngine
{
public:
	WorkScriptEngine();
	~WorkScriptEngine();

	void run(const wchar_t *fileName);

private:
	void compileFile(const wchar_t *fileName, Program *outProgram, CompileContext *outCompileContext);
};


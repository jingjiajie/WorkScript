#pragma once
#include <wchar.h>

class Program;
class LinkContext;
class Context;

class WorkScriptEngine
{
public:
	WorkScriptEngine();
	~WorkScriptEngine();

	void run(const wchar_t *fileName);

private:
	void parseFile(const wchar_t *fileName, Program *outProgram, size_t domain);
	void combineProgram(Program *destnation, Program *source);
};


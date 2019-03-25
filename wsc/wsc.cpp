#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"
#include "CmdArg.h"

#include <llvm/ADT/Triple.h>
#include <llvm/Support/Host.h>

using namespace std;
using namespace WorkScript;

int main(int argc, const char **argv) {
	setlocale(LC_CTYPE,"");

	return 0;

//	CmdArgs args;
//	args.parse(argc, argv);
//	auto fileNames = args.getRestArgs();
//	WorkScriptCompiler compiler;
//	CompileResult ret = compiler.compile(fileNames);
//	return (int)ret;
}

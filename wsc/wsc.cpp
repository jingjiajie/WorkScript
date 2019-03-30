#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"
#include "CmdArgs.h"

#include <llvm/ADT/Triple.h>
#include <llvm/Support/Host.h>

using namespace std;
using namespace WorkScript;

static void initExtraArgs(CmdArgs *args){
    args->setStrArg({WSC}, L"", 0, 'o', L"目标文件", false, L"a.ll");
}

int main(int argc, const char **argv) {
	setlocale(LC_CTYPE,"");

	CmdArgs args;
	CmdArgs::initArgs(&args);
	initExtraArgs(&args);
	args = args.getGroup(WSC);
	args.parse(argc, argv);

	WorkScriptCompiler compiler;
	CompileResult ret = compiler.compile(args);
	return (int)ret;
}

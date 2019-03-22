#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"
#include "CmdArg.h"

using namespace std;
using namespace WorkScript;

static void initArgs(CmdArgs *cmdArgs){
	cmdArgs->addStrArg({CmdArgGroup::LLC}, L"o", '\0', L"target", false, L"");
}

int main(int argc, const char **argv) {
	setlocale(LC_CTYPE,"");
	CmdArgs args;
	initArgs(&args);
	args.parse(argc, argv);
	printf("%s\n",args.get<string>(L"hello").c_str());
//	WorkScriptCompiler compiler;
//	compiler.run();
}

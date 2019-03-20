#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"
#include "cmdline.h"


using namespace llvm;

using namespace std;
using namespace WorkScript;

static void initLLVM(int argc, const char **argv);
static void initArgs(int argc, const char **argv);

int main(int argc, const char **argv) {
	setlocale(LC_CTYPE,"");

	WorkScriptCompiler compiler;
	compiler.run();
}

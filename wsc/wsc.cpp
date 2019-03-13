#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Locales.h"
#include "Defines.h"
#include "WorkScriptCompiler.h"

using namespace std;
using namespace WorkScript;

int main(int argc, const char* argv[]) {
	setlocale(LC_CTYPE,"");
	WorkScriptCompiler compiler;
	compiler.compile(argc, argv);
}

#include "stdafx.h"
#include "Function.h"
#include "FunctionTemplate.h"

using namespace WorkScript;

Function * WorkScript::FunctionTemplate::createFunction()
{
	Function *func = new Function(this->program, this->name);
	return func;
}
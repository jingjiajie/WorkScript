#include "stdafx.h"
#include "WorkScriptException.h"

using namespace std;

WorkScriptException::~WorkScriptException()
{
	if (this->message) delete[] this->message;
}

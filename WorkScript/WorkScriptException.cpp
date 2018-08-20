#include "WorkScriptException.h"
#include <iostream>
using namespace std;

WorkScriptException::~WorkScriptException()
{
	if (this->message) delete[] this->message;
}

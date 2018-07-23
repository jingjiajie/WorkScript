#include "WorkScriptException.h"
using namespace std;


WorkScriptException::WorkScriptException(string message)
{
	exception::exception(message.c_str());
}


WorkScriptException::~WorkScriptException()
{
}

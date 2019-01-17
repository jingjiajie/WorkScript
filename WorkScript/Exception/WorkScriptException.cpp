#include "WorkScriptException.h"
#include "Locale.h"

using namespace std;
using namespace WorkScript;

void WorkScriptException::setMessage(const wstring& msg)
{
	this->message = msg;
	this->messageANSI = Locale::fromWideChar(Encoding::ANSI, msg);
}

const char * WorkScriptException::what() const noexcept
{
	return this->messageANSI.c_str();
}
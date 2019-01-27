#include "WorkScriptException.h"
#include "Locales.h"

using namespace std;
using namespace WorkScript;

void WorkScriptException::setMessage(const wstring& msg)
{
	this->message = msg;
	this->messageANSI = Locales::fromWideChar(Encoding::ANSI, msg);
}

const char * WorkScriptException::what() const noexcept
{
	return this->messageANSI.c_str();
}
#include "Exception.h"
#include "Locales.h"

using namespace std;
using namespace WorkScript;

void Exception::setMessage(const wstring& msg)
{
	this->messageANSI = Locales::fromWideChar(Encoding::ANSI, msg);
}

const char * Exception::what() const noexcept
{
	return this->messageANSI.c_str();
}
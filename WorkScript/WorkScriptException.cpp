#include "stdafx.h"
#include "WorkScriptException.h"
#include "Locale.h"

using namespace std;
using namespace WorkScript;

void WorkScriptException::setMessage(const wstring& msg)
{
	this->message = msg;
	this->messageANSI = Locale::unicodeToANSI(msg);
}

const char * WorkScriptException::what() const
{
	return this->messageANSI.c_str();
}
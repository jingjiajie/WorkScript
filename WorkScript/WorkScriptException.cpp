#include "WorkScriptException.h"
#include <boost/locale.hpp>
#include <iostream>
using namespace std;

WorkScriptException::~WorkScriptException()
{
	if (this->message) delete[] this->message;
}

void WorkScriptException::setMessage(const wchar_t * const & lpszMsg)
{
	auto str = boost::locale::conv::from_utf(lpszMsg, LOCAL_BOOST_ENCODING);
	auto buff = new char[str.length() + 1];
	strcpy(buff, str.c_str());
	this->message = buff;
}

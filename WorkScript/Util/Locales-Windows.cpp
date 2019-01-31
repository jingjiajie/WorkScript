#ifdef _WIN32
#include "Locales.h"
#include "ErrorManager.h"
#include <wchar.h>
#include <Windows.h>

using namespace std;
using namespace WorkScript;

static UINT getWinCP(Encoding encoding)
{
    switch (encoding)
    {
        case Encoding::UTF_8:
            return CP_UTF8;
        case Encoding::ANSI:
            return CP_ACP;
    }
    throw InternalError(DebugInfo(), L"未知的编码：" + to_wstring(encoding));
}

wstring Locales::toWideChar(WorkScript::Encoding fromEncoding, const std::string &str)
{
	auto unicodeLen = ::MultiByteToWideChar(getWinCP(fromEncoding), 0, str.c_str(), -1, nullptr, 0);
	auto *buff = new wchar_t[unicodeLen + 1];
	::MultiByteToWideChar(getWinCP(fromEncoding), 0, str.c_str(), -1, buff, unicodeLen);
	buff[unicodeLen] = L'\0';
	wstring result = buff;
	delete[] buff;
	return result;
}

string Locales::fromWideChar(WorkScript::Encoding toEncoding, const std::wstring &str){
	auto ansiLen = ::WideCharToMultiByte(getWinCP(toEncoding), 0, str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char *buff = new char[ansiLen + 1];
	::WideCharToMultiByte(getWinCP(toEncoding), 0, str.c_str(), -1, buff, ansiLen, nullptr, nullptr);
	buff[ansiLen] = '\0';
	string result = buff;
	delete[] buff;
	return result;
}

std::string WorkScript::Locales::convert(WorkScript::Encoding fromEncoding, WorkScript::Encoding toEncoding,
										 const std::string &str)
{
	wstring unicodeStr = Locales::toWideChar(fromEncoding, str);
	return Locales::fromWideChar(toEncoding, unicodeStr);
}

#endif // _WIN32
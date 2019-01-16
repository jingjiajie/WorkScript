#ifdef _WIN32
#include "Locale.h"
#include <wchar.h>
#include <Windows.h>

using namespace std;
using namespace WorkScript;

wstring Locale::ansiToUnicode(const string & str)
{
	size_t unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
	wchar_t *buff = new wchar_t[unicodeLen + 1];
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buff, unicodeLen);
	buff[unicodeLen] = L'\0';
	wstring result = buff;
	delete[] buff;
	return result;
}

std::wstring WorkScript::Locale::utf8ToUnicode(const std::string & str)
{
	size_t unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	wchar_t *buff = new wchar_t[unicodeLen + 1];
	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, buff, unicodeLen);
	buff[unicodeLen] = L'\0';
	wstring result = buff;
	delete[] buff;
	return result;
}

string Locale::unicodeToANSI(const wstring & str)
{
	size_t ansiLen = ::WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char *buff = new char[ansiLen + 1];
	::WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, buff, ansiLen, nullptr, nullptr);
	buff[ansiLen] = '\0';
	string result = buff;
	delete[] buff;
	return result;
}

std::string WorkScript::Locale::unicodeToUTF8(const std::wstring & str)
{
	size_t utf8len = ::WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char *buff = new char[utf8len + 1];
	::WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, buff, utf8len, nullptr, nullptr);
	buff[utf8len] = '\0';
	string result = buff;
	delete[] buff;
	return result;
}

std::string WorkScript::Locale::ansiToUTF8(const std::string & str)
{
	wstring unicodeStr = Locale::ansiToUnicode(str);
	return Locale::unicodeToUTF8(unicodeStr);
}

#endif // _WIN32
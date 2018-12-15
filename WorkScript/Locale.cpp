#include "stdafx.h"
#include "Locale.h"
#include <wchar.h>
#include <Windows.h>

using namespace std;
using namespace WorkScript;

wstring Locale::ansiToUnicode(const string & str)
{
	size_t len = str.length();
	wchar_t *buff = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), len + 1, buff, len + 1);
	wstring result = buff;
	delete[] buff;
	return result;
}

string Locale::unicodeToANSI(const wstring & str)
{
	size_t len = str.length();
	char *buff = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), len + 1, buff, len + 1, nullptr, nullptr);
	string result = buff;
	return result;
}

std::string WorkScript::Locale::unicodeToUTF8(const std::wstring & str)
{
	size_t len = str.length();
	char *buff = new char[len + 1];
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), len + 1, buff, len + 1, nullptr, nullptr);
	string result = buff;
	return result;
}

std::string WorkScript::Locale::ansiToUTF8(const std::string & str)
{
	wstring unicodeStr = Locale::ansiToUnicode(str);
	return Locale::unicodeToUTF8(unicodeStr);
}

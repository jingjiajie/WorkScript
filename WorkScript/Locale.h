#pragma once
#include <string>

namespace WorkScript {
	class Locale
	{
	public:
		static std::wstring ansiToUnicode(const std::string &str);
		static std::wstring utf8ToUnicode(const std::string &str);
		static std::string unicodeToANSI(const std::wstring &str);
		static std::string unicodeToUTF8(const std::wstring &str);
		static std::string ansiToUTF8(const std::string &str);
	};
}
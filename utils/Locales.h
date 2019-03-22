#pragma once
#include <string>

namespace WorkScript {
	enum Encoding{
		ANSI, UTF_8
	};

	class Locales
	{
	public:
		static std::wstring toWideChar(Encoding fromEncoding, const std::string &str);
		static std::string fromWideChar(Encoding toEncoding, const std::wstring &str);
		static std::string convert(Encoding fromEncoding, Encoding toEncoding, const std::string &str);
	};
}

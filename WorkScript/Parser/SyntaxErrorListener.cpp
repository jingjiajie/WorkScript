#include "SyntaxErrorListener.h"
#include "SyntaxErrorException.h"
#include "Token.h"
#include "Recognizer.h"
#include "RuleContext.h"
#include "TokenSource.h"
#include "CharStream.h"
#include "IntStream.h"
#include "Locales.h"
#include "DebugInfo.h"

using namespace std;
using namespace WorkScript;

SyntaxErrorListener::SyntaxErrorListener()
{
}


SyntaxErrorListener::~SyntaxErrorListener()
{
}

//static void splitString(const string& s, vector<string>& v, const string& c)
//{
//	string::size_type pos1, pos2;
//	pos2 = s.find(c);
//	pos1 = 0;
//	while (string::npos != pos2)
//	{
//		v.push_back(s.substr(pos1, pos2 - pos1));
//
//		pos1 = pos2 + c.size();
//		pos2 = s.find(c, pos1);
//	}
//	if (pos1 != s.length())
//		v.push_back(s.substr(pos1));
//}

void SyntaxErrorListener::syntaxError(Recognizer * recognizer,
	Token * offendingSymbol,
	size_t line,
	size_t charPositionInLine,
	const std::string & msg,
	std::exception_ptr e)
{
	wstringstream ss, ssCode;
	wstring woffendingText = Locales::toWideChar(Encoding::UTF_8, offendingSymbol->getInputStream()->toString());
	wstring wmsg = Locales::toWideChar(Encoding::UTF_8, msg);
	ssCode << woffendingText;
	wstring lineData;
	for (size_t i = 0; i < line; i++) {
		getline(ssCode, lineData);
	}
	string word = offendingSymbol->getText();
	ss << endl;
	ss << lineData << L"\t其中" << wmsg << endl;
	for (size_t i = 0; i < charPositionInLine; ++i) {
		ss << L" ";
	}
	for (size_t i = 0; i < word.length(); ++i)
	{
		ss << L"~";
	}
	throw SyntaxErrorException(DebugInfo(Location(line, charPositionInLine + 1)), ss.str().c_str());
}

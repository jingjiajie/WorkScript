#include "SyntaxErrorListener.h"
#include "SyntaxErrorException.h"
#include "Token.h"
#include "Recognizer.h"
#include "RuleContext.h"
#include "TokenSource.h"
#include "CharStream.h"
#include "IntStream.h"
#include <utility>
#include <sstream>
#include <boost/locale.hpp>

using namespace std;

SyntaxErrorListener::SyntaxErrorListener()
{
}


SyntaxErrorListener::~SyntaxErrorListener()
{
}

static void splitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

void SyntaxErrorListener::syntaxError(Recognizer * recognizer,
	Token * offendingSymbol,
	size_t line,
	size_t charPositionInLine,
	const std::string & msg,
	std::exception_ptr e)
{
	stringstream ss, ssCode;
	ssCode << offendingSymbol->getInputStream()->toString();
	string lineData;
	for (int i = 0; i < line; i++) {
		getline(ssCode, lineData);
	}
	string word = offendingSymbol->getText();
	ss << endl;
	ss << lineData << "\t" << msg << endl;
	for (auto i = 0; i < charPositionInLine; ++i) {
		ss << " ";
	}
	for (auto i = 0; i < word.length(); ++i)
	{
		ss << "~";
	}
	throw std::move(SyntaxErrorException(line, charPositionInLine + 1, boost::locale::conv::to_utf<wchar_t>(ss.str(), "UTF-8").c_str()));
}

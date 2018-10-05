#pragma once
#include "BaseErrorListener.h"

using namespace antlr4;

class SyntaxErrorListener
	:public BaseErrorListener
{
public:
	SyntaxErrorListener();
	virtual ~SyntaxErrorListener();

	virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
		const std::wstring &msg, std::exception_ptr e) override;
};
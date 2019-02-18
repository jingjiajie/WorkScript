#pragma once
#include "Parser.h"
#include "DefaultErrorStrategy.h"

class SyntaxErrorStrategy
	:public antlr4::DefaultErrorStrategy
{
public:
	SyntaxErrorStrategy();
	virtual ~SyntaxErrorStrategy();

	void reportError(antlr4::Parser *recognizer, const antlr4::RecognitionException &e) override;
	void recover(antlr4::Parser *recognizer, std::exception_ptr e) override;
	antlr4::Token* recoverInline(antlr4::Parser *recognizer) override;
	void sync(antlr4::Parser *recognizer) override;
};


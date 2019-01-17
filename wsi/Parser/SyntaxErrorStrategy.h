#pragma once
#include "Parser.h"
#include "DefaultErrorStrategy.h"

class SyntaxErrorStrategy
	:public antlr4::DefaultErrorStrategy
{
public:
	SyntaxErrorStrategy();
	virtual ~SyntaxErrorStrategy();

	virtual void reportError(antlr4::Parser *recognizer, const antlr4::RecognitionException &e);
	virtual void recover(antlr4::Parser *recognizer, std::exception_ptr e) override;
	virtual antlr4::Token* recoverInline(antlr4::Parser *recognizer) override;
	virtual void sync(antlr4::Parser *recognizer) override;
};


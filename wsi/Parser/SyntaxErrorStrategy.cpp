#include "SyntaxErrorStrategy.h"
#include "RecognitionException.h"
#include "InputMismatchException.h"
#include "SyntaxErrorException.h"
#include "Locale.h"

using namespace antlr4;
using namespace std;
using namespace WorkScript;

SyntaxErrorStrategy::SyntaxErrorStrategy()
{
}


SyntaxErrorStrategy::~SyntaxErrorStrategy()
{
}

void SyntaxErrorStrategy::reportError(antlr4::Parser * recognizer, const antlr4::RecognitionException & e)
{
	string msg = "\"" +  e.getOffendingToken()->getText() + "\"是不是放错了位置？";
	recognizer->notifyErrorListeners(e.getOffendingToken(), std::move(msg), make_exception_ptr(e));
}

void SyntaxErrorStrategy::recover(antlr4::Parser * recognizer, std::exception_ptr e)
{
	std::rethrow_exception(e);
}

antlr4::Token * SyntaxErrorStrategy::recoverInline(antlr4::Parser * recognizer)
{
	throw std::move(InputMismatchException(recognizer));
}

void SyntaxErrorStrategy::sync(antlr4::Parser * recognizer)
{
}

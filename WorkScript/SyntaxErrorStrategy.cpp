#include "SyntaxErrorStrategy.h"
#include "RecognitionException.h"

using namespace antlr4;
using namespace std;

SyntaxErrorStrategy::SyntaxErrorStrategy()
{
}


SyntaxErrorStrategy::~SyntaxErrorStrategy()
{
}

void SyntaxErrorStrategy::reportError(antlr4::Parser * recognizer, const antlr4::RecognitionException & e)
{
	recognizer->notifyErrorListeners(e.getOffendingToken(), "\"" + e.getOffendingToken()->getText() + "\"" + "是不是放错了位置？", make_exception_ptr(e));
}

void SyntaxErrorStrategy::recover(antlr4::Parser * recognizer, std::exception_ptr e)
{
}

antlr4::Token * SyntaxErrorStrategy::recoverInline(antlr4::Parser * recognizer)
{
	return nullptr;
}

void SyntaxErrorStrategy::sync(antlr4::Parser * recognizer)
{
}

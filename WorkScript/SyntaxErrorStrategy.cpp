#include "SyntaxErrorStrategy.h"
#include "RecognitionException.h"
#include "InputMismatchException.h"
#include "SyntaxErrorException.h"

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
	wstring wmsg = L"\"" + boost::locale::conv::utf_to_utf<wchar_t>(e.getOffendingToken()->getText()) + L"\"是不是放错了位置？";
	string msg = boost::locale::conv::from_utf(wmsg,LOCAL_BOOST_ENCODING);
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

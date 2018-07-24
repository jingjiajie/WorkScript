#include <iostream>

#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "SystemContext.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "IdentifierExpression.h"
#include "ExpressionBind.h"

using namespace antlr4;
using namespace antlr4::tree;
using namespace std;

int main(int argc, const char* argv[]) {
	//要执行的程序写在这里

	string str = R"(
		print(head tail) = (print (head + ' ')) (print tail)
		print(1 2 3 4 5 6 7)
		)";
	ANTLRInputStream input(str);
	WorkScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	WorkScriptParser parser(&tokens);
	tree::ParseTree *tree = parser.program();

	SystemContext *lpSystemContext = new SystemContext;
	Context *lpUserContext = new Context();
	lpUserContext->setBaseContext(lpSystemContext);
	WorkScriptVisitorImpl(lpUserContext).visit(tree);
	auto expr = lpUserContext->getExpressions()[lpUserContext->getExpressions().size()-1];
	auto res = expr->evaluate(ExpressionBind());
	getchar();
	delete lpSystemContext;
	delete lpUserContext;
	return 0;
}
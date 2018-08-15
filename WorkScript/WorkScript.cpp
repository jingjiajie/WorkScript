#include <iostream>
#include <time.h>

#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "Context.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "NumberExpression.h"

using namespace antlr4;
using namespace antlr4::tree;
using namespace std;

int main(int argc, const char* argv[]) {
	//要执行的程序写在这里
	string str = R"(
			fib(0) = 1
			fib(1) = 1
			fib(x) = fib(x-1) + fib(x-2)
			print("fib(20) = " + fib(20))
		)";
	ANTLRInputStream input(str);
	WorkScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	WorkScriptParser parser(&tokens);
	tree::ParseTree *tree = parser.program();

	Program program;
	WorkScriptVisitorImpl(&program).visit(tree);
	//编译
	//=================================
	clock_t compstart, compfinish;
	compstart = clock();
	program.compile();
	compfinish = clock();
	cout << "WorkScript编译时间：" << compfinish - compstart << "ms！" << endl;
	//=================================

	clock_t start, finish;
	start = clock();
	program.execute();

	finish = clock();
	cout << "\nWorkScript计算fib(20)的运行时间为" << finish - start << "ms！" << endl << endl;
	getchar();
	return 0;
}
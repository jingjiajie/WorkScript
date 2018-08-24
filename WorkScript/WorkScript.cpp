#include <iostream>
#include <time.h>

#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "Context.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "NumberExpression.h"
#include <windows.h>

using namespace antlr4;
using namespace antlr4::tree;
using namespace std;

int main(int argc, const char* argv[]) {
	//要执行的程序写在这里
	char str[] = R"(


		显示 = print

		评价(得分 <= 60) = "不合格"
		评价(得分 <= 85) = "合格"
		评价(得分 <= 100) = "优秀"

		显示(评价(75))


		)";
	//转换为Unicode
	int len = MultiByteToWideChar(CP_ACP, 0, str, -1, nullptr, 0);
	wchar_t *unicodeStr = new wchar_t[len+1];
	MultiByteToWideChar(CP_ACP, 0, str, -1, unicodeStr, len);
	//转换为UTF-8
	len = WideCharToMultiByte(CP_UTF8, 0, unicodeStr, -1, nullptr, 0, nullptr, nullptr);
	char *utf8Str = new char[len + 1];
	WideCharToMultiByte(CP_UTF8, 0, unicodeStr, -1, utf8Str, len, nullptr, nullptr);
	ANTLRInputStream input(utf8Str);
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
	//cout << "WorkScript编译时间：" << compfinish - compstart << "ms！" << endl<<endl;
	//=================================

	clock_t start, finish;
	start = clock();
	program.execute();

	finish = clock();
	cout<<endl << "\nWorkScript的运行时间为" << finish - start << "ms！" << endl << endl;
	getchar();
	return 0;
}
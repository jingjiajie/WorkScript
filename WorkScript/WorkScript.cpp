#include <iostream>
#include <time.h>

#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "Context.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "NumberExpression.h"
#include "SyntaxErrorException.h"
#include "SyntaxErrorListener.h"
#include "SyntaxErrorStrategy.h"
#include <locale>
#include <windows.h>

using namespace antlr4;
using namespace antlr4::tree;
using namespace std;

void printUsages()
{
	printf("欢迎使用WorkScript解释器！您可以使用以下参数来启动解释器：\n");
	printf("-v 或 -version：\t显示版本号\n");
	printf("-h 或 -help：\t显示此帮助信息\n");
	printf("(文件名)：\t运行指定的WorkScript脚本文件\n");
}

void printVersion()
{
	printf("WorkScript解释器 1.0 alpha 1版本 2018-8-24\n荆佳颉 932166095@qq.com\n");
}

int main(int argc, const char* argv[]) {
	setlocale(LC_CTYPE,"");
	if (argc <= 1) {
		printUsages();
	}
	else if (argc > 2) {
		printUsages();
	}
	else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "-version") == 0) {
		printVersion();
	}
	else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-h") == 0) {
		printUsages();
	}
	else {
		auto fileName = argv[1];
		FILE *file = fopen(fileName, "r");
		if (file == nullptr) {
			printf("文件\"%s\"不存在！", fileName);
		}
		else {
			//开始读取文件
			fseek(file, 0, SEEK_END);
			size_t fileLen = ftell(file);
			size_t buffLen = fileLen + 1;
			fseek(file, 0, SEEK_SET);
			char *buff = new char[buffLen];
			char *curPos = buff;
			//按行读取
			while (fgets(curPos, buffLen, file)) {
				curPos += strlen(curPos);
			}
			fclose(file);
			//转换为Unicode
			int len = MultiByteToWideChar(CP_ACP, 0, buff, -1, nullptr, 0);
			wchar_t *unicodeStr = new wchar_t[len + 1];
			MultiByteToWideChar(CP_ACP, 0, buff, -1, unicodeStr, len);
			//转换为UTF-8
			len = WideCharToMultiByte(CP_UTF8, 0, unicodeStr, -1, nullptr, 0, nullptr, nullptr);
			char *utf8Str = new char[len + 1];
			WideCharToMultiByte(CP_UTF8, 0, unicodeStr, -1, utf8Str, len, nullptr, nullptr);
			ANTLRInputStream input(utf8Str);
			WorkScriptLexer lexer(&input);
			CommonTokenStream tokens(&lexer);

			try {
				//语法分析
				WorkScriptParser parser(&tokens);
				Ref<SyntaxErrorStrategy> syntaxErrorStrategy(new SyntaxErrorStrategy);
				parser.setErrorHandler(syntaxErrorStrategy);
				parser.removeErrorListeners();
				SyntaxErrorListener syntaxErrorListener;
				parser.addErrorListener(&syntaxErrorListener);
				tree::ParseTree *tree = parser.program();

				//遍历语法树，生成Program
				Program program;
				WorkScriptVisitorImpl visitor(&program);
				visitor.visit(tree);

				//编译Program
				//=================================
				clock_t compstart, compfinish;
				compstart = clock();
				program.compile();
				compfinish = clock();
				//cout << "WorkScript编译时间：" << compfinish - compstart << "ms！" << endl<<endl;
				//=================================
				
				//运行
				clock_t start, finish;
				start = clock();
				program.execute();

				finish = clock();
				cout << endl << "\nWorkScript的运行时间为" << finish - start << "ms！" << endl << endl;
			}
			catch (const SyntaxErrorException &ex) {
				cout << ex.what() << endl;
			}
		}
	}
	getchar();
}
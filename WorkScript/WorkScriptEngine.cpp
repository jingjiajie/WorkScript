#include "stdafx.h"
#include "WorkScriptEngine.h"
#include "Program.h"
#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "DoubleExpression.h"
#include "SyntaxErrorException.h"
#include "SyntaxErrorListener.h"
#include "SyntaxErrorStrategy.h"
#include "Pointer.h"
#include "SyntaxErrorException.h"
#include "LinkException.h"

using namespace std;
using namespace WorkScript;

WorkScriptEngine::WorkScriptEngine()
{
}


WorkScriptEngine::~WorkScriptEngine()
{
}

void WorkScriptEngine::run(const char * filePath)
{
	auto wFilePath = boost::locale::conv::to_utf<wchar_t>(filePath, LOCAL_BOOST_ENCODING);
	Program program;
	this->parseFile(wFilePath.c_str(), &program);
	//TODO JIT运行
}

void WorkScriptEngine::parseFile(const wchar_t * fileName, Program * outProgram) //throws SyntaxErrorException
{
	FILE *file = fopen(boost::locale::conv::from_utf(fileName, LOCAL_BOOST_ENCODING).c_str(), "r");
	if (file == nullptr) {
		wprintf(L"文件\"%ls\"不存在！\n", fileName);
	}
	else {
		//开始读取文件
		fseek(file, 0, SEEK_END);
		long fileLen = ftell(file);
		long buffLen = fileLen + 1;
		fseek(file, 0, SEEK_SET);
		char *buff = new char[buffLen];
		char *curPos = buff;
		//按行读取
		while (fgets(curPos, (int)buffLen, file)) {
			curPos += strlen(curPos);
		}
		fclose(file);
		//转换为Unicode
		string utf8Str = boost::locale::conv::to_utf<char>(buff, LOCAL_BOOST_ENCODING);
		delete buff;
		ANTLRInputStream input(utf8Str);
		WorkScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		//语法分析
		WorkScriptParser parser(&tokens);
		Ref<SyntaxErrorStrategy> syntaxErrorStrategy(new SyntaxErrorStrategy);
		parser.setErrorHandler(syntaxErrorStrategy);
		parser.removeErrorListeners();
		SyntaxErrorListener syntaxErrorListener;
		parser.addErrorListener(&syntaxErrorListener);
		tree::ParseTree *tree = parser.program();

		//遍历语法树，生成Program
		WorkScriptVisitorImpl visitor(outProgram);
		visitor.visit(tree);
	}
}
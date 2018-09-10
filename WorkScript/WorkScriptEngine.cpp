#include "WorkScriptEngine.h"
#include "Program.h"
#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "Context.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "DoubleExpression.h"
#include "SyntaxErrorException.h"
#include "SyntaxErrorListener.h"
#include "SyntaxErrorStrategy.h"
#include "Pointer.h"
#include "CallStack.h"
#include "StackFrame.h"
#include "MainProgram.h"
#include <boost/locale.hpp>
#include <unordered_set>
#include <stdio.h>
#include <vector>

using namespace std;

WorkScriptEngine::WorkScriptEngine()
{
}


WorkScriptEngine::~WorkScriptEngine()
{
}

void WorkScriptEngine::run(const wchar_t * filePath)
{
	vector<wstring> filesToInclude;
	filesToInclude.push_back(filePath);
	unordered_set<wstring> includedFiles;
	includedFiles.insert(filePath);
	CompileContext compileContext;

	MainProgram systemProgram;
	systemProgram.compile(&compileContext);
	vector<Program*> programs;
	while (filesToInclude.size() > 0) {
		programs.push_back(new Program());
		Program *curProgram = programs[programs.size() - 1];
		this->compileFile(filesToInclude[0].c_str(), programs[programs.size() - 1], &compileContext);
		filesToInclude.erase(filesToInclude.begin());
		//将本文件引用的其他文件加入待包含列表。如果已经包含过不要重复包含。
		auto includeFiles = curProgram->getIncludeFiles();
		for (wstring &file : includeFiles) {
			if (includedFiles.find(file) == includedFiles.end()) {
				includedFiles.insert(file);
				filesToInclude.push_back(file);
			}
		}
	}

	//先运行各个子模块，最后运行main.ws
	CallStack stack;
	try {
		StackFrame *frame = stack.newStackFrame(nullptr, compileContext.getLocalVariableCount());
		Context context(&stack, frame);
		systemProgram.execute(&context);
		for (int i = (int)programs.size()-1; i >= 0; --i) {
			programs[i]->execute(&context);
		}
		stack.popStackFrame();
	}
	catch (const WorkScriptException &ex)
	{
		stack.clearStackFrame(); //接到异常清空调用栈
		cout << ex.what() << endl;
	}
	//释放Programs
	for (Program *program : programs) {
		delete program;
	}
}

void WorkScriptEngine::compileFile(const wchar_t * fileName, Program * outProgram, CompileContext *outCompileContext) //throws SyntaxErrorException
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

		//编译Program
		outProgram->compile(outCompileContext);
	}
}
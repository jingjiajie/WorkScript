#include "stdafx.h"
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
#include "SyntaxErrorException.h"
#include "LinkException.h"

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

	DOMAIN_ID curDomain = 1;

	vector<Program*> programs;
	while (filesToInclude.size() > 0) {
		programs.push_back(new Program());
		Program *curProgram = programs[programs.size() - 1];
		//编译文件为Program对象
		this->parseFile(filesToInclude[0].c_str(), curProgram, curDomain);
		filesToInclude.erase(filesToInclude.begin());
		//将本文件引用的其他文件加入待包含列表。如果已经包含过不要重复包含。
		auto includeFiles = curProgram->getIncludeFiles();
		for (wstring &file : includeFiles) {
			if (includedFiles.find(file) == includedFiles.end()) {
				includedFiles.insert(file);
				filesToInclude.push_back(file);
			}
		}
		++curDomain;
	}
	programs.push_back(new MainProgram);

	//将所有Program对象链接到一个Program对象中
	Program combinedProgram;
	for (auto it = programs.rbegin(); it != programs.rend(); ++it)
	{
		Program *curProgram = *it;
		this->combineProgram(&combinedProgram, curProgram);
		delete curProgram;
	}

	/*=====开始链接=====*/
	SymbolTable symbolTable;
	BLOCK_ID topBlockID = symbolTable.newBlock();

	try {
		//符号收集
		LinkContext linkContext(&symbolTable, topBlockID, LinkTask::SYMBOL_COLLECTING);
		combinedProgram.link(&linkContext);
		//符号绑定
		linkContext.setLinkTask(LinkTask::SYMBOL_BINDING);
		combinedProgram.link(&linkContext);

	}
	catch (const LinkException &ex) {
		//cout << "符号表信息：" << endl;
		//symbolTable.print();
		//cout << endl << endl;
		cout << ex.what() << endl;
		return;
	}

	//cout << "符号表信息：" << endl;
	//symbolTable.print();
	//cout << endl << endl;
	//cout << "运行结果：" << endl;

	CallStack stack;
	try {
		StackFrame *frame = stack.newStackFrame(nullptr,topBlockID, symbolTable.getTotalSymbolCount(topBlockID));
		Context context(&stack, frame);
		combinedProgram.execute(&context);
		stack.popStackFrame();
	}
	catch (const WorkScriptException &ex)
	{
		stack.clearStackFrame(); //接到异常清空调用栈
		cout << ex.what() << endl;
		return;
	}
}

void WorkScriptEngine::parseFile(const wchar_t * fileName, Program * outProgram,size_t currentDomain) //throws SyntaxErrorException
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
		WorkScriptVisitorImpl visitor(outProgram,currentDomain);
		visitor.visit(tree);
	}
}

void WorkScriptEngine::combineProgram(Program * destnation, Program * source)
{
	auto exprs = source->getExpressions();
	for (size_t i = 0; i < exprs.size(); ++i) {
		destnation->pushExpression(exprs[i]);
	}
}

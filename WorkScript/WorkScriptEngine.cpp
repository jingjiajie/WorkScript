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
		//�����ļ�ΪProgram����
		this->parseFile(filesToInclude[0].c_str(), curProgram, curDomain);
		filesToInclude.erase(filesToInclude.begin());
		//�����ļ����õ������ļ�����������б�����Ѿ���������Ҫ�ظ�������
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

	//������Program�������ӵ�һ��Program������
	Program combinedProgram;
	for (auto it = programs.rbegin(); it != programs.rend(); ++it)
	{
		Program *curProgram = *it;
		this->combineProgram(&combinedProgram, curProgram);
		delete curProgram;
	}

	/*=====��ʼ����=====*/
	SymbolTable symbolTable;
	BLOCK_ID topBlockID = symbolTable.newBlock();

	try {
		//�����ռ�
		LinkContext linkContext(&symbolTable, topBlockID, LinkTask::SYMBOL_COLLECTING);
		combinedProgram.link(&linkContext);
		//���Ű�
		linkContext.setLinkTask(LinkTask::SYMBOL_BINDING);
		combinedProgram.link(&linkContext);

	}
	catch (const LinkException &ex) {
		//cout << "���ű���Ϣ��" << endl;
		//symbolTable.print();
		//cout << endl << endl;
		cout << ex.what() << endl;
		return;
	}

	//cout << "���ű���Ϣ��" << endl;
	//symbolTable.print();
	//cout << endl << endl;
	//cout << "���н����" << endl;

	CallStack stack;
	try {
		StackFrame *frame = stack.newStackFrame(nullptr,topBlockID, symbolTable.getTotalSymbolCount(topBlockID));
		Context context(&stack, frame);
		combinedProgram.execute(&context);
		stack.popStackFrame();
	}
	catch (const WorkScriptException &ex)
	{
		stack.clearStackFrame(); //�ӵ��쳣��յ���ջ
		cout << ex.what() << endl;
		return;
	}
}

void WorkScriptEngine::parseFile(const wchar_t * fileName, Program * outProgram,size_t currentDomain) //throws SyntaxErrorException
{
	FILE *file = fopen(boost::locale::conv::from_utf(fileName, LOCAL_BOOST_ENCODING).c_str(), "r");
	if (file == nullptr) {
		wprintf(L"�ļ�\"%ls\"�����ڣ�\n", fileName);
	}
	else {
		//��ʼ��ȡ�ļ�
		fseek(file, 0, SEEK_END);
		long fileLen = ftell(file);
		long buffLen = fileLen + 1;
		fseek(file, 0, SEEK_SET);
		char *buff = new char[buffLen];
		char *curPos = buff;
		//���ж�ȡ
		while (fgets(curPos, (int)buffLen, file)) {
			curPos += strlen(curPos);
		}
		fclose(file);
		//ת��ΪUnicode
		string utf8Str = boost::locale::conv::to_utf<char>(buff, LOCAL_BOOST_ENCODING);
		delete buff;
		ANTLRInputStream input(utf8Str);
		WorkScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		//�﷨����
		WorkScriptParser parser(&tokens);
		Ref<SyntaxErrorStrategy> syntaxErrorStrategy(new SyntaxErrorStrategy);
		parser.setErrorHandler(syntaxErrorStrategy);
		parser.removeErrorListeners();
		SyntaxErrorListener syntaxErrorListener;
		parser.addErrorListener(&syntaxErrorListener);
		tree::ParseTree *tree = parser.program();

		//�����﷨��������Program
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

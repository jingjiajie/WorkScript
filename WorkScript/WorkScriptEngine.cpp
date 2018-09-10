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
		//�����ļ����õ������ļ�����������б�����Ѿ���������Ҫ�ظ�������
		auto includeFiles = curProgram->getIncludeFiles();
		for (wstring &file : includeFiles) {
			if (includedFiles.find(file) == includedFiles.end()) {
				includedFiles.insert(file);
				filesToInclude.push_back(file);
			}
		}
	}

	//�����и�����ģ�飬�������main.ws
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
		stack.clearStackFrame(); //�ӵ��쳣��յ���ջ
		cout << ex.what() << endl;
	}
	//�ͷ�Programs
	for (Program *program : programs) {
		delete program;
	}
}

void WorkScriptEngine::compileFile(const wchar_t * fileName, Program * outProgram, CompileContext *outCompileContext) //throws SyntaxErrorException
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
		WorkScriptVisitorImpl visitor(outProgram);
		visitor.visit(tree);

		//����Program
		outProgram->compile(outCompileContext);
	}
}
#include "stdafx.h"
#include "WorkScriptEngine.h"
#include "Program.h"
#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "WorkScriptVisitorImpl.h"
#include "Expression.h"
#include "SyntaxErrorException.h"
#include "SyntaxErrorListener.h"
#include "SyntaxErrorStrategy.h"
#include "SyntaxErrorException.h"
#include "Locale.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"

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
	llvm::InitializeNativeTarget();
	llvm::InitializeNativeTargetAsmParser();
	llvm::InitializeNativeTargetAsmPrinter();
	auto wFilePath = Locale::ansiToUnicode(filePath);
	Program program;
	this->parseFile(wFilePath.c_str(), &program);
	llvm::LLVMContext llvmContext;
	auto llvmModule = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
	program.generateLLVMIR(&llvmContext, llvmModule.get());
	llvmModule->dump();
	//string errorStr;
	//llvm::EngineBuilder b(std::move(llvmModule));
	////llvm::RTDyldMemoryManager* RTDyldMM = NULL;
	//b.setEngineKind(llvm::EngineKind::JIT)
	//	.setErrorStr(&errorStr);
	//	//.setVerifyModules(true)
	//	//.setMCJITMemoryManager(std::unique_ptr<llvm::RTDyldMemoryManager>(RTDyldMM))
	//	//.setOptLevel(llvm::CodeGenOpt::Default)
	//auto e = b.create();
	//e->finalizeObject();
	//typedef int(*TFMAIN)();
	//TFMAIN fmain = (TFMAIN)e->getPointerToNamedFunction("main");
	//int ret = fmain();
	////printf("WorkScript JITִ�н����\n");
	////printf("%d",ret);
}

void WorkScriptEngine::parseFile(const wchar_t * fileName, Program * outProgram) //throws SyntaxErrorException
{
	FILE *file = fopen(Locale::unicodeToANSI(fileName).c_str(), "r");
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
		string utf8Str = Locale::ansiToUTF8(buff);
		ANTLRInputStream input(utf8Str);
		WorkScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		delete buff;
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
	}
}
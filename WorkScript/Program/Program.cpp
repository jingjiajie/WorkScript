#include "Program.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "VoidType.h"
#include "FunctionType.h"
#include "Function.h"
#include "FunctionCache.h"
#include "Locales.h"
#include "antlr4-runtime.h"
#include "Generated/WorkScriptLexer.h"
#include "Generated/WorkScriptParser.h"
#include "TreeCreateVisitor.h"
#include "SyntaxErrorListener.h"
#include "SyntaxErrorStrategy.h"
#include "Exception.h"
#include "InstantialContext.h"
#include "StringCache.h"

using namespace std;
using namespace WorkScript;

Program::Program(const string &filePath)
	:globalAbstractContext(DebugInfo(), this)
{
    this->parseFile(filePath);
}

Program::~Program() noexcept = default;

void WorkScript::Program::generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule)
{
	StringCache stringCache;
	GenerateContext ctx(llvmContext, llvmModule, nullptr, &this->globalAbstractContext, &this->functionCache, &stringCache);
	//TODO DebugInfo
	Function *funcMain = this->globalAbstractContext.getFunction(DebugInfo(), FunctionQuery(L"main", {}, false));
	try {
		funcMain->getLLVMFunction(DebugInfo(), &ctx, {});
	}
	catch (const CancelException &) {
		return;
	}
}

void Program::parseFile(const std::string &fileName)
{
	FILE *file = fopen(fileName.c_str(), "r");
	if (file == nullptr)
	{
		printf("文件\"%s\"不存在！\n", fileName.c_str());
	} else
	{
		//开始读取文件
		fseek(file, 0, SEEK_END);
		long fileLen = ftell(file);
		long buffLen = fileLen + 1;
		fseek(file, 0, SEEK_SET);
		char *buff = new char[buffLen];
		char *curPos = buff;
		//按行读取
		while (fgets(curPos, (int) buffLen, file))
		{
			curPos += strlen(curPos);
		}
		fclose(file);
		//转换为Unicode
		string utf8Str = Locales::convert(Encoding::ANSI, Encoding::UTF_8, buff);
		ANTLRInputStream input(utf8Str);
		WorkScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		delete []buff;
		//语法分析
		WorkScriptParser parser(&tokens);
		Ref<SyntaxErrorStrategy> syntaxErrorStrategy(new SyntaxErrorStrategy);
		parser.setErrorHandler(syntaxErrorStrategy);
		parser.removeErrorListeners();
		SyntaxErrorListener syntaxErrorListener(this, Locales::toWideChar(Encoding::ANSI, fileName));
		parser.addErrorListener(&syntaxErrorListener);
		tree::ParseTree *tree = parser.program();

		//遍历语法树，生成Program
		TreeCreateVisitor visitor(this, Locales::toWideChar(Encoding::ANSI, fileName));
		try {
			visitor.visit(tree);
		}catch (const CancelException &ex){
			ex.rethrowAbove(CancelScope::COMPILATION);
			return;
		}
	}
}

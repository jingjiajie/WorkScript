#pragma once
#include "BaseErrorListener.h"

using namespace antlr4;

namespace WorkScript
{
	class Program;
	class SyntaxErrorListener
			: public BaseErrorListener
	{
	public:
		inline explicit SyntaxErrorListener(Program *p, const std::wstring fileName)
		:program(p),fileName(fileName){}

		~SyntaxErrorListener() = default;

		virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
								 const std::string &msg, std::exception_ptr e) override;

	private:
		Program *program = nullptr;
		std::wstring fileName;
	};
}
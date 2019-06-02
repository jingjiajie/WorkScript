#pragma once
#include "BaseErrorListener.h"

using namespace antlr4;

namespace WorkScript
{
	class Module;
	class SyntaxErrorListener
			: public BaseErrorListener
	{
	public:
		inline explicit SyntaxErrorListener(Module *p, const std::wstring fileName)
		:module(p),fileName(fileName){}

		~SyntaxErrorListener() = default;

		virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
								 const std::string &msg, std::exception_ptr e) override;

	private:
		Module *module = nullptr;
		std::wstring fileName;
	};
}
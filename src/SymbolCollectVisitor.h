//#pragma once
//#include "Generated/WorkScriptBaseVisitor.h"
//
//namespace WorkScript {
//	class Program;
//	class FunctionBranch;
//
//	class SymbolCollectVisitor : public WorkScriptBaseVisitor {
//	public:
//		SymbolCollectVisitor(Program *program);
//		antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext*) override;
//		antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext*) override;
//	protected:
//		Program * program = nullptr;
//	}
//}
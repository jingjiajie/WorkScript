//#pragma once
//#include "Generated/WorkScriptBaseVisitor.h"
//
//namespace WorkScript {
//	class Module;
//	class FunctionBranch;
//
//	class SymbolCollectVisitor : public WorkScriptBaseVisitor {
//	public:
//		SymbolCollectVisitor(Module *module);
//		antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext*) override;
//		antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext*) override;
//	protected:
//		Module * module = nullptr;
//	}
//}
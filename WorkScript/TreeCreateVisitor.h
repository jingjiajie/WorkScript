#pragma once
#include <memory>
#include <vector>
#include <stack>
#include "Generated/WorkScriptBaseVisitor.h"
#include "VariableExpression.h"

namespace WorkScript {
	class Program;
	class FunctionBranch;

	class TreeCreateVisitor :
		public WorkScriptBaseVisitor
	{
	public:
		antlrcpp::Any visitIncludeCommand(WorkScriptParser::IncludeCommandContext*) override;
		antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext*) override;
		antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext*) override;
		antlrcpp::Any visitBooleanExpression(WorkScriptParser::BooleanExpressionContext*)override;
		antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext*) override;
		antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext*) override;
		antlrcpp::Any visitCallExpression(WorkScriptParser::CallExpressionContext*) override;
		antlrcpp::Any visitProgram(WorkScriptParser::ProgramContext*) override;
		antlrcpp::Any visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext*)override;
		antlrcpp::Any visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext*)override;
		antlrcpp::Any visitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext*) override;
		//antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext*) override;
		antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext*) override;
		antlrcpp::Any visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext*) override;
		antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext*)override;
		antlrcpp::Any visitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext*)override;
		//antlrcpp::Any visitListExpression(WorkScriptParser::ListExpressionContext*)override;
		antlrcpp::Any visitNegativeExpression(WorkScriptParser::NegativeExpressionContext*)override;
		antlrcpp::Any visitPositiveExpression(WorkScriptParser::PositiveExpressionContext*)override;
		antlrcpp::Any visitVarargsExpression(WorkScriptParser::VarargsExpressionContext*)override;
		//antlrcpp::Any visitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext*)override;
		TreeCreateVisitor(Program* program);
		virtual ~TreeCreateVisitor();

	private:
		Program * program = nullptr;
		bool assignable = true;
		bool declarable = false;
		size_t curDepth = 0;
		std::stack<AbstractContext*> abstractContexts;
	};
}
#pragma once
#include <memory>
#include <vector>
#include "Generated/WorkScriptBaseVisitor.h"
#include "Program.h"
#include "VariableExpression.h"

class WorkScriptVisitorImpl :
	public WorkScriptBaseVisitor
{
public:
	antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext*) override;
	antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext*) override;
	antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext*) override;
	antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext*) override;
	antlrcpp::Any visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext*) override;
	antlrcpp::Any visitExpression(WorkScriptParser::ExpressionContext*) override;
	//antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext*) override;
	antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext*) override;
	antlrcpp::Any visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext*) override;
	antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext*)override;
	antlrcpp::Any visitCompareExpression(WorkScriptParser::CompareExpressionContext*)override;
	antlrcpp::Any visitListExpression(WorkScriptParser::ListExpressionContext*)override;
	WorkScriptVisitorImpl(Program*);
	virtual ~WorkScriptVisitorImpl();
private:
	Program *program;
};
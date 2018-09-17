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
	antlrcpp::Any visitIncludeCommand(WorkScriptParser::IncludeCommandContext*) override;
	antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext*) override;
	antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext*) override;
	antlrcpp::Any visitBooleanExpression(WorkScriptParser::BooleanExpressionContext*)override;
	antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext*) override;
	antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext*) override;
	antlrcpp::Any visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext*) override;
	antlrcpp::Any visitProgram(WorkScriptParser::ProgramContext*) override;
	antlrcpp::Any visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext*)override;
	antlrcpp::Any visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext*)override;
	antlrcpp::Any visitEqualsExpression(WorkScriptParser::EqualsExpressionContext*)override;
	antlrcpp::Any visitParameterExpression(WorkScriptParser::ParameterExpressionContext*) override;
	//antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext*) override;
	antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext*) override;
	antlrcpp::Any visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext*) override;
	antlrcpp::Any visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext*)override;
	antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext*)override;
	antlrcpp::Any visitCompareExpression(WorkScriptParser::CompareExpressionContext*)override;
	antlrcpp::Any visitListExpression(WorkScriptParser::ListExpressionContext*)override;
	antlrcpp::Any visitNegativeExpression(WorkScriptParser::NegativeExpressionContext*)override;
	antlrcpp::Any visitPositiveExpression(WorkScriptParser::PositiveExpressionContext*)override;
	antlrcpp::Any visitVarargsExpression(WorkScriptParser::VarargsExpressionContext*)override;
	antlrcpp::Any visitParameterExpressionItem(WorkScriptParser::ParameterExpressionItemContext*)override;
	antlrcpp::Any visitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext*)override;
	WorkScriptVisitorImpl(Program* program,DOMAIN_ID domain);
	virtual ~WorkScriptVisitorImpl();
	void handleEscapeCharacters(const wchar_t *srcStr, wchar_t *targetStr, size_t line, size_t column)const;

	DomainAccess getDomainAccess(size_t depth)const;
	void setDomainAccess(size_t depth, DomainAccess level);

	DOMAIN_ID getDomain() const;
	void setDomain(DOMAIN_ID domain);
private:
	Program *program;
	bool assignable = true;
	bool declarable = false;
	std::unordered_map<size_t,DomainAccess> domainAccesses;
	DOMAIN_ID domain;
	size_t curDepth = 0;
};
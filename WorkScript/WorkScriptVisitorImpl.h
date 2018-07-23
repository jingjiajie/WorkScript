#pragma once
#include <memory>
#include <vector>
#include "Generated/WorkScriptBaseVisitor.h"
#include "Context.h"
#include "VariableExpression.h"

class WorkScriptVisitorImpl :
	public WorkScriptBaseVisitor
{
public:
	antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext*) override;
	antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext*) override;
	antlrcpp::Any visitIdentifierExpression(WorkScriptParser::IdentifierExpressionContext*) override;
	antlrcpp::Any visitRelationExpression(WorkScriptParser::RelationExpressionContext*) override;
	antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext*) override;
	antlrcpp::Any visitMultiTermExpression(WorkScriptParser::MultiTermExpressionContext*) override;
	antlrcpp::Any visitExpression(WorkScriptParser::ExpressionContext*) override;
	antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext*) override;
	antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext*) override;
	antlrcpp::Any visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext*) override;
	WorkScriptVisitorImpl(Context*);
	virtual ~WorkScriptVisitorImpl();
private:
	Context *context;
	bool inRelationExpressionLeft = false;
	bool inRelationExpressionRight = false;
	std::vector<std::shared_ptr<const VariableExpression>> relationLeftVariables;
	int parenthereLevel = 0;
};
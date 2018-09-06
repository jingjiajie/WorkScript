
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "WorkScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by WorkScriptParser.
 */
class  WorkScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by WorkScriptParser.
   */
    virtual antlrcpp::Any visitProgram(WorkScriptParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *context) = 0;

    virtual antlrcpp::Any visitListExpression(WorkScriptParser::ListExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStringExpression_(WorkScriptParser::StringExpression_Context *context) = 0;

    virtual antlrcpp::Any visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCompareExpression(WorkScriptParser::CompareExpressionContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpression_(WorkScriptParser::VariableExpression_Context *context) = 0;

    virtual antlrcpp::Any visitMethodInvocationExpression(WorkScriptParser::MethodInvocationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBooleanExpression_(WorkScriptParser::BooleanExpression_Context *context) = 0;

    virtual antlrcpp::Any visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpression_(WorkScriptParser::NumberExpression_Context *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionExpression_(WorkScriptParser::FunctionExpression_Context *context) = 0;

    virtual antlrcpp::Any visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualsExpression(WorkScriptParser::EqualsExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParameterExpression(WorkScriptParser::ParameterExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBlockExpression(WorkScriptParser::BlockExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBooleanExpression(WorkScriptParser::BooleanExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(WorkScriptParser::IdentifierContext *context) = 0;


};


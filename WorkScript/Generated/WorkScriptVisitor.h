
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

    virtual antlrcpp::Any visitExpression(WorkScriptParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationExpression(WorkScriptParser::RelationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPolynomialExpression(WorkScriptParser::PolynomialExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionPolynomialExpression(WorkScriptParser::FunctionPolynomialExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIndependentParentheseExpression(WorkScriptParser::IndependentParentheseExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpression(WorkScriptParser::IdentifierExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *context) = 0;


};



// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "WorkScriptVisitor.h"


/**
 * This class provides an empty implementation of WorkScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  WorkScriptBaseVisitor : public WorkScriptVisitor {
public:

  virtual antlrcpp::Any visitProgram(WorkScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(WorkScriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationExpression(WorkScriptParser::RelationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplyDivideExpression(WorkScriptParser::MultiplyDivideExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTermExpressionInPolynomial(WorkScriptParser::TermExpressionInPolynomialContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiTermExpression(WorkScriptParser::MultiTermExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(WorkScriptParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};


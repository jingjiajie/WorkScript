
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

  virtual antlrcpp::Any visitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListExpression(WorkScriptParser::ListExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpression_(WorkScriptParser::StringExpression_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionInvocationExpression(WorkScriptParser::FunctionInvocationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompareExpression(WorkScriptParser::CompareExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpression_(WorkScriptParser::VariableExpression_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodInvocationExpression(WorkScriptParser::MethodInvocationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberExpression_(WorkScriptParser::NumberExpression_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberEvaluateExpression(WorkScriptParser::MemberEvaluateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionExpression_(WorkScriptParser::FunctionExpression_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonSignMultiplyExpression(WorkScriptParser::NonSignMultiplyExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualsExpression(WorkScriptParser::EqualsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterExpression(WorkScriptParser::ParameterExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpression(WorkScriptParser::StringExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockExpression(WorkScriptParser::BlockExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(WorkScriptParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};


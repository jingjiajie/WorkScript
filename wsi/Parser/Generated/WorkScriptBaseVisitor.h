
// Generated from WorkScript.g4 by ANTLR 4.7.2

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

  virtual antlrcpp::Any visitLine(WorkScriptParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStdFunctionDecl_(WorkScriptParser::StdFunctionDecl_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefine_(WorkScriptParser::FunctionDefine_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryCompare(WorkScriptParser::BinaryCompareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(WorkScriptParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplyDivideModulus(WorkScriptParser::MultiplyDivideModulusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOrEquals(WorkScriptParser::AssignmentOrEqualsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(WorkScriptParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLevel(WorkScriptParser::AccessLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusMinus(WorkScriptParser::PlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(WorkScriptParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(WorkScriptParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegative(WorkScriptParser::NegativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositive(WorkScriptParser::PositiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthese(WorkScriptParser::ParentheseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall_(WorkScriptParser::Call_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean(WorkScriptParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(WorkScriptParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiValue(WorkScriptParser::MultiValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStdFunctionDecl(WorkScriptParser::StdFunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStdFormalParameter(WorkScriptParser::StdFormalParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStdFormalParameterItem(WorkScriptParser::StdFormalParameterItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefine(WorkScriptParser::FunctionDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(WorkScriptParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(WorkScriptParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionName(WorkScriptParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameter(WorkScriptParser::FormalParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterItem(WorkScriptParser::FormalParameterItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionImplementation(WorkScriptParser::FunctionImplementationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionConstraint(WorkScriptParser::FunctionConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(WorkScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStaticVarargs(WorkScriptParser::StaticVarargsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewlineOrComma(WorkScriptParser::NewlineOrCommaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(WorkScriptParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};


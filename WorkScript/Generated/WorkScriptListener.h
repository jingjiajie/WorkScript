
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "WorkScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by WorkScriptParser.
 */
class  WorkScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(WorkScriptParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(WorkScriptParser::ProgramContext *ctx) = 0;

  virtual void enterIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx) = 0;
  virtual void exitIncludeCommand(WorkScriptParser::IncludeCommandContext *ctx) = 0;

  virtual void enterAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext *ctx) = 0;
  virtual void exitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext *ctx) = 0;

  virtual void enterParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx) = 0;
  virtual void exitParentheseExpression(WorkScriptParser::ParentheseExpressionContext *ctx) = 0;

  virtual void enterCallExpression_(WorkScriptParser::CallExpression_Context *ctx) = 0;
  virtual void exitCallExpression_(WorkScriptParser::CallExpression_Context *ctx) = 0;

  virtual void enterStringExpression_(WorkScriptParser::StringExpression_Context *ctx) = 0;
  virtual void exitStringExpression_(WorkScriptParser::StringExpression_Context *ctx) = 0;

  virtual void enterMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx) = 0;
  virtual void exitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext *ctx) = 0;

  virtual void enterVariableExpression_(WorkScriptParser::VariableExpression_Context *ctx) = 0;
  virtual void exitVariableExpression_(WorkScriptParser::VariableExpression_Context *ctx) = 0;

  virtual void enterBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext *ctx) = 0;
  virtual void exitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext *ctx) = 0;

  virtual void enterBooleanExpression_(WorkScriptParser::BooleanExpression_Context *ctx) = 0;
  virtual void exitBooleanExpression_(WorkScriptParser::BooleanExpression_Context *ctx) = 0;

  virtual void enterAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx) = 0;
  virtual void exitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext *ctx) = 0;

  virtual void enterNumberExpression_(WorkScriptParser::NumberExpression_Context *ctx) = 0;
  virtual void exitNumberExpression_(WorkScriptParser::NumberExpression_Context *ctx) = 0;

  virtual void enterAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx) = 0;
  virtual void exitPositiveExpression(WorkScriptParser::PositiveExpressionContext *ctx) = 0;

  virtual void enterFunctionExpression_(WorkScriptParser::FunctionExpression_Context *ctx) = 0;
  virtual void exitFunctionExpression_(WorkScriptParser::FunctionExpression_Context *ctx) = 0;

  virtual void enterPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx) = 0;
  virtual void exitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext *ctx) = 0;

  virtual void enterNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx) = 0;
  virtual void exitNegativeExpression(WorkScriptParser::NegativeExpressionContext *ctx) = 0;

  virtual void enterCallExpression(WorkScriptParser::CallExpressionContext *ctx) = 0;
  virtual void exitCallExpression(WorkScriptParser::CallExpressionContext *ctx) = 0;

  virtual void enterMultiValueExpression(WorkScriptParser::MultiValueExpressionContext *ctx) = 0;
  virtual void exitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext *ctx) = 0;

  virtual void enterNumberExpression(WorkScriptParser::NumberExpressionContext *ctx) = 0;
  virtual void exitNumberExpression(WorkScriptParser::NumberExpressionContext *ctx) = 0;

  virtual void enterStringExpression(WorkScriptParser::StringExpressionContext *ctx) = 0;
  virtual void exitStringExpression(WorkScriptParser::StringExpressionContext *ctx) = 0;

  virtual void enterVariableExpression(WorkScriptParser::VariableExpressionContext *ctx) = 0;
  virtual void exitVariableExpression(WorkScriptParser::VariableExpressionContext *ctx) = 0;

  virtual void enterFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx) = 0;
  virtual void exitFunctionExpression(WorkScriptParser::FunctionExpressionContext *ctx) = 0;

  virtual void enterFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext *ctx) = 0;
  virtual void exitFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext *ctx) = 0;

  virtual void enterTypename(WorkScriptParser::TypenameContext *ctx) = 0;
  virtual void exitTypename(WorkScriptParser::TypenameContext *ctx) = 0;

  virtual void enterFunctionName(WorkScriptParser::FunctionNameContext *ctx) = 0;
  virtual void exitFunctionName(WorkScriptParser::FunctionNameContext *ctx) = 0;

  virtual void enterFormalParameterExpression(WorkScriptParser::FormalParameterExpressionContext *ctx) = 0;
  virtual void exitFormalParameterExpression(WorkScriptParser::FormalParameterExpressionContext *ctx) = 0;

  virtual void enterFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext *ctx) = 0;
  virtual void exitFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext *ctx) = 0;

  virtual void enterFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext *ctx) = 0;
  virtual void exitFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext *ctx) = 0;

  virtual void enterBlockExpression(WorkScriptParser::BlockExpressionContext *ctx) = 0;
  virtual void exitBlockExpression(WorkScriptParser::BlockExpressionContext *ctx) = 0;

  virtual void enterBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx) = 0;
  virtual void exitBooleanExpression(WorkScriptParser::BooleanExpressionContext *ctx) = 0;

  virtual void enterVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx) = 0;
  virtual void exitVarargsExpression(WorkScriptParser::VarargsExpressionContext *ctx) = 0;

  virtual void enterIdentifier(WorkScriptParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(WorkScriptParser::IdentifierContext *ctx) = 0;


};


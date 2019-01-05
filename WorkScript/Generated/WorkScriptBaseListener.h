
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "WorkScriptListener.h"


/**
 * This class provides an empty implementation of WorkScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WorkScriptBaseListener : public WorkScriptListener {
public:

  virtual void enterProgram(WorkScriptParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(WorkScriptParser::ProgramContext * /*ctx*/) override { }

  virtual void enterIncludeCommand(WorkScriptParser::IncludeCommandContext * /*ctx*/) override { }
  virtual void exitIncludeCommand(WorkScriptParser::IncludeCommandContext * /*ctx*/) override { }

  virtual void enterAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext * /*ctx*/) override { }
  virtual void exitAccessLevelExpression(WorkScriptParser::AccessLevelExpressionContext * /*ctx*/) override { }

  virtual void enterParentheseExpression(WorkScriptParser::ParentheseExpressionContext * /*ctx*/) override { }
  virtual void exitParentheseExpression(WorkScriptParser::ParentheseExpressionContext * /*ctx*/) override { }

  virtual void enterCallExpression_(WorkScriptParser::CallExpression_Context * /*ctx*/) override { }
  virtual void exitCallExpression_(WorkScriptParser::CallExpression_Context * /*ctx*/) override { }

  virtual void enterStringExpression_(WorkScriptParser::StringExpression_Context * /*ctx*/) override { }
  virtual void exitStringExpression_(WorkScriptParser::StringExpression_Context * /*ctx*/) override { }

  virtual void enterMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplyDivideModulusExpression(WorkScriptParser::MultiplyDivideModulusExpressionContext * /*ctx*/) override { }

  virtual void enterVariableExpression_(WorkScriptParser::VariableExpression_Context * /*ctx*/) override { }
  virtual void exitVariableExpression_(WorkScriptParser::VariableExpression_Context * /*ctx*/) override { }

  virtual void enterBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext * /*ctx*/) override { }
  virtual void exitBinaryCompareExpression(WorkScriptParser::BinaryCompareExpressionContext * /*ctx*/) override { }

  virtual void enterBooleanExpression_(WorkScriptParser::BooleanExpression_Context * /*ctx*/) override { }
  virtual void exitBooleanExpression_(WorkScriptParser::BooleanExpression_Context * /*ctx*/) override { }

  virtual void enterAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentOrEqualsExpression(WorkScriptParser::AssignmentOrEqualsExpressionContext * /*ctx*/) override { }

  virtual void enterNumberExpression_(WorkScriptParser::NumberExpression_Context * /*ctx*/) override { }
  virtual void exitNumberExpression_(WorkScriptParser::NumberExpression_Context * /*ctx*/) override { }

  virtual void enterAssignmentExpression(WorkScriptParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(WorkScriptParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterPositiveExpression(WorkScriptParser::PositiveExpressionContext * /*ctx*/) override { }
  virtual void exitPositiveExpression(WorkScriptParser::PositiveExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionExpression_(WorkScriptParser::FunctionExpression_Context * /*ctx*/) override { }
  virtual void exitFunctionExpression_(WorkScriptParser::FunctionExpression_Context * /*ctx*/) override { }

  virtual void enterPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext * /*ctx*/) override { }
  virtual void exitPlusMinusExpression(WorkScriptParser::PlusMinusExpressionContext * /*ctx*/) override { }

  virtual void enterNegativeExpression(WorkScriptParser::NegativeExpressionContext * /*ctx*/) override { }
  virtual void exitNegativeExpression(WorkScriptParser::NegativeExpressionContext * /*ctx*/) override { }

  virtual void enterCallExpression(WorkScriptParser::CallExpressionContext * /*ctx*/) override { }
  virtual void exitCallExpression(WorkScriptParser::CallExpressionContext * /*ctx*/) override { }

  virtual void enterMultiValueExpression(WorkScriptParser::MultiValueExpressionContext * /*ctx*/) override { }
  virtual void exitMultiValueExpression(WorkScriptParser::MultiValueExpressionContext * /*ctx*/) override { }

  virtual void enterNumberExpression(WorkScriptParser::NumberExpressionContext * /*ctx*/) override { }
  virtual void exitNumberExpression(WorkScriptParser::NumberExpressionContext * /*ctx*/) override { }

  virtual void enterStringExpression(WorkScriptParser::StringExpressionContext * /*ctx*/) override { }
  virtual void exitStringExpression(WorkScriptParser::StringExpressionContext * /*ctx*/) override { }

  virtual void enterVariableExpression(WorkScriptParser::VariableExpressionContext * /*ctx*/) override { }
  virtual void exitVariableExpression(WorkScriptParser::VariableExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionExpression(WorkScriptParser::FunctionExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionExpression(WorkScriptParser::FunctionExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionDeclarationExpression(WorkScriptParser::FunctionDeclarationExpressionContext * /*ctx*/) override { }

  virtual void enterTypename(WorkScriptParser::TypenameContext * /*ctx*/) override { }
  virtual void exitTypename(WorkScriptParser::TypenameContext * /*ctx*/) override { }

  virtual void enterFunctionName(WorkScriptParser::FunctionNameContext * /*ctx*/) override { }
  virtual void exitFunctionName(WorkScriptParser::FunctionNameContext * /*ctx*/) override { }

  virtual void enterFormalParameterExpression(WorkScriptParser::FormalParameterExpressionContext * /*ctx*/) override { }
  virtual void exitFormalParameterExpression(WorkScriptParser::FormalParameterExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionImplementationExpression(WorkScriptParser::FunctionImplementationExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionConstraintExpression(WorkScriptParser::FunctionConstraintExpressionContext * /*ctx*/) override { }

  virtual void enterBlockExpression(WorkScriptParser::BlockExpressionContext * /*ctx*/) override { }
  virtual void exitBlockExpression(WorkScriptParser::BlockExpressionContext * /*ctx*/) override { }

  virtual void enterBooleanExpression(WorkScriptParser::BooleanExpressionContext * /*ctx*/) override { }
  virtual void exitBooleanExpression(WorkScriptParser::BooleanExpressionContext * /*ctx*/) override { }

  virtual void enterVarargsExpression(WorkScriptParser::VarargsExpressionContext * /*ctx*/) override { }
  virtual void exitVarargsExpression(WorkScriptParser::VarargsExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifier(WorkScriptParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(WorkScriptParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


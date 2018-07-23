
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

  virtual void enterTermExpression(WorkScriptParser::TermExpressionContext *ctx) = 0;
  virtual void exitTermExpression(WorkScriptParser::TermExpressionContext *ctx) = 0;

  virtual void enterRelationExpression(WorkScriptParser::RelationExpressionContext *ctx) = 0;
  virtual void exitRelationExpression(WorkScriptParser::RelationExpressionContext *ctx) = 0;

  virtual void enterBlockExpression(WorkScriptParser::BlockExpressionContext *ctx) = 0;
  virtual void exitBlockExpression(WorkScriptParser::BlockExpressionContext *ctx) = 0;

  virtual void enterFunctionInvocationTerm(WorkScriptParser::FunctionInvocationTermContext *ctx) = 0;
  virtual void exitFunctionInvocationTerm(WorkScriptParser::FunctionInvocationTermContext *ctx) = 0;

  virtual void enterNumberTerm(WorkScriptParser::NumberTermContext *ctx) = 0;
  virtual void exitNumberTerm(WorkScriptParser::NumberTermContext *ctx) = 0;

  virtual void enterIdentifierTerm(WorkScriptParser::IdentifierTermContext *ctx) = 0;
  virtual void exitIdentifierTerm(WorkScriptParser::IdentifierTermContext *ctx) = 0;

  virtual void enterGreaterThanEqualTerm(WorkScriptParser::GreaterThanEqualTermContext *ctx) = 0;
  virtual void exitGreaterThanEqualTerm(WorkScriptParser::GreaterThanEqualTermContext *ctx) = 0;

  virtual void enterGreaterThanTerm(WorkScriptParser::GreaterThanTermContext *ctx) = 0;
  virtual void exitGreaterThanTerm(WorkScriptParser::GreaterThanTermContext *ctx) = 0;

  virtual void enterLessThanEqualTerm(WorkScriptParser::LessThanEqualTermContext *ctx) = 0;
  virtual void exitLessThanEqualTerm(WorkScriptParser::LessThanEqualTermContext *ctx) = 0;

  virtual void enterLessThanTerm(WorkScriptParser::LessThanTermContext *ctx) = 0;
  virtual void exitLessThanTerm(WorkScriptParser::LessThanTermContext *ctx) = 0;


};



// Generated from WorkScript.g4 by ANTLR 4.7.1
#include "stdafx.h"
#include "WorkScriptVisitor.h"

#include "WorkScriptParser.h"


using namespace antlrcpp;
using namespace antlr4;

WorkScriptParser::WorkScriptParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

WorkScriptParser::~WorkScriptParser() {
  delete _interpreter;
}

std::string WorkScriptParser::getGrammarFileName() const {
  return "WorkScript.g4";
}

const std::vector<std::string>& WorkScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& WorkScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

WorkScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::ProgramContext::EOF() {
  return getToken(WorkScriptParser::EOF, 0);
}

std::vector<WorkScriptParser::IncludeCommandContext *> WorkScriptParser::ProgramContext::includeCommand() {
  return getRuleContexts<WorkScriptParser::IncludeCommandContext>();
}

WorkScriptParser::IncludeCommandContext* WorkScriptParser::ProgramContext::includeCommand(size_t i) {
  return getRuleContext<WorkScriptParser::IncludeCommandContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ProgramContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::ProgramContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ProgramContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}


size_t WorkScriptParser::ProgramContext::getRuleIndex() const {
  return WorkScriptParser::RuleProgram;
}

antlrcpp::Any WorkScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ProgramContext* WorkScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, WorkScriptParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(39);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(37);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WorkScriptParser::HASH: {
            setState(32);
            includeCommand();
            setState(34);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
            case 1: {
              setState(33);
              match(WorkScriptParser::NEWLINE);
              break;
            }

            }
            break;
          }

          case WorkScriptParser::NEWLINE: {
            setState(36);
            match(WorkScriptParser::NEWLINE);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(41);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(47);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::ACCESS_LEVEL:
        case WorkScriptParser::INCLUDE:
        case WorkScriptParser::WHEN:
        case WorkScriptParser::BOOLEAN:
        case WorkScriptParser::IDENTIFIER:
        case WorkScriptParser::DOUBLE:
        case WorkScriptParser::INTEGER:
        case WorkScriptParser::STRING:
        case WorkScriptParser::LEFT_PARENTHESE:
        case WorkScriptParser::LEFT_BRACKET:
        case WorkScriptParser::PLUS:
        case WorkScriptParser::MINUS: {
          setState(42);
          expression(0);
          setState(44);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
          case 1: {
            setState(43);
            match(WorkScriptParser::NEWLINE);
            break;
          }

          }
          break;
        }

        case WorkScriptParser::NEWLINE: {
          setState(46);
          match(WorkScriptParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(WorkScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeCommandContext ------------------------------------------------------------------

WorkScriptParser::IncludeCommandContext::IncludeCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::IncludeCommandContext::HASH() {
  return getToken(WorkScriptParser::HASH, 0);
}

tree::TerminalNode* WorkScriptParser::IncludeCommandContext::INCLUDE() {
  return getToken(WorkScriptParser::INCLUDE, 0);
}

tree::TerminalNode* WorkScriptParser::IncludeCommandContext::STRING() {
  return getToken(WorkScriptParser::STRING, 0);
}


size_t WorkScriptParser::IncludeCommandContext::getRuleIndex() const {
  return WorkScriptParser::RuleIncludeCommand;
}

antlrcpp::Any WorkScriptParser::IncludeCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitIncludeCommand(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::IncludeCommandContext* WorkScriptParser::includeCommand() {
  IncludeCommandContext *_localctx = _tracker.createInstance<IncludeCommandContext>(_ctx, getState());
  enterRule(_localctx, 2, WorkScriptParser::RuleIncludeCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(WorkScriptParser::HASH);
    setState(55);
    match(WorkScriptParser::INCLUDE);
    setState(56);
    match(WorkScriptParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WorkScriptParser::ExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleExpression;
}

void WorkScriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AccessLevelExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::AccessLevelExpressionContext::ACCESS_LEVEL() {
  return getToken(WorkScriptParser::ACCESS_LEVEL, 0);
}

tree::TerminalNode* WorkScriptParser::AccessLevelExpressionContext::COLON() {
  return getToken(WorkScriptParser::COLON, 0);
}

WorkScriptParser::AccessLevelExpressionContext::AccessLevelExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::AccessLevelExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAccessLevelExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParentheseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ParentheseExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::ParentheseExpressionContext::ParentheseExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::ParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParentheseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::ListExpressionContext::LEFT_BRACKET() {
  return getToken(WorkScriptParser::LEFT_BRACKET, 0);
}

tree::TerminalNode* WorkScriptParser::ListExpressionContext::RIGHT_BRACKET() {
  return getToken(WorkScriptParser::RIGHT_BRACKET, 0);
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::ListExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ListExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ListExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::ListExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}

WorkScriptParser::ListExpressionContext::ListExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::ListExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitListExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExpression_Context ------------------------------------------------------------------

WorkScriptParser::StringExpressionContext* WorkScriptParser::StringExpression_Context::stringExpression() {
  return getRuleContext<WorkScriptParser::StringExpressionContext>(0);
}

WorkScriptParser::StringExpression_Context::StringExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::StringExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStringExpression_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyDivideModulusExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::MultiplyDivideModulusExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::MultiplyDivideModulusExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::MULTIPLY() {
  return getToken(WorkScriptParser::MULTIPLY, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::DIVIDE() {
  return getToken(WorkScriptParser::DIVIDE, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::MODULUS() {
  return getToken(WorkScriptParser::MODULUS, 0);
}

WorkScriptParser::MultiplyDivideModulusExpressionContext::MultiplyDivideModulusExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MultiplyDivideModulusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplyDivideModulusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionInvocationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionInvocationExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::FunctionInvocationExpressionContext::parameterExpression() {
  return getRuleContext<WorkScriptParser::ParameterExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionInvocationExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::FunctionInvocationExpressionContext::FunctionInvocationExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::FunctionInvocationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionInvocationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompareExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::CompareExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::CompareExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::CompareExpressionContext::GREATER_THAN() {
  return getToken(WorkScriptParser::GREATER_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::CompareExpressionContext::GREATER_THAN_EQUAL() {
  return getToken(WorkScriptParser::GREATER_THAN_EQUAL, 0);
}

tree::TerminalNode* WorkScriptParser::CompareExpressionContext::LESS_THAN() {
  return getToken(WorkScriptParser::LESS_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::CompareExpressionContext::LESS_THAN_EQUAL() {
  return getToken(WorkScriptParser::LESS_THAN_EQUAL, 0);
}

WorkScriptParser::CompareExpressionContext::CompareExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::CompareExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCompareExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableExpression_Context ------------------------------------------------------------------

WorkScriptParser::VariableExpressionContext* WorkScriptParser::VariableExpression_Context::variableExpression() {
  return getRuleContext<WorkScriptParser::VariableExpressionContext>(0);
}

WorkScriptParser::VariableExpression_Context::VariableExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::VariableExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVariableExpression_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::MethodInvocationExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::parameterExpression() {
  return getRuleContext<WorkScriptParser::ParameterExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::MethodInvocationExpressionContext::MethodInvocationExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MethodInvocationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMethodInvocationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanExpression_Context ------------------------------------------------------------------

WorkScriptParser::BooleanExpressionContext* WorkScriptParser::BooleanExpression_Context::booleanExpression() {
  return getRuleContext<WorkScriptParser::BooleanExpressionContext>(0);
}

WorkScriptParser::BooleanExpression_Context::BooleanExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::BooleanExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBooleanExpression_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentOrEqualsExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::AssignmentOrEqualsExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::AssignmentOrEqualsExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::AssignmentOrEqualsExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::AssignmentOrEqualsExpressionContext::AssignmentOrEqualsExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::AssignmentOrEqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOrEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberExpression_Context ------------------------------------------------------------------

WorkScriptParser::NumberExpressionContext* WorkScriptParser::NumberExpression_Context::numberExpression() {
  return getRuleContext<WorkScriptParser::NumberExpressionContext>(0);
}

WorkScriptParser::NumberExpression_Context::NumberExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::NumberExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNumberExpression_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::AssignmentExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::AssignmentExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::AssignmentExpressionContext::ASSIGN() {
  return getToken(WorkScriptParser::ASSIGN, 0);
}

WorkScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberEvaluateExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext* WorkScriptParser::MemberEvaluateExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MemberEvaluateExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::MemberEvaluateExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

WorkScriptParser::MemberEvaluateExpressionContext::MemberEvaluateExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MemberEvaluateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMemberEvaluateExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositiveExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::PositiveExpressionContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::PositiveExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::PositiveExpressionContext::PositiveExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::PositiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPositiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExpression_Context ------------------------------------------------------------------

WorkScriptParser::FunctionExpressionContext* WorkScriptParser::FunctionExpression_Context::functionExpression() {
  return getRuleContext<WorkScriptParser::FunctionExpressionContext>(0);
}

WorkScriptParser::FunctionExpression_Context::FunctionExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::FunctionExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NonSignMultiplyExpressionContext ------------------------------------------------------------------

WorkScriptParser::NumberExpressionContext* WorkScriptParser::NonSignMultiplyExpressionContext::numberExpression() {
  return getRuleContext<WorkScriptParser::NumberExpressionContext>(0);
}

WorkScriptParser::VariableExpressionContext* WorkScriptParser::NonSignMultiplyExpressionContext::variableExpression() {
  return getRuleContext<WorkScriptParser::VariableExpressionContext>(0);
}

WorkScriptParser::NonSignMultiplyExpressionContext::NonSignMultiplyExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::NonSignMultiplyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNonSignMultiplyExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::PlusMinusExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::PlusMinusExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::PlusMinusExpressionContext::PlusMinusExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::PlusMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPlusMinusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::NegativeExpressionContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::NegativeExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::NegativeExpressionContext::NegativeExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::NegativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNegativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualsExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::EqualsExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::EqualsExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::EqualsExpressionContext::DOUBLE_EQUAL() {
  return getToken(WorkScriptParser::DOUBLE_EQUAL, 0);
}

WorkScriptParser::EqualsExpressionContext::EqualsExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::EqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::expression() {
   return expression(0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WorkScriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  WorkScriptParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, WorkScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(59);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(60);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(62);
      expression(0);
      setState(63);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ListExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(65);
      match(WorkScriptParser::LEFT_BRACKET);
      setState(74);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
        | (1ULL << WorkScriptParser::INCLUDE)
        | (1ULL << WorkScriptParser::WHEN)
        | (1ULL << WorkScriptParser::BOOLEAN)
        | (1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::DOUBLE)
        | (1ULL << WorkScriptParser::INTEGER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
        | (1ULL << WorkScriptParser::LEFT_BRACKET)
        | (1ULL << WorkScriptParser::PLUS)
        | (1ULL << WorkScriptParser::MINUS))) != 0)) {
        setState(66);
        expression(0);
        setState(71);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::COMMA) {
          setState(67);
          match(WorkScriptParser::COMMA);
          setState(68);
          expression(0);
          setState(73);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(76);
      match(WorkScriptParser::RIGHT_BRACKET);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctionExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(77);
      functionExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NonSignMultiplyExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(78);
      numberExpression();
      setState(79);
      variableExpression();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NumberExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(81);
      numberExpression();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegativeExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(82);
      match(WorkScriptParser::MINUS);
      setState(83);
      expression(9);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PositiveExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(84);
      match(WorkScriptParser::PLUS);
      setState(85);
      expression(8);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<StringExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(86);
      stringExpression();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<BooleanExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      booleanExpression();
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<VariableExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(88);
      variableExpression();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(126);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(124);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(91);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(92);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WorkScriptParser::MULTIPLY)
            | (1ULL << WorkScriptParser::DIVIDE)
            | (1ULL << WorkScriptParser::MODULUS))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(93);
          expression(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(94);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(95);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(96);
          expression(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(97);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(98);
          match(WorkScriptParser::ASSIGN);
          setState(99);
          expression(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(100);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(101);
          match(WorkScriptParser::DOUBLE_EQUAL);
          setState(102);
          expression(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(103);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(104);
          match(WorkScriptParser::EQUALS);
          setState(105);
          expression(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<CompareExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(106);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(107);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WorkScriptParser::GREATER_THAN)
            | (1ULL << WorkScriptParser::GREATER_THAN_EQUAL)
            | (1ULL << WorkScriptParser::LESS_THAN)
            | (1ULL << WorkScriptParser::LESS_THAN_EQUAL))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(108);
          expression(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<FunctionInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(109);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(110);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(111);
          parameterExpression();
          setState(112);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<MethodInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(114);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(115);
          match(WorkScriptParser::POINT);
          setState(116);
          identifier();
          setState(117);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(118);
          parameterExpression();
          setState(119);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(121);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(122);
          match(WorkScriptParser::POINT);
          setState(123);
          identifier();
          break;
        }

        } 
      }
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterExpressionContext ------------------------------------------------------------------

WorkScriptParser::ParameterExpressionContext::ParameterExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::ParameterExpressionItemContext *> WorkScriptParser::ParameterExpressionContext::parameterExpressionItem() {
  return getRuleContexts<WorkScriptParser::ParameterExpressionItemContext>();
}

WorkScriptParser::ParameterExpressionItemContext* WorkScriptParser::ParameterExpressionContext::parameterExpressionItem(size_t i) {
  return getRuleContext<WorkScriptParser::ParameterExpressionItemContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ParameterExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::ParameterExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ParameterExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::ParameterExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}


size_t WorkScriptParser::ParameterExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleParameterExpression;
}

antlrcpp::Any WorkScriptParser::ParameterExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParameterExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::parameterExpression() {
  ParameterExpressionContext *_localctx = _tracker.createInstance<ParameterExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WorkScriptParser::RuleParameterExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(155);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(129);
        match(WorkScriptParser::NEWLINE);
        setState(134);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(135);
      parameterExpressionItem();
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(139);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(136);
              match(WorkScriptParser::NEWLINE); 
            }
            setState(141);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
          }
          setState(142);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::COMMA

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(146);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::NEWLINE) {
            setState(143);
            match(WorkScriptParser::NEWLINE);
            setState(148);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(149);
          parameterExpressionItem(); 
        }
        setState(154);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      break;
    }

    }
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(157);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA) {
      setState(163);
      match(WorkScriptParser::COMMA);
    }
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(166);
      match(WorkScriptParser::NEWLINE);
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterExpressionItemContext ------------------------------------------------------------------

WorkScriptParser::ParameterExpressionItemContext::ParameterExpressionItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ParameterExpressionItemContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::VarargsExpressionContext* WorkScriptParser::ParameterExpressionItemContext::varargsExpression() {
  return getRuleContext<WorkScriptParser::VarargsExpressionContext>(0);
}


size_t WorkScriptParser::ParameterExpressionItemContext::getRuleIndex() const {
  return WorkScriptParser::RuleParameterExpressionItem;
}

antlrcpp::Any WorkScriptParser::ParameterExpressionItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParameterExpressionItem(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ParameterExpressionItemContext* WorkScriptParser::parameterExpressionItem() {
  ParameterExpressionItemContext *_localctx = _tracker.createInstance<ParameterExpressionItemContext>(_ctx, getState());
  enterRule(_localctx, 8, WorkScriptParser::RuleParameterExpressionItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::ACCESS_LEVEL:
      case WorkScriptParser::INCLUDE:
      case WorkScriptParser::WHEN:
      case WorkScriptParser::BOOLEAN:
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::DOUBLE:
      case WorkScriptParser::INTEGER:
      case WorkScriptParser::STRING:
      case WorkScriptParser::LEFT_PARENTHESE:
      case WorkScriptParser::LEFT_BRACKET:
      case WorkScriptParser::PLUS:
      case WorkScriptParser::MINUS: {
        setState(172);
        expression(0);
        break;
      }

      case WorkScriptParser::APOSTROPHE: {
        setState(173);
        varargsExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberExpressionContext ------------------------------------------------------------------

WorkScriptParser::NumberExpressionContext::NumberExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::DOUBLE() {
  return getToken(WorkScriptParser::DOUBLE, 0);
}

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::INTEGER() {
  return getToken(WorkScriptParser::INTEGER, 0);
}

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}


size_t WorkScriptParser::NumberExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleNumberExpression;
}

antlrcpp::Any WorkScriptParser::NumberExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNumberExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::NumberExpressionContext* WorkScriptParser::numberExpression() {
  NumberExpressionContext *_localctx = _tracker.createInstance<NumberExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, WorkScriptParser::RuleNumberExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::PLUS

    || _la == WorkScriptParser::MINUS) {
      setState(176);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::PLUS

      || _la == WorkScriptParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(179);
    _la = _input->LA(1);
    if (!(_la == WorkScriptParser::DOUBLE

    || _la == WorkScriptParser::INTEGER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringExpressionContext ------------------------------------------------------------------

WorkScriptParser::StringExpressionContext::StringExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::StringExpressionContext::STRING() {
  return getToken(WorkScriptParser::STRING, 0);
}


size_t WorkScriptParser::StringExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleStringExpression;
}

antlrcpp::Any WorkScriptParser::StringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStringExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StringExpressionContext* WorkScriptParser::stringExpression() {
  StringExpressionContext *_localctx = _tracker.createInstance<StringExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, WorkScriptParser::RuleStringExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(WorkScriptParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableExpressionContext ------------------------------------------------------------------

WorkScriptParser::VariableExpressionContext::VariableExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::VariableExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::VariableExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleVariableExpression;
}

antlrcpp::Any WorkScriptParser::VariableExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVariableExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::VariableExpressionContext* WorkScriptParser::variableExpression() {
  VariableExpressionContext *_localctx = _tracker.createInstance<VariableExpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, WorkScriptParser::RuleVariableExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionExpressionContext ------------------------------------------------------------------

WorkScriptParser::FunctionExpressionContext::FunctionExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::FunctionDeclarationExpressionContext* WorkScriptParser::FunctionExpressionContext::functionDeclarationExpression() {
  return getRuleContext<WorkScriptParser::FunctionDeclarationExpressionContext>(0);
}

WorkScriptParser::FunctionImplementationExpressionContext* WorkScriptParser::FunctionExpressionContext::functionImplementationExpression() {
  return getRuleContext<WorkScriptParser::FunctionImplementationExpressionContext>(0);
}

WorkScriptParser::FunctionConstraintExpressionContext* WorkScriptParser::FunctionExpressionContext::functionConstraintExpression() {
  return getRuleContext<WorkScriptParser::FunctionConstraintExpressionContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionExpression;
}

antlrcpp::Any WorkScriptParser::FunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionExpressionContext* WorkScriptParser::functionExpression() {
  FunctionExpressionContext *_localctx = _tracker.createInstance<FunctionExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, WorkScriptParser::RuleFunctionExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(185);
        functionConstraintExpression();
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(186);
          match(WorkScriptParser::NEWLINE);
          setState(191);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(194);
      functionDeclarationExpression();
      setState(198);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(195);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(200);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      }
      setState(201);
      functionImplementationExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(203);
      functionDeclarationExpression();
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(204);
        match(WorkScriptParser::NEWLINE);
        setState(209);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(210);
      functionConstraintExpression();
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(211);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(216);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      }
      setState(217);
      functionImplementationExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      functionDeclarationExpression();
      setState(223);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(220);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(225);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      }
      setState(226);
      functionImplementationExpression();
      setState(230);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(227);
        match(WorkScriptParser::NEWLINE);
        setState(232);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(233);
      functionConstraintExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationExpressionContext ------------------------------------------------------------------

WorkScriptParser::FunctionDeclarationExpressionContext::FunctionDeclarationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::FunctionDeclarationExpressionContext::parameterExpression() {
  return getRuleContext<WorkScriptParser::ParameterExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::FunctionDeclarationExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::FunctionDeclarationExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionDeclarationExpression;
}

antlrcpp::Any WorkScriptParser::FunctionDeclarationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclarationExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionDeclarationExpressionContext* WorkScriptParser::functionDeclarationExpression() {
  FunctionDeclarationExpressionContext *_localctx = _tracker.createInstance<FunctionDeclarationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, WorkScriptParser::RuleFunctionDeclarationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(237);
      identifier();
    }
    setState(240);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(241);
    parameterExpression();
    setState(242);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionImplementationExpressionContext ------------------------------------------------------------------

WorkScriptParser::FunctionImplementationExpressionContext::FunctionImplementationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionImplementationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationExpressionContext::RIGHT_ARROW() {
  return getToken(WorkScriptParser::RIGHT_ARROW, 0);
}

WorkScriptParser::BlockExpressionContext* WorkScriptParser::FunctionImplementationExpressionContext::blockExpression() {
  return getRuleContext<WorkScriptParser::BlockExpressionContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionImplementationExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionImplementationExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionImplementationExpression;
}

antlrcpp::Any WorkScriptParser::FunctionImplementationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionImplementationExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionImplementationExpressionContext* WorkScriptParser::functionImplementationExpression() {
  FunctionImplementationExpressionContext *_localctx = _tracker.createInstance<FunctionImplementationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, WorkScriptParser::RuleFunctionImplementationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(244);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(245);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(246);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(251);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      }
      setState(253);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(252);
        _la = _input->LA(1);
        if (!(_la == WorkScriptParser::EQUALS

        || _la == WorkScriptParser::RIGHT_ARROW)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(255);
        match(WorkScriptParser::NEWLINE);
        setState(260);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(261);
      blockExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionConstraintExpressionContext ------------------------------------------------------------------

WorkScriptParser::FunctionConstraintExpressionContext::FunctionConstraintExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::FunctionConstraintExpressionContext::WHEN() {
  return getToken(WorkScriptParser::WHEN, 0);
}

WorkScriptParser::BlockExpressionContext* WorkScriptParser::FunctionConstraintExpressionContext::blockExpression() {
  return getRuleContext<WorkScriptParser::BlockExpressionContext>(0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionConstraintExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionConstraintExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionConstraintExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionConstraintExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionConstraintExpression;
}

antlrcpp::Any WorkScriptParser::FunctionConstraintExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionConstraintExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionConstraintExpressionContext* WorkScriptParser::functionConstraintExpression() {
  FunctionConstraintExpressionContext *_localctx = _tracker.createInstance<FunctionConstraintExpressionContext>(_ctx, getState());
  enterRule(_localctx, 22, WorkScriptParser::RuleFunctionConstraintExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(WorkScriptParser::WHEN);
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(265);
      match(WorkScriptParser::NEWLINE);
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(271);
        blockExpression();
        break;
      }

      case WorkScriptParser::ACCESS_LEVEL:
      case WorkScriptParser::INCLUDE:
      case WorkScriptParser::WHEN:
      case WorkScriptParser::BOOLEAN:
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::DOUBLE:
      case WorkScriptParser::INTEGER:
      case WorkScriptParser::STRING:
      case WorkScriptParser::LEFT_PARENTHESE:
      case WorkScriptParser::LEFT_BRACKET:
      case WorkScriptParser::PLUS:
      case WorkScriptParser::MINUS: {
        setState(272);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockExpressionContext ------------------------------------------------------------------

WorkScriptParser::BlockExpressionContext::BlockExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::BlockExpressionContext::LEFT_BRACE() {
  return getToken(WorkScriptParser::LEFT_BRACE, 0);
}

tree::TerminalNode* WorkScriptParser::BlockExpressionContext::RIGHT_BRACE() {
  return getToken(WorkScriptParser::RIGHT_BRACE, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::BlockExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::BlockExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::BlockExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::BlockExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}


size_t WorkScriptParser::BlockExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleBlockExpression;
}

antlrcpp::Any WorkScriptParser::BlockExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBlockExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::BlockExpressionContext* WorkScriptParser::blockExpression() {
  BlockExpressionContext *_localctx = _tracker.createInstance<BlockExpressionContext>(_ctx, getState());
  enterRule(_localctx, 24, WorkScriptParser::RuleBlockExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(WorkScriptParser::LEFT_BRACE);
    setState(279);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(276);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(281);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(290);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(282);
          expression(0);
          setState(284); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(283);
            match(WorkScriptParser::NEWLINE);
            setState(286); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(292);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
      }
      setState(293);
      expression(0);
    }
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(296);
      match(WorkScriptParser::NEWLINE);
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(302);
    match(WorkScriptParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExpressionContext ------------------------------------------------------------------

WorkScriptParser::BooleanExpressionContext::BooleanExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::BooleanExpressionContext::BOOLEAN() {
  return getToken(WorkScriptParser::BOOLEAN, 0);
}


size_t WorkScriptParser::BooleanExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleBooleanExpression;
}

antlrcpp::Any WorkScriptParser::BooleanExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBooleanExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::BooleanExpressionContext* WorkScriptParser::booleanExpression() {
  BooleanExpressionContext *_localctx = _tracker.createInstance<BooleanExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, WorkScriptParser::RuleBooleanExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(WorkScriptParser::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarargsExpressionContext ------------------------------------------------------------------

WorkScriptParser::VarargsExpressionContext::VarargsExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::VarargsExpressionContext::APOSTROPHE() {
  return getToken(WorkScriptParser::APOSTROPHE, 0);
}

WorkScriptParser::VariableExpressionContext* WorkScriptParser::VarargsExpressionContext::variableExpression() {
  return getRuleContext<WorkScriptParser::VariableExpressionContext>(0);
}


size_t WorkScriptParser::VarargsExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleVarargsExpression;
}

antlrcpp::Any WorkScriptParser::VarargsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVarargsExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::VarargsExpressionContext* WorkScriptParser::varargsExpression() {
  VarargsExpressionContext *_localctx = _tracker.createInstance<VarargsExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, WorkScriptParser::RuleVarargsExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(WorkScriptParser::APOSTROPHE);
    setState(307);
    variableExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

WorkScriptParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::IdentifierContext::BOOLEAN() {
  return getToken(WorkScriptParser::BOOLEAN, 0);
}

tree::TerminalNode* WorkScriptParser::IdentifierContext::WHEN() {
  return getToken(WorkScriptParser::WHEN, 0);
}

tree::TerminalNode* WorkScriptParser::IdentifierContext::INCLUDE() {
  return getToken(WorkScriptParser::INCLUDE, 0);
}

tree::TerminalNode* WorkScriptParser::IdentifierContext::ACCESS_LEVEL() {
  return getToken(WorkScriptParser::ACCESS_LEVEL, 0);
}

tree::TerminalNode* WorkScriptParser::IdentifierContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}


size_t WorkScriptParser::IdentifierContext::getRuleIndex() const {
  return WorkScriptParser::RuleIdentifier;
}

antlrcpp::Any WorkScriptParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, WorkScriptParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool WorkScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 18);
    case 7: return precpred(_ctx, 16);
    case 8: return precpred(_ctx, 15);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> WorkScriptParser::_decisionToDFA;
atn::PredictionContextCache WorkScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN WorkScriptParser::_atn;
std::vector<uint16_t> WorkScriptParser::_serializedATN;

std::vector<std::string> WorkScriptParser::_ruleNames = {
  "program", "includeCommand", "expression", "parameterExpression", "parameterExpressionItem", 
  "numberExpression", "stringExpression", "variableExpression", "functionExpression", 
  "functionDeclarationExpression", "functionImplementationExpression", "functionConstraintExpression", 
  "blockExpression", "booleanExpression", "varargsExpression", "identifier"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "'include'", "'when'", "", "", "", "", "", "'.'", "','", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "'=='", "'='", "'=>'", "':='", "':'", 
  "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'>'", "'>='", "'<'", "'<='", 
  "", "", "'...'", "'\n'"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
  "INTEGER", "STRING", "POINT", "COMMA", "LEFT_PARENTHESE", "RIGHT_PARENTHESE", 
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "DOUBLE_EQUAL", 
  "EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "MULTIPLY", 
  "DIVIDE", "MODULUS", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
  "LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "APOSTROPHE", 
  "NEWLINE", "WS"
};

dfa::Vocabulary WorkScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> WorkScriptParser::_tokenNames;

WorkScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x26, 0x13a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x25, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x28, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x2b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 
    0x2f, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x35, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x48, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x4b, 0xb, 0x4, 0x5, 0x4, 0x4d, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5c, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x7f, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x82, 0xb, 0x4, 0x3, 0x5, 0x7, 0x5, 0x85, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x88, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x8c, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x8f, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x93, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x96, 0xb, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x99, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x9c, 0xb, 0x5, 0x5, 
    0x5, 0x9e, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0xa1, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0xa4, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 0xa7, 0xa, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0xaa, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xad, 0xb, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0xb1, 0xa, 0x6, 0x3, 0x7, 0x5, 0x7, 0xb4, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0xbe, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc1, 0xb, 0xa, 0x5, 
    0xa, 0xc3, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc7, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0xca, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xd0, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xd3, 0xb, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x7, 0xa, 0xd7, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xda, 0xb, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xe0, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0xe3, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xe7, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0xea, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xee, 0xa, 0xa, 0x3, 0xb, 0x5, 0xb, 0xf1, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xfa, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0xfd, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x100, 
    0xa, 0xc, 0x3, 0xc, 0x7, 0xc, 0x103, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x106, 
    0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x109, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0x10d, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x110, 0xb, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0x114, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x118, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x11b, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x6, 
    0xe, 0x11f, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x120, 0x7, 0xe, 0x123, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0x126, 0xb, 0xe, 0x3, 0xe, 0x5, 0xe, 0x129, 
    0xa, 0xe, 0x3, 0xe, 0x7, 0xe, 0x12c, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x12f, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 0x3, 0x6, 0x12, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x2, 0x9, 0x3, 0x2, 0x1a, 0x1c, 0x3, 0x2, 0x18, 0x19, 0x3, 
    0x2, 0x1e, 0x21, 0x4, 0x2, 0xc, 0xc, 0x25, 0x25, 0x3, 0x2, 0x8, 0x9, 
    0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x3, 0x7, 0x2, 0x163, 0x2, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x38, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xed, 0x3, 0x2, 0x2, 0x2, 0x14, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x108, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x115, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x20, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x24, 0x5, 0x4, 0x3, 0x2, 0x23, 0x25, 0x7, 0x25, 0x2, 0x2, 0x24, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x7, 0x25, 0x2, 0x2, 0x27, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2e, 0x5, 0x6, 0x4, 0x2, 0x2d, 0x2f, 0x7, 0x25, 0x2, 0x2, 0x2e, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x7, 0x25, 0x2, 0x2, 0x31, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x37, 0x7, 0x2, 0x2, 0x3, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0x1d, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x4, 0x2, 0x2, 0x3a, 0x3b, 
    0x7, 0xa, 0x2, 0x2, 0x3b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x8, 
    0x4, 0x1, 0x2, 0x3d, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x3e, 0x5c, 0x7, 0x17, 
    0x2, 0x2, 0x3f, 0x40, 0x7, 0xd, 0x2, 0x2, 0x40, 0x41, 0x5, 0x6, 0x4, 
    0x2, 0x41, 0x42, 0x7, 0xe, 0x2, 0x2, 0x42, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x4c, 0x7, 0x11, 0x2, 0x2, 0x44, 0x49, 0x5, 0x6, 0x4, 0x2, 0x45, 
    0x46, 0x7, 0xc, 0x2, 0x2, 0x46, 0x48, 0x5, 0x6, 0x4, 0x2, 0x47, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x5c, 0x7, 0x12, 0x2, 0x2, 0x4f, 0x5c, 0x5, 0x12, 0xa, 0x2, 0x50, 
    0x51, 0x5, 0xc, 0x7, 0x2, 0x51, 0x52, 0x5, 0x10, 0x9, 0x2, 0x52, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x5c, 0x5, 0xc, 0x7, 0x2, 0x54, 0x55, 0x7, 
    0x19, 0x2, 0x2, 0x55, 0x5c, 0x5, 0x6, 0x4, 0xb, 0x56, 0x57, 0x7, 0x18, 
    0x2, 0x2, 0x57, 0x5c, 0x5, 0x6, 0x4, 0xa, 0x58, 0x5c, 0x5, 0xe, 0x8, 
    0x2, 0x59, 0x5c, 0x5, 0x1c, 0xf, 0x2, 0x5a, 0x5c, 0x5, 0x10, 0x9, 0x2, 
    0x5b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x80, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0xc, 0xf, 0x2, 0x2, 
    0x5e, 0x5f, 0x9, 0x2, 0x2, 0x2, 0x5f, 0x7f, 0x5, 0x6, 0x4, 0x10, 0x60, 
    0x61, 0xc, 0xd, 0x2, 0x2, 0x61, 0x62, 0x9, 0x3, 0x2, 0x2, 0x62, 0x7f, 
    0x5, 0x6, 0x4, 0xe, 0x63, 0x64, 0xc, 0x9, 0x2, 0x2, 0x64, 0x65, 0x7, 
    0x16, 0x2, 0x2, 0x65, 0x7f, 0x5, 0x6, 0x4, 0xa, 0x66, 0x67, 0xc, 0x8, 
    0x2, 0x2, 0x67, 0x68, 0x7, 0x13, 0x2, 0x2, 0x68, 0x7f, 0x5, 0x6, 0x4, 
    0x9, 0x69, 0x6a, 0xc, 0x7, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x14, 0x2, 0x2, 
    0x6b, 0x7f, 0x5, 0x6, 0x4, 0x8, 0x6c, 0x6d, 0xc, 0x6, 0x2, 0x2, 0x6d, 
    0x6e, 0x9, 0x4, 0x2, 0x2, 0x6e, 0x7f, 0x5, 0x6, 0x4, 0x7, 0x6f, 0x70, 
    0xc, 0x14, 0x2, 0x2, 0x70, 0x71, 0x7, 0xd, 0x2, 0x2, 0x71, 0x72, 0x5, 
    0x8, 0x5, 0x2, 0x72, 0x73, 0x7, 0xe, 0x2, 0x2, 0x73, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x75, 0xc, 0x12, 0x2, 0x2, 0x75, 0x76, 0x7, 0xb, 0x2, 
    0x2, 0x76, 0x77, 0x5, 0x20, 0x11, 0x2, 0x77, 0x78, 0x7, 0xd, 0x2, 0x2, 
    0x78, 0x79, 0x5, 0x8, 0x5, 0x2, 0x79, 0x7a, 0x7, 0xe, 0x2, 0x2, 0x7a, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0xc, 0x11, 0x2, 0x2, 0x7c, 0x7d, 
    0x7, 0xb, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0x20, 0x11, 0x2, 0x7e, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x60, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x66, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x85, 0x7, 0x25, 0x2, 0x2, 0x84, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x9a, 0x5, 0xa, 0x6, 0x2, 0x8a, 
    0x8c, 0x7, 0x25, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x94, 0x9, 0x5, 0x2, 0x2, 0x91, 0x93, 0x7, 0x25, 0x2, 
    0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 
    0x5, 0xa, 0x6, 0x2, 0x98, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x86, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x7, 0x25, 0x2, 0x2, 0xa0, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa7, 0x7, 0xc, 
    0x2, 0x2, 0xa6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x7, 0x25, 0x2, 0x2, 
    0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x5, 
    0x6, 0x4, 0x2, 0xaf, 0xb1, 0x5, 0x1e, 0x10, 0x2, 0xb0, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb4, 0x9, 0x3, 0x2, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb6, 0x9, 0x6, 0x2, 0x2, 0xb6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 
    0x7, 0xa, 0x2, 0x2, 0xb8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x5, 
    0x20, 0x11, 0x2, 0xba, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbf, 0x5, 0x18, 
    0xd, 0x2, 0xbc, 0xbe, 0x7, 0x25, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc8, 0x5, 
    0x14, 0xb, 0x2, 0xc5, 0xc7, 0x7, 0x25, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x16, 0xc, 0x2, 0xcc, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd1, 0x5, 0x14, 0xb, 0x2, 0xce, 0xd0, 
    0x7, 0x25, 0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd8, 0x5, 0x18, 0xd, 0x2, 0xd5, 0xd7, 0x7, 0x25, 0x2, 0x2, 
    0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x5, 
    0x16, 0xc, 0x2, 0xdc, 0xee, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe1, 0x5, 0x14, 
    0xb, 0x2, 0xde, 0xe0, 0x7, 0x25, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe8, 0x5, 0x16, 0xc, 0x2, 0xe5, 0xe7, 
    0x7, 0x25, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xec, 0x5, 0x18, 0xd, 0x2, 0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xed, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xed, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xee, 0x13, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 
    0x5, 0x20, 0x11, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0xd, 
    0x2, 0x2, 0xf3, 0xf4, 0x5, 0x8, 0x5, 0x2, 0xf4, 0xf5, 0x7, 0xe, 0x2, 
    0x2, 0xf5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x9, 0x7, 0x2, 0x2, 
    0xf7, 0x109, 0x5, 0x6, 0x4, 0x2, 0xf8, 0xfa, 0x7, 0x25, 0x2, 0x2, 0xf9, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x100, 0x9, 0x7, 
    0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x100, 0x104, 0x3, 0x2, 0x2, 0x2, 0x101, 0x103, 0x7, 0x25, 0x2, 
    0x2, 0x102, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x107, 0x109, 0x5, 0x1a, 0xe, 0x2, 0x108, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x109, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10e, 0x7, 0x5, 0x2, 0x2, 0x10b, 0x10d, 0x7, 0x25, 0x2, 0x2, 
    0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x113, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x114, 0x5, 0x1a, 0xe, 0x2, 0x112, 0x114, 0x5, 0x6, 0x4, 0x2, 
    0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x19, 0x3, 0x2, 0x2, 0x2, 0x115, 0x119, 0x7, 0xf, 0x2, 0x2, 0x116, 
    0x118, 0x7, 0x25, 0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11e, 0x5, 0x6, 0x4, 0x2, 0x11d, 
    0x11f, 0x7, 0x25, 0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 
    0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 
    0x129, 0x5, 0x6, 0x4, 0x2, 0x128, 0x124, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x12c, 0x7, 0x25, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x10, 0x2, 0x2, 0x131, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x6, 0x2, 0x2, 0x133, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x24, 0x2, 0x2, 0x135, 0x136, 
    0x5, 0x10, 0x9, 0x2, 0x136, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 
    0x9, 0x8, 0x2, 0x2, 0x138, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x24, 0x27, 
    0x29, 0x2e, 0x31, 0x33, 0x49, 0x4c, 0x5b, 0x7e, 0x80, 0x86, 0x8d, 0x94, 
    0x9a, 0x9d, 0xa2, 0xa6, 0xab, 0xb0, 0xb3, 0xbf, 0xc2, 0xc8, 0xd1, 0xd8, 
    0xe1, 0xe8, 0xed, 0xf0, 0xfb, 0xff, 0x104, 0x108, 0x10e, 0x113, 0x119, 
    0x120, 0x124, 0x128, 0x12d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

WorkScriptParser::Initializer WorkScriptParser::_init;

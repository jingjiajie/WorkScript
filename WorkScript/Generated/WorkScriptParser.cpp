
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
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(39);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WorkScriptParser::HASH: {
            setState(34);
            includeCommand();
            setState(36);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
            case 1: {
              setState(35);
              match(WorkScriptParser::NEWLINE);
              break;
            }

            }
            break;
          }

          case WorkScriptParser::NEWLINE: {
            setState(38);
            match(WorkScriptParser::NEWLINE);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(51);
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
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(49);
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
        case WorkScriptParser::PLUS:
        case WorkScriptParser::MINUS: {
          setState(44);
          expression(0);
          setState(46);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
          case 1: {
            setState(45);
            match(WorkScriptParser::NEWLINE);
            break;
          }

          }
          break;
        }

        case WorkScriptParser::NEWLINE: {
          setState(48);
          match(WorkScriptParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
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
    setState(56);
    match(WorkScriptParser::HASH);
    setState(57);
    match(WorkScriptParser::INCLUDE);
    setState(58);
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
//----------------- CallExpression_Context ------------------------------------------------------------------

WorkScriptParser::CallExpressionContext* WorkScriptParser::CallExpression_Context::callExpression() {
  return getRuleContext<WorkScriptParser::CallExpressionContext>(0);
}

WorkScriptParser::CallExpression_Context::CallExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::CallExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCallExpression_(this);
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
//----------------- BinaryCompareExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::BinaryCompareExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::BinaryCompareExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareExpressionContext::DOUBLE_EQUAL() {
  return getToken(WorkScriptParser::DOUBLE_EQUAL, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareExpressionContext::GREATER_THAN() {
  return getToken(WorkScriptParser::GREATER_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareExpressionContext::GREATER_THAN_EQUAL() {
  return getToken(WorkScriptParser::GREATER_THAN_EQUAL, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareExpressionContext::LESS_THAN() {
  return getToken(WorkScriptParser::LESS_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareExpressionContext::LESS_THAN_EQUAL() {
  return getToken(WorkScriptParser::LESS_THAN_EQUAL, 0);
}

WorkScriptParser::BinaryCompareExpressionContext::BinaryCompareExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::BinaryCompareExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBinaryCompareExpression(this);
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
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(61);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(62);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(63);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(64);
      expression(0);
      setState(65);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      functionExpression();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CallExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(68);
      callExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NumberExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(69);
      numberExpression();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegativeExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(70);
      match(WorkScriptParser::MINUS);
      setState(71);
      expression(8);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PositiveExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(72);
      match(WorkScriptParser::PLUS);
      setState(73);
      expression(7);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<StringExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(74);
      stringExpression();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BooleanExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(75);
      booleanExpression();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<VariableExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      variableExpression();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(96);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(94);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(79);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(80);
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
          setState(81);
          expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(82);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(83);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(84);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(85);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(86);
          match(WorkScriptParser::ASSIGN);
          setState(87);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(88);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(89);
          match(WorkScriptParser::EQUALS);
          setState(90);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryCompareExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(91);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(92);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WorkScriptParser::DOUBLE_EQUAL)
            | (1ULL << WorkScriptParser::GREATER_THAN)
            | (1ULL << WorkScriptParser::GREATER_THAN_EQUAL)
            | (1ULL << WorkScriptParser::LESS_THAN)
            | (1ULL << WorkScriptParser::LESS_THAN_EQUAL))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(93);
          expression(5);
          break;
        }

        } 
      }
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CallExpressionContext ------------------------------------------------------------------

WorkScriptParser::CallExpressionContext::CallExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::CallExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

tree::TerminalNode* WorkScriptParser::CallExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::MultiValueExpressionContext* WorkScriptParser::CallExpressionContext::multiValueExpression() {
  return getRuleContext<WorkScriptParser::MultiValueExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::CallExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}


size_t WorkScriptParser::CallExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleCallExpression;
}

antlrcpp::Any WorkScriptParser::CallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCallExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::CallExpressionContext* WorkScriptParser::callExpression() {
  CallExpressionContext *_localctx = _tracker.createInstance<CallExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WorkScriptParser::RuleCallExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    identifier();
    setState(100);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(101);
    multiValueExpression();
    setState(102);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiValueExpressionContext ------------------------------------------------------------------

WorkScriptParser::MultiValueExpressionContext::MultiValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::MultiValueExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::MultiValueExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::MultiValueExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::MultiValueExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::MultiValueExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::MultiValueExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}


size_t WorkScriptParser::MultiValueExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleMultiValueExpression;
}

antlrcpp::Any WorkScriptParser::MultiValueExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiValueExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::MultiValueExpressionContext* WorkScriptParser::multiValueExpression() {
  MultiValueExpressionContext *_localctx = _tracker.createInstance<MultiValueExpressionContext>(_ctx, getState());
  enterRule(_localctx, 8, WorkScriptParser::RuleMultiValueExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(104);
        match(WorkScriptParser::NEWLINE);
        setState(109);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(110);
      expression(0);
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(114);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(111);
              match(WorkScriptParser::NEWLINE); 
            }
            setState(116);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          }
          setState(117);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::COMMA

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(121);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::NEWLINE) {
            setState(118);
            match(WorkScriptParser::NEWLINE);
            setState(123);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(124);
          expression(0); 
        }
        setState(129);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      }
      break;
    }

    }
    setState(135);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(132);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(137);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA) {
      setState(138);
      match(WorkScriptParser::COMMA);
    }
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(141);
      match(WorkScriptParser::NEWLINE);
      setState(146);
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
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::PLUS

    || _la == WorkScriptParser::MINUS) {
      setState(147);
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
    setState(150);
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
    setState(152);
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
    setState(154);
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
    setState(206);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(156);
        functionConstraintExpression();
        setState(160);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(157);
          match(WorkScriptParser::NEWLINE);
          setState(162);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(165);
      functionDeclarationExpression();
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(166);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(171);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      }
      setState(172);
      functionImplementationExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(174);
      functionDeclarationExpression();
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(175);
        match(WorkScriptParser::NEWLINE);
        setState(180);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(181);
      functionConstraintExpression();
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(182);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(187);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      }
      setState(188);
      functionImplementationExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(190);
      functionDeclarationExpression();
      setState(194);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(191);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(196);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      }
      setState(197);
      functionImplementationExpression();
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(198);
        match(WorkScriptParser::NEWLINE);
        setState(203);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(204);
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

WorkScriptParser::FormalParameterExpressionContext* WorkScriptParser::FunctionDeclarationExpressionContext::formalParameterExpression() {
  return getRuleContext<WorkScriptParser::FormalParameterExpressionContext>(0);
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
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(208);
      identifier();
    }
    setState(211);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(212);
    formalParameterExpression();
    setState(213);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterExpressionContext ------------------------------------------------------------------

WorkScriptParser::FormalParameterExpressionContext::FormalParameterExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::IdentifierContext *> WorkScriptParser::FormalParameterExpressionContext::identifier() {
  return getRuleContexts<WorkScriptParser::IdentifierContext>();
}

WorkScriptParser::IdentifierContext* WorkScriptParser::FormalParameterExpressionContext::identifier(size_t i) {
  return getRuleContext<WorkScriptParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FormalParameterExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::FormalParameterExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}


size_t WorkScriptParser::FormalParameterExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFormalParameterExpression;
}

antlrcpp::Any WorkScriptParser::FormalParameterExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFormalParameterExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FormalParameterExpressionContext* WorkScriptParser::formalParameterExpression() {
  FormalParameterExpressionContext *_localctx = _tracker.createInstance<FormalParameterExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, WorkScriptParser::RuleFormalParameterExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(224);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(215);
          identifier();
          setState(216);
          match(WorkScriptParser::COMMA); 
        }
        setState(222);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      }
      setState(223);
      identifier();
    }
   
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
  enterRule(_localctx, 22, WorkScriptParser::RuleFunctionImplementationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(226);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(227);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(228);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(233);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      setState(235);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(234);
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
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(237);
        match(WorkScriptParser::NEWLINE);
        setState(242);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(243);
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
  enterRule(_localctx, 24, WorkScriptParser::RuleFunctionConstraintExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(WorkScriptParser::WHEN);
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(247);
      match(WorkScriptParser::NEWLINE);
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(253);
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
      case WorkScriptParser::PLUS:
      case WorkScriptParser::MINUS: {
        setState(254);
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
  enterRule(_localctx, 26, WorkScriptParser::RuleBlockExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(WorkScriptParser::LEFT_BRACE);
    setState(261);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(258);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(263);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(276);
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
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(264);
          expression(0);
          setState(266); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(265);
            match(WorkScriptParser::NEWLINE);
            setState(268); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(274);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      }
      setState(275);
      expression(0);
    }
    setState(281);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(278);
      match(WorkScriptParser::NEWLINE);
      setState(283);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(284);
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
  enterRule(_localctx, 28, WorkScriptParser::RuleBooleanExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
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
  enterRule(_localctx, 30, WorkScriptParser::RuleVarargsExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(WorkScriptParser::APOSTROPHE);
    setState(289);
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
  enterRule(_localctx, 32, WorkScriptParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
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
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);

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
  "program", "includeCommand", "expression", "callExpression", "multiValueExpression", 
  "numberExpression", "stringExpression", "variableExpression", "functionExpression", 
  "functionDeclarationExpression", "formalParameterExpression", "functionImplementationExpression", 
  "functionConstraintExpression", "blockExpression", "booleanExpression", 
  "varargsExpression", "identifier"
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
    0x3, 0x26, 0x128, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x27, 0xa, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x2a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2d, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x31, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x50, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x61, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x64, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x7, 0x6, 0x6c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x6f, 0xb, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x73, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x76, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x7a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x7d, 0xb, 0x6, 0x3, 0x6, 0x7, 0x6, 0x80, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x83, 0xb, 0x6, 0x5, 0x6, 0x85, 0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x88, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x8b, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x8e, 
    0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x91, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x94, 
    0xb, 0x6, 0x3, 0x7, 0x5, 0x7, 0x97, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa1, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa4, 0xb, 0xa, 0x5, 0xa, 0xa6, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xaa, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xad, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xb3, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0xb6, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xba, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xbd, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc3, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc6, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xca, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0xcd, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd1, 0xa, 0xa, 0x3, 
    0xb, 0x5, 0xb, 0xd4, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xdd, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0xe0, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0xe3, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xe8, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xeb, 0xb, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0xee, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0xf1, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0xf4, 0xb, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf7, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xfb, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 
    0xfe, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x102, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0x106, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x109, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0x10d, 0xa, 0xf, 0xd, 0xf, 0xe, 
    0xf, 0x10e, 0x7, 0xf, 0x111, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x114, 0xb, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x117, 0xa, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11a, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x11d, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x2, 0x3, 0x6, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x2, 0x9, 0x3, 
    0x2, 0x1a, 0x1c, 0x3, 0x2, 0x18, 0x19, 0x4, 0x2, 0x13, 0x13, 0x1e, 0x21, 
    0x4, 0x2, 0xc, 0xc, 0x25, 0x25, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0x14, 
    0x15, 0x3, 0x2, 0x3, 0x7, 0x2, 0x14a, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x84, 0x3, 0x2, 0x2, 0x2, 0xc, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x103, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x120, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x122, 0x3, 0x2, 0x2, 0x2, 0x22, 0x125, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 0x4, 0x3, 0x2, 0x25, 0x27, 0x7, 0x25, 
    0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x7, 0x25, 0x2, 0x2, 
    0x29, 0x24, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x35, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x6, 0x4, 0x2, 0x2f, 0x31, 0x7, 0x25, 
    0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x7, 0x25, 0x2, 0x2, 
    0x33, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x3b, 0x7, 0x1d, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x4, 0x2, 
    0x2, 0x3c, 0x3d, 0x7, 0xa, 0x2, 0x2, 0x3d, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3f, 0x8, 0x4, 0x1, 0x2, 0x3f, 0x40, 0x7, 0x3, 0x2, 0x2, 0x40, 
    0x50, 0x7, 0x17, 0x2, 0x2, 0x41, 0x42, 0x7, 0xd, 0x2, 0x2, 0x42, 0x43, 
    0x5, 0x6, 0x4, 0x2, 0x43, 0x44, 0x7, 0xe, 0x2, 0x2, 0x44, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x50, 0x5, 0x12, 0xa, 0x2, 0x46, 0x50, 0x5, 0x8, 
    0x5, 0x2, 0x47, 0x50, 0x5, 0xc, 0x7, 0x2, 0x48, 0x49, 0x7, 0x19, 0x2, 
    0x2, 0x49, 0x50, 0x5, 0x6, 0x4, 0xa, 0x4a, 0x4b, 0x7, 0x18, 0x2, 0x2, 
    0x4b, 0x50, 0x5, 0x6, 0x4, 0x9, 0x4c, 0x50, 0x5, 0xe, 0x8, 0x2, 0x4d, 
    0x50, 0x5, 0x1e, 0x10, 0x2, 0x4e, 0x50, 0x5, 0x10, 0x9, 0x2, 0x4f, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x62, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x52, 0xc, 0xd, 0x2, 0x2, 0x52, 0x53, 0x9, 0x2, 0x2, 0x2, 0x53, 0x61, 
    0x5, 0x6, 0x4, 0xe, 0x54, 0x55, 0xc, 0xc, 0x2, 0x2, 0x55, 0x56, 0x9, 
    0x3, 0x2, 0x2, 0x56, 0x61, 0x5, 0x6, 0x4, 0xd, 0x57, 0x58, 0xc, 0x8, 
    0x2, 0x2, 0x58, 0x59, 0x7, 0x16, 0x2, 0x2, 0x59, 0x61, 0x5, 0x6, 0x4, 
    0x9, 0x5a, 0x5b, 0xc, 0x7, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x14, 0x2, 0x2, 
    0x5c, 0x61, 0x5, 0x6, 0x4, 0x8, 0x5d, 0x5e, 0xc, 0x6, 0x2, 0x2, 0x5e, 
    0x5f, 0x9, 0x4, 0x2, 0x2, 0x5f, 0x61, 0x5, 0x6, 0x4, 0x7, 0x60, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x54, 0x3, 0x2, 0x2, 0x2, 0x60, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0x22, 0x12, 0x2, 0x66, 
    0x67, 0x7, 0xd, 0x2, 0x2, 0x67, 0x68, 0x5, 0xa, 0x6, 0x2, 0x68, 0x69, 
    0x7, 0xe, 0x2, 0x2, 0x69, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x7, 
    0x25, 0x2, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x81, 0x5, 0x6, 0x4, 0x2, 0x71, 0x73, 0x7, 0x25, 0x2, 0x2, 0x72, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7b, 0x9, 0x5, 
    0x2, 0x2, 0x78, 0x7a, 0x7, 0x25, 0x2, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x6, 0x4, 0x2, 0x7f, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x88, 0x7, 0x25, 0x2, 0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8e, 0x7, 0xc, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x91, 0x7, 0x25, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x94, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0xb, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x97, 0x9, 0x3, 0x2, 0x2, 0x96, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x9, 0x6, 0x2, 0x2, 0x99, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9b, 0x7, 0xa, 0x2, 0x2, 0x9b, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9d, 0x5, 0x22, 0x12, 0x2, 0x9d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0xa2, 0x5, 0x1a, 0xe, 0x2, 0x9f, 0xa1, 0x7, 0x25, 0x2, 0x2, 0xa0, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xab, 0x5, 0x14, 0xb, 0x2, 0xa8, 0xaa, 0x7, 0x25, 0x2, 0x2, 0xa9, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x18, 
    0xd, 0x2, 0xaf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb4, 0x5, 0x14, 0xb, 
    0x2, 0xb1, 0xb3, 0x7, 0x25, 0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xbb, 0x5, 0x1a, 0xe, 0x2, 0xb8, 0xba, 0x7, 
    0x25, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0xbf, 0x5, 0x18, 0xd, 0x2, 0xbf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc4, 0x5, 0x14, 0xb, 0x2, 0xc1, 0xc3, 0x7, 0x25, 0x2, 0x2, 0xc2, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xcb, 0x5, 0x18, 0xd, 
    0x2, 0xc8, 0xca, 0x7, 0x25, 0x2, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x1a, 0xe, 0x2, 0xcf, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xd4, 0x5, 0x22, 0x12, 0x2, 0xd3, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x7, 0xd, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x16, 0xc, 0x2, 0xd7, 0xd8, 
    0x7, 0xe, 0x2, 0x2, 0xd8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 
    0x22, 0x12, 0x2, 0xda, 0xdb, 0x7, 0xc, 0x2, 0x2, 0xdb, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe3, 0x5, 0x22, 0x12, 0x2, 0xe2, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x9, 
    0x7, 0x2, 0x2, 0xe5, 0xf7, 0x5, 0x6, 0x4, 0x2, 0xe6, 0xe8, 0x7, 0x25, 
    0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xed, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xee, 0x9, 0x7, 0x2, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x7, 
    0x25, 0x2, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf7, 0x5, 0x1c, 0xf, 0x2, 0xf6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x19, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfc, 
    0x7, 0x5, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x25, 0x2, 0x2, 0xfa, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x101, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 0x5, 0x1c, 0xf, 0x2, 
    0x100, 0x102, 0x5, 0x6, 0x4, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x103, 0x107, 
    0x7, 0xf, 0x2, 0x2, 0x104, 0x106, 0x7, 0x25, 0x2, 0x2, 0x105, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 
    0x5, 0x6, 0x4, 0x2, 0x10b, 0x10d, 0x7, 0x25, 0x2, 0x2, 0x10c, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x5, 0x6, 0x4, 0x2, 0x116, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11b, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 0x7, 0x25, 0x2, 0x2, 0x119, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
    0x7, 0x10, 0x2, 0x2, 0x11f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
    0x7, 0x6, 0x2, 0x2, 0x121, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 
    0x24, 0x2, 0x2, 0x123, 0x124, 0x5, 0x10, 0x9, 0x2, 0x124, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x125, 0x126, 0x9, 0x8, 0x2, 0x2, 0x126, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x26, 0x29, 0x2b, 0x30, 0x33, 0x35, 0x4f, 0x60, 0x62, 
    0x6d, 0x74, 0x7b, 0x81, 0x84, 0x89, 0x8d, 0x92, 0x96, 0xa2, 0xa5, 0xab, 
    0xb4, 0xbb, 0xc4, 0xcb, 0xd0, 0xd3, 0xde, 0xe2, 0xe9, 0xed, 0xf2, 0xf6, 
    0xfc, 0x101, 0x107, 0x10e, 0x112, 0x116, 0x11b, 
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

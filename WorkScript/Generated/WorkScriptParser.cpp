
// Generated from WorkScript.g4 by ANTLR 4.7.1


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
    setState(53);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(51);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WorkScriptParser::HASH: {
            setState(46);
            includeCommand();
            setState(48);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
            case 1: {
              setState(47);
              match(WorkScriptParser::NEWLINE);
              break;
            }

            }
            break;
          }

          case WorkScriptParser::NEWLINE: {
            setState(50);
            match(WorkScriptParser::NEWLINE);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(55);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(63);
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
      setState(61);
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
          setState(56);
          expression(0);
          setState(58);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
          case 1: {
            setState(57);
            match(WorkScriptParser::NEWLINE);
            break;
          }

          }
          break;
        }

        case WorkScriptParser::NEWLINE: {
          setState(60);
          match(WorkScriptParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
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
    setState(68);
    match(WorkScriptParser::HASH);
    setState(69);
    match(WorkScriptParser::INCLUDE);
    setState(70);
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

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::STAR() {
  return getToken(WorkScriptParser::STAR, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::SLASH() {
  return getToken(WorkScriptParser::SLASH, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusExpressionContext::PERCENT() {
  return getToken(WorkScriptParser::PERCENT, 0);
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
//----------------- StdFunctionDeclExpression_Context ------------------------------------------------------------------

WorkScriptParser::StdFunctionDeclExpressionContext* WorkScriptParser::StdFunctionDeclExpression_Context::stdFunctionDeclExpression() {
  return getRuleContext<WorkScriptParser::StdFunctionDeclExpressionContext>(0);
}

WorkScriptParser::StdFunctionDeclExpression_Context::StdFunctionDeclExpression_Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::StdFunctionDeclExpression_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFunctionDeclExpression_(this);
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
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(73);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(74);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(75);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(76);
      expression(0);
      setState(77);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<StdFunctionDeclExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(79);
      stdFunctionDeclExpression();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctionExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(80);
      functionExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CallExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(81);
      callExpression();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NumberExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(82);
      numberExpression();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegativeExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(83);
      match(WorkScriptParser::MINUS);
      setState(84);
      expression(8);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PositiveExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(85);
      match(WorkScriptParser::PLUS);
      setState(86);
      expression(7);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<StringExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      stringExpression();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<BooleanExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(88);
      booleanExpression();
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<VariableExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(89);
      variableExpression();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(109);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(107);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(92);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(93);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WorkScriptParser::STAR)
            | (1ULL << WorkScriptParser::SLASH)
            | (1ULL << WorkScriptParser::PERCENT))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(94);
          expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(95);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(96);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(97);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(98);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(99);
          match(WorkScriptParser::ASSIGN);
          setState(100);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(101);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(102);
          match(WorkScriptParser::EQUALS);
          setState(103);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryCompareExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(104);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(105);
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
          setState(106);
          expression(5);
          break;
        }

        } 
      }
      setState(111);
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
    setState(112);
    identifier();
    setState(113);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(114);
    multiValueExpression();
    setState(115);
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
    setState(143);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(117);
        match(WorkScriptParser::NEWLINE);
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(123);
      expression(0);
      setState(140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(127);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(124);
              match(WorkScriptParser::NEWLINE); 
            }
            setState(129);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          }
          setState(130);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::COMMA

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(134);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::NEWLINE) {
            setState(131);
            match(WorkScriptParser::NEWLINE);
            setState(136);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(137);
          expression(0); 
        }
        setState(142);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      }
      break;
    }

    }
    setState(148);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(145);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(150);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA) {
      setState(151);
      match(WorkScriptParser::COMMA);
    }
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(154);
      match(WorkScriptParser::NEWLINE);
      setState(159);
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
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::PLUS

    || _la == WorkScriptParser::MINUS) {
      setState(160);
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
    setState(163);
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
    setState(165);
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
    setState(167);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StdFunctionDeclExpressionContext ------------------------------------------------------------------

WorkScriptParser::StdFunctionDeclExpressionContext::StdFunctionDeclExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::TypeNameContext* WorkScriptParser::StdFunctionDeclExpressionContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::FunctionNameContext* WorkScriptParser::StdFunctionDeclExpressionContext::functionName() {
  return getRuleContext<WorkScriptParser::FunctionNameContext>(0);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::StdFormalParameterExpressionContext* WorkScriptParser::StdFunctionDeclExpressionContext::stdFormalParameterExpression() {
  return getRuleContext<WorkScriptParser::StdFormalParameterExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFunctionDeclExpressionContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclExpressionContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}


size_t WorkScriptParser::StdFunctionDeclExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleStdFunctionDeclExpression;
}

antlrcpp::Any WorkScriptParser::StdFunctionDeclExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFunctionDeclExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StdFunctionDeclExpressionContext* WorkScriptParser::stdFunctionDeclExpression() {
  StdFunctionDeclExpressionContext *_localctx = _tracker.createInstance<StdFunctionDeclExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, WorkScriptParser::RuleStdFunctionDeclExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    typeName();
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(170);
      match(WorkScriptParser::STAR);
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(176);
    functionName();
    setState(177);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(178);
    stdFormalParameterExpression();
    setState(179);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StdFormalParameterExpressionContext ------------------------------------------------------------------

WorkScriptParser::StdFormalParameterExpressionContext::StdFormalParameterExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFormalParameterExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::StdFormalParameterItemContext *> WorkScriptParser::StdFormalParameterExpressionContext::stdFormalParameterItem() {
  return getRuleContexts<WorkScriptParser::StdFormalParameterItemContext>();
}

WorkScriptParser::StdFormalParameterItemContext* WorkScriptParser::StdFormalParameterExpressionContext::stdFormalParameterItem(size_t i) {
  return getRuleContext<WorkScriptParser::StdFormalParameterItemContext>(i);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterExpressionContext::APOSTROPHE() {
  return getToken(WorkScriptParser::APOSTROPHE, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFormalParameterExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}


size_t WorkScriptParser::StdFormalParameterExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleStdFormalParameterExpression;
}

antlrcpp::Any WorkScriptParser::StdFormalParameterExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFormalParameterExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StdFormalParameterExpressionContext* WorkScriptParser::stdFormalParameterExpression() {
  StdFormalParameterExpressionContext *_localctx = _tracker.createInstance<StdFormalParameterExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, WorkScriptParser::RuleStdFormalParameterExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(184);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(181);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(186);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(187);
      stdFormalParameterItem();
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(191);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(188);
              match(WorkScriptParser::NEWLINE); 
            }
            setState(193);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
          }
          setState(194);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::COMMA

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(198);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::NEWLINE) {
            setState(195);
            match(WorkScriptParser::NEWLINE);
            setState(200);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(201);
          stdFormalParameterItem(); 
        }
        setState(206);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      }
    }
    setState(223);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(209);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(214);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      }
      setState(215);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(219);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(216);
        match(WorkScriptParser::NEWLINE);
        setState(221);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(222);
      match(WorkScriptParser::APOSTROPHE);
      break;
    }

    }
    setState(228);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(225);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(230);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
    setState(232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA) {
      setState(231);
      match(WorkScriptParser::COMMA);
    }
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(234);
      match(WorkScriptParser::NEWLINE);
      setState(239);
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

//----------------- StdFormalParameterItemContext ------------------------------------------------------------------

WorkScriptParser::StdFormalParameterItemContext::StdFormalParameterItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::TypeNameContext* WorkScriptParser::StdFormalParameterItemContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::StdFormalParameterItemContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFormalParameterItemContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterItemContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}


size_t WorkScriptParser::StdFormalParameterItemContext::getRuleIndex() const {
  return WorkScriptParser::RuleStdFormalParameterItem;
}

antlrcpp::Any WorkScriptParser::StdFormalParameterItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFormalParameterItem(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StdFormalParameterItemContext* WorkScriptParser::stdFormalParameterItem() {
  StdFormalParameterItemContext *_localctx = _tracker.createInstance<StdFormalParameterItemContext>(_ctx, getState());
  enterRule(_localctx, 20, WorkScriptParser::RuleStdFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    typeName();
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(241);
      match(WorkScriptParser::STAR);
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(247);
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
  enterRule(_localctx, 22, WorkScriptParser::RuleFunctionExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(299);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
      case 1: {
        setState(249);
        functionConstraintExpression();
        setState(253);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(250);
          match(WorkScriptParser::NEWLINE);
          setState(255);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(258);
      functionDeclarationExpression();
      setState(262);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(259);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(264);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
      }
      setState(265);
      functionImplementationExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      functionDeclarationExpression();
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(268);
        match(WorkScriptParser::NEWLINE);
        setState(273);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(274);
      functionConstraintExpression();
      setState(278);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(275);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(280);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      }
      setState(281);
      functionImplementationExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(283);
      functionDeclarationExpression();
      setState(287);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(284);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(289);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      }
      setState(290);
      functionImplementationExpression();
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(291);
        match(WorkScriptParser::NEWLINE);
        setState(296);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(297);
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

WorkScriptParser::TypeNameContext* WorkScriptParser::FunctionDeclarationExpressionContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::FunctionNameContext* WorkScriptParser::FunctionDeclarationExpressionContext::functionName() {
  return getRuleContext<WorkScriptParser::FunctionNameContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionDeclarationExpressionContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationExpressionContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
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
  enterRule(_localctx, 24, WorkScriptParser::RuleFunctionDeclarationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(302);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
        | (1ULL << WorkScriptParser::INCLUDE)
        | (1ULL << WorkScriptParser::WHEN)
        | (1ULL << WorkScriptParser::BOOLEAN)
        | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
        setState(301);
        functionName();
      }
      break;
    }

    case 2: {
      setState(304);
      typeName();
      setState(308);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(305);
        match(WorkScriptParser::STAR);
        setState(310);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(311);
      functionName();
      break;
    }

    }
    setState(315);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(316);
    formalParameterExpression();
    setState(317);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

WorkScriptParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::TypeNameContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::TypeNameContext::getRuleIndex() const {
  return WorkScriptParser::RuleTypeName;
}

antlrcpp::Any WorkScriptParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::TypeNameContext* WorkScriptParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 26, WorkScriptParser::RuleTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

WorkScriptParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::FunctionNameContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::FunctionNameContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionName;
}

antlrcpp::Any WorkScriptParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionNameContext* WorkScriptParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 28, WorkScriptParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    identifier();
   
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

std::vector<tree::TerminalNode *> WorkScriptParser::FormalParameterExpressionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FormalParameterExpressionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::FormalParameterItemContext *> WorkScriptParser::FormalParameterExpressionContext::formalParameterItem() {
  return getRuleContexts<WorkScriptParser::FormalParameterItemContext>();
}

WorkScriptParser::FormalParameterItemContext* WorkScriptParser::FormalParameterExpressionContext::formalParameterItem(size_t i) {
  return getRuleContext<WorkScriptParser::FormalParameterItemContext>(i);
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
  enterRule(_localctx, 30, WorkScriptParser::RuleFormalParameterExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(323);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
    setState(349);
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
      setState(329);
      formalParameterItem();
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(333);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(330);
              match(WorkScriptParser::NEWLINE); 
            }
            setState(335);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
          }
          setState(336);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::COMMA

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(340);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::NEWLINE) {
            setState(337);
            match(WorkScriptParser::NEWLINE);
            setState(342);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(343);
          formalParameterItem(); 
        }
        setState(348);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      }
    }
    setState(354);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(351);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA) {
      setState(357);
      match(WorkScriptParser::COMMA);
    }
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(360);
      match(WorkScriptParser::NEWLINE);
      setState(365);
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

//----------------- FormalParameterItemContext ------------------------------------------------------------------

WorkScriptParser::FormalParameterItemContext::FormalParameterItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FormalParameterItemContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::TypeNameContext* WorkScriptParser::FormalParameterItemContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FormalParameterItemContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::FormalParameterItemContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}


size_t WorkScriptParser::FormalParameterItemContext::getRuleIndex() const {
  return WorkScriptParser::RuleFormalParameterItem;
}

antlrcpp::Any WorkScriptParser::FormalParameterItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFormalParameterItem(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FormalParameterItemContext* WorkScriptParser::formalParameterItem() {
  FormalParameterItemContext *_localctx = _tracker.createInstance<FormalParameterItemContext>(_ctx, getState());
  enterRule(_localctx, 32, WorkScriptParser::RuleFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(366);
      typeName();
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(367);
        match(WorkScriptParser::STAR);
        setState(372);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(375);
    expression(0);
   
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
  enterRule(_localctx, 34, WorkScriptParser::RuleFunctionImplementationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(395);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(377);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(378);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(379);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(386);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(385);
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
      setState(391);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(388);
        match(WorkScriptParser::NEWLINE);
        setState(393);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(394);
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
  enterRule(_localctx, 36, WorkScriptParser::RuleFunctionConstraintExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(WorkScriptParser::WHEN);
    setState(401);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(398);
      match(WorkScriptParser::NEWLINE);
      setState(403);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(406);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(404);
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
        setState(405);
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
  enterRule(_localctx, 38, WorkScriptParser::RuleBlockExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(WorkScriptParser::LEFT_BRACE);
    setState(412);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(409);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(414);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    }
    setState(427);
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
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(415);
          expression(0);
          setState(417); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(416);
            match(WorkScriptParser::NEWLINE);
            setState(419); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(425);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      }
      setState(426);
      expression(0);
    }
    setState(432);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(429);
      match(WorkScriptParser::NEWLINE);
      setState(434);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(435);
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
  enterRule(_localctx, 40, WorkScriptParser::RuleBooleanExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
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
  enterRule(_localctx, 42, WorkScriptParser::RuleVarargsExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(439);
    match(WorkScriptParser::APOSTROPHE);
    setState(440);
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
  enterRule(_localctx, 44, WorkScriptParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
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
  "numberExpression", "stringExpression", "variableExpression", "stdFunctionDeclExpression", 
  "stdFormalParameterExpression", "stdFormalParameterItem", "functionExpression", 
  "functionDeclarationExpression", "typeName", "functionName", "formalParameterExpression", 
  "formalParameterItem", "functionImplementationExpression", "functionConstraintExpression", 
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
  "EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "STAR", "SLASH", 
  "PERCENT", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
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
    0x3, 0x26, 0x1bf, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x33, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x39, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x5, 0x2, 0x3d, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x40, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x43, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5d, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x6e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x71, 
    0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x7, 0x6, 0x79, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x7c, 0xb, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x80, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x83, 0xb, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x87, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x8a, 
    0xb, 0x6, 0x3, 0x6, 0x7, 0x6, 0x8d, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x90, 
    0xb, 0x6, 0x5, 0x6, 0x92, 0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x95, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x98, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x9b, 0xa, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x9e, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa1, 0xb, 0x6, 
    0x3, 0x7, 0x5, 0x7, 0xa4, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xae, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0xb1, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x7, 0xb, 0xb9, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 
    0xbc, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xc0, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0xc3, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xc7, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xca, 0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0xcd, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xd0, 0xb, 0xb, 0x5, 0xb, 0xd2, 0xa, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0xd5, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xd8, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xdc, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xdf, 0xb, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0xe2, 0xa, 0xb, 0x3, 0xb, 0x7, 0xb, 0xe5, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xe8, 0xb, 0xb, 0x3, 0xb, 0x5, 0xb, 0xeb, 0xa, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xee, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xf1, 0xb, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xf5, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xf8, 
    0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xfe, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x101, 0xb, 0xd, 0x5, 0xd, 0x103, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x107, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x10a, 
    0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x110, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x113, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x117, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x11a, 0xb, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x120, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0x123, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x127, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0x12a, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x12e, 
    0xa, 0xd, 0x3, 0xe, 0x5, 0xe, 0x131, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0x135, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x138, 0xb, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x13c, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x7, 0x11, 
    0x147, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x14a, 0xb, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x14e, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x151, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x155, 0xa, 0x11, 0xc, 0x11, 
    0xe, 0x11, 0x158, 0xb, 0x11, 0x3, 0x11, 0x7, 0x11, 0x15b, 0xa, 0x11, 
    0xc, 0x11, 0xe, 0x11, 0x15e, 0xb, 0x11, 0x5, 0x11, 0x160, 0xa, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x163, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x166, 
    0xb, 0x11, 0x3, 0x11, 0x5, 0x11, 0x169, 0xa, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0x16c, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x16f, 0xb, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0x173, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x176, 
    0xb, 0x12, 0x5, 0x12, 0x178, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x17f, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x182, 0xb, 0x13, 0x3, 0x13, 0x5, 0x13, 0x185, 0xa, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x188, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x18b, 0xb, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x18e, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x192, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x195, 0xb, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x199, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
    0x19d, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1a0, 0xb, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x6, 0x15, 0x1a4, 0xa, 0x15, 0xd, 0x15, 0xe, 0x15, 0x1a5, 
    0x7, 0x15, 0x1a8, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1ab, 0xb, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x1ae, 0xa, 0x15, 0x3, 0x15, 0x7, 0x15, 0x1b1, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1b4, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x2, 0x3, 0x6, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x9, 0x3, 0x2, 0x1a, 0x1c, 0x3, 0x2, 
    0x18, 0x19, 0x4, 0x2, 0x13, 0x13, 0x1e, 0x21, 0x4, 0x2, 0xc, 0xc, 0x25, 
    0x25, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x3, 0x7, 
    0x2, 0x1f3, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x4, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x72, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x12, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xba, 0x3, 0x2, 0x2, 0x2, 0x16, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x13b, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x141, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x148, 0x3, 0x2, 0x2, 0x2, 0x22, 0x177, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x18d, 0x3, 0x2, 0x2, 0x2, 0x26, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x28, 0x19a, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0x4, 
    0x3, 0x2, 0x31, 0x33, 0x7, 0x25, 0x2, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x36, 0x7, 0x25, 0x2, 0x2, 0x35, 0x30, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0x6, 
    0x4, 0x2, 0x3b, 0x3d, 0x7, 0x25, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x40, 0x7, 0x25, 0x2, 0x2, 0x3f, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x2, 
    0x2, 0x3, 0x45, 0x3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x1d, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x4, 0x2, 0x2, 0x48, 0x49, 0x7, 0xa, 0x2, 0x2, 
    0x49, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x8, 0x4, 0x1, 0x2, 0x4b, 
    0x4c, 0x7, 0x3, 0x2, 0x2, 0x4c, 0x5d, 0x7, 0x17, 0x2, 0x2, 0x4d, 0x4e, 
    0x7, 0xd, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x50, 0x7, 
    0xe, 0x2, 0x2, 0x50, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x51, 0x5d, 0x5, 0x12, 
    0xa, 0x2, 0x52, 0x5d, 0x5, 0x18, 0xd, 0x2, 0x53, 0x5d, 0x5, 0x8, 0x5, 
    0x2, 0x54, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x55, 0x56, 0x7, 0x19, 0x2, 0x2, 
    0x56, 0x5d, 0x5, 0x6, 0x4, 0xa, 0x57, 0x58, 0x7, 0x18, 0x2, 0x2, 0x58, 
    0x5d, 0x5, 0x6, 0x4, 0x9, 0x59, 0x5d, 0x5, 0xe, 0x8, 0x2, 0x5a, 0x5d, 
    0x5, 0x2a, 0x16, 0x2, 0x5b, 0x5d, 0x5, 0x10, 0x9, 0x2, 0x5c, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x52, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x54, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0xc, 0xd, 0x2, 0x2, 0x5f, 0x60, 0x9, 
    0x2, 0x2, 0x2, 0x60, 0x6e, 0x5, 0x6, 0x4, 0xe, 0x61, 0x62, 0xc, 0xc, 
    0x2, 0x2, 0x62, 0x63, 0x9, 0x3, 0x2, 0x2, 0x63, 0x6e, 0x5, 0x6, 0x4, 
    0xd, 0x64, 0x65, 0xc, 0x8, 0x2, 0x2, 0x65, 0x66, 0x7, 0x16, 0x2, 0x2, 
    0x66, 0x6e, 0x5, 0x6, 0x4, 0x9, 0x67, 0x68, 0xc, 0x7, 0x2, 0x2, 0x68, 
    0x69, 0x7, 0x14, 0x2, 0x2, 0x69, 0x6e, 0x5, 0x6, 0x4, 0x8, 0x6a, 0x6b, 
    0xc, 0x6, 0x2, 0x2, 0x6b, 0x6c, 0x9, 0x4, 0x2, 0x2, 0x6c, 0x6e, 0x5, 
    0x6, 0x4, 0x7, 0x6d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x64, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 
    0x5, 0x2e, 0x18, 0x2, 0x73, 0x74, 0x7, 0xd, 0x2, 0x2, 0x74, 0x75, 0x5, 
    0xa, 0x6, 0x2, 0x75, 0x76, 0x7, 0xe, 0x2, 0x2, 0x76, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x79, 0x7, 0x25, 0x2, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x8e, 0x5, 0x6, 0x4, 0x2, 0x7e, 0x80, 
    0x7, 0x25, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x84, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x88, 0x9, 0x5, 0x2, 0x2, 0x85, 0x87, 0x7, 0x25, 0x2, 0x2, 
    0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x5, 
    0x6, 0x4, 0x2, 0x8c, 0x81, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x93, 0x95, 0x7, 0x25, 0x2, 0x2, 0x94, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 0x7, 0xc, 0x2, 
    0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x25, 0x2, 0x2, 0x9d, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x9, 0x3, 
    0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x9, 0x6, 0x2, 0x2, 
    0xa6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0xa, 0x2, 0x2, 0xa8, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x2e, 0x18, 0x2, 0xaa, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xac, 0xae, 0x7, 
    0x1a, 0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x5, 0x1e, 0x10, 0x2, 0xb3, 0xb4, 0x7, 0xd, 0x2, 0x2, 0xb4, 
    0xb5, 0x5, 0x14, 0xb, 0x2, 0xb5, 0xb6, 0x7, 0xe, 0x2, 0x2, 0xb6, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x7, 0x25, 0x2, 0x2, 0xb8, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xce, 0x5, 0x16, 0xc, 0x2, 
    0xbe, 0xc0, 0x7, 0x25, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc8, 0x9, 0x5, 0x2, 0x2, 0xc5, 0xc7, 0x7, 0x25, 
    0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xcd, 0x5, 0x16, 0xc, 0x2, 0xcc, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x25, 0x2, 0x2, 
    0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdd, 0x9, 
    0x5, 0x2, 0x2, 0xda, 0xdc, 0x7, 0x25, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x24, 0x2, 0x2, 0xe1, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x7, 0x25, 0x2, 0x2, 0xe4, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x7, 0xc, 0x2, 0x2, 
    0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xec, 0xee, 0x7, 0x25, 0x2, 0x2, 0xed, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf6, 0x5, 0x1c, 0xf, 
    0x2, 0xf3, 0xf5, 0x7, 0x1a, 0x2, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x2e, 0x18, 0x2, 0xfa, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xff, 0x5, 0x26, 0x14, 0x2, 0xfc, 0xfe, 0x7, 0x25, 
    0x2, 0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x100, 0x103, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x108, 0x5, 0x1a, 0xe, 0x2, 0x105, 0x107, 
    0x7, 0x25, 0x2, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x24, 0x13, 0x2, 0x10c, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x111, 0x5, 0x1a, 0xe, 0x2, 0x10e, 0x110, 
    0x7, 0x25, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x114, 0x118, 0x5, 0x26, 0x14, 0x2, 0x115, 0x117, 
    0x7, 0x25, 0x2, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x119, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x5, 0x24, 0x13, 0x2, 0x11c, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x121, 0x5, 0x1a, 0xe, 0x2, 0x11e, 0x120, 
    0x7, 0x25, 0x2, 0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x128, 0x5, 0x24, 0x13, 0x2, 0x125, 0x127, 
    0x7, 0x25, 0x2, 0x2, 0x126, 0x125, 0x3, 0x2, 0x2, 0x2, 0x127, 0x12a, 
    0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x129, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x26, 0x14, 0x2, 0x12c, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x102, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x131, 0x5, 0x1e, 0x10, 0x2, 0x130, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x132, 0x136, 0x5, 0x1c, 0xf, 0x2, 0x133, 0x135, 0x7, 
    0x1a, 0x2, 0x2, 0x134, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x139, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x1e, 0x10, 0x2, 0x13a, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 
    0xd, 0x2, 0x2, 0x13e, 0x13f, 0x5, 0x20, 0x11, 0x2, 0x13f, 0x140, 0x7, 
    0xe, 0x2, 0x2, 0x140, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x5, 0x2e, 
    0x18, 0x2, 0x142, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x5, 0x2e, 
    0x18, 0x2, 0x144, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x145, 0x147, 0x7, 0x25, 
    0x2, 0x2, 0x146, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x15c, 0x5, 0x22, 0x12, 0x2, 0x14c, 0x14e, 0x7, 0x25, 
    0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 
    0x2, 0x2, 0x150, 0x152, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x156, 0x9, 0x5, 0x2, 0x2, 0x153, 0x155, 0x7, 0x25, 
    0x2, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x159, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15b, 0x5, 0x22, 0x12, 0x2, 0x15a, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x163, 0x7, 0x25, 0x2, 0x2, 0x162, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x168, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x7, 0xc, 
    0x2, 0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x7, 0x25, 
    0x2, 0x2, 0x16b, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x16e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x174, 0x5, 0x1c, 0xf, 0x2, 0x171, 0x173, 0x7, 0x1a, 0x2, 
    0x2, 0x172, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x178, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x177, 0x170, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x6, 0x4, 
    0x2, 0x17a, 0x23, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x9, 0x7, 0x2, 0x2, 
    0x17c, 0x18e, 0x5, 0x6, 0x4, 0x2, 0x17d, 0x17f, 0x7, 0x25, 0x2, 0x2, 
    0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x182, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 
    0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x183, 0x185, 0x9, 0x7, 0x2, 0x2, 0x184, 0x183, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x189, 0x3, 0x2, 0x2, 0x2, 
    0x186, 0x188, 0x7, 0x25, 0x2, 0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 0x5, 0x28, 0x15, 0x2, 
    0x18d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x18e, 0x25, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x193, 0x7, 0x5, 0x2, 0x2, 0x190, 
    0x192, 0x7, 0x25, 0x2, 0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x198, 0x3, 0x2, 0x2, 0x2, 0x195, 
    0x193, 0x3, 0x2, 0x2, 0x2, 0x196, 0x199, 0x5, 0x28, 0x15, 0x2, 0x197, 
    0x199, 0x5, 0x6, 0x4, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 
    0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x27, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19e, 
    0x7, 0xf, 0x2, 0x2, 0x19b, 0x19d, 0x7, 0x25, 0x2, 0x2, 0x19c, 0x19b, 
    0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 
    0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1ad, 
    0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 
    0x5, 0x6, 0x4, 0x2, 0x1a2, 0x1a4, 0x7, 0x25, 0x2, 0x2, 0x1a3, 0x1a2, 
    0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a3, 
    0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a8, 
    0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1ab, 
    0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 
    0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x6, 0x4, 0x2, 0x1ad, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b2, 
    0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x7, 0x25, 0x2, 0x2, 0x1b0, 0x1af, 
    0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b0, 
    0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b5, 
    0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
    0x7, 0x10, 0x2, 0x2, 0x1b6, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 
    0x7, 0x6, 0x2, 0x2, 0x1b8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 
    0x24, 0x2, 0x2, 0x1ba, 0x1bb, 0x5, 0x10, 0x9, 0x2, 0x1bb, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x9, 0x8, 0x2, 0x2, 0x1bd, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x32, 0x35, 0x37, 0x3c, 0x3f, 0x41, 0x5c, 0x6d, 0x6f, 
    0x7a, 0x81, 0x88, 0x8e, 0x91, 0x96, 0x9a, 0x9f, 0xa3, 0xaf, 0xba, 0xc1, 
    0xc8, 0xce, 0xd1, 0xd6, 0xdd, 0xe1, 0xe6, 0xea, 0xef, 0xf6, 0xff, 0x102, 
    0x108, 0x111, 0x118, 0x121, 0x128, 0x12d, 0x130, 0x136, 0x13b, 0x148, 
    0x14f, 0x156, 0x15c, 0x15f, 0x164, 0x168, 0x16d, 0x174, 0x177, 0x180, 
    0x184, 0x189, 0x18d, 0x193, 0x198, 0x19e, 0x1a5, 0x1a9, 0x1ad, 0x1b2, 
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

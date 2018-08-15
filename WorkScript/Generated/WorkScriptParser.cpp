
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

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::ProgramContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ProgramContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ProgramContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
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
    enterOuterAlt(_localctx, 1);
    setState(16);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::NEWLINE)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACE))) != 0)) {
      setState(14);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::IDENTIFIER:
        case WorkScriptParser::NUMBER:
        case WorkScriptParser::STRING:
        case WorkScriptParser::LEFT_PARENTHESE:
        case WorkScriptParser::LEFT_BRACE: {
          setState(10);
          expression();
          setState(11);
          match(WorkScriptParser::NEWLINE);
          break;
        }

        case WorkScriptParser::NEWLINE: {
          setState(13);
          match(WorkScriptParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(18);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(19);
    match(WorkScriptParser::EOF);
   
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

WorkScriptParser::TermExpressionContext* WorkScriptParser::ExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}


size_t WorkScriptParser::ExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleExpression;
}

antlrcpp::Any WorkScriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 2, WorkScriptParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    termExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext::TermExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WorkScriptParser::TermExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleTermExpression;
}

void WorkScriptParser::TermExpressionContext::copyFrom(TermExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParentheseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::ParentheseExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::ParentheseExpressionContext::ParentheseExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::ParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParentheseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermBlockExpressionContext ------------------------------------------------------------------

WorkScriptParser::BlockExpressionContext* WorkScriptParser::TermBlockExpressionContext::blockExpression() {
  return getRuleContext<WorkScriptParser::BlockExpressionContext>(0);
}

WorkScriptParser::TermBlockExpressionContext::TermBlockExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::TermBlockExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTermBlockExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::FunctionInvocationExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionInvocationExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ListExpressionContext* WorkScriptParser::FunctionInvocationExpressionContext::listExpression() {
  return getRuleContext<WorkScriptParser::ListExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionInvocationExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::FunctionInvocationExpressionContext::FunctionInvocationExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::FunctionInvocationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionInvocationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::NUMBER() {
  return getToken(WorkScriptParser::NUMBER, 0);
}

WorkScriptParser::NumberExpressionContext::NumberExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::NumberExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNumberExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::VariableExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

WorkScriptParser::VariableExpressionContext::VariableExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::VariableExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVariableExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompareExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::CompareExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::CompareExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
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

WorkScriptParser::CompareExpressionContext::CompareExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::CompareExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCompareExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ListExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::listExpression() {
  return getRuleContext<WorkScriptParser::ListExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::MethodInvocationExpressionContext::MethodInvocationExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MethodInvocationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMethodInvocationExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ListExpressionContext* WorkScriptParser::FunctionExpressionContext::listExpression() {
  return getRuleContext<WorkScriptParser::ListExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::FunctionExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

WorkScriptParser::BlockExpressionContext* WorkScriptParser::FunctionExpressionContext::blockExpression() {
  return getRuleContext<WorkScriptParser::BlockExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

WorkScriptParser::FunctionExpressionContext::FunctionExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::FunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::AssignmentExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* WorkScriptParser::AssignmentExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::AssignmentExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

WorkScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyDivideExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::MultiplyDivideExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::MultiplyDivideExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideExpressionContext::MULTIPLY() {
  return getToken(WorkScriptParser::MULTIPLY, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideExpressionContext::DIVIDE() {
  return getToken(WorkScriptParser::DIVIDE, 0);
}

WorkScriptParser::MultiplyDivideExpressionContext::MultiplyDivideExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MultiplyDivideExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplyDivideExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberEvaluateExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::MemberEvaluateExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MemberEvaluateExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

tree::TerminalNode* WorkScriptParser::MemberEvaluateExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

WorkScriptParser::MemberEvaluateExpressionContext::MemberEvaluateExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MemberEvaluateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMemberEvaluateExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::StringExpressionContext::STRING() {
  return getToken(WorkScriptParser::STRING, 0);
}

WorkScriptParser::StringExpressionContext::StringExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::StringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStringExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::PlusMinusExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::PlusMinusExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::PlusMinusExpressionContext::PlusMinusExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::PlusMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPlusMinusExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::termExpression() {
   return termExpression(0);
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::termExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WorkScriptParser::TermExpressionContext *_localctx = _tracker.createInstance<TermExpressionContext>(_ctx, parentState);
  WorkScriptParser::TermExpressionContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, WorkScriptParser::RuleTermExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(24);
      match(WorkScriptParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(25);
      match(WorkScriptParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VariableExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(26);
      match(WorkScriptParser::IDENTIFIER);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AssignmentExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(27);
      match(WorkScriptParser::IDENTIFIER);
      setState(28);
      match(WorkScriptParser::EQUALS);
      setState(29);
      termExpression(10);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(31);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::IDENTIFIER) {
        setState(30);
        match(WorkScriptParser::IDENTIFIER);
      }
      setState(33);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(34);
      listExpression();
      setState(35);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      setState(39);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::EQUALS: {
          setState(36);
          match(WorkScriptParser::EQUALS);
          setState(37);
          termExpression(0);
          break;
        }

        case WorkScriptParser::LEFT_BRACE: {
          setState(38);
          blockExpression();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(41);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(42);
      termExpression(0);
      setState(43);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<TermBlockExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(45);
      blockExpression();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(72);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(48);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(49);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::MULTIPLY

          || _la == WorkScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(50);
          termExpression(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(51);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(52);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(53);
          termExpression(4);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CompareExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(54);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(55);
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
          setState(56);
          termExpression(3);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<FunctionInvocationExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(57);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(58);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(59);
          listExpression();
          setState(60);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<MethodInvocationExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(62);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(63);
          match(WorkScriptParser::POINT);
          setState(64);
          match(WorkScriptParser::IDENTIFIER);
          setState(65);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(66);
          listExpression();
          setState(67);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(69);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(70);
          match(WorkScriptParser::POINT);
          setState(71);
          match(WorkScriptParser::IDENTIFIER);
          break;
        }

        } 
      }
      setState(76);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ListExpressionContext ------------------------------------------------------------------

WorkScriptParser::ListExpressionContext::ListExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::ListExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::ListExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::ListExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::ListExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
}

tree::TerminalNode* WorkScriptParser::ListExpressionContext::LEFT_BRACKET() {
  return getToken(WorkScriptParser::LEFT_BRACKET, 0);
}

tree::TerminalNode* WorkScriptParser::ListExpressionContext::RIGHT_BRACKET() {
  return getToken(WorkScriptParser::RIGHT_BRACKET, 0);
}


size_t WorkScriptParser::ListExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleListExpression;
}

antlrcpp::Any WorkScriptParser::ListExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitListExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ListExpressionContext* WorkScriptParser::listExpression() {
  ListExpressionContext *_localctx = _tracker.createInstance<ListExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WorkScriptParser::RuleListExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::NUMBER:
      case WorkScriptParser::STRING:
      case WorkScriptParser::LEFT_PARENTHESE:
      case WorkScriptParser::LEFT_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(77);
        termExpression(0);
        setState(82);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::COMMA) {
          setState(78);
          match(WorkScriptParser::COMMA);
          setState(79);
          termExpression(0);
          setState(84);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case WorkScriptParser::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        match(WorkScriptParser::LEFT_BRACKET);
        setState(94);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
          | (1ULL << WorkScriptParser::NUMBER)
          | (1ULL << WorkScriptParser::STRING)
          | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
          | (1ULL << WorkScriptParser::LEFT_BRACE))) != 0)) {
          setState(86);
          termExpression(0);
          setState(91);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == WorkScriptParser::COMMA) {
            setState(87);
            match(WorkScriptParser::COMMA);
            setState(88);
            termExpression(0);
            setState(93);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(96);
        match(WorkScriptParser::RIGHT_BRACKET);
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
  enterRule(_localctx, 8, WorkScriptParser::RuleBlockExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(WorkScriptParser::LEFT_BRACE);
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(100);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(105);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACE))) != 0)) {
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(106);
          expression();
          setState(108); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(107);
            match(WorkScriptParser::NEWLINE);
            setState(110); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(116);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      setState(117);
      expression();
    }
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(120);
      match(WorkScriptParser::NEWLINE);
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(126);
    match(WorkScriptParser::RIGHT_BRACE);
   
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
    case 2: return termExpressionSempred(dynamic_cast<TermExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::termExpressionSempred(TermExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);

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
  "program", "expression", "termExpression", "listExpression", "blockExpression"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "", "", "'.'", "','", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "'='", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "IDENTIFIER", "NUMBER", "STRING", "POINT", "COMMA", "NEWLINE", "LEFT_PARENTHESE", 
  "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", 
  "EQUALS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "GREATER_THAN", "GREATER_THAN_EQUAL", 
  "LESS_THAN", "LESS_THAN_EQUAL", "WS"
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
    0x3, 0x18, 0x83, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x11, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x14, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x22, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x2a, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x31, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x4b, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x4e, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0x53, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x56, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x5c, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x5f, 0xb, 0x5, 0x5, 0x5, 0x61, 0xa, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x64, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x68, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x6b, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x6f, 0xa, 
    0x6, 0xd, 0x6, 0xe, 0x6, 0x70, 0x7, 0x6, 0x73, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x76, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x79, 0xa, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x7c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x7f, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x2, 0x3, 0x6, 0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x5, 
    0x3, 0x2, 0x12, 0x13, 0x3, 0x2, 0x10, 0x11, 0x3, 0x2, 0x14, 0x17, 0x2, 
    0x96, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x30, 0x3, 0x2, 0x2, 0x2, 0x8, 0x63, 0x3, 0x2, 0x2, 0x2, 0xa, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x5, 0x4, 0x3, 0x2, 0xd, 0xe, 0x7, 0x8, 
    0x2, 0x2, 0xe, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf, 0x11, 0x7, 0x8, 0x2, 0x2, 
    0x10, 0xc, 0x3, 0x2, 0x2, 0x2, 0x10, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x2, 0x2, 0x3, 0x16, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x18, 0x5, 0x6, 0x4, 0x2, 0x18, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1a, 0x8, 0x4, 0x1, 0x2, 0x1a, 0x31, 0x7, 0x4, 0x2, 0x2, 
    0x1b, 0x31, 0x7, 0x5, 0x2, 0x2, 0x1c, 0x31, 0x7, 0x3, 0x2, 0x2, 0x1d, 
    0x1e, 0x7, 0x3, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0xf, 0x2, 0x2, 0x1f, 0x31, 
    0x5, 0x6, 0x4, 0xc, 0x20, 0x22, 0x7, 0x3, 0x2, 0x2, 0x21, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x23, 0x24, 0x7, 0x9, 0x2, 0x2, 0x24, 0x25, 0x5, 0x8, 0x5, 
    0x2, 0x25, 0x29, 0x7, 0xa, 0x2, 0x2, 0x26, 0x27, 0x7, 0xf, 0x2, 0x2, 
    0x27, 0x2a, 0x5, 0x6, 0x4, 0x2, 0x28, 0x2a, 0x5, 0xa, 0x6, 0x2, 0x29, 
    0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x9, 0x2, 0x2, 0x2c, 0x2d, 0x5, 
    0x6, 0x4, 0x2, 0x2d, 0x2e, 0x7, 0xa, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x31, 0x5, 0xa, 0x6, 0x2, 0x30, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x21, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0xc, 0x6, 0x2, 0x2, 0x33, 0x34, 0x9, 
    0x2, 0x2, 0x2, 0x34, 0x4b, 0x5, 0x6, 0x4, 0x7, 0x35, 0x36, 0xc, 0x5, 
    0x2, 0x2, 0x36, 0x37, 0x9, 0x3, 0x2, 0x2, 0x37, 0x4b, 0x5, 0x6, 0x4, 
    0x6, 0x38, 0x39, 0xc, 0x4, 0x2, 0x2, 0x39, 0x3a, 0x9, 0x4, 0x2, 0x2, 
    0x3a, 0x4b, 0x5, 0x6, 0x4, 0x5, 0x3b, 0x3c, 0xc, 0xa, 0x2, 0x2, 0x3c, 
    0x3d, 0x7, 0x9, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0x8, 0x5, 0x2, 0x3e, 0x3f, 
    0x7, 0xa, 0x2, 0x2, 0x3f, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0xc, 
    0x9, 0x2, 0x2, 0x41, 0x42, 0x7, 0x6, 0x2, 0x2, 0x42, 0x43, 0x7, 0x3, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0x9, 0x2, 0x2, 0x44, 0x45, 0x5, 0x8, 0x5, 
    0x2, 0x45, 0x46, 0x7, 0xa, 0x2, 0x2, 0x46, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x48, 0xc, 0x8, 0x2, 0x2, 0x48, 0x49, 0x7, 0x6, 0x2, 0x2, 0x49, 
    0x4b, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x32, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x40, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x54, 0x5, 0x6, 0x4, 0x2, 0x50, 
    0x51, 0x7, 0x7, 0x2, 0x2, 0x51, 0x53, 0x5, 0x6, 0x4, 0x2, 0x52, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x60, 0x7, 0xd, 0x2, 
    0x2, 0x58, 0x5d, 0x5, 0x6, 0x4, 0x2, 0x59, 0x5a, 0x7, 0x7, 0x2, 0x2, 
    0x5a, 0x5c, 0x5, 0x6, 0x4, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x58, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x64, 0x7, 0xe, 0x2, 
    0x2, 0x63, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x63, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x9, 0x3, 0x2, 0x2, 0x2, 0x65, 0x69, 0x7, 0xb, 0x2, 0x2, 0x66, 
    0x68, 0x7, 0x8, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6e, 0x5, 0x4, 0x3, 0x2, 0x6d, 0x6f, 0x7, 0x8, 0x2, 
    0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x77, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x79, 0x5, 0x4, 0x3, 0x2, 0x78, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7c, 0x7, 0x8, 0x2, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0xc, 0x2, 0x2, 0x81, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x10, 0x12, 0x21, 0x29, 0x30, 0x4a, 0x4c, 0x54, 0x5d, 
    0x60, 0x63, 0x69, 0x70, 0x74, 0x78, 0x7d, 
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

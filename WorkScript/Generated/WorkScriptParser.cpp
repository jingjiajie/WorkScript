
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
      | (1ULL << WorkScriptParser::LEFT_BRACE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
      setState(14);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::IDENTIFIER:
        case WorkScriptParser::NUMBER:
        case WorkScriptParser::STRING:
        case WorkScriptParser::LEFT_PARENTHESE:
        case WorkScriptParser::LEFT_BRACE:
        case WorkScriptParser::LEFT_BRACKET: {
          setState(10);
          expression(0);
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


size_t WorkScriptParser::ExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleExpression;
}

void WorkScriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
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
//----------------- TermBlockExpressionContext ------------------------------------------------------------------

WorkScriptParser::BlockExpressionContext* WorkScriptParser::TermBlockExpressionContext::blockExpression() {
  return getRuleContext<WorkScriptParser::BlockExpressionContext>(0);
}

WorkScriptParser::TermBlockExpressionContext::TermBlockExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::TermBlockExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTermBlockExpression(this);
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
//----------------- NumberExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::NUMBER() {
  return getToken(WorkScriptParser::NUMBER, 0);
}

WorkScriptParser::NumberExpressionContext::NumberExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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

WorkScriptParser::VariableExpressionContext::VariableExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::VariableExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVariableExpression(this);
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
//----------------- MethodInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
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
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::AssignmentExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::AssignmentExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::AssignmentExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyDivideExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::MultiplyDivideExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::MultiplyDivideExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideExpressionContext::MULTIPLY() {
  return getToken(WorkScriptParser::MULTIPLY, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideExpressionContext::DIVIDE() {
  return getToken(WorkScriptParser::DIVIDE, 0);
}

WorkScriptParser::MultiplyDivideExpressionContext::MultiplyDivideExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MultiplyDivideExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplyDivideExpression(this);
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

tree::TerminalNode* WorkScriptParser::MemberEvaluateExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

WorkScriptParser::MemberEvaluateExpressionContext::MemberEvaluateExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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

WorkScriptParser::StringExpressionContext::StringExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::StringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStringExpression(this);
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

WorkScriptParser::ExpressionContext* WorkScriptParser::expression() {
   return expression(0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WorkScriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  WorkScriptParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, WorkScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(22);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(23);
      expression(0);
      setState(24);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ListExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(26);
      match(WorkScriptParser::LEFT_BRACKET);
      setState(37);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
        | (1ULL << WorkScriptParser::LEFT_BRACE)
        | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
        setState(27);
        expression(0);
        setState(34);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
          | (1ULL << WorkScriptParser::NUMBER)
          | (1ULL << WorkScriptParser::STRING)
          | (1ULL << WorkScriptParser::COMMA)
          | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
          | (1ULL << WorkScriptParser::LEFT_BRACE)
          | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
          setState(29);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == WorkScriptParser::COMMA) {
            setState(28);
            match(WorkScriptParser::COMMA);
          }
          setState(31);
          expression(0);
          setState(36);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(39);
      match(WorkScriptParser::RIGHT_BRACKET);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TermBlockExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(40);
      blockExpression();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctionExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(41);
      functionExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(WorkScriptParser::NUMBER);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(43);
      match(WorkScriptParser::STRING);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<VariableExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(44);
      match(WorkScriptParser::IDENTIFIER);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(76);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(74);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(47);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(48);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::MULTIPLY

          || _la == WorkScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(49);
          expression(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(50);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(51);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(52);
          expression(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(53);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(54);
          match(WorkScriptParser::EQUALS);
          setState(55);
          expression(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(56);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(57);
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
          setState(58);
          expression(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<FunctionInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(59);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(60);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(61);
          parameterExpression();
          setState(62);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<MethodInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(64);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(65);
          match(WorkScriptParser::POINT);
          setState(66);
          match(WorkScriptParser::IDENTIFIER);
          setState(67);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(68);
          parameterExpression();
          setState(69);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(71);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(72);
          match(WorkScriptParser::POINT);
          setState(73);
          match(WorkScriptParser::IDENTIFIER);
          break;
        }

        } 
      }
      setState(78);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::ParameterExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ParameterExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
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
  enterRule(_localctx, 4, WorkScriptParser::RuleParameterExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
      setState(79);
      expression(0);
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::COMMA)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
        | (1ULL << WorkScriptParser::LEFT_BRACE)
        | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
        setState(81);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WorkScriptParser::COMMA) {
          setState(80);
          match(WorkScriptParser::COMMA);
        }
        setState(83);
        expression(0);
        setState(88);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- FunctionExpressionContext ------------------------------------------------------------------

WorkScriptParser::FunctionExpressionContext::FunctionExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::FunctionExpressionContext::parameterExpression() {
  return getRuleContext<WorkScriptParser::ParameterExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
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
  enterRule(_localctx, 6, WorkScriptParser::RuleFunctionExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::IDENTIFIER) {
      setState(91);
      match(WorkScriptParser::IDENTIFIER);
    }
    setState(94);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(95);
    parameterExpression();
    setState(96);
    match(WorkScriptParser::RIGHT_PARENTHESE);
    setState(97);
    match(WorkScriptParser::EQUALS);
    setState(98);
    expression(0);
   
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
    setState(100);
    match(WorkScriptParser::LEFT_BRACE);
    setState(104);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(101);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(106);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
      setState(115);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(107);
          expression(0);
          setState(109); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(108);
            match(WorkScriptParser::NEWLINE);
            setState(111); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(117);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      setState(118);
      expression(0);
    }
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(121);
      match(WorkScriptParser::NEWLINE);
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
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
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);

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
  "program", "expression", "parameterExpression", "functionExpression", 
  "blockExpression"
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
    0x3, 0x18, 0x84, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x11, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x14, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x20, 0xa, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x23, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x26, 0xb, 0x3, 0x5, 0x3, 
    0x28, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x30, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x50, 
    0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x54, 0xa, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x57, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5a, 0xb, 0x4, 0x5, 0x4, 0x5c, 
    0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x5f, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x69, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x6c, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 
    0x6, 0x70, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x71, 0x7, 0x6, 0x74, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x77, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x7a, 0xa, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x7d, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x80, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x2, 0x3, 0x4, 0x7, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0x2, 0x5, 0x3, 0x2, 0x12, 0x13, 0x3, 0x2, 0x10, 0x11, 0x3, 
    0x2, 0x14, 0x17, 0x2, 0x99, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x66, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x5, 0x4, 0x3, 0x2, 
    0xd, 0xe, 0x7, 0x8, 0x2, 0x2, 0xe, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf, 0x11, 
    0x7, 0x8, 0x2, 0x2, 0x10, 0xc, 0x3, 0x2, 0x2, 0x2, 0x10, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x14, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x3, 0x2, 0x2, 0x2, 0x13, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x2, 0x2, 0x3, 0x16, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x8, 0x3, 0x1, 0x2, 0x18, 0x19, 
    0x7, 0x9, 0x2, 0x2, 0x19, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x1a, 0x1b, 0x7, 
    0xa, 0x2, 0x2, 0x1b, 0x30, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x27, 0x7, 0xd, 
    0x2, 0x2, 0x1d, 0x24, 0x5, 0x4, 0x3, 0x2, 0x1e, 0x20, 0x7, 0x7, 0x2, 
    0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x23, 0x5, 0x4, 0x3, 0x2, 0x22, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x23, 0x26, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x30, 0x7, 0xe, 0x2, 0x2, 0x2a, 0x30, 0x5, 0xa, 0x6, 0x2, 
    0x2b, 0x30, 0x5, 0x8, 0x5, 0x2, 0x2c, 0x30, 0x7, 0x4, 0x2, 0x2, 0x2d, 
    0x30, 0x7, 0x5, 0x2, 0x2, 0x2e, 0x30, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2c, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0xc, 0xb, 0x2, 0x2, 
    0x32, 0x33, 0x9, 0x2, 0x2, 0x2, 0x33, 0x4d, 0x5, 0x4, 0x3, 0xc, 0x34, 
    0x35, 0xc, 0xa, 0x2, 0x2, 0x35, 0x36, 0x9, 0x3, 0x2, 0x2, 0x36, 0x4d, 
    0x5, 0x4, 0x3, 0xb, 0x37, 0x38, 0xc, 0x7, 0x2, 0x2, 0x38, 0x39, 0x7, 
    0xf, 0x2, 0x2, 0x39, 0x4d, 0x5, 0x4, 0x3, 0x8, 0x3a, 0x3b, 0xc, 0x6, 
    0x2, 0x2, 0x3b, 0x3c, 0x9, 0x4, 0x2, 0x2, 0x3c, 0x4d, 0x5, 0x4, 0x3, 
    0x7, 0x3d, 0x3e, 0xc, 0xe, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x9, 0x2, 0x2, 
    0x3f, 0x40, 0x5, 0x6, 0x4, 0x2, 0x40, 0x41, 0x7, 0xa, 0x2, 0x2, 0x41, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0xc, 0xd, 0x2, 0x2, 0x43, 0x44, 
    0x7, 0x6, 0x2, 0x2, 0x44, 0x45, 0x7, 0x3, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x9, 0x2, 0x2, 0x46, 0x47, 0x5, 0x6, 0x4, 0x2, 0x47, 0x48, 0x7, 0xa, 
    0x2, 0x2, 0x48, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0xc, 0xc, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x6, 0x2, 0x2, 0x4b, 0x4d, 0x7, 0x3, 0x2, 0x2, 
    0x4c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x34, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x58, 0x5, 0x4, 0x3, 0x2, 
    0x52, 0x54, 0x7, 0x7, 0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 
    0x5, 0x4, 0x3, 0x2, 0x56, 0x53, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x5e, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x9, 0x2, 0x2, 0x61, 0x62, 0x5, 
    0x6, 0x4, 0x2, 0x62, 0x63, 0x7, 0xa, 0x2, 0x2, 0x63, 0x64, 0x7, 0xf, 
    0x2, 0x2, 0x64, 0x65, 0x5, 0x4, 0x3, 0x2, 0x65, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x6a, 0x7, 0xb, 0x2, 0x2, 0x67, 0x69, 0x7, 0x8, 0x2, 0x2, 
    0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x5, 
    0x4, 0x3, 0x2, 0x6e, 0x70, 0x7, 0x8, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7a, 0x5, 
    0x4, 0x3, 0x2, 0x79, 0x75, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x7, 0x8, 0x2, 
    0x2, 0x7c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 
    0x7, 0xc, 0x2, 0x2, 0x82, 0xb, 0x3, 0x2, 0x2, 0x2, 0x13, 0x10, 0x12, 
    0x1f, 0x24, 0x27, 0x2f, 0x4c, 0x4e, 0x53, 0x58, 0x5b, 0x5e, 0x6a, 0x71, 
    0x75, 0x79, 0x7e, 
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

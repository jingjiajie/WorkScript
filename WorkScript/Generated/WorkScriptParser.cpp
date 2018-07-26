
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

tree::TerminalNode* WorkScriptParser::ProgramContext::EOF() {
  return getToken(WorkScriptParser::EOF, 0);
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
    setState(20);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(16);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::NEWLINE)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
        setState(14);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WorkScriptParser::IDENTIFIER:
          case WorkScriptParser::NUMBER:
          case WorkScriptParser::STRING:
          case WorkScriptParser::LEFT_PARENTHESE: {
            setState(12);
            expression();
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
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(19);
      match(WorkScriptParser::EOF);
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

//----------------- ExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::ExpressionContext::NEWLINE() {
  return getToken(WorkScriptParser::NEWLINE, 0);
}

tree::TerminalNode* WorkScriptParser::ExpressionContext::EOF() {
  return getToken(WorkScriptParser::EOF, 0);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::ExpressionContext::polynomialExpression() {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(0);
}

WorkScriptParser::RelationExpressionContext* WorkScriptParser::ExpressionContext::relationExpression() {
  return getRuleContext<WorkScriptParser::RelationExpressionContext>(0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(22);
      polynomialExpression();
      break;
    }

    case 2: {
      setState(23);
      relationExpression();
      break;
    }

    }
    setState(26);
    _la = _input->LA(1);
    if (!(_la == WorkScriptParser::EOF

    || _la == WorkScriptParser::NEWLINE)) {
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

//----------------- RelationExpressionContext ------------------------------------------------------------------

WorkScriptParser::RelationExpressionContext::RelationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::PolynomialExpressionContext *> WorkScriptParser::RelationExpressionContext::polynomialExpression() {
  return getRuleContexts<WorkScriptParser::PolynomialExpressionContext>();
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::RelationExpressionContext::polynomialExpression(size_t i) {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::RelationExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}


size_t WorkScriptParser::RelationExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleRelationExpression;
}

antlrcpp::Any WorkScriptParser::RelationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitRelationExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::RelationExpressionContext* WorkScriptParser::relationExpression() {
  RelationExpressionContext *_localctx = _tracker.createInstance<RelationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, WorkScriptParser::RuleRelationExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    polynomialExpression();
    setState(29);
    match(WorkScriptParser::EQUALS);
    setState(30);
    polynomialExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PolynomialExpressionContext ------------------------------------------------------------------

WorkScriptParser::PolynomialExpressionContext::PolynomialExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::PolynomialExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::PolynomialExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}


size_t WorkScriptParser::PolynomialExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RulePolynomialExpression;
}

antlrcpp::Any WorkScriptParser::PolynomialExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPolynomialExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::polynomialExpression() {
  PolynomialExpressionContext *_localctx = _tracker.createInstance<PolynomialExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WorkScriptParser::RulePolynomialExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(32);
      termExpression(0);
      setState(35); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0));
   
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

//----------------- FunctionPolynomialExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::FunctionPolynomialExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

WorkScriptParser::ParentheseExpressionContext* WorkScriptParser::FunctionPolynomialExpressionContext::parentheseExpression() {
  return getRuleContext<WorkScriptParser::ParentheseExpressionContext>(0);
}

WorkScriptParser::FunctionPolynomialExpressionContext::FunctionPolynomialExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::FunctionPolynomialExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionPolynomialExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberEvaluateExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::MemberEvaluateExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::MemberEvaluateExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::MemberEvaluateExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

WorkScriptParser::MemberEvaluateExpressionContext::MemberEvaluateExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MemberEvaluateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMemberEvaluateExpression(this);
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
//----------------- IndependentParentheseExpressionContext ------------------------------------------------------------------

WorkScriptParser::ParentheseExpressionContext* WorkScriptParser::IndependentParentheseExpressionContext::parentheseExpression() {
  return getRuleContext<WorkScriptParser::ParentheseExpressionContext>(0);
}

WorkScriptParser::IndependentParentheseExpressionContext::IndependentParentheseExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::IndependentParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitIndependentParentheseExpression(this);
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
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::IdentifierExpressionContext::IDENTIFIER() {
  return getToken(WorkScriptParser::IDENTIFIER, 0);
}

WorkScriptParser::IdentifierExpressionContext::IdentifierExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, WorkScriptParser::RuleTermExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(42);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::NUMBER: {
        _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(38);
        match(WorkScriptParser::NUMBER);
        break;
      }

      case WorkScriptParser::STRING: {
        _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(39);
        match(WorkScriptParser::STRING);
        break;
      }

      case WorkScriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(40);
        match(WorkScriptParser::IDENTIFIER);
        break;
      }

      case WorkScriptParser::LEFT_PARENTHESE: {
        _localctx = _tracker.createInstance<IndependentParentheseExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(41);
        parentheseExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(55);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(44);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(45);
          match(WorkScriptParser::POINT);
          setState(46);
          termExpression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiplyDivideExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(47);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
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
          termExpression(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(50);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
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
          termExpression(2);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<FunctionPolynomialExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(53);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(54);
          parentheseExpression();
          break;
        }

        } 
      }
      setState(59);
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

//----------------- ParentheseExpressionContext ------------------------------------------------------------------

WorkScriptParser::ParentheseExpressionContext::ParentheseExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::ParentheseExpressionContext::polynomialExpression() {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(0);
}


size_t WorkScriptParser::ParentheseExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleParentheseExpression;
}

antlrcpp::Any WorkScriptParser::ParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParentheseExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ParentheseExpressionContext* WorkScriptParser::parentheseExpression() {
  ParentheseExpressionContext *_localctx = _tracker.createInstance<ParentheseExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, WorkScriptParser::RuleParentheseExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
      setState(61);
      polynomialExpression();
    }
    setState(64);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
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
    case 4: return termExpressionSempred(dynamic_cast<TermExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::termExpressionSempred(TermExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);
    case 3: return precpred(_ctx, 5);

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
  "program", "expression", "relationExpression", "polynomialExpression", 
  "termExpression", "parentheseExpression"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "", "", "'.'", "", "'('", "')'", "'{'", "'}'", "'='", "'+'", "'-'", 
  "'*'", "'/'", "'>'", "'>='", "'<'", "'<='"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
  "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
  "MULTIPLY", "DIVIDE", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", 
  "LESS_THAN_EQUAL", "WS"
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
    0x3, 0x15, 0x45, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x11, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x14, 0xb, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x17, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x1b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x6, 0x5, 0x24, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x25, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2d, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x3a, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x3d, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x41, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x3, 0xa, 0x8, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0x2, 0x5, 0x3, 0x3, 0x7, 0x7, 0x3, 0x2, 0xf, 0x10, 0x3, 
    0x2, 0xd, 0xe, 0x2, 0x4b, 0x2, 0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x11, 0x5, 0x4, 0x3, 0x2, 0xf, 0x11, 0x7, 0x7, 0x2, 0x2, 0x10, 
    0xe, 0x3, 0x2, 0x2, 0x2, 0x10, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x13, 0x17, 0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x15, 0x17, 0x7, 0x2, 0x2, 0x3, 0x16, 0x12, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x15, 0x3, 0x2, 0x2, 0x2, 0x17, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x1b, 0x5, 0x8, 0x5, 0x2, 0x19, 0x1b, 0x5, 0x6, 0x4, 0x2, 0x1a, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x9, 0x2, 0x2, 0x2, 0x1d, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x8, 0x5, 0x2, 0x1f, 0x20, 0x7, 0xc, 
    0x2, 0x2, 0x20, 0x21, 0x5, 0x8, 0x5, 0x2, 0x21, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x24, 0x5, 0xa, 0x6, 0x2, 0x23, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x9, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 
    0x8, 0x6, 0x1, 0x2, 0x28, 0x2d, 0x7, 0x4, 0x2, 0x2, 0x29, 0x2d, 0x7, 
    0x5, 0x2, 0x2, 0x2a, 0x2d, 0x7, 0x3, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0xc, 
    0x7, 0x2, 0x2c, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0xc, 0x5, 0x2, 0x2, 0x2f, 
    0x30, 0x7, 0x6, 0x2, 0x2, 0x30, 0x3a, 0x5, 0xa, 0x6, 0x6, 0x31, 0x32, 
    0xc, 0x4, 0x2, 0x2, 0x32, 0x33, 0x9, 0x3, 0x2, 0x2, 0x33, 0x3a, 0x5, 
    0xa, 0x6, 0x5, 0x34, 0x35, 0xc, 0x3, 0x2, 0x2, 0x35, 0x36, 0x9, 0x4, 
    0x2, 0x2, 0x36, 0x3a, 0x5, 0xa, 0x6, 0x4, 0x37, 0x38, 0xc, 0x7, 0x2, 
    0x2, 0x38, 0x3a, 0x5, 0xc, 0x7, 0x2, 0x39, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x31, 0x3, 0x2, 0x2, 0x2, 0x39, 0x34, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x8, 
    0x2, 0x2, 0x3f, 0x41, 0x5, 0x8, 0x5, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x7, 0x9, 0x2, 0x2, 0x43, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb, 
    0x10, 0x12, 0x16, 0x1a, 0x25, 0x2c, 0x39, 0x3b, 0x40, 
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


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
    setState(18);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::NEWLINE)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
        setState(12);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WorkScriptParser::IDENTIFIER:
          case WorkScriptParser::NUMBER:
          case WorkScriptParser::STRING:
          case WorkScriptParser::LEFT_PARENTHESE: {
            setState(10);
            expression();
            break;
          }

          case WorkScriptParser::NEWLINE: {
            setState(11);
            match(WorkScriptParser::NEWLINE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(16);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(17);
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
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(20);
      polynomialExpression();
      break;
    }

    case 2: {
      setState(21);
      relationExpression();
      break;
    }

    }
    setState(24);
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
    setState(26);
    polynomialExpression();
    setState(27);
    match(WorkScriptParser::EQUALS);
    setState(28);
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

std::vector<tree::TerminalNode *> WorkScriptParser::PolynomialExpressionContext::COMMA() {
  return getTokens(WorkScriptParser::COMMA);
}

tree::TerminalNode* WorkScriptParser::PolynomialExpressionContext::COMMA(size_t i) {
  return getToken(WorkScriptParser::COMMA, i);
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
    setState(30);
    termExpression(0);
    setState(37);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::COMMA)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
      setState(32);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::COMMA) {
        setState(31);
        match(WorkScriptParser::COMMA);
      }
      setState(34);
      termExpression(0);
      setState(39);
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
//----------------- EvaluatedFunctionExpressionContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> WorkScriptParser::EvaluatedFunctionExpressionContext::LEFT_PARENTHESE() {
  return getTokens(WorkScriptParser::LEFT_PARENTHESE);
}

tree::TerminalNode* WorkScriptParser::EvaluatedFunctionExpressionContext::LEFT_PARENTHESE(size_t i) {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::EvaluatedFunctionExpressionContext::RIGHT_PARENTHESE() {
  return getTokens(WorkScriptParser::RIGHT_PARENTHESE);
}

tree::TerminalNode* WorkScriptParser::EvaluatedFunctionExpressionContext::RIGHT_PARENTHESE(size_t i) {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, i);
}

std::vector<WorkScriptParser::PolynomialExpressionContext *> WorkScriptParser::EvaluatedFunctionExpressionContext::polynomialExpression() {
  return getRuleContexts<WorkScriptParser::PolynomialExpressionContext>();
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::EvaluatedFunctionExpressionContext::polynomialExpression(size_t i) {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(i);
}

WorkScriptParser::EvaluatedFunctionExpressionContext::EvaluatedFunctionExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::EvaluatedFunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitEvaluatedFunctionExpression(this);
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

tree::TerminalNode* WorkScriptParser::IndependentParentheseExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

tree::TerminalNode* WorkScriptParser::IndependentParentheseExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::IndependentParentheseExpressionContext::polynomialExpression() {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(0);
}

WorkScriptParser::IndependentParentheseExpressionContext::IndependentParentheseExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::IndependentParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitIndependentParentheseExpression(this);
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
//----------------- DirectFunctionExpressionContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::DirectFunctionExpressionContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::DirectFunctionExpressionContext::LEFT_PARENTHESE() {
  return getTokens(WorkScriptParser::LEFT_PARENTHESE);
}

tree::TerminalNode* WorkScriptParser::DirectFunctionExpressionContext::LEFT_PARENTHESE(size_t i) {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::DirectFunctionExpressionContext::RIGHT_PARENTHESE() {
  return getTokens(WorkScriptParser::RIGHT_PARENTHESE);
}

tree::TerminalNode* WorkScriptParser::DirectFunctionExpressionContext::RIGHT_PARENTHESE(size_t i) {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, i);
}

std::vector<WorkScriptParser::PolynomialExpressionContext *> WorkScriptParser::DirectFunctionExpressionContext::polynomialExpression() {
  return getRuleContexts<WorkScriptParser::PolynomialExpressionContext>();
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::DirectFunctionExpressionContext::polynomialExpression(size_t i) {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(i);
}

WorkScriptParser::DirectFunctionExpressionContext::DirectFunctionExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::DirectFunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitDirectFunctionExpression(this);
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
    setState(63);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(41);
      match(WorkScriptParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(WorkScriptParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(43);
      match(WorkScriptParser::IDENTIFIER);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<EvaluatedFunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(44);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(46);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
        setState(45);
        polynomialExpression();
      }
      setState(48);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      setState(54); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(49);
                match(WorkScriptParser::LEFT_PARENTHESE);
                setState(51);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if ((((_la & ~ 0x3fULL) == 0) &&
                  ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
                  | (1ULL << WorkScriptParser::NUMBER)
                  | (1ULL << WorkScriptParser::STRING)
                  | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
                  setState(50);
                  polynomialExpression();
                }
                setState(53);
                match(WorkScriptParser::RIGHT_PARENTHESE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(56); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IndependentParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(58);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(60);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
        setState(59);
        polynomialExpression();
      }
      setState(62);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(89);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(87);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(65);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(66);
          match(WorkScriptParser::POINT);
          setState(67);
          termExpression(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiplyDivideExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(68);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(69);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::MULTIPLY

          || _la == WorkScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(70);
          termExpression(4);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(71);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(72);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(73);
          termExpression(3);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(74);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(75);
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
          setState(76);
          termExpression(2);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<DirectFunctionExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(77);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(83); 
          _errHandler->sync(this);
          alt = 1;
          do {
            switch (alt) {
              case 1: {
                    setState(78);
                    match(WorkScriptParser::LEFT_PARENTHESE);
                    setState(80);
                    _errHandler->sync(this);

                    _la = _input->LA(1);
                    if ((((_la & ~ 0x3fULL) == 0) &&
                      ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
                      | (1ULL << WorkScriptParser::NUMBER)
                      | (1ULL << WorkScriptParser::STRING)
                      | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
                      setState(79);
                      polynomialExpression();
                    }
                    setState(82);
                    match(WorkScriptParser::RIGHT_PARENTHESE);
                    break;
                  }

            default:
              throw NoViableAltException(this);
            }
            setState(85); 
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
          } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
          break;
        }

        } 
      }
      setState(91);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
    case 4: return termExpressionSempred(dynamic_cast<TermExpressionContext *>(context), predicateIndex);

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
    case 3: return precpred(_ctx, 1);
    case 4: return precpred(_ctx, 6);

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
  "termExpression"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "", "", "'.'", "','", "", "'('", "')'", "'{'", "'}'", "'='", "'+'", 
  "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "IDENTIFIER", "NUMBER", "STRING", "POINT", "COMMA", "NEWLINE", "LEFT_PARENTHESE", 
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
    0x3, 0x16, 0x5f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x7, 
    0x2, 0xf, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x12, 0xb, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x15, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x23, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x26, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x29, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x31, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x36, 0xa, 0x6, 0x3, 0x6, 0x6, 0x6, 0x39, 0xa, 0x6, 0xd, 
    0x6, 0xe, 0x6, 0x3a, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x3f, 0xa, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x42, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 
    0x6, 0x6, 0x6, 0x56, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x57, 0x7, 0x6, 0x5a, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5d, 0xb, 0x6, 0x3, 0x6, 0x2, 0x3, 0xa, 
    0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x6, 0x3, 0x3, 0x8, 0x8, 0x3, 0x2, 
    0x10, 0x11, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x12, 0x15, 0x2, 0x6e, 0x2, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x20, 0x3, 0x2, 0x2, 0x2, 0xa, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xf, 0x5, 0x4, 0x3, 0x2, 0xd, 0xf, 0x7, 0x8, 0x2, 0x2, 
    0xe, 0xc, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf, 0x12, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x11, 0x15, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 
    0x2, 0x2, 0x13, 0x15, 0x7, 0x2, 0x2, 0x3, 0x14, 0x10, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x19, 0x5, 0x8, 0x5, 0x2, 0x17, 0x19, 0x5, 0x6, 0x4, 0x2, 0x18, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x9, 0x2, 0x2, 0x2, 0x1b, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0x8, 0x5, 0x2, 0x1d, 0x1e, 0x7, 0xd, 
    0x2, 0x2, 0x1e, 0x1f, 0x5, 0x8, 0x5, 0x2, 0x1f, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x27, 0x5, 0xa, 0x6, 0x2, 0x21, 0x23, 0x7, 0x7, 0x2, 0x2, 
    0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 0xa, 0x6, 0x2, 0x25, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x8, 0x6, 0x1, 
    0x2, 0x2b, 0x42, 0x7, 0x4, 0x2, 0x2, 0x2c, 0x42, 0x7, 0x5, 0x2, 0x2, 
    0x2d, 0x42, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x30, 0x7, 0x9, 0x2, 0x2, 0x2f, 
    0x31, 0x5, 0x8, 0x5, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x38, 0x7, 
    0xa, 0x2, 0x2, 0x33, 0x35, 0x7, 0x9, 0x2, 0x2, 0x34, 0x36, 0x5, 0x8, 
    0x5, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x39, 0x7, 0xa, 0x2, 0x2, 
    0x38, 0x33, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 0x7, 0x9, 0x2, 0x2, 0x3d, 0x3f, 0x5, 
    0x8, 0x5, 0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 0x7, 0xa, 0x2, 
    0x2, 0x41, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x41, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x41, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
    0xc, 0x6, 0x2, 0x2, 0x44, 0x45, 0x7, 0x6, 0x2, 0x2, 0x45, 0x5a, 0x5, 
    0xa, 0x6, 0x7, 0x46, 0x47, 0xc, 0x5, 0x2, 0x2, 0x47, 0x48, 0x9, 0x3, 
    0x2, 0x2, 0x48, 0x5a, 0x5, 0xa, 0x6, 0x6, 0x49, 0x4a, 0xc, 0x4, 0x2, 
    0x2, 0x4a, 0x4b, 0x9, 0x4, 0x2, 0x2, 0x4b, 0x5a, 0x5, 0xa, 0x6, 0x5, 
    0x4c, 0x4d, 0xc, 0x3, 0x2, 0x2, 0x4d, 0x4e, 0x9, 0x5, 0x2, 0x2, 0x4e, 
    0x5a, 0x5, 0xa, 0x6, 0x4, 0x4f, 0x55, 0xc, 0x8, 0x2, 0x2, 0x50, 0x52, 
    0x7, 0x9, 0x2, 0x2, 0x51, 0x53, 0x5, 0x8, 0x5, 0x2, 0x52, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x56, 0x7, 0xa, 0x2, 0x2, 0x55, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x59, 0x46, 0x3, 0x2, 0x2, 0x2, 0x59, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x59, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x11, 0xe, 0x10, 0x14, 0x18, 0x22, 
    0x27, 0x30, 0x35, 0x3a, 0x3e, 0x41, 0x52, 0x57, 0x59, 0x5b, 
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

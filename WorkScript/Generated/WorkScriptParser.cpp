
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
      polynomialExpression(0);
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
    polynomialExpression(0);
    setState(27);
    match(WorkScriptParser::EQUALS);
    setState(28);
    polynomialExpression(0);
   
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


size_t WorkScriptParser::PolynomialExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RulePolynomialExpression;
}

void WorkScriptParser::PolynomialExpressionContext::copyFrom(PolynomialExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermExpressionInPolynomialContext ------------------------------------------------------------------

WorkScriptParser::TermExpressionContext* WorkScriptParser::TermExpressionInPolynomialContext::termExpression() {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(0);
}

WorkScriptParser::TermExpressionInPolynomialContext::TermExpressionInPolynomialContext(PolynomialExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::TermExpressionInPolynomialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTermExpressionInPolynomial(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::PolynomialExpressionContext *> WorkScriptParser::PlusMinusExpressionContext::polynomialExpression() {
  return getRuleContexts<WorkScriptParser::PolynomialExpressionContext>();
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::PlusMinusExpressionContext::polynomialExpression(size_t i) {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::PlusMinusExpressionContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::PlusMinusExpressionContext::PlusMinusExpressionContext(PolynomialExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::PlusMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPlusMinusExpression(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::polynomialExpression() {
   return polynomialExpression(0);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::polynomialExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WorkScriptParser::PolynomialExpressionContext *_localctx = _tracker.createInstance<PolynomialExpressionContext>(_ctx, parentState);
  WorkScriptParser::PolynomialExpressionContext *previousContext = _localctx;
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, WorkScriptParser::RulePolynomialExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<TermExpressionInPolynomialContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(31);
    termExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(38);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<PolynomialExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RulePolynomialExpression);
        setState(33);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(34);
        _la = _input->LA(1);
        if (!(_la == WorkScriptParser::PLUS

        || _la == WorkScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(35);
        polynomialExpression(2); 
      }
      setState(40);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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

//----------------- MultiTermExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::TermExpressionContext *> WorkScriptParser::MultiTermExpressionContext::termExpression() {
  return getRuleContexts<WorkScriptParser::TermExpressionContext>();
}

WorkScriptParser::TermExpressionContext* WorkScriptParser::MultiTermExpressionContext::termExpression(size_t i) {
  return getRuleContext<WorkScriptParser::TermExpressionContext>(i);
}

WorkScriptParser::MultiTermExpressionContext::MultiTermExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MultiTermExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiTermExpression(this);
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
//----------------- ParentheseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

tree::TerminalNode* WorkScriptParser::ParentheseExpressionContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::PolynomialExpressionContext* WorkScriptParser::ParentheseExpressionContext::polynomialExpression() {
  return getRuleContext<WorkScriptParser::PolynomialExpressionContext>(0);
}

WorkScriptParser::ParentheseExpressionContext::ParentheseExpressionContext(TermExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::ParentheseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParentheseExpression(this);
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
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::NUMBER: {
        _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(42);
        match(WorkScriptParser::NUMBER);
        break;
      }

      case WorkScriptParser::STRING: {
        _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(43);
        match(WorkScriptParser::STRING);
        break;
      }

      case WorkScriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(44);
        match(WorkScriptParser::IDENTIFIER);
        break;
      }

      case WorkScriptParser::LEFT_PARENTHESE: {
        _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(45);
        match(WorkScriptParser::LEFT_PARENTHESE);
        setState(47);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << WorkScriptParser::IDENTIFIER)
          | (1ULL << WorkScriptParser::NUMBER)
          | (1ULL << WorkScriptParser::STRING)
          | (1ULL << WorkScriptParser::LEFT_PARENTHESE))) != 0)) {
          setState(46);
          polynomialExpression(0);
        }
        setState(49);
        match(WorkScriptParser::RIGHT_PARENTHESE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(61);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(52);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(53);
          match(WorkScriptParser::POINT);
          setState(54);
          termExpression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiTermExpressionContext>(_tracker.createInstance<TermExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleTermExpression);
          setState(55);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(57); 
          _errHandler->sync(this);
          alt = 1;
          do {
            switch (alt) {
              case 1: {
                    setState(56);
                    termExpression(0);
                    break;
                  }

            default:
              throw NoViableAltException(this);
            }
            setState(59); 
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
          } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
          break;
        }

        } 
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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
    case 3: return polynomialExpressionSempred(dynamic_cast<PolynomialExpressionContext *>(context), predicateIndex);
    case 4: return termExpressionSempred(dynamic_cast<TermExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::polynomialExpressionSempred(PolynomialExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::termExpressionSempred(TermExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 1);

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
  "", "", "", "", "'.'", "", "'('", "')'", "'{'", "'}'", "'='", "'+'", "'-'", 
  "'>'", "'>='", "'<'", "'<='"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "IDENTIFIER", "NUMBER", "STRING", "POINT", "NEWLINE", "LEFT_PARENTHESE", 
  "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "EQUALS", "PLUS", "MINUS", 
  "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", 
  "WS"
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
    0x3, 0x13, 0x45, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x7, 
    0x2, 0xf, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x12, 0xb, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x15, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x27, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x2a, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x32, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0x35, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 
    0x6, 0x3c, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x3d, 0x7, 0x6, 0x40, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x43, 0xb, 0x6, 0x3, 0x6, 0x2, 0x4, 0x8, 0xa, 
    0x7, 0x2, 0x4, 0x6, 0x8, 0xa, 0x2, 0x4, 0x3, 0x3, 0x7, 0x7, 0x3, 0x2, 
    0xd, 0xe, 0x2, 0x4b, 0x2, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x34, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf, 0x5, 0x4, 0x3, 0x2, 0xd, 
    0xf, 0x7, 0x7, 0x2, 0x2, 0xe, 0xc, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xf, 0x12, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 0x2, 0x2, 
    0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x13, 0x15, 0x7, 0x2, 0x2, 0x3, 0x14, 
    0x10, 0x3, 0x2, 0x2, 0x2, 0x14, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x19, 0x5, 0x8, 0x5, 0x2, 0x17, 0x19, 0x5, 
    0x6, 0x4, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x9, 0x2, 0x2, 
    0x2, 0x1b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0x8, 0x5, 0x2, 
    0x1d, 0x1e, 0x7, 0xc, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x8, 0x5, 0x2, 0x1f, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x8, 0x5, 0x1, 0x2, 0x21, 0x22, 
    0x5, 0xa, 0x6, 0x2, 0x22, 0x28, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0xc, 
    0x3, 0x2, 0x2, 0x24, 0x25, 0x9, 0x3, 0x2, 0x2, 0x25, 0x27, 0x5, 0x8, 
    0x5, 0x4, 0x26, 0x23, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x2c, 0x8, 0x6, 0x1, 0x2, 0x2c, 0x35, 0x7, 0x4, 0x2, 0x2, 0x2d, 0x35, 
    0x7, 0x5, 0x2, 0x2, 0x2e, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x31, 0x7, 
    0x8, 0x2, 0x2, 0x30, 0x32, 0x5, 0x8, 0x5, 0x2, 0x31, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x35, 0x7, 0x9, 0x2, 0x2, 0x34, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x35, 0x41, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0xc, 0x5, 0x2, 0x2, 0x37, 0x38, 0x7, 0x6, 0x2, 0x2, 0x38, 0x40, 0x5, 
    0xa, 0x6, 0x6, 0x39, 0x3b, 0xc, 0x3, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0xa, 
    0x6, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe, 0x10, 0x14, 
    0x18, 0x28, 0x31, 0x34, 0x3d, 0x3f, 0x41, 
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

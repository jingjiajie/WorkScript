
// Generated from WorkScript.g4 by ANTLR 4.7.2


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

std::vector<WorkScriptParser::LineContext *> WorkScriptParser::ProgramContext::line() {
  return getRuleContexts<WorkScriptParser::LineContext>();
}

WorkScriptParser::LineContext* WorkScriptParser::ProgramContext::line(size_t i) {
  return getRuleContext<WorkScriptParser::LineContext>(i);
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
    setState(43);
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
      | (1ULL << WorkScriptParser::SEMICOLON)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(40);
      line();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    match(WorkScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

WorkScriptParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::LineContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::LineContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::LineContext::NEWLINE() {
  return getToken(WorkScriptParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::LineContext::SEMICOLON() {
  return getTokens(WorkScriptParser::SEMICOLON);
}

tree::TerminalNode* WorkScriptParser::LineContext::SEMICOLON(size_t i) {
  return getToken(WorkScriptParser::SEMICOLON, i);
}


size_t WorkScriptParser::LineContext::getRuleIndex() const {
  return WorkScriptParser::RuleLine;
}


antlrcpp::Any WorkScriptParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::LineContext* WorkScriptParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, WorkScriptParser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(51);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == WorkScriptParser::SEMICOLON) {
                  setState(48);
                  match(WorkScriptParser::SEMICOLON);
                  setState(53);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(54);
                expression(0);
                setState(58);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(55);
                    match(WorkScriptParser::SEMICOLON); 
                  }
                  setState(60);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(63); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(66);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(65);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(69); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(68);
                match(WorkScriptParser::SEMICOLON);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(71); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(74);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(73);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(76);
      match(WorkScriptParser::NEWLINE);
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


size_t WorkScriptParser::ExpressionContext::getRuleIndex() const {
  return WorkScriptParser::RuleExpression;
}

void WorkScriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryCompareContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::BinaryCompareContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::BinaryCompareContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareContext::DOUBLE_EQUAL() {
  return getToken(WorkScriptParser::DOUBLE_EQUAL, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareContext::GREATER_THAN() {
  return getToken(WorkScriptParser::GREATER_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareContext::GREATER_THAN_EQUAL() {
  return getToken(WorkScriptParser::GREATER_THAN_EQUAL, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareContext::LESS_THAN() {
  return getToken(WorkScriptParser::LESS_THAN, 0);
}

tree::TerminalNode* WorkScriptParser::BinaryCompareContext::LESS_THAN_EQUAL() {
  return getToken(WorkScriptParser::LESS_THAN_EQUAL, 0);
}

WorkScriptParser::BinaryCompareContext::BinaryCompareContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::BinaryCompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBinaryCompare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

WorkScriptParser::IdentifierContext* WorkScriptParser::VariableContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

WorkScriptParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyDivideModulusContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::MultiplyDivideModulusContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::MultiplyDivideModulusContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusContext::STAR() {
  return getToken(WorkScriptParser::STAR, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusContext::SLASH() {
  return getToken(WorkScriptParser::SLASH, 0);
}

tree::TerminalNode* WorkScriptParser::MultiplyDivideModulusContext::PERCENT() {
  return getToken(WorkScriptParser::PERCENT, 0);
}

WorkScriptParser::MultiplyDivideModulusContext::MultiplyDivideModulusContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::MultiplyDivideModulusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplyDivideModulus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StdFunctionDecl_Context ------------------------------------------------------------------

WorkScriptParser::StdFunctionDeclContext* WorkScriptParser::StdFunctionDecl_Context::stdFunctionDecl() {
  return getRuleContext<WorkScriptParser::StdFunctionDeclContext>(0);
}

WorkScriptParser::StdFunctionDecl_Context::StdFunctionDecl_Context(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::StdFunctionDecl_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFunctionDecl_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentOrEqualsContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::AssignmentOrEqualsContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::AssignmentOrEqualsContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::AssignmentOrEqualsContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::AssignmentOrEqualsContext::AssignmentOrEqualsContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::AssignmentOrEqualsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOrEquals(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::StringContext::STRING() {
  return getToken(WorkScriptParser::STRING, 0);
}

WorkScriptParser::StringContext::StringContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AccessLevelContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::AccessLevelContext::ACCESS_LEVEL() {
  return getToken(WorkScriptParser::ACCESS_LEVEL, 0);
}

tree::TerminalNode* WorkScriptParser::AccessLevelContext::COLON() {
  return getToken(WorkScriptParser::COLON, 0);
}

WorkScriptParser::AccessLevelContext::AccessLevelContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::AccessLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAccessLevel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::PlusMinusContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::PlusMinusContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::PlusMinusContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::PlusMinusContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::PlusMinusContext::PlusMinusContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::PlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::AssignmentContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::AssignmentContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::AssignmentContext::ASSIGN() {
  return getToken(WorkScriptParser::ASSIGN, 0);
}

WorkScriptParser::AssignmentContext::AssignmentContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::NumberContext::DOUBLE() {
  return getToken(WorkScriptParser::DOUBLE, 0);
}

tree::TerminalNode* WorkScriptParser::NumberContext::INTEGER() {
  return getToken(WorkScriptParser::INTEGER, 0);
}

tree::TerminalNode* WorkScriptParser::NumberContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

tree::TerminalNode* WorkScriptParser::NumberContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::NumberContext::NumberContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::NegativeContext::MINUS() {
  return getToken(WorkScriptParser::MINUS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::NegativeContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::NegativeContext::NegativeContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::NegativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNegative(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositiveContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::PositiveContext::PLUS() {
  return getToken(WorkScriptParser::PLUS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::PositiveContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

WorkScriptParser::PositiveContext::PositiveContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::PositiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitPositive(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Function_Context ------------------------------------------------------------------

WorkScriptParser::FunctionContext* WorkScriptParser::Function_Context::function() {
  return getRuleContext<WorkScriptParser::FunctionContext>(0);
}

WorkScriptParser::Function_Context::Function_Context(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::Function_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunction_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParentheseContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::ParentheseContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::ParentheseContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::ParentheseContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::ParentheseContext::ParentheseContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::ParentheseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitParenthese(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Call_Context ------------------------------------------------------------------

WorkScriptParser::CallContext* WorkScriptParser::Call_Context::call() {
  return getRuleContext<WorkScriptParser::CallContext>(0);
}

WorkScriptParser::Call_Context::Call_Context(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::Call_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCall_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanContext ------------------------------------------------------------------

tree::TerminalNode* WorkScriptParser::BooleanContext::BOOLEAN() {
  return getToken(WorkScriptParser::BOOLEAN, 0);
}

WorkScriptParser::BooleanContext::BooleanContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
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
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, WorkScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(80);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(81);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(82);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(83);
      expression(0);
      setState(84);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<StdFunctionDecl_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(86);
      stdFunctionDecl();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Function_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      function();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Call_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(88);
      call();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(90);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::PLUS

      || _la == WorkScriptParser::MINUS) {
        setState(89);
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
      setState(92);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::DOUBLE

      || _la == WorkScriptParser::INTEGER)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegativeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(93);
      match(WorkScriptParser::MINUS);
      setState(94);
      expression(8);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PositiveContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(95);
      match(WorkScriptParser::PLUS);
      setState(96);
      expression(7);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(WorkScriptParser::STRING);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      match(WorkScriptParser::BOOLEAN);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(99);
      identifier();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(117);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(102);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(103);
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
          setState(104);
          expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(105);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(106);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(107);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(108);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(109);
          match(WorkScriptParser::ASSIGN);
          setState(110);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(111);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(112);
          match(WorkScriptParser::EQUALS);
          setState(113);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryCompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(114);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(115);
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
          setState(116);
          expression(5);
          break;
        }

        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

WorkScriptParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::CallContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

tree::TerminalNode* WorkScriptParser::CallContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::MultiValueContext* WorkScriptParser::CallContext::multiValue() {
  return getRuleContext<WorkScriptParser::MultiValueContext>(0);
}

tree::TerminalNode* WorkScriptParser::CallContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}


size_t WorkScriptParser::CallContext::getRuleIndex() const {
  return WorkScriptParser::RuleCall;
}


antlrcpp::Any WorkScriptParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::CallContext* WorkScriptParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 6, WorkScriptParser::RuleCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    identifier();
    setState(123);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(124);
    multiValue();
    setState(125);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiValueContext ------------------------------------------------------------------

WorkScriptParser::MultiValueContext::MultiValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::MultiValueContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::MultiValueContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WorkScriptParser::MultiValueContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::MultiValueContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::NewlineOrCommaContext *> WorkScriptParser::MultiValueContext::newlineOrComma() {
  return getRuleContexts<WorkScriptParser::NewlineOrCommaContext>();
}

WorkScriptParser::NewlineOrCommaContext* WorkScriptParser::MultiValueContext::newlineOrComma(size_t i) {
  return getRuleContext<WorkScriptParser::NewlineOrCommaContext>(i);
}


size_t WorkScriptParser::MultiValueContext::getRuleIndex() const {
  return WorkScriptParser::RuleMultiValue;
}


antlrcpp::Any WorkScriptParser::MultiValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMultiValue(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::MultiValueContext* WorkScriptParser::multiValue() {
  MultiValueContext *_localctx = _tracker.createInstance<MultiValueContext>(_ctx, getState());
  enterRule(_localctx, 8, WorkScriptParser::RuleMultiValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
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
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(127);
        match(WorkScriptParser::NEWLINE);
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(133);
      expression(0);
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(134);
        newlineOrComma();
        setState(135);
        expression(0);
        setState(141);
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

//----------------- StdFunctionDeclContext ------------------------------------------------------------------

WorkScriptParser::StdFunctionDeclContext::StdFunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::TypeNameContext* WorkScriptParser::StdFunctionDeclContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::FunctionNameContext* WorkScriptParser::StdFunctionDeclContext::functionName() {
  return getRuleContext<WorkScriptParser::FunctionNameContext>(0);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::StdFormalParameterContext* WorkScriptParser::StdFunctionDeclContext::stdFormalParameter() {
  return getRuleContext<WorkScriptParser::StdFormalParameterContext>(0);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFunctionDeclContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::StdFunctionDeclContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}


size_t WorkScriptParser::StdFunctionDeclContext::getRuleIndex() const {
  return WorkScriptParser::RuleStdFunctionDecl;
}


antlrcpp::Any WorkScriptParser::StdFunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StdFunctionDeclContext* WorkScriptParser::stdFunctionDecl() {
  StdFunctionDeclContext *_localctx = _tracker.createInstance<StdFunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, WorkScriptParser::RuleStdFunctionDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    typeName();
    setState(148);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(145);
      match(WorkScriptParser::STAR);
      setState(150);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(151);
    functionName();
    setState(152);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(153);
    stdFormalParameter();
    setState(154);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StdFormalParameterContext ------------------------------------------------------------------

WorkScriptParser::StdFormalParameterContext::StdFormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WorkScriptParser::StdFormalParameterContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::StdFormalParameterItemContext *> WorkScriptParser::StdFormalParameterContext::stdFormalParameterItem() {
  return getRuleContexts<WorkScriptParser::StdFormalParameterItemContext>();
}

WorkScriptParser::StdFormalParameterItemContext* WorkScriptParser::StdFormalParameterContext::stdFormalParameterItem(size_t i) {
  return getRuleContext<WorkScriptParser::StdFormalParameterItemContext>(i);
}

std::vector<WorkScriptParser::NewlineOrCommaContext *> WorkScriptParser::StdFormalParameterContext::newlineOrComma() {
  return getRuleContexts<WorkScriptParser::NewlineOrCommaContext>();
}

WorkScriptParser::NewlineOrCommaContext* WorkScriptParser::StdFormalParameterContext::newlineOrComma(size_t i) {
  return getRuleContext<WorkScriptParser::NewlineOrCommaContext>(i);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterContext::APOSTROPHE() {
  return getToken(WorkScriptParser::APOSTROPHE, 0);
}


size_t WorkScriptParser::StdFormalParameterContext::getRuleIndex() const {
  return WorkScriptParser::RuleStdFormalParameter;
}


antlrcpp::Any WorkScriptParser::StdFormalParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFormalParameter(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StdFormalParameterContext* WorkScriptParser::stdFormalParameter() {
  StdFormalParameterContext *_localctx = _tracker.createInstance<StdFormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 12, WorkScriptParser::RuleStdFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(156);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(162);
      stdFormalParameterItem();
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(163);
          newlineOrComma();
          setState(164);
          stdFormalParameterItem(); 
        }
        setState(170);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      }
    }
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA

    || _la == WorkScriptParser::NEWLINE) {
      setState(173);
      newlineOrComma();
      setState(174);
      match(WorkScriptParser::APOSTROPHE);
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

std::vector<tree::TerminalNode *> WorkScriptParser::StdFormalParameterItemContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::StdFormalParameterItemContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::StdFormalParameterItemContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
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
  enterRule(_localctx, 14, WorkScriptParser::RuleStdFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    typeName();
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(179);
      match(WorkScriptParser::STAR);
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::INCLUDE)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(185);
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

//----------------- FunctionContext ------------------------------------------------------------------

WorkScriptParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::FunctionDeclarationContext* WorkScriptParser::FunctionContext::functionDeclaration() {
  return getRuleContext<WorkScriptParser::FunctionDeclarationContext>(0);
}

WorkScriptParser::FunctionImplementationContext* WorkScriptParser::FunctionContext::functionImplementation() {
  return getRuleContext<WorkScriptParser::FunctionImplementationContext>(0);
}

WorkScriptParser::FunctionConstraintContext* WorkScriptParser::FunctionContext::functionConstraint() {
  return getRuleContext<WorkScriptParser::FunctionConstraintContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunction;
}


antlrcpp::Any WorkScriptParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionContext* WorkScriptParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 16, WorkScriptParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(195);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(188);
        functionConstraint();
        setState(192);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(189);
          match(WorkScriptParser::NEWLINE);
          setState(194);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(197);
      functionDeclaration();
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(198);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(203);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      }
      setState(204);
      functionImplementation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
      functionDeclaration();
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(207);
        match(WorkScriptParser::NEWLINE);
        setState(212);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(213);
      functionConstraint();
      setState(217);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(214);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(219);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      }
      setState(220);
      functionImplementation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(222);
      functionDeclaration();
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(223);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(228);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      }
      setState(229);
      functionImplementation();
      setState(233);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(230);
        match(WorkScriptParser::NEWLINE);
        setState(235);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(236);
      functionConstraint();
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

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

WorkScriptParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationContext::LEFT_PARENTHESE() {
  return getToken(WorkScriptParser::LEFT_PARENTHESE, 0);
}

WorkScriptParser::FormalParameterContext* WorkScriptParser::FunctionDeclarationContext::formalParameter() {
  return getRuleContext<WorkScriptParser::FormalParameterContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationContext::RIGHT_PARENTHESE() {
  return getToken(WorkScriptParser::RIGHT_PARENTHESE, 0);
}

WorkScriptParser::TypeNameContext* WorkScriptParser::FunctionDeclarationContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::FunctionNameContext* WorkScriptParser::FunctionDeclarationContext::functionName() {
  return getRuleContext<WorkScriptParser::FunctionNameContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionDeclarationContext::STAR() {
  return getTokens(WorkScriptParser::STAR);
}

tree::TerminalNode* WorkScriptParser::FunctionDeclarationContext::STAR(size_t i) {
  return getToken(WorkScriptParser::STAR, i);
}


size_t WorkScriptParser::FunctionDeclarationContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionDeclaration;
}


antlrcpp::Any WorkScriptParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionDeclarationContext* WorkScriptParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, WorkScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(241);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
        | (1ULL << WorkScriptParser::INCLUDE)
        | (1ULL << WorkScriptParser::WHEN)
        | (1ULL << WorkScriptParser::BOOLEAN)
        | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
        setState(240);
        functionName();
      }
      break;
    }

    case 2: {
      setState(243);
      typeName();
      setState(247);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(244);
        match(WorkScriptParser::STAR);
        setState(249);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(250);
      functionName();
      break;
    }

    }
    setState(254);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(255);
    formalParameter();
    setState(256);
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
  enterRule(_localctx, 20, WorkScriptParser::RuleTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
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
  enterRule(_localctx, 22, WorkScriptParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterContext ------------------------------------------------------------------

WorkScriptParser::FormalParameterContext::FormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WorkScriptParser::FormalParameterContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FormalParameterContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}

std::vector<WorkScriptParser::FormalParameterItemContext *> WorkScriptParser::FormalParameterContext::formalParameterItem() {
  return getRuleContexts<WorkScriptParser::FormalParameterItemContext>();
}

WorkScriptParser::FormalParameterItemContext* WorkScriptParser::FormalParameterContext::formalParameterItem(size_t i) {
  return getRuleContext<WorkScriptParser::FormalParameterItemContext>(i);
}

std::vector<WorkScriptParser::NewlineOrCommaContext *> WorkScriptParser::FormalParameterContext::newlineOrComma() {
  return getRuleContexts<WorkScriptParser::NewlineOrCommaContext>();
}

WorkScriptParser::NewlineOrCommaContext* WorkScriptParser::FormalParameterContext::newlineOrComma(size_t i) {
  return getRuleContext<WorkScriptParser::NewlineOrCommaContext>(i);
}


size_t WorkScriptParser::FormalParameterContext::getRuleIndex() const {
  return WorkScriptParser::RuleFormalParameter;
}


antlrcpp::Any WorkScriptParser::FormalParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFormalParameter(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FormalParameterContext* WorkScriptParser::formalParameter() {
  FormalParameterContext *_localctx = _tracker.createInstance<FormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 24, WorkScriptParser::RuleFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(262);
      match(WorkScriptParser::NEWLINE);
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(277);
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
      setState(268);
      formalParameterItem();
      setState(274);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(269);
        newlineOrComma();
        setState(270);
        formalParameterItem();
        setState(276);
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
  enterRule(_localctx, 26, WorkScriptParser::RuleFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(279);
      typeName();
      setState(283);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(280);
        match(WorkScriptParser::STAR);
        setState(285);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(288);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionImplementationContext ------------------------------------------------------------------

WorkScriptParser::FunctionImplementationContext::FunctionImplementationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionImplementationContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationContext::RIGHT_ARROW() {
  return getToken(WorkScriptParser::RIGHT_ARROW, 0);
}

WorkScriptParser::BlockContext* WorkScriptParser::FunctionImplementationContext::block() {
  return getRuleContext<WorkScriptParser::BlockContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionImplementationContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionImplementationContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionImplementationContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionImplementation;
}


antlrcpp::Any WorkScriptParser::FunctionImplementationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionImplementation(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionImplementationContext* WorkScriptParser::functionImplementation() {
  FunctionImplementationContext *_localctx = _tracker.createInstance<FunctionImplementationContext>(_ctx, getState());
  enterRule(_localctx, 28, WorkScriptParser::RuleFunctionImplementation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(290);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(291);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(295);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(292);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(297);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
      }
      setState(299);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(298);
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
      setState(304);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(301);
        match(WorkScriptParser::NEWLINE);
        setState(306);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(307);
      block();
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

//----------------- FunctionConstraintContext ------------------------------------------------------------------

WorkScriptParser::FunctionConstraintContext::FunctionConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::FunctionConstraintContext::WHEN() {
  return getToken(WorkScriptParser::WHEN, 0);
}

WorkScriptParser::BlockContext* WorkScriptParser::FunctionConstraintContext::block() {
  return getRuleContext<WorkScriptParser::BlockContext>(0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionConstraintContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionConstraintContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionConstraintContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionConstraintContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionConstraint;
}


antlrcpp::Any WorkScriptParser::FunctionConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionConstraint(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionConstraintContext* WorkScriptParser::functionConstraint() {
  FunctionConstraintContext *_localctx = _tracker.createInstance<FunctionConstraintContext>(_ctx, getState());
  enterRule(_localctx, 30, WorkScriptParser::RuleFunctionConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(WorkScriptParser::WHEN);
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(311);
      match(WorkScriptParser::NEWLINE);
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(319);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(317);
        block();
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
        setState(318);
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

//----------------- BlockContext ------------------------------------------------------------------

WorkScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::BlockContext::LEFT_BRACE() {
  return getToken(WorkScriptParser::LEFT_BRACE, 0);
}

tree::TerminalNode* WorkScriptParser::BlockContext::RIGHT_BRACE() {
  return getToken(WorkScriptParser::RIGHT_BRACE, 0);
}

std::vector<WorkScriptParser::LineContext *> WorkScriptParser::BlockContext::line() {
  return getRuleContexts<WorkScriptParser::LineContext>();
}

WorkScriptParser::LineContext* WorkScriptParser::BlockContext::line(size_t i) {
  return getRuleContext<WorkScriptParser::LineContext>(i);
}


size_t WorkScriptParser::BlockContext::getRuleIndex() const {
  return WorkScriptParser::RuleBlock;
}


antlrcpp::Any WorkScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::BlockContext* WorkScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 32, WorkScriptParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(WorkScriptParser::LEFT_BRACE);
    setState(325);
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
      | (1ULL << WorkScriptParser::SEMICOLON)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(322);
      line();
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(328);
    match(WorkScriptParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StaticVarargsContext ------------------------------------------------------------------

WorkScriptParser::StaticVarargsContext::StaticVarargsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::StaticVarargsContext::APOSTROPHE() {
  return getToken(WorkScriptParser::APOSTROPHE, 0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::StaticVarargsContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::StaticVarargsContext::getRuleIndex() const {
  return WorkScriptParser::RuleStaticVarargs;
}


antlrcpp::Any WorkScriptParser::StaticVarargsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStaticVarargs(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StaticVarargsContext* WorkScriptParser::staticVarargs() {
  StaticVarargsContext *_localctx = _tracker.createInstance<StaticVarargsContext>(_ctx, getState());
  enterRule(_localctx, 34, WorkScriptParser::RuleStaticVarargs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(WorkScriptParser::APOSTROPHE);
    setState(331);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewlineOrCommaContext ------------------------------------------------------------------

WorkScriptParser::NewlineOrCommaContext::NewlineOrCommaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::NewlineOrCommaContext::COMMA() {
  return getToken(WorkScriptParser::COMMA, 0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::NewlineOrCommaContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::NewlineOrCommaContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::NewlineOrCommaContext::getRuleIndex() const {
  return WorkScriptParser::RuleNewlineOrComma;
}


antlrcpp::Any WorkScriptParser::NewlineOrCommaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNewlineOrComma(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::NewlineOrCommaContext* WorkScriptParser::newlineOrComma() {
  NewlineOrCommaContext *_localctx = _tracker.createInstance<NewlineOrCommaContext>(_ctx, getState());
  enterRule(_localctx, 36, WorkScriptParser::RuleNewlineOrComma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(333);
      match(WorkScriptParser::COMMA);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(335); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(334);
        match(WorkScriptParser::NEWLINE);
        setState(337); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == WorkScriptParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(342);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(339);
        match(WorkScriptParser::NEWLINE);
        setState(344);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(345);
      match(WorkScriptParser::COMMA);
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(346);
        match(WorkScriptParser::NEWLINE);
        setState(351);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
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
  enterRule(_localctx, 38, WorkScriptParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
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
  "program", "line", "expression", "call", "multiValue", "stdFunctionDecl", 
  "stdFormalParameter", "stdFormalParameterItem", "function", "functionDeclaration", 
  "typeName", "functionName", "formalParameter", "formalParameterItem", 
  "functionImplementation", "functionConstraint", "block", "staticVarargs", 
  "newlineOrComma", "identifier"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "'include'", "'when'", "", "", "", "", "", "';'", "'.'", "','", 
  "'('", "')'", "'{'", "'}'", "'['", "']'", "'=='", "'='", "'=>'", "':='", 
  "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'>'", "'>='", "'<'", 
  "'<='", "", "", "'...'", "'\n'"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "ACCESS_LEVEL", "INCLUDE", "WHEN", "BOOLEAN", "IDENTIFIER", "DOUBLE", 
  "INTEGER", "STRING", "SEMICOLON", "POINT", "COMMA", "LEFT_PARENTHESE", 
  "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", 
  "DOUBLE_EQUAL", "EQUALS", "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", 
  "STAR", "SLASH", "PERCENT", "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", 
  "LESS_THAN", "LESS_THAN_EQUAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", 
  "APOSTROPHE", "NEWLINE", "WS"
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
    0x3, 0x27, 0x167, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x3, 0x2, 0x7, 0x2, 0x2c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2f, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x34, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x37, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3b, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x3e, 0xb, 0x3, 0x6, 0x3, 0x40, 0xa, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0x41, 0x3, 0x3, 0x5, 0x3, 0x45, 0xa, 0x3, 0x3, 0x3, 0x6, 
    0x3, 0x48, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x49, 0x3, 0x3, 0x5, 0x3, 0x4d, 
    0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x50, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x5d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x67, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x78, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x7b, 0xb, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x7, 
    0x6, 0x83, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x86, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x8c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x8f, 0xb, 0x6, 0x5, 0x6, 0x91, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x95, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x98, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x7, 0x8, 0xa0, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0xa3, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x7, 0x8, 0xa9, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xac, 0xb, 0x8, 0x5, 0x8, 
    0xae, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xb3, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb7, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xba, 
    0xb, 0x9, 0x3, 0x9, 0x5, 0x9, 0xbd, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0xc1, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc4, 0xb, 0xa, 0x5, 0xa, 0xc6, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xca, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0xcd, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xd3, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xd6, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xda, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xdd, 0xb, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xe3, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0xe6, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xea, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0xed, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xf1, 0xa, 
    0xa, 0x3, 0xb, 0x5, 0xb, 0xf4, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0xf8, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xfb, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xff, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x7, 0xe, 0x10a, 0xa, 0xe, 
    0xc, 0xe, 0xe, 0xe, 0x10d, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x7, 0xe, 0x113, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x116, 0xb, 0xe, 
    0x5, 0xe, 0x118, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11c, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x11f, 0xb, 0xf, 0x5, 0xf, 0x121, 0xa, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x128, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x12b, 0xb, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x12e, 0xa, 0x10, 0x3, 0x10, 0x7, 0x10, 0x131, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x134, 0xb, 0x10, 0x3, 0x10, 0x5, 0x10, 0x137, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x13b, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0x13e, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x142, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x146, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x149, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x6, 0x14, 0x152, 0xa, 0x14, 0xd, 0x14, 0xe, 0x14, 
    0x153, 0x3, 0x14, 0x7, 0x14, 0x157, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x15a, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x15e, 0xa, 0x14, 
    0xc, 0x14, 0xe, 0x14, 0x161, 0xb, 0x14, 0x5, 0x14, 0x163, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x2, 0x3, 0x6, 0x16, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2, 0x8, 0x3, 0x2, 0x19, 0x1a, 0x3, 0x2, 
    0x8, 0x9, 0x3, 0x2, 0x1b, 0x1d, 0x4, 0x2, 0x14, 0x14, 0x1f, 0x22, 0x3, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x3, 0x7, 0x2, 0x192, 0x2, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x90, 0x3, 0x2, 0x2, 0x2, 0xc, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xfe, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x104, 0x3, 0x2, 0x2, 0x2, 0x18, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x136, 0x3, 0x2, 0x2, 0x2, 0x20, 0x138, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x24, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x26, 0x162, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x164, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 
    0x4, 0x3, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x31, 0x7, 0x2, 0x2, 0x3, 0x31, 0x3, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x34, 0x7, 0xb, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x3c, 0x5, 0x6, 0x4, 0x2, 0x39, 0x3b, 0x7, 0xb, 0x2, 
    0x2, 0x3a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x45, 0x7, 0x26, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x46, 0x48, 0x7, 0xb, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x7, 
    0x26, 0x2, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x7, 0x26, 0x2, 
    0x2, 0x4f, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x5, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x52, 0x8, 0x4, 0x1, 0x2, 0x52, 0x53, 0x7, 0x3, 0x2, 0x2, 0x53, 0x67, 
    0x7, 0x18, 0x2, 0x2, 0x54, 0x55, 0x7, 0xe, 0x2, 0x2, 0x55, 0x56, 0x5, 
    0x6, 0x4, 0x2, 0x56, 0x57, 0x7, 0xf, 0x2, 0x2, 0x57, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x67, 0x5, 0xc, 0x7, 0x2, 0x59, 0x67, 0x5, 0x12, 0xa, 
    0x2, 0x5a, 0x67, 0x5, 0x8, 0x5, 0x2, 0x5b, 0x5d, 0x9, 0x2, 0x2, 0x2, 
    0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x67, 0x9, 0x3, 0x2, 0x2, 0x5f, 0x60, 
    0x7, 0x1a, 0x2, 0x2, 0x60, 0x67, 0x5, 0x6, 0x4, 0xa, 0x61, 0x62, 0x7, 
    0x19, 0x2, 0x2, 0x62, 0x67, 0x5, 0x6, 0x4, 0x9, 0x63, 0x67, 0x7, 0xa, 
    0x2, 0x2, 0x64, 0x67, 0x7, 0x6, 0x2, 0x2, 0x65, 0x67, 0x5, 0x28, 0x15, 
    0x2, 0x66, 0x51, 0x3, 0x2, 0x2, 0x2, 0x66, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x58, 0x3, 0x2, 0x2, 0x2, 0x66, 0x59, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x66, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x61, 0x3, 0x2, 0x2, 0x2, 0x66, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x79, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0xc, 0xd, 0x2, 
    0x2, 0x69, 0x6a, 0x9, 0x4, 0x2, 0x2, 0x6a, 0x78, 0x5, 0x6, 0x4, 0xe, 
    0x6b, 0x6c, 0xc, 0xc, 0x2, 0x2, 0x6c, 0x6d, 0x9, 0x2, 0x2, 0x2, 0x6d, 
    0x78, 0x5, 0x6, 0x4, 0xd, 0x6e, 0x6f, 0xc, 0x8, 0x2, 0x2, 0x6f, 0x70, 
    0x7, 0x17, 0x2, 0x2, 0x70, 0x78, 0x5, 0x6, 0x4, 0x9, 0x71, 0x72, 0xc, 
    0x7, 0x2, 0x2, 0x72, 0x73, 0x7, 0x15, 0x2, 0x2, 0x73, 0x78, 0x5, 0x6, 
    0x4, 0x8, 0x74, 0x75, 0xc, 0x6, 0x2, 0x2, 0x75, 0x76, 0x9, 0x5, 0x2, 
    0x2, 0x76, 0x78, 0x5, 0x6, 0x4, 0x7, 0x77, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x77, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x77, 0x74, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x7d, 0x5, 0x28, 0x15, 0x2, 0x7d, 0x7e, 0x7, 0xe, 0x2, 
    0x2, 0x7e, 0x7f, 0x5, 0xa, 0x6, 0x2, 0x7f, 0x80, 0x7, 0xf, 0x2, 0x2, 
    0x80, 0x9, 0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 0x7, 0x26, 0x2, 0x2, 0x82, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8d, 0x5, 0x6, 
    0x4, 0x2, 0x88, 0x89, 0x5, 0x26, 0x14, 0x2, 0x89, 0x8a, 0x5, 0x6, 0x4, 
    0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x84, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0xb, 0x3, 0x2, 0x2, 0x2, 0x92, 0x96, 0x5, 0x16, 
    0xc, 0x2, 0x93, 0x95, 0x7, 0x1b, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x98, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x18, 0xd, 0x2, 0x9a, 0x9b, 
    0x7, 0xe, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x9d, 0x7, 
    0xf, 0x2, 0x2, 0x9d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x26, 
    0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xad, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xaa, 0x5, 0x10, 0x9, 0x2, 0xa5, 0xa6, 0x5, 0x26, 0x14, 0x2, 0xa6, 0xa7, 
    0x5, 0x10, 0x9, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x5, 0x26, 0x14, 0x2, 0xb0, 0xb1, 0x7, 0x25, 0x2, 0x2, 0xb1, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb8, 0x5, 0x16, 
    0xc, 0x2, 0xb5, 0xb7, 0x7, 0x1b, 0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x28, 0x15, 0x2, 0xbc, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xc2, 0x5, 0x20, 0x11, 0x2, 0xbf, 0xc1, 0x7, 0x26, 
    0x2, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0xcb, 0x5, 0x14, 0xb, 0x2, 0xc8, 0xca, 0x7, 
    0x26, 0x2, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0xcf, 0x5, 0x1e, 0x10, 0x2, 0xcf, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xd4, 0x5, 0x14, 0xb, 0x2, 0xd1, 0xd3, 0x7, 0x26, 0x2, 0x2, 0xd2, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xdb, 0x5, 0x20, 0x11, 
    0x2, 0xd8, 0xda, 0x7, 0x26, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x1e, 0x10, 0x2, 0xdf, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe4, 0x5, 0x14, 0xb, 0x2, 0xe1, 0xe3, 0x7, 0x26, 
    0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 
    0xeb, 0x5, 0x1e, 0x10, 0x2, 0xe8, 0xea, 0x7, 0x26, 0x2, 0x2, 0xe9, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x5, 0x20, 0x11, 
    0x2, 0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x18, 0xd, 0x2, 0xf3, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf9, 0x5, 0x16, 0xc, 0x2, 0xf6, 0xf8, 0x7, 0x1b, 
    0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x5, 0x18, 0xd, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0xe, 0x2, 0x2, 0x101, 0x102, 0x5, 
    0x1a, 0xe, 0x2, 0x102, 0x103, 0x7, 0xf, 0x2, 0x2, 0x103, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x105, 0x5, 0x28, 0x15, 0x2, 0x105, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x5, 0x28, 0x15, 0x2, 0x107, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x10a, 0x7, 0x26, 0x2, 0x2, 0x109, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x117, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x114, 0x5, 
    0x1c, 0xf, 0x2, 0x10f, 0x110, 0x5, 0x26, 0x14, 0x2, 0x110, 0x111, 0x5, 
    0x1c, 0xf, 0x2, 0x111, 0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11d, 0x5, 0x16, 0xc, 0x2, 0x11a, 0x11c, 0x7, 0x1b, 
    0x2, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x119, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x5, 0x6, 
    0x4, 0x2, 0x123, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x9, 0x6, 0x2, 
    0x2, 0x125, 0x137, 0x5, 0x6, 0x4, 0x2, 0x126, 0x128, 0x7, 0x26, 0x2, 
    0x2, 0x127, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 
    0x2, 0x12c, 0x12e, 0x9, 0x6, 0x2, 0x2, 0x12d, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x131, 0x7, 0x26, 0x2, 0x2, 0x130, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x134, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x5, 0x22, 0x12, 
    0x2, 0x136, 0x124, 0x3, 0x2, 0x2, 0x2, 0x136, 0x129, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13c, 0x7, 0x5, 0x2, 0x2, 
    0x139, 0x13b, 0x7, 0x26, 0x2, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x141, 0x3, 0x2, 0x2, 0x2, 
    0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x142, 0x5, 0x22, 0x12, 0x2, 
    0x140, 0x142, 0x5, 0x6, 0x4, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x21, 0x3, 0x2, 0x2, 0x2, 0x143, 
    0x147, 0x7, 0x10, 0x2, 0x2, 0x144, 0x146, 0x5, 0x4, 0x3, 0x2, 0x145, 
    0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 
    0x14b, 0x7, 0x11, 0x2, 0x2, 0x14b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x14d, 0x7, 0x25, 0x2, 0x2, 0x14d, 0x14e, 0x5, 0x28, 0x15, 0x2, 0x14e, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x163, 0x7, 0xd, 0x2, 0x2, 0x150, 0x152, 
    0x7, 0x26, 0x2, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x163, 0x3, 0x2, 0x2, 0x2, 0x155, 0x157, 
    0x7, 0x26, 0x2, 0x2, 0x156, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x15f, 0x7, 0xd, 0x2, 0x2, 0x15c, 0x15e, 
    0x7, 0x26, 0x2, 0x2, 0x15d, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x160, 0x163, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x158, 0x3, 0x2, 0x2, 0x2, 0x163, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x164, 0x165, 0x9, 0x7, 0x2, 0x2, 0x165, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x2d, 0x35, 0x3c, 0x41, 0x44, 0x49, 0x4c, 0x4f, 0x5c, 
    0x66, 0x77, 0x79, 0x84, 0x8d, 0x90, 0x96, 0xa1, 0xaa, 0xad, 0xb2, 0xb8, 
    0xbc, 0xc2, 0xc5, 0xcb, 0xd4, 0xdb, 0xe4, 0xeb, 0xf0, 0xf3, 0xf9, 0xfe, 
    0x10b, 0x114, 0x117, 0x11d, 0x120, 0x129, 0x12d, 0x132, 0x136, 0x13c, 
    0x141, 0x147, 0x153, 0x158, 0x15f, 0x162, 
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

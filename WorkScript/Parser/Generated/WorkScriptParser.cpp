
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
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
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
      setState(48);
      line();
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

//----------------- LineContext ------------------------------------------------------------------

WorkScriptParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::LineContext::NEWLINE() {
  return getToken(WorkScriptParser::NEWLINE, 0);
}

std::vector<WorkScriptParser::FunctionContext *> WorkScriptParser::LineContext::function() {
  return getRuleContexts<WorkScriptParser::FunctionContext>();
}

WorkScriptParser::FunctionContext* WorkScriptParser::LineContext::function(size_t i) {
  return getRuleContext<WorkScriptParser::FunctionContext>(i);
}

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::LineContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::LineContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
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
    setState(88);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(59);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == WorkScriptParser::SEMICOLON) {
                  setState(56);
                  match(WorkScriptParser::SEMICOLON);
                  setState(61);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(64);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
                case 1: {
                  setState(62);
                  function();
                  break;
                }

                case 2: {
                  setState(63);
                  expression(0);
                  break;
                }

                }
                setState(69);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(66);
                    match(WorkScriptParser::SEMICOLON); 
                  }
                  setState(71);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(74); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(77);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(76);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(80); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(79);
                match(WorkScriptParser::SEMICOLON);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(82); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(85);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(84);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
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

//----------------- FunctionContext ------------------------------------------------------------------

WorkScriptParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WorkScriptParser::FunctionContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunction;
}

void WorkScriptParser::FunctionContext::copyFrom(FunctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDefine_Context ------------------------------------------------------------------

WorkScriptParser::FunctionDefineContext* WorkScriptParser::FunctionDefine_Context::functionDefine() {
  return getRuleContext<WorkScriptParser::FunctionDefineContext>(0);
}

WorkScriptParser::FunctionDefine_Context::FunctionDefine_Context(FunctionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::FunctionDefine_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDefine_(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StdFunctionDecl_Context ------------------------------------------------------------------

WorkScriptParser::StdFunctionDeclContext* WorkScriptParser::StdFunctionDecl_Context::stdFunctionDecl() {
  return getRuleContext<WorkScriptParser::StdFunctionDeclContext>(0);
}

WorkScriptParser::StdFunctionDecl_Context::StdFunctionDecl_Context(FunctionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any WorkScriptParser::StdFunctionDecl_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStdFunctionDecl_(this);
  else
    return visitor->visitChildren(this);
}
WorkScriptParser::FunctionContext* WorkScriptParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, WorkScriptParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<WorkScriptParser::StdFunctionDecl_Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(90);
      stdFunctionDecl();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<WorkScriptParser::FunctionDefine_Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(91);
      functionDefine();
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, WorkScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(95);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(96);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(98);
      expression(0);
      setState(99);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Call_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(101);
      call();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::PLUS

      || _la == WorkScriptParser::MINUS) {
        setState(102);
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
      setState(105);
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

    case 5: {
      _localctx = _tracker.createInstance<NegativeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(106);
      match(WorkScriptParser::MINUS);
      setState(107);
      expression(8);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<PositiveContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(108);
      match(WorkScriptParser::PLUS);
      setState(109);
      expression(7);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(110);
      match(WorkScriptParser::STRING);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(111);
      match(WorkScriptParser::BOOLEAN);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(112);
      identifier();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(132);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(130);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(115);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(116);
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
          setState(117);
          expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(118);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(119);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(120);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(121);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(122);
          match(WorkScriptParser::ASSIGN);
          setState(123);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(124);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(125);
          match(WorkScriptParser::EQUALS);
          setState(126);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryCompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(127);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(128);
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
          setState(129);
          expression(5);
          break;
        }

        } 
      }
      setState(134);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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
  enterRule(_localctx, 8, WorkScriptParser::RuleCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    identifier();
    setState(136);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(137);
    multiValue();
    setState(138);
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
  enterRule(_localctx, 10, WorkScriptParser::RuleMultiValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(140);
        match(WorkScriptParser::NEWLINE);
        setState(145);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(146);
      expression(0);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(147);
        newlineOrComma();
        setState(148);
        expression(0);
        setState(154);
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

WorkScriptParser::TypeContext* WorkScriptParser::StdFunctionDeclContext::type() {
  return getRuleContext<WorkScriptParser::TypeContext>(0);
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
  enterRule(_localctx, 12, WorkScriptParser::RuleStdFunctionDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    type();
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(158);
      match(WorkScriptParser::STAR);
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(164);
    functionName();
    setState(165);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(166);
    stdFormalParameter();
    setState(167);
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
  enterRule(_localctx, 14, WorkScriptParser::RuleStdFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(172);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(169);
        match(WorkScriptParser::NEWLINE); 
      }
      setState(174);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
      | (1ULL << WorkScriptParser::IDENTIFIER))) != 0)) {
      setState(175);
      stdFormalParameterItem();
      setState(181);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(176);
          newlineOrComma();
          setState(177);
          stdFormalParameterItem(); 
        }
        setState(183);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      }
    }
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::COMMA

    || _la == WorkScriptParser::NEWLINE) {
      setState(186);
      newlineOrComma();
      setState(187);
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

WorkScriptParser::TypeContext* WorkScriptParser::StdFormalParameterItemContext::type() {
  return getRuleContext<WorkScriptParser::TypeContext>(0);
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
  enterRule(_localctx, 16, WorkScriptParser::RuleStdFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    type();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(192);
      match(WorkScriptParser::STAR);
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::IDENTIFIER) {
      setState(198);
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

//----------------- FunctionDefineContext ------------------------------------------------------------------

WorkScriptParser::FunctionDefineContext::FunctionDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::FunctionDeclarationContext* WorkScriptParser::FunctionDefineContext::functionDeclaration() {
  return getRuleContext<WorkScriptParser::FunctionDeclarationContext>(0);
}

WorkScriptParser::FunctionImplementationContext* WorkScriptParser::FunctionDefineContext::functionImplementation() {
  return getRuleContext<WorkScriptParser::FunctionImplementationContext>(0);
}

WorkScriptParser::FunctionConstraintContext* WorkScriptParser::FunctionDefineContext::functionConstraint() {
  return getRuleContext<WorkScriptParser::FunctionConstraintContext>(0);
}

std::vector<tree::TerminalNode *> WorkScriptParser::FunctionDefineContext::NEWLINE() {
  return getTokens(WorkScriptParser::NEWLINE);
}

tree::TerminalNode* WorkScriptParser::FunctionDefineContext::NEWLINE(size_t i) {
  return getToken(WorkScriptParser::NEWLINE, i);
}


size_t WorkScriptParser::FunctionDefineContext::getRuleIndex() const {
  return WorkScriptParser::RuleFunctionDefine;
}


antlrcpp::Any WorkScriptParser::FunctionDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDefine(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::FunctionDefineContext* WorkScriptParser::functionDefine() {
  FunctionDefineContext *_localctx = _tracker.createInstance<FunctionDefineContext>(_ctx, getState());
  enterRule(_localctx, 18, WorkScriptParser::RuleFunctionDefine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(208);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::WHEN) {
        setState(201);
        functionConstraint();
        setState(205);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(202);
          match(WorkScriptParser::NEWLINE);
          setState(207);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(210);
      functionDeclaration();
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(211);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(216);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      }
      setState(217);
      functionImplementation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(219);
      functionDeclaration();
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(220);
        match(WorkScriptParser::NEWLINE);
        setState(225);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(226);
      functionConstraint();
      setState(230);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(227);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(232);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
      setState(233);
      functionImplementation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(235);
      functionDeclaration();
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(236);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(241);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      setState(242);
      functionImplementation();
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(243);
        match(WorkScriptParser::NEWLINE);
        setState(248);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(249);
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

WorkScriptParser::TypeContext* WorkScriptParser::FunctionDeclarationContext::type() {
  return getRuleContext<WorkScriptParser::TypeContext>(0);
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
  enterRule(_localctx, 20, WorkScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::IDENTIFIER) {
        setState(253);
        functionName();
      }
      break;
    }

    case 2: {
      setState(256);
      type();
      setState(260);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(257);
        match(WorkScriptParser::STAR);
        setState(262);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(263);
      functionName();
      break;
    }

    }
    setState(267);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(268);
    formalParameter();
    setState(269);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

WorkScriptParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WorkScriptParser::TypeQualifierContext *> WorkScriptParser::TypeContext::typeQualifier() {
  return getRuleContexts<WorkScriptParser::TypeQualifierContext>();
}

WorkScriptParser::TypeQualifierContext* WorkScriptParser::TypeContext::typeQualifier(size_t i) {
  return getRuleContext<WorkScriptParser::TypeQualifierContext>(i);
}

std::vector<WorkScriptParser::TypeSpecifierContext *> WorkScriptParser::TypeContext::typeSpecifier() {
  return getRuleContexts<WorkScriptParser::TypeSpecifierContext>();
}

WorkScriptParser::TypeSpecifierContext* WorkScriptParser::TypeContext::typeSpecifier(size_t i) {
  return getRuleContext<WorkScriptParser::TypeSpecifierContext>(i);
}

std::vector<WorkScriptParser::StorageClassSpecifierContext *> WorkScriptParser::TypeContext::storageClassSpecifier() {
  return getRuleContexts<WorkScriptParser::StorageClassSpecifierContext>();
}

WorkScriptParser::StorageClassSpecifierContext* WorkScriptParser::TypeContext::storageClassSpecifier(size_t i) {
  return getRuleContext<WorkScriptParser::StorageClassSpecifierContext>(i);
}


size_t WorkScriptParser::TypeContext::getRuleIndex() const {
  return WorkScriptParser::RuleType;
}


antlrcpp::Any WorkScriptParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::TypeContext* WorkScriptParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 22, WorkScriptParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(274); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(274);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case WorkScriptParser::CONST:
                case WorkScriptParser::VOLATILE: {
                  setState(271);
                  typeQualifier();
                  break;
                }

                case WorkScriptParser::IDENTIFIER: {
                  setState(272);
                  typeSpecifier();
                  break;
                }

                case WorkScriptParser::EXTERN:
                case WorkScriptParser::STATIC: {
                  setState(273);
                  storageClassSpecifier();
                  break;
                }

              default:
                throw NoViableAltException(this);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(276); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

WorkScriptParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::IdentifierContext* WorkScriptParser::TypeSpecifierContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}


size_t WorkScriptParser::TypeSpecifierContext::getRuleIndex() const {
  return WorkScriptParser::RuleTypeSpecifier;
}


antlrcpp::Any WorkScriptParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::TypeSpecifierContext* WorkScriptParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 24, WorkScriptParser::RuleTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierContext ------------------------------------------------------------------

WorkScriptParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::CONST() {
  return getToken(WorkScriptParser::CONST, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::VOLATILE() {
  return getToken(WorkScriptParser::VOLATILE, 0);
}


size_t WorkScriptParser::TypeQualifierContext::getRuleIndex() const {
  return WorkScriptParser::RuleTypeQualifier;
}


antlrcpp::Any WorkScriptParser::TypeQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitTypeQualifier(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::TypeQualifierContext* WorkScriptParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 26, WorkScriptParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    _la = _input->LA(1);
    if (!(_la == WorkScriptParser::CONST

    || _la == WorkScriptParser::VOLATILE)) {
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

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

WorkScriptParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::StorageClassSpecifierContext::STATIC() {
  return getToken(WorkScriptParser::STATIC, 0);
}

tree::TerminalNode* WorkScriptParser::StorageClassSpecifierContext::EXTERN() {
  return getToken(WorkScriptParser::EXTERN, 0);
}


size_t WorkScriptParser::StorageClassSpecifierContext::getRuleIndex() const {
  return WorkScriptParser::RuleStorageClassSpecifier;
}


antlrcpp::Any WorkScriptParser::StorageClassSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitStorageClassSpecifier(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::StorageClassSpecifierContext* WorkScriptParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 28, WorkScriptParser::RuleStorageClassSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    _la = _input->LA(1);
    if (!(_la == WorkScriptParser::EXTERN

    || _la == WorkScriptParser::STATIC)) {
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
  enterRule(_localctx, 30, WorkScriptParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
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
  enterRule(_localctx, 32, WorkScriptParser::RuleFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(286);
      match(WorkScriptParser::NEWLINE);
      setState(291);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(292);
      formalParameterItem();
      setState(298);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(293);
        newlineOrComma();
        setState(294);
        formalParameterItem();
        setState(300);
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

WorkScriptParser::TypeContext* WorkScriptParser::FormalParameterItemContext::type() {
  return getRuleContext<WorkScriptParser::TypeContext>(0);
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
  enterRule(_localctx, 34, WorkScriptParser::RuleFormalParameterItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(303);
      type();
      setState(307);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(304);
        match(WorkScriptParser::STAR);
        setState(309);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(312);
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
  enterRule(_localctx, 36, WorkScriptParser::RuleFunctionImplementation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(314);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(315);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(316);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(321);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      }
      setState(323);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(322);
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
      setState(328);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(325);
        match(WorkScriptParser::NEWLINE);
        setState(330);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(331);
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
  enterRule(_localctx, 38, WorkScriptParser::RuleFunctionConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    match(WorkScriptParser::WHEN);
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(335);
      match(WorkScriptParser::NEWLINE);
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(343);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(341);
        block();
        break;
      }

      case WorkScriptParser::ACCESS_LEVEL:
      case WorkScriptParser::BOOLEAN:
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::DOUBLE:
      case WorkScriptParser::INTEGER:
      case WorkScriptParser::STRING:
      case WorkScriptParser::LEFT_PARENTHESE:
      case WorkScriptParser::PLUS:
      case WorkScriptParser::MINUS: {
        setState(342);
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
  enterRule(_localctx, 40, WorkScriptParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    match(WorkScriptParser::LEFT_BRACE);
    setState(349);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
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
      setState(346);
      line();
      setState(351);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(352);
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
  enterRule(_localctx, 42, WorkScriptParser::RuleStaticVarargs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
    match(WorkScriptParser::APOSTROPHE);
    setState(355);
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
  enterRule(_localctx, 44, WorkScriptParser::RuleNewlineOrComma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      match(WorkScriptParser::COMMA);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(358);
        match(WorkScriptParser::NEWLINE);
        setState(361); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == WorkScriptParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(363);
        match(WorkScriptParser::NEWLINE);
        setState(368);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(369);
      match(WorkScriptParser::COMMA);
      setState(373);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(370);
        match(WorkScriptParser::NEWLINE);
        setState(375);
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
  enterRule(_localctx, 46, WorkScriptParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(WorkScriptParser::IDENTIFIER);
   
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
    case 3: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
  "program", "line", "function", "expression", "call", "multiValue", "stdFunctionDecl", 
  "stdFormalParameter", "stdFormalParameterItem", "functionDefine", "functionDeclaration", 
  "type", "typeSpecifier", "typeQualifier", "storageClassSpecifier", "functionName", 
  "formalParameter", "formalParameterItem", "functionImplementation", "functionConstraint", 
  "block", "staticVarargs", "newlineOrComma", "identifier"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "'include'", "'when'", "'const'", "'volatile'", "'extern'", "'static'", 
  "", "", "", "", "", "';'", "'.'", "','", "'('", "')'", "'{'", "'}'", "'['", 
  "']'", "'=='", "'='", "'=>'", "':='", "':'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'#'", "'>'", "'>='", "'<'", "'<='", "", "", "'...'", "'\n'"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "ACCESS_LEVEL", "INCLUDE", "WHEN", "CONST", "VOLATILE", "EXTERN", 
  "STATIC", "BOOLEAN", "IDENTIFIER", "DOUBLE", "INTEGER", "STRING", "SEMICOLON", 
  "POINT", "COMMA", "LEFT_PARENTHESE", "RIGHT_PARENTHESE", "LEFT_BRACE", 
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "DOUBLE_EQUAL", "EQUALS", 
  "RIGHT_ARROW", "ASSIGN", "COLON", "PLUS", "MINUS", "STAR", "SLASH", "PERCENT", 
  "HASH", "GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", 
  "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "APOSTROPHE", "NEWLINE", "WS"
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
    0x3, 0x2b, 0x17f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 
    0x3c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3f, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x43, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0x46, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x49, 0xb, 0x3, 0x6, 0x3, 0x4b, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0x4c, 0x3, 0x3, 0x5, 0x3, 0x50, 0xa, 0x3, 0x3, 0x3, 0x6, 0x3, 0x53, 
    0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x54, 0x3, 0x3, 0x5, 0x3, 0x58, 0xa, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x5b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5f, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6a, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x74, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x85, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x88, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x7, 0x7, 0x90, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x93, 0xb, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x99, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0x9c, 0xb, 0x7, 0x5, 0x7, 0x9e, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0xa2, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xa5, 0xb, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x7, 0x9, 0xad, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb0, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0xb6, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb9, 0xb, 
    0x9, 0x5, 0x9, 0xbb, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0xc0, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc4, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xc7, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 0xca, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xce, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xd1, 0xb, 0xb, 
    0x5, 0xb, 0xd3, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xd7, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xda, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0xe0, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xe3, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x7, 0xb, 0xe7, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xea, 0xb, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xf0, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xf3, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xf7, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xfa, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xfe, 0xa, 0xb, 0x3, 0xc, 0x5, 0xc, 0x101, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x105, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x108, 0xb, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x10c, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 0x115, 0xa, 
    0xd, 0xd, 0xd, 0xe, 0xd, 0x116, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x7, 0x12, 0x122, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x125, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x12b, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x12e, 0xb, 0x12, 0x5, 0x12, 0x130, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x134, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x137, 0xb, 0x13, 
    0x5, 0x13, 0x139, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0x140, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x143, 
    0xb, 0x14, 0x3, 0x14, 0x5, 0x14, 0x146, 0xa, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x149, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x14c, 0xb, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x14f, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x153, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x156, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x15a, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x15e, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x161, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x6, 0x18, 0x16a, 
    0xa, 0x18, 0xd, 0x18, 0xe, 0x18, 0x16b, 0x3, 0x18, 0x7, 0x18, 0x16f, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x172, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x7, 0x18, 0x176, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x179, 0xb, 0x18, 
    0x5, 0x18, 0x17b, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x2, 0x3, 
    0x8, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x2, 0x9, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 
    0x1f, 0x21, 0x4, 0x2, 0x18, 0x18, 0x23, 0x26, 0x3, 0x2, 0x6, 0x7, 0x3, 
    0x2, 0x8, 0x9, 0x3, 0x2, 0x19, 0x1a, 0x2, 0x1a9, 0x2, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5e, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x73, 0x3, 0x2, 0x2, 0x2, 0xa, 0x89, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x10, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x14, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x20, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x24, 0x138, 0x3, 0x2, 0x2, 0x2, 0x26, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x150, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x15b, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x164, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x5, 0x4, 0x3, 
    0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3c, 0x7, 
    0xf, 0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x42, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x43, 0x5, 0x6, 0x4, 0x2, 0x41, 0x43, 0x5, 0x8, 0x5, 0x2, 0x42, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x7, 0xf, 0x2, 0x2, 0x45, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 
    0x7, 0x2a, 0x2, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x7, 0xf, 
    0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x57, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x7, 0x2a, 0x2, 0x2, 0x57, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x7, 0x2a, 0x2, 0x2, 0x5a, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x52, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x5, 0xe, 0x8, 
    0x2, 0x5d, 0x5f, 0x5, 0x14, 0xb, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x61, 0x8, 0x5, 0x1, 0x2, 0x61, 0x62, 0x7, 0x3, 0x2, 0x2, 0x62, 0x74, 
    0x7, 0x1c, 0x2, 0x2, 0x63, 0x64, 0x7, 0x12, 0x2, 0x2, 0x64, 0x65, 0x5, 
    0x8, 0x5, 0x2, 0x65, 0x66, 0x7, 0x13, 0x2, 0x2, 0x66, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x74, 0x5, 0xa, 0x6, 0x2, 0x68, 0x6a, 0x9, 0x2, 0x2, 
    0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x74, 0x9, 0x3, 0x2, 0x2, 0x6c, 
    0x6d, 0x7, 0x1e, 0x2, 0x2, 0x6d, 0x74, 0x5, 0x8, 0x5, 0xa, 0x6e, 0x6f, 
    0x7, 0x1d, 0x2, 0x2, 0x6f, 0x74, 0x5, 0x8, 0x5, 0x9, 0x70, 0x74, 0x7, 
    0xe, 0x2, 0x2, 0x71, 0x74, 0x7, 0xa, 0x2, 0x2, 0x72, 0x74, 0x5, 0x30, 
    0x19, 0x2, 0x73, 0x60, 0x3, 0x2, 0x2, 0x2, 0x73, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x67, 0x3, 0x2, 0x2, 0x2, 0x73, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x86, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0xc, 
    0xd, 0x2, 0x2, 0x76, 0x77, 0x9, 0x4, 0x2, 0x2, 0x77, 0x85, 0x5, 0x8, 
    0x5, 0xe, 0x78, 0x79, 0xc, 0xc, 0x2, 0x2, 0x79, 0x7a, 0x9, 0x2, 0x2, 
    0x2, 0x7a, 0x85, 0x5, 0x8, 0x5, 0xd, 0x7b, 0x7c, 0xc, 0x8, 0x2, 0x2, 
    0x7c, 0x7d, 0x7, 0x1b, 0x2, 0x2, 0x7d, 0x85, 0x5, 0x8, 0x5, 0x9, 0x7e, 
    0x7f, 0xc, 0x7, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x19, 0x2, 0x2, 0x80, 0x85, 
    0x5, 0x8, 0x5, 0x8, 0x81, 0x82, 0xc, 0x6, 0x2, 0x2, 0x82, 0x83, 0x9, 
    0x5, 0x2, 0x2, 0x83, 0x85, 0x5, 0x8, 0x5, 0x7, 0x84, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x78, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x9, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x30, 0x19, 0x2, 0x8a, 0x8b, 0x7, 
    0x12, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0xc, 0x7, 0x2, 0x8c, 0x8d, 0x7, 0x13, 
    0x2, 0x2, 0x8d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x7, 0x2a, 0x2, 
    0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x9a, 
    0x5, 0x8, 0x5, 0x2, 0x95, 0x96, 0x5, 0x2e, 0x18, 0x2, 0x96, 0x97, 0x5, 
    0x8, 0x5, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x91, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa3, 
    0x5, 0x18, 0xd, 0x2, 0xa0, 0xa2, 0x7, 0x1f, 0x2, 0x2, 0xa1, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x20, 0x11, 0x2, 
    0xa7, 0xa8, 0x7, 0x12, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x10, 0x9, 0x2, 0xa9, 
    0xaa, 0x7, 0x13, 0x2, 0x2, 0xaa, 0xf, 0x3, 0x2, 0x2, 0x2, 0xab, 0xad, 
    0x7, 0x2a, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb7, 0x5, 0x12, 0xa, 0x2, 0xb2, 0xb3, 0x5, 0x2e, 0x18, 0x2, 
    0xb3, 0xb4, 0x5, 0x12, 0xa, 0x2, 0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbd, 0x5, 0x2e, 0x18, 0x2, 0xbd, 0xbe, 0x7, 0x29, 0x2, 0x2, 
    0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc5, 
    0x5, 0x18, 0xd, 0x2, 0xc2, 0xc4, 0x7, 0x1f, 0x2, 0x2, 0xc3, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x5, 0x30, 0x19, 0x2, 
    0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcf, 0x5, 0x28, 0x15, 0x2, 0xcc, 0xce, 
    0x7, 0x2a, 0x2, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd8, 0x5, 0x16, 0xc, 0x2, 0xd5, 
    0xd7, 0x7, 0x2a, 0x2, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdc, 0x5, 0x26, 0x14, 0x2, 0xdc, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xe1, 0x5, 0x16, 0xc, 0x2, 0xde, 0xe0, 0x7, 0x2a, 0x2, 0x2, 
    0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe8, 0x5, 
    0x28, 0x15, 0x2, 0xe5, 0xe7, 0x7, 0x2a, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x26, 0x14, 0x2, 0xec, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf1, 0x5, 0x16, 0xc, 0x2, 0xee, 0xf0, 
    0x7, 0x2a, 0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xf8, 0x5, 0x26, 0x14, 0x2, 0xf5, 0xf7, 0x7, 0x2a, 0x2, 0x2, 
    0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x5, 
    0x28, 0x15, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0x15, 0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x5, 0x20, 0x11, 0x2, 
    0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x102, 0x106, 0x5, 0x18, 0xd, 0x2, 0x103, 
    0x105, 0x7, 0x1f, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x3, 0x2, 0x2, 0x2, 0x108, 
    0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x20, 0x11, 0x2, 0x10a, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x100, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x10e, 0x7, 0x12, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x22, 0x12, 0x2, 0x10f, 
    0x110, 0x7, 0x13, 0x2, 0x2, 0x110, 0x17, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x115, 0x5, 0x1c, 0xf, 0x2, 0x112, 0x115, 0x5, 0x1a, 0xe, 0x2, 0x113, 
    0x115, 0x5, 0x1e, 0x10, 0x2, 0x114, 0x111, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x19, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
    0x5, 0x30, 0x19, 0x2, 0x119, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 
    0x9, 0x6, 0x2, 0x2, 0x11b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x9, 
    0x7, 0x2, 0x2, 0x11d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x30, 
    0x19, 0x2, 0x11f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x120, 0x122, 0x7, 0x2a, 
    0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x12c, 0x5, 0x24, 0x13, 0x2, 0x127, 0x128, 0x5, 0x2e, 
    0x18, 0x2, 0x128, 0x129, 0x5, 0x24, 0x13, 0x2, 0x129, 0x12b, 0x3, 0x2, 
    0x2, 0x2, 0x12a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12f, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x23, 0x3, 0x2, 0x2, 0x2, 0x131, 0x135, 0x5, 0x18, 
    0xd, 0x2, 0x132, 0x134, 0x7, 0x1f, 0x2, 0x2, 0x133, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x131, 0x3, 0x2, 
    0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x13b, 0x5, 0x8, 0x5, 0x2, 0x13b, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x13c, 0x13d, 0x9, 0x8, 0x2, 0x2, 0x13d, 0x14f, 0x5, 0x8, 0x5, 
    0x2, 0x13e, 0x140, 0x7, 0x2a, 0x2, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x146, 0x9, 0x8, 0x2, 
    0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 
    0x2, 0x146, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x147, 0x149, 0x7, 0x2a, 0x2, 
    0x2, 0x148, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x14f, 0x5, 0x2a, 0x16, 0x2, 0x14e, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x154, 0x7, 0x5, 0x2, 0x2, 0x151, 0x153, 0x7, 0x2a, 0x2, 0x2, 
    0x152, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x156, 0x3, 0x2, 0x2, 0x2, 
    0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x159, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 0x2, 0x2, 
    0x157, 0x15a, 0x5, 0x2a, 0x16, 0x2, 0x158, 0x15a, 0x5, 0x8, 0x5, 0x2, 
    0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15f, 0x7, 0x14, 0x2, 0x2, 
    0x15c, 0x15e, 0x5, 0x4, 0x3, 0x2, 0x15d, 0x15c, 0x3, 0x2, 0x2, 0x2, 
    0x15e, 0x161, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x7, 0x15, 0x2, 0x2, 
    0x163, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x7, 0x29, 0x2, 0x2, 
    0x165, 0x166, 0x5, 0x30, 0x19, 0x2, 0x166, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x167, 0x17b, 0x7, 0x11, 0x2, 0x2, 0x168, 0x16a, 0x7, 0x2a, 0x2, 0x2, 
    0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16f, 0x7, 0x2a, 0x2, 0x2, 
    0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x173, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x177, 0x7, 0x11, 0x2, 0x2, 0x174, 0x176, 0x7, 0x2a, 0x2, 0x2, 
    0x175, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 0x179, 0x3, 0x2, 0x2, 0x2, 
    0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x178, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x167, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x169, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x170, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17d, 0x7, 0xb, 0x2, 0x2, 0x17d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 
    0x3d, 0x42, 0x47, 0x4c, 0x4f, 0x54, 0x57, 0x5a, 0x5e, 0x69, 0x73, 0x84, 
    0x86, 0x91, 0x9a, 0x9d, 0xa3, 0xae, 0xb7, 0xba, 0xbf, 0xc5, 0xc9, 0xcf, 
    0xd2, 0xd8, 0xe1, 0xe8, 0xf1, 0xf8, 0xfd, 0x100, 0x106, 0x10b, 0x114, 
    0x116, 0x123, 0x12c, 0x12f, 0x135, 0x138, 0x141, 0x145, 0x14a, 0x14e, 
    0x154, 0x159, 0x15f, 0x16b, 0x170, 0x177, 0x17a, 
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

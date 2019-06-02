
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


//----------------- ModuleContext ------------------------------------------------------------------

WorkScriptParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::ModuleContext::EOF() {
  return getToken(WorkScriptParser::EOF, 0);
}

std::vector<WorkScriptParser::LineContext *> WorkScriptParser::ModuleContext::line() {
  return getRuleContexts<WorkScriptParser::LineContext>();
}

WorkScriptParser::LineContext* WorkScriptParser::ModuleContext::line(size_t i) {
  return getRuleContext<WorkScriptParser::LineContext>(i);
}


size_t WorkScriptParser::ModuleContext::getRuleIndex() const {
  return WorkScriptParser::RuleModule;
}

antlrcpp::Any WorkScriptParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ModuleContext* WorkScriptParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 0, WorkScriptParser::RuleModule);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
      | (1ULL << WorkScriptParser::SHORT)
      | (1ULL << WorkScriptParser::LONG)
      | (1ULL << WorkScriptParser::SIGNED)
      | (1ULL << WorkScriptParser::UNSIGNED)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::SEMICOLON)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(50);
      line();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
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
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(74); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(61);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == WorkScriptParser::SEMICOLON) {
                  setState(58);
                  match(WorkScriptParser::SEMICOLON);
                  setState(63);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(66);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
                case 1: {
                  setState(64);
                  function();
                  break;
                }

                case 2: {
                  setState(65);
                  expression(0);
                  break;
                }

                }
                setState(71);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(68);
                    match(WorkScriptParser::SEMICOLON); 
                  }
                  setState(73);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(76); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(79);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(78);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(81);
                match(WorkScriptParser::SEMICOLON);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(84); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(87);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(86);
        match(WorkScriptParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(89);
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
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<WorkScriptParser::StdFunctionDecl_Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(92);
      stdFunctionDecl();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FunctionContext *>(_tracker.createInstance<WorkScriptParser::FunctionDefine_Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(93);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, WorkScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AccessLevelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(97);
      match(WorkScriptParser::ACCESS_LEVEL);
      setState(98);
      match(WorkScriptParser::COLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParentheseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(99);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(100);
      expression(0);
      setState(101);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Call_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      call();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(105);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::PLUS

      || _la == WorkScriptParser::MINUS) {
        setState(104);
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
      setState(107);
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
      setState(108);
      match(WorkScriptParser::MINUS);
      setState(109);
      expression(8);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<PositiveContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(110);
      match(WorkScriptParser::PLUS);
      setState(111);
      expression(7);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(112);
      match(WorkScriptParser::STRING);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(113);
      match(WorkScriptParser::BOOLEAN);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(114);
      identifier();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(134);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(132);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideModulusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(117);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(118);
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
          setState(119);
          expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(120);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(121);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(122);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(123);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(124);
          match(WorkScriptParser::ASSIGN);
          setState(125);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(126);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(127);
          match(WorkScriptParser::EQUALS);
          setState(128);
          expression(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryCompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(129);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(130);
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
          setState(131);
          expression(5);
          break;
        }

        } 
      }
      setState(136);
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
    setState(137);
    identifier();
    setState(138);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(139);
    multiValue();
    setState(140);
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
    setState(157);
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
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(142);
        match(WorkScriptParser::NEWLINE);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(148);
      expression(0);
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(149);
        newlineOrComma();
        setState(150);
        expression(0);
        setState(156);
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
    setState(159);
    type();
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(160);
      match(WorkScriptParser::STAR);
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(166);
    functionName();
    setState(167);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(168);
    stdFormalParameter();
    setState(169);
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

WorkScriptParser::RuntimeVarargsContext* WorkScriptParser::StdFormalParameterContext::runtimeVarargs() {
  return getRuleContext<WorkScriptParser::RuntimeVarargsContext>(0);
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
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::CONST:
      case WorkScriptParser::VOLATILE:
      case WorkScriptParser::EXTERN:
      case WorkScriptParser::STATIC:
      case WorkScriptParser::SHORT:
      case WorkScriptParser::LONG:
      case WorkScriptParser::SIGNED:
      case WorkScriptParser::UNSIGNED:
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::COMMA:
      case WorkScriptParser::RIGHT_PARENTHESE:
      case WorkScriptParser::LEFT_BRACKET:
      case WorkScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 1);
        setState(174);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(171);
            match(WorkScriptParser::NEWLINE); 
          }
          setState(176);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        }

        setState(186);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
          | (1ULL << WorkScriptParser::VOLATILE)
          | (1ULL << WorkScriptParser::EXTERN)
          | (1ULL << WorkScriptParser::STATIC)
          | (1ULL << WorkScriptParser::SHORT)
          | (1ULL << WorkScriptParser::LONG)
          | (1ULL << WorkScriptParser::SIGNED)
          | (1ULL << WorkScriptParser::UNSIGNED)
          | (1ULL << WorkScriptParser::IDENTIFIER)
          | (1ULL << WorkScriptParser::LEFT_BRACKET))) != 0)) {
          setState(177);
          stdFormalParameterItem();
          setState(183);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(178);
              newlineOrComma();
              setState(179);
              stdFormalParameterItem(); 
            }
            setState(185);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
          }
        }
        setState(191);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WorkScriptParser::COMMA

        || _la == WorkScriptParser::NEWLINE) {
          setState(188);
          newlineOrComma();
          setState(189);
          runtimeVarargs();
        }
        break;
      }

      case WorkScriptParser::APOSTROPHE: {
        enterOuterAlt(_localctx, 2);
        setState(193);
        runtimeVarargs();
        setState(197);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(194);
          match(WorkScriptParser::NEWLINE);
          setState(199);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
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
    setState(202);
    type();
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::STAR) {
      setState(203);
      match(WorkScriptParser::STAR);
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::IDENTIFIER) {
      setState(209);
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
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::WHEN) {
        setState(212);
        functionConstraint();
        setState(216);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(213);
          match(WorkScriptParser::NEWLINE);
          setState(218);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(221);
      functionDeclaration();
      setState(225);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(222);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(227);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
      setState(228);
      functionImplementation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(230);
      functionDeclaration();
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(231);
        match(WorkScriptParser::NEWLINE);
        setState(236);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(237);
      functionConstraint();
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(238);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(243);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      }
      setState(244);
      functionImplementation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(246);
      functionDeclaration();
      setState(250);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(247);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(252);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }
      setState(253);
      functionImplementation();
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(254);
        match(WorkScriptParser::NEWLINE);
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(260);
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
    setState(276);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(265);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::IDENTIFIER) {
        setState(264);
        functionName();
      }
      break;
    }

    case 2: {
      setState(267);
      type();
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(268);
        match(WorkScriptParser::STAR);
        setState(273);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(274);
      functionName();
      break;
    }

    }
    setState(278);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(279);
    formalParameter();
    setState(280);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
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

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::STATIC() {
  return getToken(WorkScriptParser::STATIC, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::EXTERN() {
  return getToken(WorkScriptParser::EXTERN, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::CONST() {
  return getToken(WorkScriptParser::CONST, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::VOLATILE() {
  return getToken(WorkScriptParser::VOLATILE, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::LONG() {
  return getToken(WorkScriptParser::LONG, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::SHORT() {
  return getToken(WorkScriptParser::SHORT, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::SIGNED() {
  return getToken(WorkScriptParser::SIGNED, 0);
}

tree::TerminalNode* WorkScriptParser::TypeQualifierContext::UNSIGNED() {
  return getToken(WorkScriptParser::UNSIGNED, 0);
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
  enterRule(_localctx, 22, WorkScriptParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
      | (1ULL << WorkScriptParser::SHORT)
      | (1ULL << WorkScriptParser::LONG)
      | (1ULL << WorkScriptParser::SIGNED)
      | (1ULL << WorkScriptParser::UNSIGNED))) != 0))) {
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

//----------------- TypeContext ------------------------------------------------------------------

WorkScriptParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WorkScriptParser::TypeNameContext* WorkScriptParser::TypeContext::typeName() {
  return getRuleContext<WorkScriptParser::TypeNameContext>(0);
}

WorkScriptParser::ReferenceTypeContext* WorkScriptParser::TypeContext::referenceType() {
  return getRuleContext<WorkScriptParser::ReferenceTypeContext>(0);
}

std::vector<WorkScriptParser::TypeQualifierContext *> WorkScriptParser::TypeContext::typeQualifier() {
  return getRuleContexts<WorkScriptParser::TypeQualifierContext>();
}

WorkScriptParser::TypeQualifierContext* WorkScriptParser::TypeContext::typeQualifier(size_t i) {
  return getRuleContext<WorkScriptParser::TypeQualifierContext>(i);
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
  enterRule(_localctx, 24, WorkScriptParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
        | (1ULL << WorkScriptParser::VOLATILE)
        | (1ULL << WorkScriptParser::EXTERN)
        | (1ULL << WorkScriptParser::STATIC)
        | (1ULL << WorkScriptParser::SHORT)
        | (1ULL << WorkScriptParser::LONG)
        | (1ULL << WorkScriptParser::SIGNED)
        | (1ULL << WorkScriptParser::UNSIGNED))) != 0)) {
        setState(284);
        typeQualifier();
        setState(289);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(292);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::IDENTIFIER: {
          setState(290);
          typeName();
          break;
        }

        case WorkScriptParser::LEFT_BRACKET: {
          setState(291);
          referenceType();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
        | (1ULL << WorkScriptParser::VOLATILE)
        | (1ULL << WorkScriptParser::EXTERN)
        | (1ULL << WorkScriptParser::STATIC)
        | (1ULL << WorkScriptParser::SHORT)
        | (1ULL << WorkScriptParser::LONG)
        | (1ULL << WorkScriptParser::SIGNED)
        | (1ULL << WorkScriptParser::UNSIGNED))) != 0)) {
        setState(294);
        typeQualifier();
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(301); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(300);
        typeQualifier();
        setState(303); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::CONST)
        | (1ULL << WorkScriptParser::VOLATILE)
        | (1ULL << WorkScriptParser::EXTERN)
        | (1ULL << WorkScriptParser::STATIC)
        | (1ULL << WorkScriptParser::SHORT)
        | (1ULL << WorkScriptParser::LONG)
        | (1ULL << WorkScriptParser::SIGNED)
        | (1ULL << WorkScriptParser::UNSIGNED))) != 0));
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

//----------------- ReferenceTypeContext ------------------------------------------------------------------

WorkScriptParser::ReferenceTypeContext::ReferenceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::ReferenceTypeContext::LEFT_BRACKET() {
  return getToken(WorkScriptParser::LEFT_BRACKET, 0);
}

WorkScriptParser::TypeContext* WorkScriptParser::ReferenceTypeContext::type() {
  return getRuleContext<WorkScriptParser::TypeContext>(0);
}

tree::TerminalNode* WorkScriptParser::ReferenceTypeContext::RIGHT_BRACKET() {
  return getToken(WorkScriptParser::RIGHT_BRACKET, 0);
}


size_t WorkScriptParser::ReferenceTypeContext::getRuleIndex() const {
  return WorkScriptParser::RuleReferenceType;
}

antlrcpp::Any WorkScriptParser::ReferenceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitReferenceType(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::ReferenceTypeContext* WorkScriptParser::referenceType() {
  ReferenceTypeContext *_localctx = _tracker.createInstance<ReferenceTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, WorkScriptParser::RuleReferenceType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    match(WorkScriptParser::LEFT_BRACKET);
    setState(308);
    type();
    setState(309);
    match(WorkScriptParser::RIGHT_BRACKET);
   
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
  enterRule(_localctx, 28, WorkScriptParser::RuleTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
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
  enterRule(_localctx, 30, WorkScriptParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
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

WorkScriptParser::StaticVarargsContext* WorkScriptParser::FormalParameterContext::staticVarargs() {
  return getRuleContext<WorkScriptParser::StaticVarargsContext>(0);
}

WorkScriptParser::RuntimeVarargsContext* WorkScriptParser::FormalParameterContext::runtimeVarargs() {
  return getRuleContext<WorkScriptParser::RuntimeVarargsContext>(0);
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
    size_t alt;
    setState(353);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(315);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(320);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      }

      setState(330);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
        | (1ULL << WorkScriptParser::CONST)
        | (1ULL << WorkScriptParser::VOLATILE)
        | (1ULL << WorkScriptParser::EXTERN)
        | (1ULL << WorkScriptParser::STATIC)
        | (1ULL << WorkScriptParser::SHORT)
        | (1ULL << WorkScriptParser::LONG)
        | (1ULL << WorkScriptParser::SIGNED)
        | (1ULL << WorkScriptParser::UNSIGNED)
        | (1ULL << WorkScriptParser::BOOLEAN)
        | (1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::DOUBLE)
        | (1ULL << WorkScriptParser::INTEGER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
        | (1ULL << WorkScriptParser::LEFT_BRACKET)
        | (1ULL << WorkScriptParser::PLUS)
        | (1ULL << WorkScriptParser::MINUS))) != 0)) {
        setState(321);
        formalParameterItem();
        setState(327);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(322);
            newlineOrComma();
            setState(323);
            formalParameterItem(); 
          }
          setState(329);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
        }
      }
      setState(337);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::COMMA

      || _la == WorkScriptParser::NEWLINE) {
        setState(332);
        newlineOrComma();
        setState(335);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
        case 1: {
          setState(333);
          staticVarargs();
          break;
        }

        case 2: {
          setState(334);
          runtimeVarargs();
          break;
        }

        }
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(339);
      staticVarargs();
      setState(343);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(340);
        match(WorkScriptParser::NEWLINE);
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(346);
      runtimeVarargs();
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(347);
        match(WorkScriptParser::NEWLINE);
        setState(352);
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
    setState(362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(355);
      type();
      setState(359);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::STAR) {
        setState(356);
        match(WorkScriptParser::STAR);
        setState(361);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(364);
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
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      _la = _input->LA(1);
      if (!(_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(367);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(368);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(373);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(375);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS

      || _la == WorkScriptParser::RIGHT_ARROW) {
        setState(374);
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
      setState(380);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(377);
        match(WorkScriptParser::NEWLINE);
        setState(382);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(383);
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
    setState(386);
    match(WorkScriptParser::WHEN);
    setState(390);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(387);
      match(WorkScriptParser::NEWLINE);
      setState(392);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(395);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(393);
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
        setState(394);
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
    setState(397);
    match(WorkScriptParser::LEFT_BRACE);
    setState(401);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::ACCESS_LEVEL)
      | (1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::CONST)
      | (1ULL << WorkScriptParser::VOLATILE)
      | (1ULL << WorkScriptParser::EXTERN)
      | (1ULL << WorkScriptParser::STATIC)
      | (1ULL << WorkScriptParser::SHORT)
      | (1ULL << WorkScriptParser::LONG)
      | (1ULL << WorkScriptParser::SIGNED)
      | (1ULL << WorkScriptParser::UNSIGNED)
      | (1ULL << WorkScriptParser::BOOLEAN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::DOUBLE)
      | (1ULL << WorkScriptParser::INTEGER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::SEMICOLON)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS)
      | (1ULL << WorkScriptParser::NEWLINE))) != 0)) {
      setState(398);
      line();
      setState(403);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(404);
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
    setState(406);
    match(WorkScriptParser::APOSTROPHE);
    setState(407);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuntimeVarargsContext ------------------------------------------------------------------

WorkScriptParser::RuntimeVarargsContext::RuntimeVarargsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::RuntimeVarargsContext::APOSTROPHE() {
  return getToken(WorkScriptParser::APOSTROPHE, 0);
}


size_t WorkScriptParser::RuntimeVarargsContext::getRuleIndex() const {
  return WorkScriptParser::RuleRuntimeVarargs;
}

antlrcpp::Any WorkScriptParser::RuntimeVarargsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitRuntimeVarargs(this);
  else
    return visitor->visitChildren(this);
}

WorkScriptParser::RuntimeVarargsContext* WorkScriptParser::runtimeVarargs() {
  RuntimeVarargsContext *_localctx = _tracker.createInstance<RuntimeVarargsContext>(_ctx, getState());
  enterRule(_localctx, 44, WorkScriptParser::RuleRuntimeVarargs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(WorkScriptParser::APOSTROPHE);
   
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
  enterRule(_localctx, 46, WorkScriptParser::RuleNewlineOrComma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(430);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      match(WorkScriptParser::COMMA);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(413); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(412);
        match(WorkScriptParser::NEWLINE);
        setState(415); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == WorkScriptParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(417);
        match(WorkScriptParser::NEWLINE);
        setState(422);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(423);
      match(WorkScriptParser::COMMA);
      setState(427);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(424);
        match(WorkScriptParser::NEWLINE);
        setState(429);
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
  enterRule(_localctx, 48, WorkScriptParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
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
  "module", "line", "function", "expression", "call", "multiValue", "stdFunctionDecl",
  "stdFormalParameter", "stdFormalParameterItem", "functionDefine", "functionDeclaration", 
  "typeQualifier", "type", "referenceType", "typeName", "functionName", 
  "formalParameter", "formalParameterItem", "functionImplementation", "functionConstraint", 
  "block", "staticVarargs", "runtimeVarargs", "newlineOrComma", "identifier"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "", "'include'", "'when'", "'const'", "'volatile'", "'extern'", "'static'", 
  "'short'", "'long'", "'signed'", "'unsigned'", "", "", "", "", "", "';'", 
  "'.'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'=='", "'='", 
  "'=>'", "':='", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'>'", 
  "'>='", "'<'", "'<='", "", "", "'...'", "'\n'"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "ACCESS_LEVEL", "INCLUDE", "WHEN", "CONST", "VOLATILE", "EXTERN", 
  "STATIC", "SHORT", "LONG", "SIGNED", "UNSIGNED", "BOOLEAN", "IDENTIFIER", 
  "DOUBLE", "INTEGER", "STRING", "SEMICOLON", "POINT", "COMMA", "LEFT_PARENTHESE", 
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
    0x3, 0x2f, 0x1b5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x3, 0x2, 0x7, 0x2, 
    0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x39, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x7, 0x3, 0x3e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x45, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0x48, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4b, 0xb, 0x3, 0x6, 0x3, 0x4d, 0xa, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0x4e, 0x3, 0x3, 0x5, 0x3, 0x52, 0xa, 0x3, 0x3, 0x3, 
    0x6, 0x3, 0x55, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x56, 0x3, 0x3, 0x5, 0x3, 
    0x5a, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x5d, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x61, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6c, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x76, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x87, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x8a, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x7, 0x7, 0x92, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x95, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x9b, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x9e, 0xb, 0x7, 0x5, 0x7, 0xa0, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa4, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xa7, 
    0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x7, 0x9, 0xaf, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb2, 0xb, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb8, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0xbb, 0xb, 0x9, 0x5, 0x9, 0xbd, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0xc2, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xc6, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xc9, 0xb, 0x9, 0x5, 0x9, 0xcb, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0xcf, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xd2, 0xb, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xd5, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0xd9, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xdc, 0xb, 0xb, 0x5, 0xb, 0xde, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xe2, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0xe5, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0xeb, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xee, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0xf2, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xf5, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xfb, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0xfe, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x102, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0x105, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x109, 
    0xa, 0xb, 0x3, 0xc, 0x5, 0xc, 0x10c, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0x110, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x113, 0xb, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0x117, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x7, 0xe, 0x120, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x123, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x127, 0xa, 
    0xe, 0x3, 0xe, 0x7, 0xe, 0x12a, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x12d, 
    0xb, 0xe, 0x3, 0xe, 0x6, 0xe, 0x130, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x131, 
    0x5, 0xe, 0x134, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x7, 0x12, 0x13f, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x142, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x148, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x14b, 0xb, 0x12, 0x5, 0x12, 0x14d, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0x152, 0xa, 0x12, 0x5, 0x12, 0x154, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x158, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x15b, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x15f, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x162, 0xb, 0x12, 0x5, 0x12, 0x164, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x168, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x16b, 0xb, 0x13, 0x5, 0x13, 0x16d, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x174, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x177, 0xb, 0x14, 0x3, 0x14, 0x5, 0x14, 0x17a, 0xa, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0x17d, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x180, 
    0xb, 0x14, 0x3, 0x14, 0x5, 0x14, 0x183, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x7, 0x15, 0x187, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x18a, 0xb, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x18e, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x7, 0x16, 0x192, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x195, 0xb, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 0x1a0, 0xa, 0x19, 0xd, 0x19, 
    0xe, 0x19, 0x1a1, 0x3, 0x19, 0x7, 0x19, 0x1a5, 0xa, 0x19, 0xc, 0x19, 
    0xe, 0x19, 0x1a8, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x1ac, 
    0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x1af, 0xb, 0x19, 0x5, 0x19, 0x1b1, 
    0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x2, 0x3, 0x8, 0x1b, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x2, 
    0x8, 0x3, 0x2, 0x21, 0x22, 0x3, 0x2, 0x10, 0x11, 0x3, 0x2, 0x23, 0x25, 
    0x4, 0x2, 0x1c, 0x1c, 0x27, 0x2a, 0x3, 0x2, 0x6, 0xd, 0x3, 0x2, 0x1d, 
    0x1e, 0x2, 0x1e8, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x4, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x60, 0x3, 0x2, 0x2, 0x2, 0x8, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x8b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xca, 0x3, 0x2, 0x2, 0x2, 0x12, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x108, 0x3, 0x2, 0x2, 0x2, 0x16, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x135, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x22, 0x163, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x16c, 0x3, 0x2, 0x2, 0x2, 0x26, 0x182, 0x3, 0x2, 0x2, 0x2, 0x28, 0x184, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1b0, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x5, 0x4, 0x3, 
    0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 
    0x7, 0x2, 0x2, 0x3, 0x3b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 0x7, 
    0x13, 0x2, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x44, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x45, 0x5, 0x6, 0x4, 0x2, 0x43, 0x45, 0x5, 0x8, 0x5, 0x2, 0x44, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x7, 0x13, 0x2, 0x2, 0x47, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 
    0x7, 0x2e, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x7, 0x13, 
    0x2, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x59, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x7, 0x2e, 0x2, 0x2, 0x59, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0x2e, 0x2, 0x2, 0x5c, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x54, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x5, 0xe, 0x8, 
    0x2, 0x5f, 0x61, 0x5, 0x14, 0xb, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x7, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x63, 0x8, 0x5, 0x1, 0x2, 0x63, 0x64, 0x7, 0x3, 0x2, 0x2, 0x64, 0x76, 
    0x7, 0x20, 0x2, 0x2, 0x65, 0x66, 0x7, 0x16, 0x2, 0x2, 0x66, 0x67, 0x5, 
    0x8, 0x5, 0x2, 0x67, 0x68, 0x7, 0x17, 0x2, 0x2, 0x68, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x76, 0x5, 0xa, 0x6, 0x2, 0x6a, 0x6c, 0x9, 0x2, 0x2, 
    0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x76, 0x9, 0x3, 0x2, 0x2, 0x6e, 
    0x6f, 0x7, 0x22, 0x2, 0x2, 0x6f, 0x76, 0x5, 0x8, 0x5, 0xa, 0x70, 0x71, 
    0x7, 0x21, 0x2, 0x2, 0x71, 0x76, 0x5, 0x8, 0x5, 0x9, 0x72, 0x76, 0x7, 
    0x12, 0x2, 0x2, 0x73, 0x76, 0x7, 0xe, 0x2, 0x2, 0x74, 0x76, 0x5, 0x32, 
    0x1a, 0x2, 0x75, 0x62, 0x3, 0x2, 0x2, 0x2, 0x75, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x69, 0x3, 0x2, 0x2, 0x2, 0x75, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x75, 0x70, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x88, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0xc, 
    0xd, 0x2, 0x2, 0x78, 0x79, 0x9, 0x4, 0x2, 0x2, 0x79, 0x87, 0x5, 0x8, 
    0x5, 0xe, 0x7a, 0x7b, 0xc, 0xc, 0x2, 0x2, 0x7b, 0x7c, 0x9, 0x2, 0x2, 
    0x2, 0x7c, 0x87, 0x5, 0x8, 0x5, 0xd, 0x7d, 0x7e, 0xc, 0x8, 0x2, 0x2, 
    0x7e, 0x7f, 0x7, 0x1f, 0x2, 0x2, 0x7f, 0x87, 0x5, 0x8, 0x5, 0x9, 0x80, 
    0x81, 0xc, 0x7, 0x2, 0x2, 0x81, 0x82, 0x7, 0x1d, 0x2, 0x2, 0x82, 0x87, 
    0x5, 0x8, 0x5, 0x7, 0x83, 0x84, 0xc, 0x6, 0x2, 0x2, 0x84, 0x85, 0x9, 
    0x5, 0x2, 0x2, 0x85, 0x87, 0x5, 0x8, 0x5, 0x7, 0x86, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x80, 0x3, 0x2, 0x2, 0x2, 0x86, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x9, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x32, 0x1a, 0x2, 0x8c, 0x8d, 0x7, 
    0x16, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0xc, 0x7, 0x2, 0x8e, 0x8f, 0x7, 0x17, 
    0x2, 0x2, 0x8f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x2e, 0x2, 
    0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9c, 
    0x5, 0x8, 0x5, 0x2, 0x97, 0x98, 0x5, 0x30, 0x19, 0x2, 0x98, 0x99, 0x5, 
    0x8, 0x5, 0x2, 0x99, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa5, 
    0x5, 0x1a, 0xe, 0x2, 0xa2, 0xa4, 0x7, 0x23, 0x2, 0x2, 0xa3, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x20, 0x11, 0x2, 
    0xa9, 0xaa, 0x7, 0x16, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x10, 0x9, 0x2, 0xab, 
    0xac, 0x7, 0x17, 0x2, 0x2, 0xac, 0xf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 
    0x7, 0x2e, 0x2, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xb9, 0x5, 0x12, 0xa, 0x2, 0xb4, 0xb5, 0x5, 0x30, 0x19, 0x2, 
    0xb5, 0xb6, 0x5, 0x12, 0xa, 0x2, 0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x5, 0x30, 0x19, 0x2, 0xbf, 0xc0, 0x5, 0x2e, 0x18, 
    0x2, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xc7, 0x5, 0x2e, 0x18, 0x2, 0xc4, 0xc6, 0x7, 0x2e, 0x2, 0x2, 0xc5, 0xc4, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xd0, 0x5, 0x1a, 0xe, 0x2, 0xcd, 0xcf, 0x7, 0x23, 0x2, 0x2, 0xce, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x32, 
    0x1a, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xda, 0x5, 0x28, 0x15, 0x2, 
    0xd7, 0xd9, 0x7, 0x2e, 0x2, 0x2, 0xd8, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe3, 0x5, 0x16, 0xc, 
    0x2, 0xe0, 0xe2, 0x7, 0x2e, 0x2, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x26, 0x14, 0x2, 0xe7, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xec, 0x5, 0x16, 0xc, 0x2, 0xe9, 0xeb, 0x7, 0x2e, 
    0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf3, 0x5, 0x28, 0x15, 0x2, 0xf0, 0xf2, 0x7, 0x2e, 0x2, 0x2, 0xf1, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x26, 0x14, 
    0x2, 0xf7, 0x109, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfc, 0x5, 0x16, 0xc, 0x2, 
    0xf9, 0xfb, 0x7, 0x2e, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 
    0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0xff, 0x103, 0x5, 0x26, 0x14, 0x2, 0x100, 0x102, 0x7, 
    0x2e, 0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x5, 0x28, 0x15, 0x2, 0x107, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x108, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x109, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x10a, 0x10c, 0x5, 0x20, 0x11, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x111, 0x5, 0x1a, 0xe, 0x2, 0x10e, 0x110, 0x7, 0x23, 0x2, 
    0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x114, 0x115, 0x5, 0x20, 0x11, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x116, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x16, 0x2, 
    0x2, 0x119, 0x11a, 0x5, 0x22, 0x12, 0x2, 0x11a, 0x11b, 0x7, 0x17, 0x2, 
    0x2, 0x11b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x9, 0x6, 0x2, 0x2, 
    0x11d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x120, 0x5, 0x18, 0xd, 0x2, 
    0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x126, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x127, 0x5, 0x1e, 0x10, 0x2, 0x125, 0x127, 0x5, 0x1c, 0xf, 0x2, 
    0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x127, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12a, 0x5, 0x18, 0xd, 0x2, 
    0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x130, 0x5, 0x18, 0xd, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x121, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x7, 0x1a, 0x2, 0x2, 
    0x136, 0x137, 0x5, 0x1a, 0xe, 0x2, 0x137, 0x138, 0x7, 0x1b, 0x2, 0x2, 
    0x138, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x32, 0x1a, 0x2, 
    0x13a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x32, 0x1a, 0x2, 
    0x13c, 0x21, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13f, 0x7, 0x2e, 0x2, 0x2, 
    0x13e, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x149, 0x5, 0x24, 0x13, 0x2, 0x144, 0x145, 0x5, 0x30, 0x19, 0x2, 
    0x145, 0x146, 0x5, 0x24, 0x13, 0x2, 0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x144, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x143, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x153, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 0x5, 0x30, 0x19, 0x2, 
    0x14f, 0x152, 0x5, 0x2c, 0x17, 0x2, 0x150, 0x152, 0x5, 0x2e, 0x18, 0x2, 
    0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 
    0x152, 0x154, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x164, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x159, 0x5, 0x2c, 0x17, 0x2, 0x156, 0x158, 0x7, 0x2e, 0x2, 0x2, 
    0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 
    0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x164, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x160, 0x5, 0x2e, 0x18, 0x2, 0x15d, 0x15f, 0x7, 0x2e, 0x2, 0x2, 
    0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x140, 0x3, 0x2, 0x2, 0x2, 0x163, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x164, 0x23, 0x3, 0x2, 0x2, 0x2, 0x165, 
    0x169, 0x5, 0x1a, 0xe, 0x2, 0x166, 0x168, 0x7, 0x23, 0x2, 0x2, 0x167, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x167, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 
    0x16d, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x5, 0x8, 0x5, 0x2, 0x16f, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x9, 0x7, 0x2, 0x2, 0x171, 0x183, 
    0x5, 0x8, 0x5, 0x2, 0x172, 0x174, 0x7, 0x2e, 0x2, 0x2, 0x173, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 
    0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x179, 
    0x3, 0x2, 0x2, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 
    0x9, 0x7, 0x2, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 
    0x3, 0x2, 0x2, 0x2, 0x17a, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 
    0x7, 0x2e, 0x2, 0x2, 0x17c, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 
    0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x5, 0x2a, 0x16, 0x2, 0x182, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x182, 0x175, 0x3, 0x2, 0x2, 0x2, 0x183, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x184, 0x188, 0x7, 0x5, 0x2, 0x2, 0x185, 0x187, 0x7, 
    0x2e, 0x2, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18a, 0x3, 
    0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 
    0x2, 0x2, 0x2, 0x189, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x18b, 0x18e, 0x5, 0x2a, 0x16, 0x2, 0x18c, 0x18e, 0x5, 
    0x8, 0x5, 0x2, 0x18d, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x193, 0x7, 0x18, 
    0x2, 0x2, 0x190, 0x192, 0x5, 0x4, 0x3, 0x2, 0x191, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x195, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x7, 0x19, 
    0x2, 0x2, 0x197, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x2d, 
    0x2, 0x2, 0x199, 0x19a, 0x5, 0x32, 0x1a, 0x2, 0x19a, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x19c, 0x7, 0x2d, 0x2, 0x2, 0x19c, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x19d, 0x1b1, 0x7, 0x15, 0x2, 0x2, 0x19e, 0x1a0, 0x7, 0x2e, 
    0x2, 0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 
    0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 
    0x2, 0x2, 0x1a2, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a5, 0x7, 0x2e, 
    0x2, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 
    0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1a7, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 
    0x2, 0x2, 0x1a9, 0x1ad, 0x7, 0x15, 0x2, 0x2, 0x1aa, 0x1ac, 0x7, 0x2e, 
    0x2, 0x2, 0x1ab, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1af, 0x3, 0x2, 
    0x2, 0x2, 0x1ad, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 
    0x2, 0x2, 0x1ae, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 
    0x2, 0x2, 0x1b0, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x19f, 0x3, 0x2, 
    0x2, 0x2, 0x1b0, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b3, 0x7, 0xf, 0x2, 0x2, 0x1b3, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x37, 0x3f, 0x44, 0x49, 0x4e, 0x51, 0x56, 0x59, 0x5c, 0x60, 0x6b, 
    0x75, 0x86, 0x88, 0x93, 0x9c, 0x9f, 0xa5, 0xb0, 0xb9, 0xbc, 0xc1, 0xc7, 
    0xca, 0xd0, 0xd4, 0xda, 0xdd, 0xe3, 0xec, 0xf3, 0xfc, 0x103, 0x108, 
    0x10b, 0x111, 0x116, 0x121, 0x126, 0x12b, 0x131, 0x133, 0x140, 0x149, 
    0x14c, 0x151, 0x153, 0x159, 0x160, 0x163, 0x169, 0x16c, 0x175, 0x179, 
    0x17e, 0x182, 0x188, 0x18d, 0x193, 0x1a1, 0x1a6, 0x1ad, 0x1b0, 
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

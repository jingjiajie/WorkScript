
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

std::vector<tree::TerminalNode *> WorkScriptParser::ProgramContext::EOF() {
  return getTokens(WorkScriptParser::EOF);
}

tree::TerminalNode* WorkScriptParser::ProgramContext::EOF(size_t i) {
  return getToken(WorkScriptParser::EOF, i);
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
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::NEWLINE)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(28);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case WorkScriptParser::WHEN:
        case WorkScriptParser::IDENTIFIER:
        case WorkScriptParser::NUMBER:
        case WorkScriptParser::STRING:
        case WorkScriptParser::LEFT_PARENTHESE:
        case WorkScriptParser::LEFT_BRACKET:
        case WorkScriptParser::PLUS:
        case WorkScriptParser::MINUS: {
          setState(24);
          expression(0);
          setState(25);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::EOF

          || _la == WorkScriptParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case WorkScriptParser::NEWLINE: {
          setState(27);
          match(WorkScriptParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(33);
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
//----------------- MethodInvocationExpressionContext ------------------------------------------------------------------

WorkScriptParser::ExpressionContext* WorkScriptParser::MethodInvocationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* WorkScriptParser::MethodInvocationExpressionContext::POINT() {
  return getToken(WorkScriptParser::POINT, 0);
}

WorkScriptParser::IdentifierContext* WorkScriptParser::MethodInvocationExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
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

WorkScriptParser::IdentifierContext* WorkScriptParser::MemberEvaluateExpressionContext::identifier() {
  return getRuleContext<WorkScriptParser::IdentifierContext>(0);
}

WorkScriptParser::MemberEvaluateExpressionContext::MemberEvaluateExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::MemberEvaluateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitMemberEvaluateExpression(this);
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
//----------------- NonSignMultiplyExpressionContext ------------------------------------------------------------------

WorkScriptParser::NumberExpressionContext* WorkScriptParser::NonSignMultiplyExpressionContext::numberExpression() {
  return getRuleContext<WorkScriptParser::NumberExpressionContext>(0);
}

WorkScriptParser::VariableExpressionContext* WorkScriptParser::NonSignMultiplyExpressionContext::variableExpression() {
  return getRuleContext<WorkScriptParser::VariableExpressionContext>(0);
}

WorkScriptParser::NonSignMultiplyExpressionContext::NonSignMultiplyExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::NonSignMultiplyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitNonSignMultiplyExpression(this);
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
//----------------- EqualsExpressionContext ------------------------------------------------------------------

std::vector<WorkScriptParser::ExpressionContext *> WorkScriptParser::EqualsExpressionContext::expression() {
  return getRuleContexts<WorkScriptParser::ExpressionContext>();
}

WorkScriptParser::ExpressionContext* WorkScriptParser::EqualsExpressionContext::expression(size_t i) {
  return getRuleContext<WorkScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* WorkScriptParser::EqualsExpressionContext::DOUBLE_EQUAL() {
  return getToken(WorkScriptParser::DOUBLE_EQUAL, 0);
}

WorkScriptParser::EqualsExpressionContext::EqualsExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any WorkScriptParser::EqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WorkScriptVisitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
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
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParentheseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(37);
      match(WorkScriptParser::LEFT_PARENTHESE);
      setState(38);
      expression(0);
      setState(39);
      match(WorkScriptParser::RIGHT_PARENTHESE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ListExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(41);
      match(WorkScriptParser::LEFT_BRACKET);
      setState(50);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WorkScriptParser::WHEN)
        | (1ULL << WorkScriptParser::IDENTIFIER)
        | (1ULL << WorkScriptParser::NUMBER)
        | (1ULL << WorkScriptParser::STRING)
        | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
        | (1ULL << WorkScriptParser::LEFT_BRACKET)
        | (1ULL << WorkScriptParser::PLUS)
        | (1ULL << WorkScriptParser::MINUS))) != 0)) {
        setState(42);
        expression(0);
        setState(47);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::COMMA) {
          setState(43);
          match(WorkScriptParser::COMMA);
          setState(44);
          expression(0);
          setState(49);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(52);
      match(WorkScriptParser::RIGHT_BRACKET);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(53);
      functionExpression();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NonSignMultiplyExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      numberExpression();
      setState(55);
      variableExpression();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NumberExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(57);
      numberExpression();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegativeExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(58);
      match(WorkScriptParser::MINUS);
      setState(59);
      expression(8);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PositiveExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(60);
      match(WorkScriptParser::PLUS);
      setState(61);
      expression(7);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<StringExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(62);
      stringExpression();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<VariableExpression_Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(63);
      variableExpression();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(99);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyDivideExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(66);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(67);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::MULTIPLY

          || _la == WorkScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(68);
          expression(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(69);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(70);
          _la = _input->LA(1);
          if (!(_la == WorkScriptParser::PLUS

          || _la == WorkScriptParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(71);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(72);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(73);
          match(WorkScriptParser::ASSIGN);
          setState(74);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(75);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(76);
          match(WorkScriptParser::DOUBLE_EQUAL);
          setState(77);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AssignmentOrEqualsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(78);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(79);
          match(WorkScriptParser::EQUALS);
          setState(80);
          expression(5);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<CompareExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(81);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(82);
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
          setState(83);
          expression(4);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<FunctionInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(84);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(85);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(86);
          parameterExpression();
          setState(87);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<MethodInvocationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(89);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(90);
          match(WorkScriptParser::POINT);
          setState(91);
          identifier();
          setState(92);
          match(WorkScriptParser::LEFT_PARENTHESE);
          setState(93);
          parameterExpression();
          setState(94);
          match(WorkScriptParser::RIGHT_PARENTHESE);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<MemberEvaluateExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(96);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(97);
          match(WorkScriptParser::POINT);
          setState(98);
          identifier();
          break;
        }

        } 
      }
      setState(103);
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
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(104);
      expression(0);
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::COMMA) {
        setState(105);
        match(WorkScriptParser::COMMA);
        setState(106);
        expression(0);
        setState(111);
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

//----------------- NumberExpressionContext ------------------------------------------------------------------

WorkScriptParser::NumberExpressionContext::NumberExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WorkScriptParser::NumberExpressionContext::NUMBER() {
  return getToken(WorkScriptParser::NUMBER, 0);
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
  enterRule(_localctx, 6, WorkScriptParser::RuleNumberExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::PLUS

    || _la == WorkScriptParser::MINUS) {
      setState(114);
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
    setState(117);
    match(WorkScriptParser::NUMBER);
   
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
  enterRule(_localctx, 8, WorkScriptParser::RuleStringExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
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
  enterRule(_localctx, 10, WorkScriptParser::RuleVariableExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
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
  enterRule(_localctx, 12, WorkScriptParser::RuleFunctionExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(130);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(123);
        functionConstraintExpression();
        setState(127);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WorkScriptParser::NEWLINE) {
          setState(124);
          match(WorkScriptParser::NEWLINE);
          setState(129);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      }
      setState(132);
      functionDeclarationExpression();
      setState(136);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(133);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(138);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      setState(139);
      functionImplementationExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      functionDeclarationExpression();
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
      functionConstraintExpression();
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(149);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(154);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      }
      setState(155);
      functionImplementationExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(157);
      functionDeclarationExpression();
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(158);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(163);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      }
      setState(164);
      functionImplementationExpression();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(165);
        match(WorkScriptParser::NEWLINE);
        setState(170);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(171);
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

WorkScriptParser::ParameterExpressionContext* WorkScriptParser::FunctionDeclarationExpressionContext::parameterExpression() {
  return getRuleContext<WorkScriptParser::ParameterExpressionContext>(0);
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
  enterRule(_localctx, 14, WorkScriptParser::RuleFunctionDeclarationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WorkScriptParser::WHEN

    || _la == WorkScriptParser::IDENTIFIER) {
      setState(175);
      identifier();
    }
    setState(178);
    match(WorkScriptParser::LEFT_PARENTHESE);
    setState(179);
    parameterExpression();
    setState(180);
    match(WorkScriptParser::RIGHT_PARENTHESE);
   
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

tree::TerminalNode* WorkScriptParser::FunctionImplementationExpressionContext::EQUALS() {
  return getToken(WorkScriptParser::EQUALS, 0);
}

WorkScriptParser::ExpressionContext* WorkScriptParser::FunctionImplementationExpressionContext::expression() {
  return getRuleContext<WorkScriptParser::ExpressionContext>(0);
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
  enterRule(_localctx, 16, WorkScriptParser::RuleFunctionImplementationExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(182);
      match(WorkScriptParser::EQUALS);
      setState(183);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(184);
          match(WorkScriptParser::NEWLINE); 
        }
        setState(189);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      }
      setState(191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WorkScriptParser::EQUALS) {
        setState(190);
        match(WorkScriptParser::EQUALS);
      }
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WorkScriptParser::NEWLINE) {
        setState(193);
        match(WorkScriptParser::NEWLINE);
        setState(198);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(199);
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
  enterRule(_localctx, 18, WorkScriptParser::RuleFunctionConstraintExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(WorkScriptParser::WHEN);
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WorkScriptParser::NEWLINE) {
      setState(203);
      match(WorkScriptParser::NEWLINE);
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WorkScriptParser::LEFT_BRACE: {
        setState(209);
        blockExpression();
        break;
      }

      case WorkScriptParser::WHEN:
      case WorkScriptParser::IDENTIFIER:
      case WorkScriptParser::NUMBER:
      case WorkScriptParser::STRING:
      case WorkScriptParser::LEFT_PARENTHESE:
      case WorkScriptParser::LEFT_BRACKET:
      case WorkScriptParser::PLUS:
      case WorkScriptParser::MINUS: {
        setState(210);
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
  enterRule(_localctx, 20, WorkScriptParser::RuleBlockExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(WorkScriptParser::LEFT_BRACE);
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
    setState(232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WorkScriptParser::WHEN)
      | (1ULL << WorkScriptParser::IDENTIFIER)
      | (1ULL << WorkScriptParser::NUMBER)
      | (1ULL << WorkScriptParser::STRING)
      | (1ULL << WorkScriptParser::LEFT_PARENTHESE)
      | (1ULL << WorkScriptParser::LEFT_BRACKET)
      | (1ULL << WorkScriptParser::PLUS)
      | (1ULL << WorkScriptParser::MINUS))) != 0)) {
      setState(228);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(220);
          expression(0);
          setState(222); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(221);
            match(WorkScriptParser::NEWLINE);
            setState(224); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == WorkScriptParser::NEWLINE); 
        }
        setState(230);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
      setState(231);
      expression(0);
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
    setState(240);
    match(WorkScriptParser::RIGHT_BRACE);
   
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

tree::TerminalNode* WorkScriptParser::IdentifierContext::WHEN() {
  return getToken(WorkScriptParser::WHEN, 0);
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
  enterRule(_localctx, 22, WorkScriptParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    _la = _input->LA(1);
    if (!(_la == WorkScriptParser::WHEN

    || _la == WorkScriptParser::IDENTIFIER)) {
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
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WorkScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 17);
    case 7: return precpred(_ctx, 15);
    case 8: return precpred(_ctx, 14);

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
  "program", "expression", "parameterExpression", "numberExpression", "stringExpression", 
  "variableExpression", "functionExpression", "functionDeclarationExpression", 
  "functionImplementationExpression", "functionConstraintExpression", "blockExpression", 
  "identifier"
};

std::vector<std::string> WorkScriptParser::_literalNames = {
  "", "'when'", "", "", "", "'.'", "','", "", "'('", "')'", "'{'", "'}'", 
  "'['", "']'", "'=='", "'='", "':='", "'+'", "'-'", "'*'", "'/'", "'>'", 
  "'>='", "'<'", "'<='"
};

std::vector<std::string> WorkScriptParser::_symbolicNames = {
  "", "WHEN", "IDENTIFIER", "NUMBER", "STRING", "POINT", "COMMA", "NEWLINE", 
  "LEFT_PARENTHESE", "RIGHT_PARENTHESE", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", 
  "RIGHT_BRACKET", "DOUBLE_EQUAL", "EQUALS", "ASSIGN", "PLUS", "MINUS", 
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
    0x3, 0x1b, 0xf7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x1f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x22, 0xb, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x25, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x30, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x33, 0xb, 0x3, 0x5, 0x3, 0x35, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x43, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x66, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x69, 0xb, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x6e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x71, 0xb, 
    0x4, 0x5, 0x4, 0x73, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x76, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0x80, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x83, 0xb, 0x8, 0x5, 
    0x8, 0x85, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x89, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0x8c, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x7, 0x8, 0x92, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x95, 0xb, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x99, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x9c, 0xb, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa2, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0xa5, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa9, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0xac, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0xb0, 0xa, 0x8, 0x3, 0x9, 0x5, 0x9, 0xb3, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xbc, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0xbf, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc2, 0xa, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0xc5, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc8, 0xb, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xcb, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0xcf, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xd2, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xd6, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xda, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0xdd, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0xe1, 
    0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0xe2, 0x7, 0xc, 0xe5, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0xe8, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0xeb, 0xa, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0xee, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xf1, 0xb, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x2, 0x3, 0x4, 0xe, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x2, 0x7, 0x3, 
    0x3, 0x9, 0x9, 0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x13, 0x14, 0x3, 0x2, 
    0x17, 0x1a, 0x3, 0x2, 0x3, 0x4, 0x2, 0x118, 0x2, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x42, 0x3, 0x2, 0x2, 0x2, 0x6, 0x72, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0xa, 0x79, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xca, 0x3, 0x2, 0x2, 0x2, 0x14, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf4, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x1b, 0x5, 0x4, 0x3, 0x2, 0x1b, 0x1c, 0x9, 0x2, 0x2, 0x2, 
    0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1f, 0x7, 0x9, 0x2, 0x2, 0x1e, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x24, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 
    0x2, 0x2, 0x23, 0x25, 0x7, 0x2, 0x2, 0x3, 0x24, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x27, 0x8, 0x3, 0x1, 0x2, 0x27, 0x28, 0x7, 0xa, 0x2, 0x2, 0x28, 
    0x29, 0x5, 0x4, 0x3, 0x2, 0x29, 0x2a, 0x7, 0xb, 0x2, 0x2, 0x2a, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0x34, 0x7, 0xe, 0x2, 0x2, 0x2c, 0x31, 0x5, 
    0x4, 0x3, 0x2, 0x2d, 0x2e, 0x7, 0x8, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 
    0x3, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x43, 0x7, 0xf, 0x2, 0x2, 0x37, 0x43, 0x5, 
    0xe, 0x8, 0x2, 0x38, 0x39, 0x5, 0x8, 0x5, 0x2, 0x39, 0x3a, 0x5, 0xc, 
    0x7, 0x2, 0x3a, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x43, 0x5, 0x8, 0x5, 
    0x2, 0x3c, 0x3d, 0x7, 0x14, 0x2, 0x2, 0x3d, 0x43, 0x5, 0x4, 0x3, 0xa, 
    0x3e, 0x3f, 0x7, 0x13, 0x2, 0x2, 0x3f, 0x43, 0x5, 0x4, 0x3, 0x9, 0x40, 
    0x43, 0x5, 0xa, 0x6, 0x2, 0x41, 0x43, 0x5, 0xc, 0x7, 0x2, 0x42, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x38, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x67, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0xc, 0xe, 0x2, 0x2, 0x45, 
    0x46, 0x9, 0x3, 0x2, 0x2, 0x46, 0x66, 0x5, 0x4, 0x3, 0xf, 0x47, 0x48, 
    0xc, 0xc, 0x2, 0x2, 0x48, 0x49, 0x9, 0x4, 0x2, 0x2, 0x49, 0x66, 0x5, 
    0x4, 0x3, 0xd, 0x4a, 0x4b, 0xc, 0x8, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x12, 
    0x2, 0x2, 0x4c, 0x66, 0x5, 0x4, 0x3, 0x9, 0x4d, 0x4e, 0xc, 0x7, 0x2, 
    0x2, 0x4e, 0x4f, 0x7, 0x10, 0x2, 0x2, 0x4f, 0x66, 0x5, 0x4, 0x3, 0x8, 
    0x50, 0x51, 0xc, 0x6, 0x2, 0x2, 0x51, 0x52, 0x7, 0x11, 0x2, 0x2, 0x52, 
    0x66, 0x5, 0x4, 0x3, 0x7, 0x53, 0x54, 0xc, 0x5, 0x2, 0x2, 0x54, 0x55, 
    0x9, 0x5, 0x2, 0x2, 0x55, 0x66, 0x5, 0x4, 0x3, 0x6, 0x56, 0x57, 0xc, 
    0x13, 0x2, 0x2, 0x57, 0x58, 0x7, 0xa, 0x2, 0x2, 0x58, 0x59, 0x5, 0x6, 
    0x4, 0x2, 0x59, 0x5a, 0x7, 0xb, 0x2, 0x2, 0x5a, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x5c, 0xc, 0x11, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x7, 0x2, 0x2, 
    0x5d, 0x5e, 0x5, 0x18, 0xd, 0x2, 0x5e, 0x5f, 0x7, 0xa, 0x2, 0x2, 0x5f, 
    0x60, 0x5, 0x6, 0x4, 0x2, 0x60, 0x61, 0x7, 0xb, 0x2, 0x2, 0x61, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0xc, 0x10, 0x2, 0x2, 0x63, 0x64, 0x7, 
    0x7, 0x2, 0x2, 0x64, 0x66, 0x5, 0x18, 0xd, 0x2, 0x65, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x47, 0x3, 0x2, 0x2, 0x2, 0x65, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x65, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x53, 0x3, 0x2, 0x2, 0x2, 0x65, 0x56, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x65, 0x62, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x5, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6f, 0x5, 0x4, 0x3, 0x2, 0x6b, 0x6c, 0x7, 0x8, 0x2, 
    0x2, 0x6c, 0x6e, 0x5, 0x4, 0x3, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x7, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 0x9, 0x4, 
    0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x5, 0x2, 0x2, 
    0x78, 0x9, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x6, 0x2, 0x2, 0x7a, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x18, 0xd, 0x2, 0x7c, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x81, 0x5, 0x14, 0xb, 0x2, 0x7e, 0x80, 0x7, 
    0x9, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x8a, 0x5, 0x10, 0x9, 0x2, 0x87, 0x89, 
    0x7, 0x9, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x8e, 0x5, 0x12, 0xa, 0x2, 0x8e, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x93, 0x5, 0x10, 0x9, 0x2, 0x90, 0x92, 0x7, 0x9, 0x2, 0x2, 0x91, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9a, 0x5, 0x14, 
    0xb, 0x2, 0x97, 0x99, 0x7, 0x9, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x12, 0xa, 0x2, 0x9e, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa3, 0x5, 0x10, 0x9, 0x2, 0xa0, 0xa2, 0x7, 
    0x9, 0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xaa, 0x5, 0x12, 0xa, 0x2, 0xa7, 0xa9, 0x7, 0x9, 0x2, 0x2, 0xa8, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x5, 0x14, 
    0xb, 0x2, 0xae, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x18, 0xd, 0x2, 0xb2, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0xa, 0x2, 0x2, 0xb5, 0xb6, 0x5, 
    0x6, 0x4, 0x2, 0xb6, 0xb7, 0x7, 0xb, 0x2, 0x2, 0xb7, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb9, 0x7, 0x11, 0x2, 0x2, 0xb9, 0xcb, 0x5, 0x4, 0x3, 
    0x2, 0xba, 0xbc, 0x7, 0x9, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x7, 0x11, 0x2, 0x2, 0xc1, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xc5, 0x7, 0x9, 0x2, 0x2, 0xc4, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x16, 0xc, 0x2, 0xca, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xd0, 0x7, 0x3, 0x2, 0x2, 0xcd, 0xcf, 0x7, 0x9, 
    0x2, 0x2, 0xce, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd6, 0x5, 0x16, 0xc, 0x2, 0xd4, 0xd6, 0x5, 0x4, 0x3, 0x2, 0xd5, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xdb, 0x7, 0xc, 0x2, 0x2, 0xd8, 0xda, 0x7, 0x9, 
    0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xea, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0xe0, 0x5, 0x4, 0x3, 0x2, 0xdf, 0xe1, 0x7, 0x9, 0x2, 0x2, 0xe0, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xeb, 0x5, 0x4, 0x3, 0x2, 0xea, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xef, 0x3, 0x2, 0x2, 0x2, 0xec, 0xee, 0x7, 
    0x9, 0x2, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xf3, 0x7, 0xd, 0x2, 0x2, 0xf3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf5, 0x9, 0x6, 0x2, 0x2, 0xf5, 0x19, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1e, 
    0x20, 0x24, 0x31, 0x34, 0x42, 0x65, 0x67, 0x6f, 0x72, 0x75, 0x81, 0x84, 
    0x8a, 0x93, 0x9a, 0xa3, 0xaa, 0xaf, 0xb2, 0xbd, 0xc1, 0xc6, 0xca, 0xd0, 
    0xd5, 0xdb, 0xe2, 0xe6, 0xea, 0xef, 
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

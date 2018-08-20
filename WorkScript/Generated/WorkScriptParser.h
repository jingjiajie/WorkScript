
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptParser : public antlr4::Parser {
public:
  enum {
    IDENTIFIER = 1, NUMBER = 2, STRING = 3, POINT = 4, COMMA = 5, NEWLINE = 6, 
    LEFT_PARENTHESE = 7, RIGHT_PARENTHESE = 8, LEFT_BRACE = 9, RIGHT_BRACE = 10, 
    LEFT_BRACKET = 11, RIGHT_BRACKET = 12, EQUALS = 13, PLUS = 14, MINUS = 15, 
    MULTIPLY = 16, DIVIDE = 17, GREATER_THAN = 18, GREATER_THAN_EQUAL = 19, 
    LESS_THAN = 20, LESS_THAN_EQUAL = 21, WS = 22
  };

  enum {
    RuleProgram = 0, RuleExpression = 1, RuleParameterExpression = 2, RuleFunctionExpression = 3, 
    RuleBlockExpression = 4
  };

  WorkScriptParser(antlr4::TokenStream *input);
  ~WorkScriptParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ExpressionContext;
  class ParameterExpressionContext;
  class FunctionExpressionContext;
  class BlockExpressionContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParentheseExpressionContext : public ExpressionContext {
  public:
    ParentheseExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TermBlockExpressionContext : public ExpressionContext {
  public:
    TermBlockExpressionContext(ExpressionContext *ctx);

    BlockExpressionContext *blockExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListExpressionContext : public ExpressionContext {
  public:
    ListExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionInvocationExpressionContext : public ExpressionContext {
  public:
    FunctionInvocationExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ParameterExpressionContext *parameterExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExpressionContext : public ExpressionContext {
  public:
    NumberExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableExpressionContext : public ExpressionContext {
  public:
    VariableExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompareExpressionContext : public ExpressionContext {
  public:
    CompareExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *GREATER_THAN();
    antlr4::tree::TerminalNode *GREATER_THAN_EQUAL();
    antlr4::tree::TerminalNode *LESS_THAN();
    antlr4::tree::TerminalNode *LESS_THAN_EQUAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MethodInvocationExpressionContext : public ExpressionContext {
  public:
    MethodInvocationExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ParameterExpressionContext *parameterExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentExpressionContext : public ExpressionContext {
  public:
    AssignmentExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EQUALS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplyDivideExpressionContext : public ExpressionContext {
  public:
    MultiplyDivideExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberEvaluateExpressionContext : public ExpressionContext {
  public:
    MemberEvaluateExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringExpressionContext : public ExpressionContext {
  public:
    StringExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExpression_Context : public ExpressionContext {
  public:
    FunctionExpression_Context(ExpressionContext *ctx);

    FunctionExpressionContext *functionExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusMinusExpressionContext : public ExpressionContext {
  public:
    PlusMinusExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ParameterExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParameterExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterExpressionContext* parameterExpression();

  class  FunctionExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ParameterExpressionContext *parameterExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionExpressionContext* functionExpression();

  class  BlockExpressionContext : public antlr4::ParserRuleContext {
  public:
    BlockExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockExpressionContext* blockExpression();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};


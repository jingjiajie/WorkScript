
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
    RuleProgram = 0, RuleExpression = 1, RuleTermExpression = 2, RuleListExpression = 3, 
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
  class TermExpressionContext;
  class ListExpressionContext;
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
    virtual size_t getRuleIndex() const override;
    TermExpressionContext *termExpression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  TermExpressionContext : public antlr4::ParserRuleContext {
  public:
    TermExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TermExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParentheseExpressionContext : public TermExpressionContext {
  public:
    ParentheseExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    TermExpressionContext *termExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TermBlockExpressionContext : public TermExpressionContext {
  public:
    TermBlockExpressionContext(TermExpressionContext *ctx);

    BlockExpressionContext *blockExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionInvocationExpressionContext : public TermExpressionContext {
  public:
    FunctionInvocationExpressionContext(TermExpressionContext *ctx);

    TermExpressionContext *termExpression();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ListExpressionContext *listExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExpressionContext : public TermExpressionContext {
  public:
    NumberExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableExpressionContext : public TermExpressionContext {
  public:
    VariableExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompareExpressionContext : public TermExpressionContext {
  public:
    CompareExpressionContext(TermExpressionContext *ctx);

    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    antlr4::tree::TerminalNode *GREATER_THAN();
    antlr4::tree::TerminalNode *GREATER_THAN_EQUAL();
    antlr4::tree::TerminalNode *LESS_THAN();
    antlr4::tree::TerminalNode *LESS_THAN_EQUAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MethodInvocationExpressionContext : public TermExpressionContext {
  public:
    MethodInvocationExpressionContext(TermExpressionContext *ctx);

    TermExpressionContext *termExpression();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ListExpressionContext *listExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExpressionContext : public TermExpressionContext {
  public:
    FunctionExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ListExpressionContext *listExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    antlr4::tree::TerminalNode *EQUALS();
    TermExpressionContext *termExpression();
    BlockExpressionContext *blockExpression();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentExpressionContext : public TermExpressionContext {
  public:
    AssignmentExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQUALS();
    TermExpressionContext *termExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplyDivideExpressionContext : public TermExpressionContext {
  public:
    MultiplyDivideExpressionContext(TermExpressionContext *ctx);

    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberEvaluateExpressionContext : public TermExpressionContext {
  public:
    MemberEvaluateExpressionContext(TermExpressionContext *ctx);

    TermExpressionContext *termExpression();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringExpressionContext : public TermExpressionContext {
  public:
    StringExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusMinusExpressionContext : public TermExpressionContext {
  public:
    PlusMinusExpressionContext(TermExpressionContext *ctx);

    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermExpressionContext* termExpression();
  TermExpressionContext* termExpression(int precedence);
  class  ListExpressionContext : public antlr4::ParserRuleContext {
  public:
    ListExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListExpressionContext* listExpression();

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
  bool termExpressionSempred(TermExpressionContext *_localctx, size_t predicateIndex);

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


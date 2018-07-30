
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptParser : public antlr4::Parser {
public:
  enum {
    IDENTIFIER = 1, NUMBER = 2, STRING = 3, POINT = 4, COMMA = 5, NEWLINE = 6, 
    LEFT_PARENTHESE = 7, RIGHT_PARENTHESE = 8, LEFT_BRACE = 9, RIGHT_BRACE = 10, 
    EQUALS = 11, PLUS = 12, MINUS = 13, MULTIPLY = 14, DIVIDE = 15, GREATER_THAN = 16, 
    GREATER_THAN_EQUAL = 17, LESS_THAN = 18, LESS_THAN_EQUAL = 19, WS = 20
  };

  enum {
    RuleProgram = 0, RuleExpression = 1, RuleRelationExpression = 2, RulePolynomialExpression = 3, 
    RuleTermExpression = 4
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
  class RelationExpressionContext;
  class PolynomialExpressionContext;
  class TermExpressionContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *EOF();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *EOF();
    PolynomialExpressionContext *polynomialExpression();
    RelationExpressionContext *relationExpression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  RelationExpressionContext : public antlr4::ParserRuleContext {
  public:
    RelationExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PolynomialExpressionContext *> polynomialExpression();
    PolynomialExpressionContext* polynomialExpression(size_t i);
    antlr4::tree::TerminalNode *EQUALS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationExpressionContext* relationExpression();

  class  PolynomialExpressionContext : public antlr4::ParserRuleContext {
  public:
    PolynomialExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PolynomialExpressionContext* polynomialExpression();

  class  TermExpressionContext : public antlr4::ParserRuleContext {
  public:
    TermExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TermExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MemberEvaluateExpressionContext : public TermExpressionContext {
  public:
    MemberEvaluateExpressionContext(TermExpressionContext *ctx);

    std::vector<TermExpressionContext *> termExpression();
    TermExpressionContext* termExpression(size_t i);
    antlr4::tree::TerminalNode *POINT();
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

  class  StringExpressionContext : public TermExpressionContext {
  public:
    StringExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EvaluatedFunctionExpressionContext : public TermExpressionContext {
  public:
    EvaluatedFunctionExpressionContext(TermExpressionContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> LEFT_PARENTHESE();
    antlr4::tree::TerminalNode* LEFT_PARENTHESE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_PARENTHESE();
    antlr4::tree::TerminalNode* RIGHT_PARENTHESE(size_t i);
    std::vector<PolynomialExpressionContext *> polynomialExpression();
    PolynomialExpressionContext* polynomialExpression(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExpressionContext : public TermExpressionContext {
  public:
    NumberExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndependentParentheseExpressionContext : public TermExpressionContext {
  public:
    IndependentParentheseExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    PolynomialExpressionContext *polynomialExpression();
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

  class  DirectFunctionExpressionContext : public TermExpressionContext {
  public:
    DirectFunctionExpressionContext(TermExpressionContext *ctx);

    TermExpressionContext *termExpression();
    std::vector<antlr4::tree::TerminalNode *> LEFT_PARENTHESE();
    antlr4::tree::TerminalNode* LEFT_PARENTHESE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_PARENTHESE();
    antlr4::tree::TerminalNode* RIGHT_PARENTHESE(size_t i);
    std::vector<PolynomialExpressionContext *> polynomialExpression();
    PolynomialExpressionContext* polynomialExpression(size_t i);
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

  class  IdentifierExpressionContext : public TermExpressionContext {
  public:
    IdentifierExpressionContext(TermExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermExpressionContext* termExpression();
  TermExpressionContext* termExpression(int precedence);

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


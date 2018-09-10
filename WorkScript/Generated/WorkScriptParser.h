
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptParser : public antlr4::Parser {
public:
  enum {
    INCLUDE = 1, WHEN = 2, BOOLEAN = 3, IDENTIFIER = 4, DOUBLE = 5, INTEGER = 6, 
    STRING = 7, POINT = 8, COMMA = 9, NEWLINE = 10, LEFT_PARENTHESE = 11, 
    RIGHT_PARENTHESE = 12, LEFT_BRACE = 13, RIGHT_BRACE = 14, LEFT_BRACKET = 15, 
    RIGHT_BRACKET = 16, DOUBLE_EQUAL = 17, EQUALS = 18, RIGHT_ARROW = 19, 
    ASSIGN = 20, PLUS = 21, MINUS = 22, MULTIPLY = 23, DIVIDE = 24, MODULUS = 25, 
    HASH = 26, GREATER_THAN = 27, GREATER_THAN_EQUAL = 28, LESS_THAN = 29, 
    LESS_THAN_EQUAL = 30, SINGLE_LINE_COMMENT = 31, MULTILINE_COMMENT_IN_SINGLE_LINE = 32, 
    MULTILINE_COMMENT = 33, APOSTROPHE = 34, WS = 35
  };

  enum {
    RuleProgram = 0, RuleCommand = 1, RuleIncludeCommand = 2, RuleExpression = 3, 
    RuleParameterExpression = 4, RuleParameterExpressionItem = 5, RuleNumberExpression = 6, 
    RuleStringExpression = 7, RuleVariableExpression = 8, RuleFunctionExpression = 9, 
    RuleFunctionDeclarationExpression = 10, RuleFunctionImplementationExpression = 11, 
    RuleFunctionConstraintExpression = 12, RuleBlockExpression = 13, RuleBooleanExpression = 14, 
    RuleVarargsExpression = 15, RuleIdentifier = 16
  };

  WorkScriptParser(antlr4::TokenStream *input);
  ~WorkScriptParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class CommandContext;
  class IncludeCommandContext;
  class ExpressionContext;
  class ParameterExpressionContext;
  class ParameterExpressionItemContext;
  class NumberExpressionContext;
  class StringExpressionContext;
  class VariableExpressionContext;
  class FunctionExpressionContext;
  class FunctionDeclarationExpressionContext;
  class FunctionImplementationExpressionContext;
  class FunctionConstraintExpressionContext;
  class BlockExpressionContext;
  class BooleanExpressionContext;
  class VarargsExpressionContext;
  class IdentifierContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<CommandContext *> command();
    CommandContext* command(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IncludeCommandContext *includeCommand();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandContext* command();

  class  IncludeCommandContext : public antlr4::ParserRuleContext {
  public:
    IncludeCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HASH();
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeCommandContext* includeCommand();

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

  class  StringExpression_Context : public ExpressionContext {
  public:
    StringExpression_Context(ExpressionContext *ctx);

    StringExpressionContext *stringExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplyDivideModulusExpressionContext : public ExpressionContext {
  public:
    MultiplyDivideModulusExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MODULUS();
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

  class  VariableExpression_Context : public ExpressionContext {
  public:
    VariableExpression_Context(ExpressionContext *ctx);

    VariableExpressionContext *variableExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MethodInvocationExpressionContext : public ExpressionContext {
  public:
    MethodInvocationExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *POINT();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ParameterExpressionContext *parameterExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanExpression_Context : public ExpressionContext {
  public:
    BooleanExpression_Context(ExpressionContext *ctx);

    BooleanExpressionContext *booleanExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentOrEqualsExpressionContext : public ExpressionContext {
  public:
    AssignmentOrEqualsExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EQUALS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExpression_Context : public ExpressionContext {
  public:
    NumberExpression_Context(ExpressionContext *ctx);

    NumberExpressionContext *numberExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentExpressionContext : public ExpressionContext {
  public:
    AssignmentExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberEvaluateExpressionContext : public ExpressionContext {
  public:
    MemberEvaluateExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *POINT();
    IdentifierContext *identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositiveExpressionContext : public ExpressionContext {
  public:
    PositiveExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *PLUS();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExpression_Context : public ExpressionContext {
  public:
    FunctionExpression_Context(ExpressionContext *ctx);

    FunctionExpressionContext *functionExpression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NonSignMultiplyExpressionContext : public ExpressionContext {
  public:
    NonSignMultiplyExpressionContext(ExpressionContext *ctx);

    NumberExpressionContext *numberExpression();
    VariableExpressionContext *variableExpression();
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

  class  NegativeExpressionContext : public ExpressionContext {
  public:
    NegativeExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *MINUS();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqualsExpressionContext : public ExpressionContext {
  public:
    EqualsExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_EQUAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ParameterExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParameterExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterExpressionItemContext *> parameterExpressionItem();
    ParameterExpressionItemContext* parameterExpressionItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterExpressionContext* parameterExpression();

  class  ParameterExpressionItemContext : public antlr4::ParserRuleContext {
  public:
    ParameterExpressionItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    VarargsExpressionContext *varargsExpression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterExpressionItemContext* parameterExpressionItem();

  class  NumberExpressionContext : public antlr4::ParserRuleContext {
  public:
    NumberExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberExpressionContext* numberExpression();

  class  StringExpressionContext : public antlr4::ParserRuleContext {
  public:
    StringExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringExpressionContext* stringExpression();

  class  VariableExpressionContext : public antlr4::ParserRuleContext {
  public:
    VariableExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableExpressionContext* variableExpression();

  class  FunctionExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclarationExpressionContext *functionDeclarationExpression();
    FunctionImplementationExpressionContext *functionImplementationExpression();
    FunctionConstraintExpressionContext *functionConstraintExpression();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionExpressionContext* functionExpression();

  class  FunctionDeclarationExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ParameterExpressionContext *parameterExpression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclarationExpressionContext* functionDeclarationExpression();

  class  FunctionImplementationExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionImplementationExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *RIGHT_ARROW();
    BlockExpressionContext *blockExpression();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionImplementationExpressionContext* functionImplementationExpression();

  class  FunctionConstraintExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionConstraintExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    BlockExpressionContext *blockExpression();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionConstraintExpressionContext* functionConstraintExpression();

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

  class  BooleanExpressionContext : public antlr4::ParserRuleContext {
  public:
    BooleanExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanExpressionContext* booleanExpression();

  class  VarargsExpressionContext : public antlr4::ParserRuleContext {
  public:
    VarargsExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *APOSTROPHE();
    VariableExpressionContext *variableExpression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarargsExpressionContext* varargsExpression();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();


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


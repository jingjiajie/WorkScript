
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptParser : public antlr4::Parser {
public:
  enum {
    ACCESS_LEVEL = 1, INCLUDE = 2, WHEN = 3, CONST = 4, VOLATILE = 5, EXTERN = 6, 
    STATIC = 7, SHORT = 8, LONG = 9, SIGNED = 10, UNSIGNED = 11, BOOLEAN = 12, 
    IDENTIFIER = 13, DOUBLE = 14, INTEGER = 15, STRING = 16, SEMICOLON = 17, 
    POINT = 18, COMMA = 19, LEFT_PARENTHESE = 20, RIGHT_PARENTHESE = 21, 
    LEFT_BRACE = 22, RIGHT_BRACE = 23, LEFT_BRACKET = 24, RIGHT_BRACKET = 25, 
    DOUBLE_EQUAL = 26, EQUALS = 27, RIGHT_ARROW = 28, ASSIGN = 29, COLON = 30, 
    PLUS = 31, MINUS = 32, STAR = 33, SLASH = 34, PERCENT = 35, HASH = 36, 
    GREATER_THAN = 37, GREATER_THAN_EQUAL = 38, LESS_THAN = 39, LESS_THAN_EQUAL = 40, 
    SINGLE_LINE_COMMENT = 41, MULTILINE_COMMENT = 42, APOSTROPHE = 43, NEWLINE = 44, 
    WS = 45
  };

  enum {
    RuleModule = 0, RuleLine = 1, RuleFunction = 2, RuleExpression = 3,
    RuleCall = 4, RuleMultiValue = 5, RuleStdFunctionDecl = 6, RuleStdFormalParameter = 7, 
    RuleStdFormalParameterItem = 8, RuleFunctionDefine = 9, RuleFunctionDeclaration = 10, 
    RuleTypeQualifier = 11, RuleType = 12, RuleReferenceType = 13, RuleTypeName = 14, 
    RuleFunctionName = 15, RuleFormalParameter = 16, RuleFormalParameterItem = 17, 
    RuleFunctionImplementation = 18, RuleFunctionConstraint = 19, RuleBlock = 20, 
    RuleStaticVarargs = 21, RuleRuntimeVarargs = 22, RuleNewlineOrComma = 23, 
    RuleIdentifier = 24
  };

  WorkScriptParser(antlr4::TokenStream *input);
  ~WorkScriptParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ModuleContext;
  class LineContext;
  class FunctionContext;
  class ExpressionContext;
  class CallContext;
  class MultiValueContext;
  class StdFunctionDeclContext;
  class StdFormalParameterContext;
  class StdFormalParameterItemContext;
  class FunctionDefineContext;
  class FunctionDeclarationContext;
  class TypeQualifierContext;
  class TypeContext;
  class ReferenceTypeContext;
  class TypeNameContext;
  class FunctionNameContext;
  class FormalParameterContext;
  class FormalParameterItemContext;
  class FunctionImplementationContext;
  class FunctionConstraintContext;
  class BlockContext;
  class StaticVarargsContext;
  class RuntimeVarargsContext;
  class NewlineOrCommaContext;
  class IdentifierContext; 

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FunctionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FunctionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionDefine_Context : public FunctionContext {
  public:
    FunctionDefine_Context(FunctionContext *ctx);

    FunctionDefineContext *functionDefine();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StdFunctionDecl_Context : public FunctionContext {
  public:
    StdFunctionDecl_Context(FunctionContext *ctx);

    StdFunctionDeclContext *stdFunctionDecl();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FunctionContext* function();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryCompareContext : public ExpressionContext {
  public:
    BinaryCompareContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_EQUAL();
    antlr4::tree::TerminalNode *GREATER_THAN();
    antlr4::tree::TerminalNode *GREATER_THAN_EQUAL();
    antlr4::tree::TerminalNode *LESS_THAN();
    antlr4::tree::TerminalNode *LESS_THAN_EQUAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableContext : public ExpressionContext {
  public:
    VariableContext(ExpressionContext *ctx);

    IdentifierContext *identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplyDivideModulusContext : public ExpressionContext {
  public:
    MultiplyDivideModulusContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PERCENT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentOrEqualsContext : public ExpressionContext {
  public:
    AssignmentOrEqualsContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EQUALS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpressionContext {
  public:
    StringContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AccessLevelContext : public ExpressionContext {
  public:
    AccessLevelContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *ACCESS_LEVEL();
    antlr4::tree::TerminalNode *COLON();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusMinusContext : public ExpressionContext {
  public:
    PlusMinusContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentContext : public ExpressionContext {
  public:
    AssignmentContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberContext : public ExpressionContext {
  public:
    NumberContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeContext : public ExpressionContext {
  public:
    NegativeContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *MINUS();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositiveContext : public ExpressionContext {
  public:
    PositiveContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *PLUS();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParentheseContext : public ExpressionContext {
  public:
    ParentheseContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Call_Context : public ExpressionContext {
  public:
    Call_Context(ExpressionContext *ctx);

    CallContext *call();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanContext : public ExpressionContext {
  public:
    BooleanContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *BOOLEAN();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    MultiValueContext *multiValue();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallContext* call();

  class  MultiValueContext : public antlr4::ParserRuleContext {
  public:
    MultiValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<NewlineOrCommaContext *> newlineOrComma();
    NewlineOrCommaContext* newlineOrComma(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiValueContext* multiValue();

  class  StdFunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    StdFunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    FunctionNameContext *functionName();
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    StdFormalParameterContext *stdFormalParameter();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StdFunctionDeclContext* stdFunctionDecl();

  class  StdFormalParameterContext : public antlr4::ParserRuleContext {
  public:
    StdFormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StdFormalParameterItemContext *> stdFormalParameterItem();
    StdFormalParameterItemContext* stdFormalParameterItem(size_t i);
    std::vector<NewlineOrCommaContext *> newlineOrComma();
    NewlineOrCommaContext* newlineOrComma(size_t i);
    RuntimeVarargsContext *runtimeVarargs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StdFormalParameterContext* stdFormalParameter();

  class  StdFormalParameterItemContext : public antlr4::ParserRuleContext {
  public:
    StdFormalParameterItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StdFormalParameterItemContext* stdFormalParameterItem();

  class  FunctionDefineContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclarationContext *functionDeclaration();
    FunctionImplementationContext *functionImplementation();
    FunctionConstraintContext *functionConstraint();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefineContext* functionDefine();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PARENTHESE();
    FormalParameterContext *formalParameter();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESE();
    TypeContext *type();
    FunctionNameContext *functionName();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  TypeQualifierContext : public antlr4::ParserRuleContext {
  public:
    TypeQualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *VOLATILE();
    antlr4::tree::TerminalNode *LONG();
    antlr4::tree::TerminalNode *SHORT();
    antlr4::tree::TerminalNode *SIGNED();
    antlr4::tree::TerminalNode *UNSIGNED();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeQualifierContext* typeQualifier();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    ReferenceTypeContext *referenceType();
    std::vector<TypeQualifierContext *> typeQualifier();
    TypeQualifierContext* typeQualifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ReferenceTypeContext : public antlr4::ParserRuleContext {
  public:
    ReferenceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    TypeContext *type();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReferenceTypeContext* referenceType();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionNameContext* functionName();

  class  FormalParameterContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<FormalParameterItemContext *> formalParameterItem();
    FormalParameterItemContext* formalParameterItem(size_t i);
    std::vector<NewlineOrCommaContext *> newlineOrComma();
    NewlineOrCommaContext* newlineOrComma(size_t i);
    StaticVarargsContext *staticVarargs();
    RuntimeVarargsContext *runtimeVarargs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterContext* formalParameter();

  class  FormalParameterItemContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterItemContext* formalParameterItem();

  class  FunctionImplementationContext : public antlr4::ParserRuleContext {
  public:
    FunctionImplementationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *RIGHT_ARROW();
    BlockContext *block();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionImplementationContext* functionImplementation();

  class  FunctionConstraintContext : public antlr4::ParserRuleContext {
  public:
    FunctionConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    BlockContext *block();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionConstraintContext* functionConstraint();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StaticVarargsContext : public antlr4::ParserRuleContext {
  public:
    StaticVarargsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *APOSTROPHE();
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StaticVarargsContext* staticVarargs();

  class  RuntimeVarargsContext : public antlr4::ParserRuleContext {
  public:
    RuntimeVarargsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *APOSTROPHE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuntimeVarargsContext* runtimeVarargs();

  class  NewlineOrCommaContext : public antlr4::ParserRuleContext {
  public:
    NewlineOrCommaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewlineOrCommaContext* newlineOrComma();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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


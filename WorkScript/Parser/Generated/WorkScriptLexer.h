
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
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

  WorkScriptLexer(antlr4::CharStream *input);
  ~WorkScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};


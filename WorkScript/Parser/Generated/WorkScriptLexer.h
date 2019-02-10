
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
public:
  enum {
    ACCESS_LEVEL = 1, INCLUDE = 2, WHEN = 3, CONST = 4, VOLATILE = 5, EXTERN = 6, 
    STATIC = 7, BOOLEAN = 8, IDENTIFIER = 9, DOUBLE = 10, INTEGER = 11, 
    STRING = 12, SEMICOLON = 13, POINT = 14, COMMA = 15, LEFT_PARENTHESE = 16, 
    RIGHT_PARENTHESE = 17, LEFT_BRACE = 18, RIGHT_BRACE = 19, LEFT_BRACKET = 20, 
    RIGHT_BRACKET = 21, DOUBLE_EQUAL = 22, EQUALS = 23, RIGHT_ARROW = 24, 
    ASSIGN = 25, COLON = 26, PLUS = 27, MINUS = 28, STAR = 29, SLASH = 30, 
    PERCENT = 31, HASH = 32, GREATER_THAN = 33, GREATER_THAN_EQUAL = 34, 
    LESS_THAN = 35, LESS_THAN_EQUAL = 36, SINGLE_LINE_COMMENT = 37, MULTILINE_COMMENT = 38, 
    APOSTROPHE = 39, NEWLINE = 40, WS = 41
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



// Generated from WorkScript.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
public:
  enum {
    ACCESS_LEVEL = 1, INCLUDE = 2, WHEN = 3, BOOLEAN = 4, IDENTIFIER = 5, 
    DOUBLE = 6, INTEGER = 7, STRING = 8, SEMICOLON = 9, POINT = 10, COMMA = 11, 
    LEFT_PARENTHESE = 12, RIGHT_PARENTHESE = 13, LEFT_BRACE = 14, RIGHT_BRACE = 15, 
    LEFT_BRACKET = 16, RIGHT_BRACKET = 17, DOUBLE_EQUAL = 18, EQUALS = 19, 
    RIGHT_ARROW = 20, ASSIGN = 21, COLON = 22, PLUS = 23, MINUS = 24, STAR = 25, 
    SLASH = 26, PERCENT = 27, HASH = 28, GREATER_THAN = 29, GREATER_THAN_EQUAL = 30, 
    LESS_THAN = 31, LESS_THAN_EQUAL = 32, SINGLE_LINE_COMMENT = 33, MULTILINE_COMMENT = 34, 
    APOSTROPHE = 35, NEWLINE = 36, WS = 37
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


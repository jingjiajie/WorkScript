
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
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


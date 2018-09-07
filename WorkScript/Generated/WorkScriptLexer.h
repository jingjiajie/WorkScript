
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
public:
  enum {
    WHEN = 1, BOOLEAN = 2, IDENTIFIER = 3, DOUBLE = 4, INTEGER = 5, STRING = 6, 
    POINT = 7, COMMA = 8, NEWLINE = 9, LEFT_PARENTHESE = 10, RIGHT_PARENTHESE = 11, 
    LEFT_BRACE = 12, RIGHT_BRACE = 13, LEFT_BRACKET = 14, RIGHT_BRACKET = 15, 
    DOUBLE_EQUAL = 16, EQUALS = 17, RIGHT_ARROW = 18, ASSIGN = 19, PLUS = 20, 
    MINUS = 21, MULTIPLY = 22, DIVIDE = 23, MODULUS = 24, GREATER_THAN = 25, 
    GREATER_THAN_EQUAL = 26, LESS_THAN = 27, LESS_THAN_EQUAL = 28, SINGLE_LINE_COMMENT = 29, 
    MULTILINE_COMMENT_IN_SINGLE_LINE = 30, MULTILINE_COMMENT = 31, APOSTROPHE = 32, 
    WS = 33
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


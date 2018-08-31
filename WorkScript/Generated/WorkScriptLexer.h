
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
public:
  enum {
    WHEN = 1, IDENTIFIER = 2, NUMBER = 3, STRING = 4, POINT = 5, COMMA = 6, 
    NEWLINE = 7, LEFT_PARENTHESE = 8, RIGHT_PARENTHESE = 9, LEFT_BRACE = 10, 
    RIGHT_BRACE = 11, LEFT_BRACKET = 12, RIGHT_BRACKET = 13, DOUBLE_EQUAL = 14, 
    EQUALS = 15, ASSIGN = 16, PLUS = 17, MINUS = 18, MULTIPLY = 19, DIVIDE = 20, 
    MODULUS = 21, GREATER_THAN = 22, GREATER_THAN_EQUAL = 23, LESS_THAN = 24, 
    LESS_THAN_EQUAL = 25, WS = 26
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


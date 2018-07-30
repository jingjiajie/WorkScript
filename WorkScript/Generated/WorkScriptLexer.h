
// Generated from WorkScript.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  WorkScriptLexer : public antlr4::Lexer {
public:
  enum {
    IDENTIFIER = 1, NUMBER = 2, STRING = 3, POINT = 4, COMMA = 5, NEWLINE = 6, 
    LEFT_PARENTHESE = 7, RIGHT_PARENTHESE = 8, LEFT_BRACE = 9, RIGHT_BRACE = 10, 
    EQUALS = 11, PLUS = 12, MINUS = 13, MULTIPLY = 14, DIVIDE = 15, GREATER_THAN = 16, 
    GREATER_THAN_EQUAL = 17, LESS_THAN = 18, LESS_THAN_EQUAL = 19, WS = 20
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


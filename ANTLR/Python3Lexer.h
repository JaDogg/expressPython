
    #include<bits/stdc++.h>
    #include "Python3Parser.h"
    using namespace std;
    using namespace antlr4;


// Generated from Python3.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Python3Lexer : public antlr4::Lexer {
public:
  enum {
    STRING = 1, NUMBER = 2, INTEGER = 3, DIVMOD = 4, INPUT = 5, OPEN = 6, 
    STATICMETHOD = 7, ALL = 8, ENUMERATE = 9, INT = 10, ORD = 11, STR = 12, 
    ANY = 13, EVAL = 14, ISINSTANCE = 15, POW = 16, SUM = 17, BASESTRING = 18, 
    EXECFILE = 19, ISSUBCLASS = 20, ABS = 21, SUPER = 22, BIN = 23, FILE = 24, 
    ITER = 25, PROPERTY = 26, TUPLE = 27, BOOL = 28, FILTER = 29, LEN = 30, 
    RANGE = 31, TYPE = 32, BYTEARRAY = 33, FLOAT = 34, LIST = 35, RAW_INPUT = 36, 
    UNICHR = 37, CALLABLE = 38, FORMAT = 39, LOCALS = 40, REDUCE = 41, UNICODE = 42, 
    CHR = 43, FROZENSET = 44, LONG = 45, RELOAD = 46, VARS = 47, CLASSMETHOD = 48, 
    GETATTR = 49, MAP = 50, REPR = 51, XRANGE = 52, CMP = 53, GLOBALS = 54, 
    MAX = 55, REVERSED = 56, ZIP = 57, COMPILE = 58, HASATTR = 59, MEMORYVIEW = 60, 
    ROUND = 61, UNDERSCORE_IMPORT = 62, COMPLEX = 63, HASH = 64, MIN = 65, 
    SET = 66, APPLY = 67, DELATTR = 68, HELP = 69, NEXT = 70, SETATTR = 71, 
    BUFFER = 72, DICT = 73, HEX = 74, OBJECT = 75, SLICE = 76, COERCE = 77, 
    DIR = 78, ID = 79, OCT = 80, SORTED = 81, INTERN = 82, BASE_EXCEPTION = 83, 
    SYSTEM_EXIT = 84, KEYBOARD_INTERRUPT = 85, GENERATOR_EXIT = 86, EXCEPTION = 87, 
    STOP_ITERATION = 88, ARITHMETIC_ERROR = 89, FLOATINGPOINT_ERROR = 90, 
    OVERFLOW_ERROR = 91, ZERO_DIVISION_ERROR = 92, ASSERTION_ERROR = 93, 
    ATTRIBUTE_ERROR = 94, BUFFER_ERROR = 95, EOF_ERROR = 96, IMPORT_ERROR = 97, 
    LOOKUP_ERROR = 98, INDEX_ERROR = 99, KEY_ERROR = 100, MEMORY_ERROR = 101, 
    NAME_ERROR = 102, UNBOUND_LOCAL_ERROR = 103, OS_ERROR = 104, BLOCKING_IO_ERROR = 105, 
    CHILD_PROCESS_ERROR = 106, CONNECTION_ERROR = 107, BROKEN_PIPE_ERROR = 108, 
    CONNECTION_ABORTED_ERROR = 109, CONNECTION_REFUSED_ERROR = 110, CONNECTION_RESET_ERROR = 111, 
    FILE_EXISTS_ERROR = 112, FILE_NOT_FOUND_ERROR = 113, INTERRUPTED_ERROR = 114, 
    IS_A_DIRECTORY_ERROR = 115, NOT_A_DIRECTORY_ERROR = 116, PERMISSION_ERROR = 117, 
    PROCESS_LOOKUP_ERROR = 118, TIMEOUT_ERROR = 119, REFERENCE_ERROR = 120, 
    RUNTIME_ERROR = 121, NOT_IMPLEMENTED_ERROR = 122, SYNTAX_ERROR = 123, 
    INDENTATION_ERROR = 124, TAB_ERROR = 125, SYSTEM_ERROR = 126, TYPE_ERROR = 127, 
    VALUE_ERROR = 128, UNICODE_ERROR = 129, UNICODE_DECODE_ERROR = 130, 
    UNICODE_ENCODE_ERROR = 131, UNICODE_TRANSLATE_ERROR = 132, WARNING = 133, 
    DEPRECATION_WARNING = 134, PENDING_DEPRECATION_WARNING = 135, RUNTIME_WARNING = 136, 
    SYNTAX_WARNING = 137, USER_WARNING = 138, FUTURE_WARNING = 139, IMPORT_WARNING = 140, 
    UNICODE_WARNING = 141, BYTES_WARNING = 142, RESOURCE_WARNING = 143, 
    PRINT = 144, DEF = 145, RETURN = 146, RAISE = 147, FROM = 148, IMPORT = 149, 
    AS = 150, GLOBAL = 151, NONLOCAL = 152, ASSERT = 153, IF = 154, ELIF = 155, 
    ELSE = 156, WHILE = 157, FOR = 158, IN = 159, TRY = 160, FINALLY = 161, 
    WITH = 162, EXCEPT = 163, LAMBDA = 164, OR = 165, AND = 166, NOT = 167, 
    IS = 168, NONE = 169, TRUE = 170, FALSE = 171, CLASS = 172, YIELD = 173, 
    DEL = 174, PASS = 175, CONTINUE = 176, BREAK = 177, ASYNC = 178, AWAIT = 179, 
    NEWLINE = 180, NAME = 181, STRING_LITERAL = 182, BYTES_LITERAL = 183, 
    DECIMAL_INTEGER = 184, OCT_INTEGER = 185, HEX_INTEGER = 186, BIN_INTEGER = 187, 
    FLOAT_NUMBER = 188, IMAG_NUMBER = 189, DOT = 190, ELLIPSIS = 191, STAR = 192, 
    OPEN_PAREN = 193, CLOSE_PAREN = 194, COMMA = 195, COLON = 196, SEMI_COLON = 197, 
    POWER = 198, ASSIGN = 199, OPEN_BRACK = 200, CLOSE_BRACK = 201, OR_OP = 202, 
    XOR = 203, AND_OP = 204, LEFT_SHIFT = 205, RIGHT_SHIFT = 206, ADD = 207, 
    MINUS = 208, DIV = 209, MOD = 210, IDIV = 211, NOT_OP = 212, OPEN_BRACE = 213, 
    CLOSE_BRACE = 214, LESS_THAN = 215, GREATER_THAN = 216, EQUALS = 217, 
    GT_EQ = 218, LT_EQ = 219, NOT_EQ_1 = 220, NOT_EQ_2 = 221, AT = 222, 
    ARROW = 223, ADD_ASSIGN = 224, SUB_ASSIGN = 225, MULT_ASSIGN = 226, 
    AT_ASSIGN = 227, DIV_ASSIGN = 228, MOD_ASSIGN = 229, AND_ASSIGN = 230, 
    OR_ASSIGN = 231, XOR_ASSIGN = 232, LEFT_SHIFT_ASSIGN = 233, RIGHT_SHIFT_ASSIGN = 234, 
    POWER_ASSIGN = 235, IDIV_ASSIGN = 236, SKIP_ = 237, UNKNOWN_CHAR = 238
  };

  Python3Lexer(antlr4::CharStream *input);
  ~Python3Lexer();


      private:
            // A queue where extra tokens are pushed on (see the NEWLINE lexer rule).
            list<unique_ptr<Token>> Tokens;
            // The stack that keeps track of the indentation level.
            stack<int> Indents;
            // The amount of opened braces, brackets and parenthesis.
            int Opened = 0;
            // The most recently produced token.
            Token* LastToken;

          public:
              void emit2(unique_ptr<Token> token) override
              {     
                  setToken(move(token));
                  // Tokens.push_back(move(token));
              }

          private:
              CommonToken* commonToken(size_t type, string text)
              {
                  int stop = this->getCharIndex() - 1;
                  int start = text.length() == 0 ? stop : stop - text.length() + 1;
                  return new CommonToken(this->_tokenFactorySourcePair, type, DEFAULT_TOKEN_CHANNEL, start, stop);
              }

          public:
              unique_ptr<Token> createDedent()
              {
                  CommonToken* dedent = new CommonToken(Python3Parser::DEDENT, "");
                  dedent->setLine(LastToken->getLine());
                  Token* obj = dedent;
                  unique_ptr<Token> ptr(obj);
                  return ptr;
              }

              unique_ptr<Token> nextToken()
              {
                  // Check if the end-of-file is ahead and there are still some DEDENTS expected.
                  if (_input->LA(1) == EOF && this->Indents.size() != 0)
                  {
                      // Remove any trailing EOF tokens from our buffer.
                      for(auto ptr = Tokens.begin(); ptr != Tokens.end(); ptr++) {
                          if((*ptr)->getType() == EOF) {
                              Tokens.erase(ptr);
                          }
                      }
                      Token* obj = commonToken(NEWLINE, "\n");
                      unique_ptr<Token> uptr(obj);
                      // First emit an extra line break that serves as the end of the statement.
                      emit2(move(uptr));
                      
                      // Now emit as much DEDENT tokens as needed.
                      while (Indents.size() != 0)
                      {
                          emit2(createDedent());
                          Indents.pop();
                      }
                      
                      // Put the EOF back on the token stream.
                      obj = commonToken(EOF, "<EOF>");
                      unique_ptr<Token> uptr2(obj);
                      emit2(move(uptr2));
                  }

                  auto next = antlr4::Lexer::nextToken();
                  if (next->getChannel() == DEFAULT_TOKEN_CHANNEL)
                  {
                      // Keep track of the last token on the default channel.
                      LastToken = next.get();
                  }

                  if (Tokens.size() == 0)
                  {
                      return next;
                  }
                  else
                  {		
                  	return move(next);
                    // auto x = move(Tokens.back()); Tokens.pop_back();
                    // return x;
                  }
              }

            // Calculates the indentation of the provided spaces, taking the
            // following rules into account:
            //
            // "Tabs are replaced (from left to right) by one to eight spaces
            //  such that the total number of characters up to and including
            //  the replacement is a multiple of eight [...]"
            //
            //  -- https://docs.python.org/3.1/reference/lexical_analysis.html#indentation
            static int getIndentationCount(string spaces)
            {
                int count = 0;
                char charArray[spaces.length()];
                strcpy(charArray, spaces.c_str());
                for(char ch : charArray)
                {
                    count += ch == '\t' ? 8 - (count % 8) : 1;
                }
                return count;
            }

            bool atStartOfInput()
            {
                return getCharPositionInLine() == 0 && getLine() == 1;
            }

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

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
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};


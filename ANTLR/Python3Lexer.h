
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
    STRING = 1, COMMENTS = 2, NUMBER = 3, INTEGER = 4, HACKISH = 5, PRIVATE = 6, 
    SPECIAL = 7, BUG = 8, DIVMOD = 9, INPUT = 10, OPEN = 11, STATICMETHOD = 12, 
    ALL = 13, ENUMERATE = 14, INT = 15, ORD = 16, STR = 17, ANY = 18, EVAL = 19, 
    ISINSTANCE = 20, POW = 21, SUM = 22, BASESTRING = 23, EXECFILE = 24, 
    ISSUBCLASS = 25, ABS = 26, SUPER = 27, BIN = 28, FILE = 29, ITER = 30, 
    PROPERTY = 31, TUPLE = 32, BOOL = 33, FILTER = 34, LEN = 35, RANGE = 36, 
    TYPE = 37, BYTEARRAY = 38, FLOAT = 39, LIST = 40, RAW_INPUT = 41, UNICHR = 42, 
    CALLABLE = 43, FORMAT = 44, LOCALS = 45, REDUCE = 46, UNICODE = 47, 
    CHR = 48, FROZENSET = 49, LONG = 50, RELOAD = 51, VARS = 52, CLASSMETHOD = 53, 
    GETATTR = 54, MAP = 55, REPR = 56, XRANGE = 57, CMP = 58, GLOBALS = 59, 
    MAX = 60, REVERSED = 61, ZIP = 62, COMPILE = 63, HASATTR = 64, MEMORYVIEW = 65, 
    ROUND = 66, UNDERSCORE_IMPORT = 67, COMPLEX = 68, HASH = 69, MIN = 70, 
    SET = 71, APPLY = 72, DELATTR = 73, HELP = 74, NEXT = 75, SETATTR = 76, 
    BUFFER = 77, DICT = 78, HEX = 79, OBJECT = 80, SLICE = 81, COERCE = 82, 
    DIR = 83, ID = 84, OCT = 85, SORTED = 86, INTERN = 87, BASE_EXCEPTION = 88, 
    SYSTEM_EXIT = 89, KEYBOARD_INTERRUPT = 90, GENERATOR_EXIT = 91, EXCEPTION = 92, 
    STOP_ITERATION = 93, ARITHMETIC_ERROR = 94, FLOATINGPOINT_ERROR = 95, 
    OVERFLOW_ERROR = 96, ZERO_DIVISION_ERROR = 97, ASSERTION_ERROR = 98, 
    ATTRIBUTE_ERROR = 99, BUFFER_ERROR = 100, EOF_ERROR = 101, IMPORT_ERROR = 102, 
    LOOKUP_ERROR = 103, INDEX_ERROR = 104, KEY_ERROR = 105, MEMORY_ERROR = 106, 
    NAME_ERROR = 107, UNBOUND_LOCAL_ERROR = 108, OS_ERROR = 109, BLOCKING_IO_ERROR = 110, 
    CHILD_PROCESS_ERROR = 111, CONNECTION_ERROR = 112, BROKEN_PIPE_ERROR = 113, 
    CONNECTION_ABORTED_ERROR = 114, CONNECTION_REFUSED_ERROR = 115, CONNECTION_RESET_ERROR = 116, 
    FILE_EXISTS_ERROR = 117, FILE_NOT_FOUND_ERROR = 118, INTERRUPTED_ERROR = 119, 
    IS_A_DIRECTORY_ERROR = 120, NOT_A_DIRECTORY_ERROR = 121, PERMISSION_ERROR = 122, 
    PROCESS_LOOKUP_ERROR = 123, TIMEOUT_ERROR = 124, REFERENCE_ERROR = 125, 
    RUNTIME_ERROR = 126, NOT_IMPLEMENTED_ERROR = 127, SYNTAX_ERROR = 128, 
    INDENTATION_ERROR = 129, TAB_ERROR = 130, SYSTEM_ERROR = 131, TYPE_ERROR = 132, 
    VALUE_ERROR = 133, UNICODE_ERROR = 134, UNICODE_DECODE_ERROR = 135, 
    UNICODE_ENCODE_ERROR = 136, UNICODE_TRANSLATE_ERROR = 137, WARNING = 138, 
    DEPRECATION_WARNING = 139, PENDING_DEPRECATION_WARNING = 140, RUNTIME_WARNING = 141, 
    SYNTAX_WARNING = 142, USER_WARNING = 143, FUTURE_WARNING = 144, IMPORT_WARNING = 145, 
    UNICODE_WARNING = 146, BYTES_WARNING = 147, RESOURCE_WARNING = 148, 
    PRINT = 149, DEF = 150, RETURN = 151, RAISE = 152, FROM = 153, IMPORT = 154, 
    AS = 155, GLOBAL = 156, NONLOCAL = 157, ASSERT = 158, IF = 159, ELIF = 160, 
    ELSE = 161, WHILE = 162, FOR = 163, IN = 164, TRY = 165, FINALLY = 166, 
    WITH = 167, EXCEPT = 168, LAMBDA = 169, OR = 170, AND = 171, NOT = 172, 
    IS = 173, NONE = 174, TRUE = 175, FALSE = 176, CLASS = 177, YIELD = 178, 
    DEL = 179, PASS = 180, CONTINUE = 181, BREAK = 182, ASYNC = 183, AWAIT = 184, 
    NEWLINE = 185, NAME = 186, STRING_LITERAL = 187, BYTES_LITERAL = 188, 
    DECIMAL_INTEGER = 189, OCT_INTEGER = 190, HEX_INTEGER = 191, BIN_INTEGER = 192, 
    FLOAT_NUMBER = 193, IMAG_NUMBER = 194, DOT = 195, ELLIPSIS = 196, STAR = 197, 
    OPEN_PAREN = 198, CLOSE_PAREN = 199, COMMA = 200, COLON = 201, SEMI_COLON = 202, 
    POWER = 203, ASSIGN = 204, OPEN_BRACK = 205, CLOSE_BRACK = 206, OR_OP = 207, 
    XOR = 208, AND_OP = 209, LEFT_SHIFT = 210, RIGHT_SHIFT = 211, ADD = 212, 
    MINUS = 213, DIV = 214, MOD = 215, IDIV = 216, NOT_OP = 217, OPEN_BRACE = 218, 
    CLOSE_BRACE = 219, LESS_THAN = 220, GREATER_THAN = 221, EQUALS = 222, 
    GT_EQ = 223, LT_EQ = 224, NOT_EQ_1 = 225, NOT_EQ_2 = 226, AT = 227, 
    ARROW = 228, ADD_ASSIGN = 229, SUB_ASSIGN = 230, MULT_ASSIGN = 231, 
    AT_ASSIGN = 232, DIV_ASSIGN = 233, MOD_ASSIGN = 234, AND_ASSIGN = 235, 
    OR_ASSIGN = 236, XOR_ASSIGN = 237, LEFT_SHIFT_ASSIGN = 238, RIGHT_SHIFT_ASSIGN = 239, 
    POWER_ASSIGN = 240, IDIV_ASSIGN = 241, SKIP_ = 242, UNKNOWN_CHAR = 243
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


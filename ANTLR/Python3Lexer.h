
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
    STRING_LONG = 1, STRING_SHORT = 2, STRING = 3, COMMENTS = 4, NUMBER = 5, 
    INTEGER = 6, HACKISH = 7, PRIVATE = 8, SPECIAL = 9, BUG = 10, DIVMOD = 11, 
    INPUT = 12, OPEN = 13, STATICMETHOD = 14, ALL = 15, ENUMERATE = 16, 
    INT = 17, ORD = 18, STR = 19, ANY = 20, EVAL = 21, ISINSTANCE = 22, 
    POW = 23, SUM = 24, BASESTRING = 25, EXECFILE = 26, ISSUBCLASS = 27, 
    ABS = 28, SUPER = 29, BIN = 30, FILE = 31, ITER = 32, PROPERTY = 33, 
    TUPLE = 34, BOOL = 35, FILTER = 36, LEN = 37, RANGE = 38, TYPE = 39, 
    BYTEARRAY = 40, FLOAT = 41, LIST = 42, RAW_INPUT = 43, UNICHR = 44, 
    CALLABLE = 45, FORMAT = 46, LOCALS = 47, REDUCE = 48, UNICODE = 49, 
    CHR = 50, FROZENSET = 51, LONG = 52, RELOAD = 53, VARS = 54, CLASSMETHOD = 55, 
    GETATTR = 56, MAP = 57, REPR = 58, XRANGE = 59, CMP = 60, GLOBALS = 61, 
    MAX = 62, REVERSED = 63, ZIP = 64, COMPILE = 65, HASATTR = 66, MEMORYVIEW = 67, 
    ROUND = 68, UNDERSCORE_IMPORT = 69, COMPLEX = 70, HASH = 71, MIN = 72, 
    SET = 73, APPLY = 74, DELATTR = 75, HELP = 76, NEXT = 77, SETATTR = 78, 
    BUFFER = 79, DICT = 80, HEX = 81, OBJECT = 82, SLICE = 83, COERCE = 84, 
    DIR = 85, ID = 86, OCT = 87, SORTED = 88, INTERN = 89, BASE_EXCEPTION = 90, 
    SYSTEM_EXIT = 91, KEYBOARD_INTERRUPT = 92, GENERATOR_EXIT = 93, EXCEPTION = 94, 
    STOP_ITERATION = 95, ARITHMETIC_ERROR = 96, FLOATINGPOINT_ERROR = 97, 
    OVERFLOW_ERROR = 98, ZERO_DIVISION_ERROR = 99, ASSERTION_ERROR = 100, 
    ATTRIBUTE_ERROR = 101, BUFFER_ERROR = 102, EOF_ERROR = 103, IMPORT_ERROR = 104, 
    LOOKUP_ERROR = 105, INDEX_ERROR = 106, KEY_ERROR = 107, MEMORY_ERROR = 108, 
    NAME_ERROR = 109, UNBOUND_LOCAL_ERROR = 110, OS_ERROR = 111, BLOCKING_IO_ERROR = 112, 
    CHILD_PROCESS_ERROR = 113, CONNECTION_ERROR = 114, BROKEN_PIPE_ERROR = 115, 
    CONNECTION_ABORTED_ERROR = 116, CONNECTION_REFUSED_ERROR = 117, CONNECTION_RESET_ERROR = 118, 
    FILE_EXISTS_ERROR = 119, FILE_NOT_FOUND_ERROR = 120, INTERRUPTED_ERROR = 121, 
    IS_A_DIRECTORY_ERROR = 122, NOT_A_DIRECTORY_ERROR = 123, PERMISSION_ERROR = 124, 
    PROCESS_LOOKUP_ERROR = 125, TIMEOUT_ERROR = 126, REFERENCE_ERROR = 127, 
    RUNTIME_ERROR = 128, NOT_IMPLEMENTED_ERROR = 129, SYNTAX_ERROR = 130, 
    INDENTATION_ERROR = 131, TAB_ERROR = 132, SYSTEM_ERROR = 133, TYPE_ERROR = 134, 
    VALUE_ERROR = 135, UNICODE_ERROR = 136, UNICODE_DECODE_ERROR = 137, 
    UNICODE_ENCODE_ERROR = 138, UNICODE_TRANSLATE_ERROR = 139, WARNING = 140, 
    DEPRECATION_WARNING = 141, PENDING_DEPRECATION_WARNING = 142, RUNTIME_WARNING = 143, 
    SYNTAX_WARNING = 144, USER_WARNING = 145, FUTURE_WARNING = 146, IMPORT_WARNING = 147, 
    UNICODE_WARNING = 148, BYTES_WARNING = 149, RESOURCE_WARNING = 150, 
    PRINT = 151, DEF = 152, RETURN = 153, RAISE = 154, FROM = 155, IMPORT = 156, 
    AS = 157, GLOBAL = 158, NONLOCAL = 159, ASSERT = 160, IF = 161, ELIF = 162, 
    ELSE = 163, WHILE = 164, FOR = 165, IN = 166, TRY = 167, FINALLY = 168, 
    WITH = 169, EXCEPT = 170, LAMBDA = 171, OR = 172, AND = 173, NOT = 174, 
    IS = 175, NONE = 176, TRUE = 177, FALSE = 178, CLASS = 179, YIELD = 180, 
    DEL = 181, PASS = 182, CONTINUE = 183, BREAK = 184, ASYNC = 185, AWAIT = 186, 
    NEWLINE = 187, NAME = 188, STRING_LITERAL = 189, STRING_LONG_LITERAL = 190, 
    STRING_SHORT_LITERAL = 191, BYTES_LITERAL = 192, BYTES_LONG_LITERAL = 193, 
    BYTES_SHORT_LITERAL = 194, DECIMAL_INTEGER = 195, OCT_INTEGER = 196, 
    HEX_INTEGER = 197, BIN_INTEGER = 198, FLOAT_NUMBER = 199, IMAG_NUMBER = 200, 
    DOT = 201, ELLIPSIS = 202, STAR = 203, OPEN_PAREN = 204, CLOSE_PAREN = 205, 
    COMMA = 206, COLON = 207, SEMI_COLON = 208, POWER = 209, ASSIGN = 210, 
    OPEN_BRACK = 211, CLOSE_BRACK = 212, OR_OP = 213, XOR = 214, AND_OP = 215, 
    LEFT_SHIFT = 216, RIGHT_SHIFT = 217, ADD = 218, MINUS = 219, DIV = 220, 
    MOD = 221, IDIV = 222, NOT_OP = 223, OPEN_BRACE = 224, CLOSE_BRACE = 225, 
    LESS_THAN = 226, GREATER_THAN = 227, EQUALS = 228, GT_EQ = 229, LT_EQ = 230, 
    NOT_EQ_1 = 231, NOT_EQ_2 = 232, AT = 233, ARROW = 234, ADD_ASSIGN = 235, 
    SUB_ASSIGN = 236, MULT_ASSIGN = 237, AT_ASSIGN = 238, DIV_ASSIGN = 239, 
    MOD_ASSIGN = 240, AND_ASSIGN = 241, OR_ASSIGN = 242, XOR_ASSIGN = 243, 
    LEFT_SHIFT_ASSIGN = 244, RIGHT_SHIFT_ASSIGN = 245, POWER_ASSIGN = 246, 
    IDIV_ASSIGN = 247, SKIP_ = 248, UNKNOWN_CHAR = 249
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


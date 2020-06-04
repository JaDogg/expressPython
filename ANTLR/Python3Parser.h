
// Generated from Python3.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Python3Parser : public antlr4::Parser {
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
    IDIV_ASSIGN = 247, SKIP_ = 248, UNKNOWN_CHAR = 249, INDENT = 250, DEDENT = 251
  };

  enum {
    RuleSingle_input = 0, RuleFile_input = 1, RuleEval_input = 2, RuleDecorator = 3, 
    RuleDecorators = 4, RuleDecorated = 5, RuleAsync_funcdef = 6, RuleFuncdef = 7, 
    RuleParameters = 8, RuleTypedargslist = 9, RuleTfpdef = 10, RuleVarargslist = 11, 
    RuleVfpdef = 12, RuleStmt = 13, RuleSimple_stmt = 14, RuleSmall_stmt = 15, 
    RuleExpr_stmt = 16, RuleAnnassign = 17, RuleTestlist_star_expr = 18, 
    RuleAugassign = 19, RuleDel_stmt = 20, RulePass_stmt = 21, RuleFlow_stmt = 22, 
    RuleBreak_stmt = 23, RuleContinue_stmt = 24, RuleReturn_stmt = 25, RuleYield_stmt = 26, 
    RuleRaise_stmt = 27, RuleImport_stmt = 28, RuleImport_name = 29, RuleImport_from = 30, 
    RuleImport_as_name = 31, RuleDotted_as_name = 32, RuleImport_as_names = 33, 
    RuleDotted_as_names = 34, RuleDotted_name = 35, RuleGlobal_stmt = 36, 
    RuleNonlocal_stmt = 37, RuleAssert_stmt = 38, RuleCompound_stmt = 39, 
    RuleAsync_stmt = 40, RuleIf_stmt = 41, RuleWhile_stmt = 42, RuleFor_stmt = 43, 
    RuleTry_stmt = 44, RuleWith_stmt = 45, RuleWith_item = 46, RuleExcept_clause = 47, 
    RuleSuite = 48, RuleTest = 49, RuleTest_nocond = 50, RuleLambdef = 51, 
    RuleLambdef_nocond = 52, RuleOr_test = 53, RuleAnd_test = 54, RuleNot_test = 55, 
    RuleComparison = 56, RuleComp_op = 57, RuleStar_expr = 58, RuleExpr = 59, 
    RuleXor_expr = 60, RuleAnd_expr = 61, RuleShift_expr = 62, RuleArith_expr = 63, 
    RuleTerm = 64, RuleFactor = 65, RulePower = 66, RuleAtom_expr = 67, 
    RuleAtom = 68, RuleTestlist_comp = 69, RuleTrailer = 70, RuleSubscriptlist = 71, 
    RuleSubscript = 72, RuleSliceop = 73, RuleExprlist = 74, RuleTestlist = 75, 
    RuleDictorsetmaker = 76, RuleClassdef = 77, RuleArglist = 78, RuleArgument = 79, 
    RuleComp_iter = 80, RuleComp_for = 81, RuleComp_if = 82, RuleEncoding_decl = 83, 
    RuleYield_expr = 84, RuleYield_arg = 85
  };

  Python3Parser(antlr4::TokenStream *input);
  ~Python3Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Single_inputContext;
  class File_inputContext;
  class Eval_inputContext;
  class DecoratorContext;
  class DecoratorsContext;
  class DecoratedContext;
  class Async_funcdefContext;
  class FuncdefContext;
  class ParametersContext;
  class TypedargslistContext;
  class TfpdefContext;
  class VarargslistContext;
  class VfpdefContext;
  class StmtContext;
  class Simple_stmtContext;
  class Small_stmtContext;
  class Expr_stmtContext;
  class AnnassignContext;
  class Testlist_star_exprContext;
  class AugassignContext;
  class Del_stmtContext;
  class Pass_stmtContext;
  class Flow_stmtContext;
  class Break_stmtContext;
  class Continue_stmtContext;
  class Return_stmtContext;
  class Yield_stmtContext;
  class Raise_stmtContext;
  class Import_stmtContext;
  class Import_nameContext;
  class Import_fromContext;
  class Import_as_nameContext;
  class Dotted_as_nameContext;
  class Import_as_namesContext;
  class Dotted_as_namesContext;
  class Dotted_nameContext;
  class Global_stmtContext;
  class Nonlocal_stmtContext;
  class Assert_stmtContext;
  class Compound_stmtContext;
  class Async_stmtContext;
  class If_stmtContext;
  class While_stmtContext;
  class For_stmtContext;
  class Try_stmtContext;
  class With_stmtContext;
  class With_itemContext;
  class Except_clauseContext;
  class SuiteContext;
  class TestContext;
  class Test_nocondContext;
  class LambdefContext;
  class Lambdef_nocondContext;
  class Or_testContext;
  class And_testContext;
  class Not_testContext;
  class ComparisonContext;
  class Comp_opContext;
  class Star_exprContext;
  class ExprContext;
  class Xor_exprContext;
  class And_exprContext;
  class Shift_exprContext;
  class Arith_exprContext;
  class TermContext;
  class FactorContext;
  class PowerContext;
  class Atom_exprContext;
  class AtomContext;
  class Testlist_compContext;
  class TrailerContext;
  class SubscriptlistContext;
  class SubscriptContext;
  class SliceopContext;
  class ExprlistContext;
  class TestlistContext;
  class DictorsetmakerContext;
  class ClassdefContext;
  class ArglistContext;
  class ArgumentContext;
  class Comp_iterContext;
  class Comp_forContext;
  class Comp_ifContext;
  class Encoding_declContext;
  class Yield_exprContext;
  class Yield_argContext; 

  class  Single_inputContext : public antlr4::ParserRuleContext {
  public:
    Single_inputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    Simple_stmtContext *simple_stmt();
    Compound_stmtContext *compound_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_inputContext* single_input();

  class  File_inputContext : public antlr4::ParserRuleContext {
  public:
    File_inputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  File_inputContext* file_input();

  class  Eval_inputContext : public antlr4::ParserRuleContext {
  public:
    Eval_inputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TestlistContext *testlist();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Eval_inputContext* eval_input();

  class  DecoratorContext : public antlr4::ParserRuleContext {
  public:
    DecoratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    Dotted_nameContext *dotted_name();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    ArglistContext *arglist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecoratorContext* decorator();

  class  DecoratorsContext : public antlr4::ParserRuleContext {
  public:
    DecoratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DecoratorContext *> decorator();
    DecoratorContext* decorator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecoratorsContext* decorators();

  class  DecoratedContext : public antlr4::ParserRuleContext {
  public:
    DecoratedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecoratorsContext *decorators();
    ClassdefContext *classdef();
    FuncdefContext *funcdef();
    Async_funcdefContext *async_funcdef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecoratedContext* decorated();

  class  Async_funcdefContext : public antlr4::ParserRuleContext {
  public:
    Async_funcdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASYNC();
    FuncdefContext *funcdef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Async_funcdefContext* async_funcdef();

  class  FuncdefContext : public antlr4::ParserRuleContext {
  public:
    FuncdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *NAME();
    ParametersContext *parameters();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    antlr4::tree::TerminalNode *ARROW();
    TestContext *test();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncdefContext* funcdef();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    TypedargslistContext *typedargslist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParametersContext* parameters();

  class  TypedargslistContext : public antlr4::ParserRuleContext {
  public:
    TypedargslistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TfpdefContext *> tfpdef();
    TfpdefContext* tfpdef(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *POWER();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypedargslistContext* typedargslist();

  class  TfpdefContext : public antlr4::ParserRuleContext {
  public:
    TfpdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    TestContext *test();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TfpdefContext* tfpdef();

  class  VarargslistContext : public antlr4::ParserRuleContext {
  public:
    VarargslistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VfpdefContext *> vfpdef();
    VfpdefContext* vfpdef(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *POWER();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarargslistContext* varargslist();

  class  VfpdefContext : public antlr4::ParserRuleContext {
  public:
    VfpdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VfpdefContext* vfpdef();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_stmtContext *simple_stmt();
    Compound_stmtContext *compound_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  Simple_stmtContext : public antlr4::ParserRuleContext {
  public:
    Simple_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Small_stmtContext *> small_stmt();
    Small_stmtContext* small_stmt(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> SEMI_COLON();
    antlr4::tree::TerminalNode* SEMI_COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_stmtContext* simple_stmt();

  class  Small_stmtContext : public antlr4::ParserRuleContext {
  public:
    Small_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_stmtContext *expr_stmt();
    Del_stmtContext *del_stmt();
    Pass_stmtContext *pass_stmt();
    Flow_stmtContext *flow_stmt();
    Import_stmtContext *import_stmt();
    Global_stmtContext *global_stmt();
    Nonlocal_stmtContext *nonlocal_stmt();
    Assert_stmtContext *assert_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Small_stmtContext* small_stmt();

  class  Expr_stmtContext : public antlr4::ParserRuleContext {
  public:
    Expr_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Testlist_star_exprContext *> testlist_star_expr();
    Testlist_star_exprContext* testlist_star_expr(size_t i);
    AnnassignContext *annassign();
    AugassignContext *augassign();
    std::vector<Yield_exprContext *> yield_expr();
    Yield_exprContext* yield_expr(size_t i);
    TestlistContext *testlist();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr_stmtContext* expr_stmt();

  class  AnnassignContext : public antlr4::ParserRuleContext {
  public:
    AnnassignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AnnassignContext* annassign();

  class  Testlist_star_exprContext : public antlr4::ParserRuleContext {
  public:
    Testlist_star_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<Star_exprContext *> star_expr();
    Star_exprContext* star_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Testlist_star_exprContext* testlist_star_expr();

  class  AugassignContext : public antlr4::ParserRuleContext {
  public:
    AugassignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD_ASSIGN();
    antlr4::tree::TerminalNode *SUB_ASSIGN();
    antlr4::tree::TerminalNode *MULT_ASSIGN();
    antlr4::tree::TerminalNode *AT_ASSIGN();
    antlr4::tree::TerminalNode *DIV_ASSIGN();
    antlr4::tree::TerminalNode *MOD_ASSIGN();
    antlr4::tree::TerminalNode *AND_ASSIGN();
    antlr4::tree::TerminalNode *OR_ASSIGN();
    antlr4::tree::TerminalNode *XOR_ASSIGN();
    antlr4::tree::TerminalNode *LEFT_SHIFT_ASSIGN();
    antlr4::tree::TerminalNode *RIGHT_SHIFT_ASSIGN();
    antlr4::tree::TerminalNode *POWER_ASSIGN();
    antlr4::tree::TerminalNode *IDIV_ASSIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AugassignContext* augassign();

  class  Del_stmtContext : public antlr4::ParserRuleContext {
  public:
    Del_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEL();
    ExprlistContext *exprlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Del_stmtContext* del_stmt();

  class  Pass_stmtContext : public antlr4::ParserRuleContext {
  public:
    Pass_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PASS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pass_stmtContext* pass_stmt();

  class  Flow_stmtContext : public antlr4::ParserRuleContext {
  public:
    Flow_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Break_stmtContext *break_stmt();
    Continue_stmtContext *continue_stmt();
    Return_stmtContext *return_stmt();
    Raise_stmtContext *raise_stmt();
    Yield_stmtContext *yield_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Flow_stmtContext* flow_stmt();

  class  Break_stmtContext : public antlr4::ParserRuleContext {
  public:
    Break_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Break_stmtContext* break_stmt();

  class  Continue_stmtContext : public antlr4::ParserRuleContext {
  public:
    Continue_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Continue_stmtContext* continue_stmt();

  class  Return_stmtContext : public antlr4::ParserRuleContext {
  public:
    Return_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    TestlistContext *testlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_stmtContext* return_stmt();

  class  Yield_stmtContext : public antlr4::ParserRuleContext {
  public:
    Yield_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Yield_exprContext *yield_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Yield_stmtContext* yield_stmt();

  class  Raise_stmtContext : public antlr4::ParserRuleContext {
  public:
    Raise_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAISE();
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    antlr4::tree::TerminalNode *FROM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Raise_stmtContext* raise_stmt();

  class  Import_stmtContext : public antlr4::ParserRuleContext {
  public:
    Import_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Import_nameContext *import_name();
    Import_fromContext *import_from();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Import_stmtContext* import_stmt();

  class  Import_nameContext : public antlr4::ParserRuleContext {
  public:
    Import_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    Dotted_as_namesContext *dotted_as_names();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Import_nameContext* import_name();

  class  Import_fromContext : public antlr4::ParserRuleContext {
  public:
    Import_fromContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *IMPORT();
    Dotted_nameContext *dotted_name();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    Import_as_namesContext *import_as_names();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELLIPSIS();
    antlr4::tree::TerminalNode* ELLIPSIS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Import_fromContext* import_from();

  class  Import_as_nameContext : public antlr4::ParserRuleContext {
  public:
    Import_as_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Import_as_nameContext* import_as_name();

  class  Dotted_as_nameContext : public antlr4::ParserRuleContext {
  public:
    Dotted_as_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Dotted_nameContext *dotted_name();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dotted_as_nameContext* dotted_as_name();

  class  Import_as_namesContext : public antlr4::ParserRuleContext {
  public:
    Import_as_namesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Import_as_nameContext *> import_as_name();
    Import_as_nameContext* import_as_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Import_as_namesContext* import_as_names();

  class  Dotted_as_namesContext : public antlr4::ParserRuleContext {
  public:
    Dotted_as_namesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dotted_as_nameContext *> dotted_as_name();
    Dotted_as_nameContext* dotted_as_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dotted_as_namesContext* dotted_as_names();

  class  Dotted_nameContext : public antlr4::ParserRuleContext {
  public:
    Dotted_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dotted_nameContext* dotted_name();

  class  Global_stmtContext : public antlr4::ParserRuleContext {
  public:
    Global_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GLOBAL();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Global_stmtContext* global_stmt();

  class  Nonlocal_stmtContext : public antlr4::ParserRuleContext {
  public:
    Nonlocal_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NONLOCAL();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Nonlocal_stmtContext* nonlocal_stmt();

  class  Assert_stmtContext : public antlr4::ParserRuleContext {
  public:
    Assert_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSERT();
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Assert_stmtContext* assert_stmt();

  class  Compound_stmtContext : public antlr4::ParserRuleContext {
  public:
    Compound_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_stmtContext *if_stmt();
    While_stmtContext *while_stmt();
    For_stmtContext *for_stmt();
    Try_stmtContext *try_stmt();
    With_stmtContext *with_stmt();
    FuncdefContext *funcdef();
    ClassdefContext *classdef();
    DecoratedContext *decorated();
    Async_stmtContext *async_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_stmtContext* compound_stmt();

  class  Async_stmtContext : public antlr4::ParserRuleContext {
  public:
    Async_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASYNC();
    FuncdefContext *funcdef();
    With_stmtContext *with_stmt();
    For_stmtContext *for_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Async_stmtContext* async_stmt();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_stmtContext* if_stmt();

  class  While_stmtContext : public antlr4::ParserRuleContext {
  public:
    While_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    TestContext *test();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_stmtContext* while_stmt();

  class  For_stmtContext : public antlr4::ParserRuleContext {
  public:
    For_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    ExprlistContext *exprlist();
    antlr4::tree::TerminalNode *IN();
    TestlistContext *testlist();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_stmtContext* for_stmt();

  class  Try_stmtContext : public antlr4::ParserRuleContext {
  public:
    Try_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    antlr4::tree::TerminalNode *FINALLY();
    std::vector<Except_clauseContext *> except_clause();
    Except_clauseContext* except_clause(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Try_stmtContext* try_stmt();

  class  With_stmtContext : public antlr4::ParserRuleContext {
  public:
    With_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<With_itemContext *> with_item();
    With_itemContext* with_item(size_t i);
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  With_stmtContext* with_stmt();

  class  With_itemContext : public antlr4::ParserRuleContext {
  public:
    With_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TestContext *test();
    antlr4::tree::TerminalNode *AS();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  With_itemContext* with_item();

  class  Except_clauseContext : public antlr4::ParserRuleContext {
  public:
    Except_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCEPT();
    TestContext *test();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Except_clauseContext* except_clause();

  class  SuiteContext : public antlr4::ParserRuleContext {
  public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_stmtContext *simple_stmt();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *INDENT();
    antlr4::tree::TerminalNode *DEDENT();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SuiteContext* suite();

  class  TestContext : public antlr4::ParserRuleContext {
  public:
    TestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Or_testContext *> or_test();
    Or_testContext* or_test(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    TestContext *test();
    LambdefContext *lambdef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TestContext* test();

  class  Test_nocondContext : public antlr4::ParserRuleContext {
  public:
    Test_nocondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Or_testContext *or_test();
    Lambdef_nocondContext *lambdef_nocond();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Test_nocondContext* test_nocond();

  class  LambdefContext : public antlr4::ParserRuleContext {
  public:
    LambdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LAMBDA();
    antlr4::tree::TerminalNode *COLON();
    TestContext *test();
    VarargslistContext *varargslist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LambdefContext* lambdef();

  class  Lambdef_nocondContext : public antlr4::ParserRuleContext {
  public:
    Lambdef_nocondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LAMBDA();
    antlr4::tree::TerminalNode *COLON();
    Test_nocondContext *test_nocond();
    VarargslistContext *varargslist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lambdef_nocondContext* lambdef_nocond();

  class  Or_testContext : public antlr4::ParserRuleContext {
  public:
    Or_testContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<And_testContext *> and_test();
    And_testContext* and_test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Or_testContext* or_test();

  class  And_testContext : public antlr4::ParserRuleContext {
  public:
    And_testContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Not_testContext *> not_test();
    Not_testContext* not_test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  And_testContext* and_test();

  class  Not_testContext : public antlr4::ParserRuleContext {
  public:
    Not_testContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    Not_testContext *not_test();
    ComparisonContext *comparison();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Not_testContext* not_test();

  class  ComparisonContext : public antlr4::ParserRuleContext {
  public:
    ComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Comp_opContext *> comp_op();
    Comp_opContext* comp_op(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparisonContext* comparison();

  class  Comp_opContext : public antlr4::ParserRuleContext {
  public:
    Comp_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESS_THAN();
    antlr4::tree::TerminalNode *GREATER_THAN();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *GT_EQ();
    antlr4::tree::TerminalNode *LT_EQ();
    antlr4::tree::TerminalNode *NOT_EQ_1();
    antlr4::tree::TerminalNode *NOT_EQ_2();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *IS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_opContext* comp_op();

  class  Star_exprContext : public antlr4::ParserRuleContext {
  public:
    Star_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Star_exprContext* star_expr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Xor_exprContext *> xor_expr();
    Xor_exprContext* xor_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR_OP();
    antlr4::tree::TerminalNode* OR_OP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();

  class  Xor_exprContext : public antlr4::ParserRuleContext {
  public:
    Xor_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<And_exprContext *> and_expr();
    And_exprContext* and_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XOR();
    antlr4::tree::TerminalNode* XOR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Xor_exprContext* xor_expr();

  class  And_exprContext : public antlr4::ParserRuleContext {
  public:
    And_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Shift_exprContext *> shift_expr();
    Shift_exprContext* shift_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND_OP();
    antlr4::tree::TerminalNode* AND_OP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  And_exprContext* and_expr();

  class  Shift_exprContext : public antlr4::ParserRuleContext {
  public:
    Shift_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Arith_exprContext *> arith_expr();
    Arith_exprContext* arith_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LEFT_SHIFT();
    antlr4::tree::TerminalNode* LEFT_SHIFT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_SHIFT();
    antlr4::tree::TerminalNode* RIGHT_SHIFT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Shift_exprContext* shift_expr();

  class  Arith_exprContext : public antlr4::ParserRuleContext {
  public:
    Arith_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ADD();
    antlr4::tree::TerminalNode* ADD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arith_exprContext* arith_expr();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AT();
    antlr4::tree::TerminalNode* AT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MOD();
    antlr4::tree::TerminalNode* MOD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IDIV();
    antlr4::tree::TerminalNode* IDIV(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT_OP();
    PowerContext *power();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  PowerContext : public antlr4::ParserRuleContext {
  public:
    PowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Atom_exprContext *atom_expr();
    antlr4::tree::TerminalNode *POWER();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PowerContext* power();

  class  Atom_exprContext : public antlr4::ParserRuleContext {
  public:
    Atom_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *AWAIT();
    std::vector<TrailerContext *> trailer();
    TrailerContext* trailer(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Atom_exprContext* atom_expr();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACK();
    antlr4::tree::TerminalNode *CLOSE_BRACK();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ELLIPSIS();
    antlr4::tree::TerminalNode *NONE();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    Yield_exprContext *yield_expr();
    Testlist_compContext *testlist_comp();
    DictorsetmakerContext *dictorsetmaker();
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();

  class  Testlist_compContext : public antlr4::ParserRuleContext {
  public:
    Testlist_compContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<Star_exprContext *> star_expr();
    Star_exprContext* star_expr(size_t i);
    Comp_forContext *comp_for();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Testlist_compContext* testlist_comp();

  class  TrailerContext : public antlr4::ParserRuleContext {
  public:
    TrailerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    ArglistContext *arglist();
    antlr4::tree::TerminalNode *OPEN_BRACK();
    SubscriptlistContext *subscriptlist();
    antlr4::tree::TerminalNode *CLOSE_BRACK();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TrailerContext* trailer();

  class  SubscriptlistContext : public antlr4::ParserRuleContext {
  public:
    SubscriptlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SubscriptContext *> subscript();
    SubscriptContext* subscript(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubscriptlistContext* subscriptlist();

  class  SubscriptContext : public antlr4::ParserRuleContext {
  public:
    SubscriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    antlr4::tree::TerminalNode *COLON();
    SliceopContext *sliceop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubscriptContext* subscript();

  class  SliceopContext : public antlr4::ParserRuleContext {
  public:
    SliceopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    TestContext *test();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SliceopContext* sliceop();

  class  ExprlistContext : public antlr4::ParserRuleContext {
  public:
    ExprlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Star_exprContext *> star_expr();
    Star_exprContext* star_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprlistContext* exprlist();

  class  TestlistContext : public antlr4::ParserRuleContext {
  public:
    TestlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TestlistContext* testlist();

  class  DictorsetmakerContext : public antlr4::ParserRuleContext {
  public:
    DictorsetmakerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> POWER();
    antlr4::tree::TerminalNode* POWER(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Comp_forContext *comp_for();
    std::vector<Star_exprContext *> star_expr();
    Star_exprContext* star_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DictorsetmakerContext* dictorsetmaker();

  class  ClassdefContext : public antlr4::ParserRuleContext {
  public:
    ClassdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    ArglistContext *arglist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ClassdefContext* classdef();

  class  ArglistContext : public antlr4::ParserRuleContext {
  public:
    ArglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArglistContext* arglist();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TestContext *> test();
    TestContext* test(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *STAR();
    Comp_forContext *comp_for();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentContext* argument();

  class  Comp_iterContext : public antlr4::ParserRuleContext {
  public:
    Comp_iterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Comp_forContext *comp_for();
    Comp_ifContext *comp_if();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_iterContext* comp_iter();

  class  Comp_forContext : public antlr4::ParserRuleContext {
  public:
    Comp_forContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    ExprlistContext *exprlist();
    antlr4::tree::TerminalNode *IN();
    Or_testContext *or_test();
    antlr4::tree::TerminalNode *ASYNC();
    Comp_iterContext *comp_iter();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_forContext* comp_for();

  class  Comp_ifContext : public antlr4::ParserRuleContext {
  public:
    Comp_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    Test_nocondContext *test_nocond();
    Comp_iterContext *comp_iter();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_ifContext* comp_if();

  class  Encoding_declContext : public antlr4::ParserRuleContext {
  public:
    Encoding_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Encoding_declContext* encoding_decl();

  class  Yield_exprContext : public antlr4::ParserRuleContext {
  public:
    Yield_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *YIELD();
    Yield_argContext *yield_arg();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Yield_exprContext* yield_expr();

  class  Yield_argContext : public antlr4::ParserRuleContext {
  public:
    Yield_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    TestContext *test();
    TestlistContext *testlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Yield_argContext* yield_arg();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};


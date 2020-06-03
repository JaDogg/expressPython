
// Generated from Python3.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Python3Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Python3Parser.
 */
class  Python3Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSingle_input(Python3Parser::Single_inputContext *ctx) = 0;
  virtual void exitSingle_input(Python3Parser::Single_inputContext *ctx) = 0;

  virtual void enterFile_input(Python3Parser::File_inputContext *ctx) = 0;
  virtual void exitFile_input(Python3Parser::File_inputContext *ctx) = 0;

  virtual void enterEval_input(Python3Parser::Eval_inputContext *ctx) = 0;
  virtual void exitEval_input(Python3Parser::Eval_inputContext *ctx) = 0;

  virtual void enterDecorator(Python3Parser::DecoratorContext *ctx) = 0;
  virtual void exitDecorator(Python3Parser::DecoratorContext *ctx) = 0;

  virtual void enterDecorators(Python3Parser::DecoratorsContext *ctx) = 0;
  virtual void exitDecorators(Python3Parser::DecoratorsContext *ctx) = 0;

  virtual void enterDecorated(Python3Parser::DecoratedContext *ctx) = 0;
  virtual void exitDecorated(Python3Parser::DecoratedContext *ctx) = 0;

  virtual void enterAsync_funcdef(Python3Parser::Async_funcdefContext *ctx) = 0;
  virtual void exitAsync_funcdef(Python3Parser::Async_funcdefContext *ctx) = 0;

  virtual void enterFuncdef(Python3Parser::FuncdefContext *ctx) = 0;
  virtual void exitFuncdef(Python3Parser::FuncdefContext *ctx) = 0;

  virtual void enterParameters(Python3Parser::ParametersContext *ctx) = 0;
  virtual void exitParameters(Python3Parser::ParametersContext *ctx) = 0;

  virtual void enterTypedargslist(Python3Parser::TypedargslistContext *ctx) = 0;
  virtual void exitTypedargslist(Python3Parser::TypedargslistContext *ctx) = 0;

  virtual void enterTfpdef(Python3Parser::TfpdefContext *ctx) = 0;
  virtual void exitTfpdef(Python3Parser::TfpdefContext *ctx) = 0;

  virtual void enterVarargslist(Python3Parser::VarargslistContext *ctx) = 0;
  virtual void exitVarargslist(Python3Parser::VarargslistContext *ctx) = 0;

  virtual void enterVfpdef(Python3Parser::VfpdefContext *ctx) = 0;
  virtual void exitVfpdef(Python3Parser::VfpdefContext *ctx) = 0;

  virtual void enterStmt(Python3Parser::StmtContext *ctx) = 0;
  virtual void exitStmt(Python3Parser::StmtContext *ctx) = 0;

  virtual void enterSimple_stmt(Python3Parser::Simple_stmtContext *ctx) = 0;
  virtual void exitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) = 0;

  virtual void enterSmall_stmt(Python3Parser::Small_stmtContext *ctx) = 0;
  virtual void exitSmall_stmt(Python3Parser::Small_stmtContext *ctx) = 0;

  virtual void enterExpr_stmt(Python3Parser::Expr_stmtContext *ctx) = 0;
  virtual void exitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) = 0;

  virtual void enterAnnassign(Python3Parser::AnnassignContext *ctx) = 0;
  virtual void exitAnnassign(Python3Parser::AnnassignContext *ctx) = 0;

  virtual void enterTestlist_star_expr(Python3Parser::Testlist_star_exprContext *ctx) = 0;
  virtual void exitTestlist_star_expr(Python3Parser::Testlist_star_exprContext *ctx) = 0;

  virtual void enterAugassign(Python3Parser::AugassignContext *ctx) = 0;
  virtual void exitAugassign(Python3Parser::AugassignContext *ctx) = 0;

  virtual void enterDel_stmt(Python3Parser::Del_stmtContext *ctx) = 0;
  virtual void exitDel_stmt(Python3Parser::Del_stmtContext *ctx) = 0;

  virtual void enterPass_stmt(Python3Parser::Pass_stmtContext *ctx) = 0;
  virtual void exitPass_stmt(Python3Parser::Pass_stmtContext *ctx) = 0;

  virtual void enterFlow_stmt(Python3Parser::Flow_stmtContext *ctx) = 0;
  virtual void exitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) = 0;

  virtual void enterBreak_stmt(Python3Parser::Break_stmtContext *ctx) = 0;
  virtual void exitBreak_stmt(Python3Parser::Break_stmtContext *ctx) = 0;

  virtual void enterContinue_stmt(Python3Parser::Continue_stmtContext *ctx) = 0;
  virtual void exitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) = 0;

  virtual void enterReturn_stmt(Python3Parser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(Python3Parser::Return_stmtContext *ctx) = 0;

  virtual void enterYield_stmt(Python3Parser::Yield_stmtContext *ctx) = 0;
  virtual void exitYield_stmt(Python3Parser::Yield_stmtContext *ctx) = 0;

  virtual void enterRaise_stmt(Python3Parser::Raise_stmtContext *ctx) = 0;
  virtual void exitRaise_stmt(Python3Parser::Raise_stmtContext *ctx) = 0;

  virtual void enterImport_stmt(Python3Parser::Import_stmtContext *ctx) = 0;
  virtual void exitImport_stmt(Python3Parser::Import_stmtContext *ctx) = 0;

  virtual void enterImport_name(Python3Parser::Import_nameContext *ctx) = 0;
  virtual void exitImport_name(Python3Parser::Import_nameContext *ctx) = 0;

  virtual void enterImport_from(Python3Parser::Import_fromContext *ctx) = 0;
  virtual void exitImport_from(Python3Parser::Import_fromContext *ctx) = 0;

  virtual void enterImport_as_name(Python3Parser::Import_as_nameContext *ctx) = 0;
  virtual void exitImport_as_name(Python3Parser::Import_as_nameContext *ctx) = 0;

  virtual void enterDotted_as_name(Python3Parser::Dotted_as_nameContext *ctx) = 0;
  virtual void exitDotted_as_name(Python3Parser::Dotted_as_nameContext *ctx) = 0;

  virtual void enterImport_as_names(Python3Parser::Import_as_namesContext *ctx) = 0;
  virtual void exitImport_as_names(Python3Parser::Import_as_namesContext *ctx) = 0;

  virtual void enterDotted_as_names(Python3Parser::Dotted_as_namesContext *ctx) = 0;
  virtual void exitDotted_as_names(Python3Parser::Dotted_as_namesContext *ctx) = 0;

  virtual void enterDotted_name(Python3Parser::Dotted_nameContext *ctx) = 0;
  virtual void exitDotted_name(Python3Parser::Dotted_nameContext *ctx) = 0;

  virtual void enterGlobal_stmt(Python3Parser::Global_stmtContext *ctx) = 0;
  virtual void exitGlobal_stmt(Python3Parser::Global_stmtContext *ctx) = 0;

  virtual void enterNonlocal_stmt(Python3Parser::Nonlocal_stmtContext *ctx) = 0;
  virtual void exitNonlocal_stmt(Python3Parser::Nonlocal_stmtContext *ctx) = 0;

  virtual void enterAssert_stmt(Python3Parser::Assert_stmtContext *ctx) = 0;
  virtual void exitAssert_stmt(Python3Parser::Assert_stmtContext *ctx) = 0;

  virtual void enterCompound_stmt(Python3Parser::Compound_stmtContext *ctx) = 0;
  virtual void exitCompound_stmt(Python3Parser::Compound_stmtContext *ctx) = 0;

  virtual void enterAsync_stmt(Python3Parser::Async_stmtContext *ctx) = 0;
  virtual void exitAsync_stmt(Python3Parser::Async_stmtContext *ctx) = 0;

  virtual void enterIf_stmt(Python3Parser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(Python3Parser::If_stmtContext *ctx) = 0;

  virtual void enterWhile_stmt(Python3Parser::While_stmtContext *ctx) = 0;
  virtual void exitWhile_stmt(Python3Parser::While_stmtContext *ctx) = 0;

  virtual void enterFor_stmt(Python3Parser::For_stmtContext *ctx) = 0;
  virtual void exitFor_stmt(Python3Parser::For_stmtContext *ctx) = 0;

  virtual void enterTry_stmt(Python3Parser::Try_stmtContext *ctx) = 0;
  virtual void exitTry_stmt(Python3Parser::Try_stmtContext *ctx) = 0;

  virtual void enterWith_stmt(Python3Parser::With_stmtContext *ctx) = 0;
  virtual void exitWith_stmt(Python3Parser::With_stmtContext *ctx) = 0;

  virtual void enterWith_item(Python3Parser::With_itemContext *ctx) = 0;
  virtual void exitWith_item(Python3Parser::With_itemContext *ctx) = 0;

  virtual void enterExcept_clause(Python3Parser::Except_clauseContext *ctx) = 0;
  virtual void exitExcept_clause(Python3Parser::Except_clauseContext *ctx) = 0;

  virtual void enterSuite(Python3Parser::SuiteContext *ctx) = 0;
  virtual void exitSuite(Python3Parser::SuiteContext *ctx) = 0;

  virtual void enterTest(Python3Parser::TestContext *ctx) = 0;
  virtual void exitTest(Python3Parser::TestContext *ctx) = 0;

  virtual void enterTest_nocond(Python3Parser::Test_nocondContext *ctx) = 0;
  virtual void exitTest_nocond(Python3Parser::Test_nocondContext *ctx) = 0;

  virtual void enterLambdef(Python3Parser::LambdefContext *ctx) = 0;
  virtual void exitLambdef(Python3Parser::LambdefContext *ctx) = 0;

  virtual void enterLambdef_nocond(Python3Parser::Lambdef_nocondContext *ctx) = 0;
  virtual void exitLambdef_nocond(Python3Parser::Lambdef_nocondContext *ctx) = 0;

  virtual void enterOr_test(Python3Parser::Or_testContext *ctx) = 0;
  virtual void exitOr_test(Python3Parser::Or_testContext *ctx) = 0;

  virtual void enterAnd_test(Python3Parser::And_testContext *ctx) = 0;
  virtual void exitAnd_test(Python3Parser::And_testContext *ctx) = 0;

  virtual void enterNot_test(Python3Parser::Not_testContext *ctx) = 0;
  virtual void exitNot_test(Python3Parser::Not_testContext *ctx) = 0;

  virtual void enterComparison(Python3Parser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(Python3Parser::ComparisonContext *ctx) = 0;

  virtual void enterComp_op(Python3Parser::Comp_opContext *ctx) = 0;
  virtual void exitComp_op(Python3Parser::Comp_opContext *ctx) = 0;

  virtual void enterStar_expr(Python3Parser::Star_exprContext *ctx) = 0;
  virtual void exitStar_expr(Python3Parser::Star_exprContext *ctx) = 0;

  virtual void enterExpr(Python3Parser::ExprContext *ctx) = 0;
  virtual void exitExpr(Python3Parser::ExprContext *ctx) = 0;

  virtual void enterXor_expr(Python3Parser::Xor_exprContext *ctx) = 0;
  virtual void exitXor_expr(Python3Parser::Xor_exprContext *ctx) = 0;

  virtual void enterAnd_expr(Python3Parser::And_exprContext *ctx) = 0;
  virtual void exitAnd_expr(Python3Parser::And_exprContext *ctx) = 0;

  virtual void enterShift_expr(Python3Parser::Shift_exprContext *ctx) = 0;
  virtual void exitShift_expr(Python3Parser::Shift_exprContext *ctx) = 0;

  virtual void enterArith_expr(Python3Parser::Arith_exprContext *ctx) = 0;
  virtual void exitArith_expr(Python3Parser::Arith_exprContext *ctx) = 0;

  virtual void enterTerm(Python3Parser::TermContext *ctx) = 0;
  virtual void exitTerm(Python3Parser::TermContext *ctx) = 0;

  virtual void enterFactor(Python3Parser::FactorContext *ctx) = 0;
  virtual void exitFactor(Python3Parser::FactorContext *ctx) = 0;

  virtual void enterPower(Python3Parser::PowerContext *ctx) = 0;
  virtual void exitPower(Python3Parser::PowerContext *ctx) = 0;

  virtual void enterAtom_expr(Python3Parser::Atom_exprContext *ctx) = 0;
  virtual void exitAtom_expr(Python3Parser::Atom_exprContext *ctx) = 0;

  virtual void enterAtom(Python3Parser::AtomContext *ctx) = 0;
  virtual void exitAtom(Python3Parser::AtomContext *ctx) = 0;

  virtual void enterTestlist_comp(Python3Parser::Testlist_compContext *ctx) = 0;
  virtual void exitTestlist_comp(Python3Parser::Testlist_compContext *ctx) = 0;

  virtual void enterTrailer(Python3Parser::TrailerContext *ctx) = 0;
  virtual void exitTrailer(Python3Parser::TrailerContext *ctx) = 0;

  virtual void enterSubscriptlist(Python3Parser::SubscriptlistContext *ctx) = 0;
  virtual void exitSubscriptlist(Python3Parser::SubscriptlistContext *ctx) = 0;

  virtual void enterSubscript(Python3Parser::SubscriptContext *ctx) = 0;
  virtual void exitSubscript(Python3Parser::SubscriptContext *ctx) = 0;

  virtual void enterSliceop(Python3Parser::SliceopContext *ctx) = 0;
  virtual void exitSliceop(Python3Parser::SliceopContext *ctx) = 0;

  virtual void enterExprlist(Python3Parser::ExprlistContext *ctx) = 0;
  virtual void exitExprlist(Python3Parser::ExprlistContext *ctx) = 0;

  virtual void enterTestlist(Python3Parser::TestlistContext *ctx) = 0;
  virtual void exitTestlist(Python3Parser::TestlistContext *ctx) = 0;

  virtual void enterDictorsetmaker(Python3Parser::DictorsetmakerContext *ctx) = 0;
  virtual void exitDictorsetmaker(Python3Parser::DictorsetmakerContext *ctx) = 0;

  virtual void enterClassdef(Python3Parser::ClassdefContext *ctx) = 0;
  virtual void exitClassdef(Python3Parser::ClassdefContext *ctx) = 0;

  virtual void enterArglist(Python3Parser::ArglistContext *ctx) = 0;
  virtual void exitArglist(Python3Parser::ArglistContext *ctx) = 0;

  virtual void enterArgument(Python3Parser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(Python3Parser::ArgumentContext *ctx) = 0;

  virtual void enterComp_iter(Python3Parser::Comp_iterContext *ctx) = 0;
  virtual void exitComp_iter(Python3Parser::Comp_iterContext *ctx) = 0;

  virtual void enterComp_for(Python3Parser::Comp_forContext *ctx) = 0;
  virtual void exitComp_for(Python3Parser::Comp_forContext *ctx) = 0;

  virtual void enterComp_if(Python3Parser::Comp_ifContext *ctx) = 0;
  virtual void exitComp_if(Python3Parser::Comp_ifContext *ctx) = 0;

  virtual void enterEncoding_decl(Python3Parser::Encoding_declContext *ctx) = 0;
  virtual void exitEncoding_decl(Python3Parser::Encoding_declContext *ctx) = 0;

  virtual void enterYield_expr(Python3Parser::Yield_exprContext *ctx) = 0;
  virtual void exitYield_expr(Python3Parser::Yield_exprContext *ctx) = 0;

  virtual void enterYield_arg(Python3Parser::Yield_argContext *ctx) = 0;
  virtual void exitYield_arg(Python3Parser::Yield_argContext *ctx) = 0;


};


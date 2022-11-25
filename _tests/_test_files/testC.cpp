
/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: testC.cpp
 *  test unit functionality of functions
 *  ensure all functions work as intended 
 * ************************************************************************* */

#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

//TEST FILES ----------------------------------------------------------------|
#include "../../includes/node/node.h"
#include "../../includes/plotter/plot.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/data_pkg/tk_data.h"
#include "../../includes/data_pkg/graph_info.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
/* ========================================================================= *
 * GRAPHICS 
 * ========================================================================= */
#include "../../includes/Graphics/animate.h"
#include "../../includes/Graphics/system.h"
#include "../../includes/Graphics/sidebar.h"
/* ========================================================================= *
 * TOKEN FILES
 * ========================================================================= */
#include "../../includes/token/token.h"
#include "../../includes/token/double.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
/* ========================================================================= *
 * TOKENIZER - SHUNTING YARD - RPN 
 * ========================================================================= */
#include "../../includes/rpn/rpn.h"
#include "../../includes/tokenizer/tokenizer.h"
#include "../../includes/shunting_yard/shunting_yard.h"
//----------------------------------------------------------------------------|

const bool debug = false;

class Test_TKN_SY_RPN : public testing::Test{
  protected:
  std::string expected;
  std::string output;
  tokenizer Tr;
  ShuntingYard Sy;
  RPN Rn;
};

/* ========================================================================= *
 * TOKENIZER UNIT TESTS
 * ========================================================================= */
//set string
TEST_F(Test_TKN_SY_RPN, TK_SET_STR){
  expected = "wokers123*2948!!$!";
  Tr.set_str("wokers123*2948!!$!");
  output = Tr.get_str();
  EXPECT_EQ(output,expected);
}
//set infix
TEST_F(Test_TKN_SY_RPN, TK_SET_INFIX){
  expected = "[1][+][2][+][3]";
  Tr.set_str("1+2");
  Tr.set_infix(Tr.tokenize());
  Tr.set_str("+3");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//basic add
TEST_F(Test_TKN_SY_RPN, TK_NUM_ADD){
  expected = "[1][+][2]";
  Tr.set_str("1+2");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//unary minus operator
TEST_F(Test_TKN_SY_RPN, TK_UNARY_NEG){
  expected = "[$][4]";
  Tr.set_str("-4");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//minus operator
TEST_F(Test_TKN_SY_RPN, TK_MINUS){
  expected = "[1][-][4]";
  Tr.set_str("1-4");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//basic parenthesis
TEST_F(Test_TKN_SY_RPN, TK_PAREN){
  expected = "[(][7][)]";
  Tr.set_str("(7)");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//predefined function
TEST_F(Test_TKN_SY_RPN, TK_PREDEF_FUNCT){
  expected = "[sin][x]";
  Tr.set_str("sinx");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//composite function(2)
TEST_F(Test_TKN_SY_RPN, TK_COMP_FUNCT){
  expected = "[(][5][+][(][9][)][)]";
  Tr.set_str("B");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//composite function + num(1)
TEST_F(Test_TKN_SY_RPN, TK_COMP_FUNCT_PLUS_1){
  expected = "[(][5][+][(][9][)][)][+][1]";
  Tr.set_str("B+1");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//complex expression 
TEST_F(Test_TKN_SY_RPN, TK_COMPLEX_1){
  expected = "[9][*][8][/][4][^][5][+][sin][x][-][4]";
  Tr.set_str("9*8/4^5+sinx-4");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}

/* ========================================================================= *
 * SHUNTING YARD UNIT TESTS -{if any tokenzier test fail invalidate these test}
 * ========================================================================= */
//addition
TEST_F(Test_TKN_SY_RPN, SY_ADD){
  expected = "[3][5][+]";
  Tr.set_str("3+5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//subtraction
TEST_F(Test_TKN_SY_RPN, SY_SUB){
  expected = "[3][5][-]";
  Tr.set_str("3-5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//multiplication
TEST_F(Test_TKN_SY_RPN, SY_MULTI){
  expected = "[3][5][*]";
  Tr.set_str("3*5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//division
TEST_F(Test_TKN_SY_RPN, SY_DIVIDE){
  expected = "[3][5][/]";
  Tr.set_str("3/5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//exponent
TEST_F(Test_TKN_SY_RPN, SY_EXPONENT){
  expected = "[3][5][^]";
  Tr.set_str("3^5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//complex expression
TEST_F(Test_TKN_SY_RPN, SY_COMPLEX_1){
  expected = "[3][18][9][/][3][3][^][*][+][10][-]";
  Tr.set_str("3+18/9*3^3-10");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}

/* ========================================================================= *
 * RPN UNIT TESTS -{if any shunting_yard test fail invalidate these test}
 * ========================================================================= */


//wip



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testC.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}



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

//TEST FILES -----------------------------------------------------------------|
#include "../../includes/node/node.h"
#include "../../includes/plotter/plot.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/data_pkg/tk_data.h"
#include "../../includes/data_pkg/graph_info.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
// ---------------------------------------------------------------------------|
#include "../../includes/Graphics/animate.h"
#include "../../includes/Graphics/system.h"
#include "../../includes/Graphics/sidebar.h"
//----------------------------------------------------------------------------|
#include "../../includes/token/token.h"
#include "../../includes/token/double.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
// ---------------------------------------------------------------------------| 
#include "../../includes/rpn/rpn.h"
#include "../../includes/tokenizer/tokenizer.h"
#include "../../includes/shunting_yard/shunting_yard.h"
//----------------------------------------------------------------------------|

const bool debug = true;

class Test_TKN_SY_RPN : public testing::Test{
  protected:
  std::string expected;
  std::string output;
  tokenizer Tr;
  ShuntingYard Sy;
  RPN Rn;
};

class Test_Tokenizer : public testing::Test,public tokenizer{
    protected:
    //only need to test these since they dont have one return path
    int testNon(std::string a){
      return Non(a);
    }
    int testNum(std::string a){
      return Num(a);
    }      
    int testOper(std::string a){
      return Oper(a);
    }       
    int testAlpha(std::string a){
      return Alpha(a);
    }      
    int testFunct(std::string a){
      return Funct(a);
    }                      
};

/* ========================================================================= *
 * TOKENIZER UNIT TESTS
 * ========================================================================= */
//number string
TEST_F(Test_Tokenizer, Non_isNum){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testNon("4");
  EXPECT_EQ(output,NUM);
}
//non_number string
TEST_F(Test_Tokenizer, Non_is_notNum){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testNon("+");
  EXPECT_EQ(output,OPER);
}
//Num and is a num
TEST_F(Test_Tokenizer, Num_is_Num_single){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testNum("8");
  EXPECT_EQ(output,NUM);
}
//num and is not a num
TEST_F(Test_Tokenizer, Num_is_notNum){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testNum("*");
  EXPECT_EQ(output,ACCEPT);
}
//operator is operator
TEST_F(Test_Tokenizer, Oper_is_Oper){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("+");
  EXPECT_EQ(output,ACCEPT);
}
//operator is lp
TEST_F(Test_Tokenizer, Oper_is_LP){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("(");
  EXPECT_EQ(output,LP);
}
//operator is rp
TEST_F(Test_Tokenizer, Oper_is_RP){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper(")");
  EXPECT_EQ(output,RP);
}
//operator is not an operator
TEST_F(Test_Tokenizer, Oper_is_NotOper){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("b");
  EXPECT_EQ(output,ALPH);
}
//alphabetical single
TEST_F(Test_Tokenizer, Alph_single){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("b");
  EXPECT_EQ(output,ALPH);
}
//multiple alphabetical
TEST_F(Test_Tokenizer, Alph_mutli){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("ba");
  EXPECT_EQ(output,ALPH);
}
//function does not match list
TEST_F(Test_Tokenizer, Funct_Not_Match){
  if(!debug){
    GTEST_SKIP();
  }
  int output = testOper("sih");
  EXPECT_EQ(output,ALPH);
}

//---------------------------------------------------------------------------
//set string
TEST_F(Test_TKN_SY_RPN, TK_SET_STR){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "wokers123*2948!!$!";
  Tr.set_str("wokers123*2948!!$!");
  output = Tr.get_str();
  EXPECT_EQ(output,expected);

}
//set infix
TEST_F(Test_TKN_SY_RPN, TK_SET_INFIX){
  if(!debug){
    GTEST_SKIP();
  }
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
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[1][+][2]";
  Tr.set_str("1+2");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//unary minus operator
TEST_F(Test_TKN_SY_RPN, TK_UNARY_NEG){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[$][4]";
  Tr.set_str("-4");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//minus operator
TEST_F(Test_TKN_SY_RPN, TK_SUBTRACT){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[1][-][4]";
  Tr.set_str("1-4");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//basic parenthesis
TEST_F(Test_TKN_SY_RPN, TK_PAREN){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[(][7][)]";
  Tr.set_str("(7)");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//predefined function
TEST_F(Test_TKN_SY_RPN, TK_PREDEF_FUNCT){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[sin][x]";
  Tr.set_str("sinx");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//composite function(2)
TEST_F(Test_TKN_SY_RPN, TK_COMP_FUNCT){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[(][5][+][(][9][)][)]";
  Tr.set_str("B");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//composite function + num(1)
TEST_F(Test_TKN_SY_RPN, TK_COMP_FUNCT_PLUS_1){
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[(][5][+][(][9][)][)][+][1]";
  Tr.set_str("B+1");
  Tr.tokenize();
  output = Tr.get_infix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//complex expression 1
TEST_F(Test_TKN_SY_RPN, TK_COMPLEX_1){
  if(!debug){
    GTEST_SKIP();
  }
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
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[3][5][+]";
  Tr.set_str("3+5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//subtraction
TEST_F(Test_TKN_SY_RPN, SY_SUBTRACT){
  if(!debug){
    GTEST_SKIP();
  }
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
  if(!debug){
    GTEST_SKIP();
  }
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
  if(!debug){
    GTEST_SKIP();
  }
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
  if(!debug){
    GTEST_SKIP();
  }
  expected = "[3][5][^]";
  Tr.set_str("3^5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Sy.postfix();
  output = Sy.get_postfix().get_queue_str();
  EXPECT_EQ(output,expected);
}
//complex expression 1
TEST_F(Test_TKN_SY_RPN, SY_COMPLEX_1){
  if(!debug){
    GTEST_SKIP();
  }
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
//addition
TEST_F(Test_TKN_SY_RPN, RPN_ADD){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("3+5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,8);
}
//subtraction
TEST_F(Test_TKN_SY_RPN, RPN_SUBTRACT){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("3-5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,-2);
}
//multiplication
TEST_F(Test_TKN_SY_RPN, RPN_MULTIPLY){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("3*5");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,15);
}
//division
TEST_F(Test_TKN_SY_RPN, RPN_DIVIDE){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("18/9");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,2);
}
//exponent
TEST_F(Test_TKN_SY_RPN, RPN_EXPONENT){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("2^3");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,8);
}
//instantiate x with set_instan()
TEST_F(Test_TKN_SY_RPN, RPN_INSTAN_1){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("x+2");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  Rn.set_instan(4);
  int output = Rn();
  EXPECT_EQ(output,6);
} //FAIL_COUNT: 1
//instantiate x with rpn(x)
TEST_F(Test_TKN_SY_RPN, RPN_INSTAN_2){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("x+2");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn(4);
  EXPECT_EQ(output,6);
}
//complex expression 1
TEST_F(Test_TKN_SY_RPN, RPN_COMPLEX_1){
  if(!debug){
    GTEST_SKIP();
  }
  Tr.set_str("3+18/9*3^3-10");
  Tr.tokenize();
  Sy.set_infix(Tr.get_infix());
  Rn.set_input(Sy.postfix());
  int output = Rn();
  EXPECT_EQ(output,47);
}

//TESTING INFO----
//testing::GTEST_FLAG(filter) = "Test_TKN_SY_RPN.SY_ADD";  //how to just run one specific test
//testing::GTEST_FLAG(filter) = "-Test_TKN_SY_RPN.SY_ADD"; //how to just exclude one specific test from running 
                                                          //(we add "-" in front of name)
//this stuff will be included in the main()
/*
we can also do 
if(debug){
  GTEST_SKIP();
}
and change the debug to skip a test
*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n|-* * * * * * * * running testC.cpp * * * * * * * *-|\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


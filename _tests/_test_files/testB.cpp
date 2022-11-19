#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;

//TEST FILES ------------------------------------------------------>[]
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/token/token.h"
#include "../../includes/token/tk_string.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/token/double.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/tk_data/tk_data.h"
//++++++++++ ------------------------------------------------------>[]

void title(string name){
  cout << "\033[1;33mTEST [ \033[0m" << name << "\033[1;33m ] \033[0m"<<"\033[1;43m::\033[0m"<<endl;
}
void t(string s){
  if(s==""){
    cout<<endl;
    return;
  }
  cout<<"\033[1;33m|\033[0m"<<s<< "\033[1;33m \033[0m"<<endl;
}
void t(string s,int a){
  if(a>0){
    cout<<endl;
  }
  else if(a<0){
    cout<<s<<endl;
    return;
  }
  cout<<"\033[1;33m|\033[0m"<<s<< "\033[1;33m \033[0m";
}
/*
t() FUNCT:
default: str with yellow arrow endl;
0 = no endl
-1 = no yellow arrow
"" = just endl
*/
void border(){
  cout << "\033[1;32m-------------------------- \033[0m"<<endl;
}
//green border 
void end(){
  cout <<endl<< "\033[1;35m ALL SUB_TEST PROCESSES {FINISHED}  \033[0m"<<endl;
}
void end(int a){
  if(a>0){
  cout <<endl<< "\033[1;35m TEST {FINISHED}  \033[0m"<<endl;
  return;
  }
  else
  cout <<endl<< "\033[1;31m NO_TEST_RAN  \033[0m"<<endl;
}
/*
end() FUNCT:
default : sub process
int arg : TEST process
*/

template <typename ITEM_TYPE>
string outputV2(node<ITEM_TYPE>* head){
  node<ITEM_TYPE> * wlk = head;
  string result ="";
  while(wlk->_next != nullptr){
    result = result + to_string(wlk->_item) + ",";
    wlk = wlk->_next;
  }
    result = result + to_string(wlk->_item) + "";
  return result;
}

template <typename ITEM_TYPE>
void check(string expected, node<ITEM_TYPE> *  a){
  int status;
  string A = outputV2(a);
  if(expected==A){
    status = 0;
  }
  else{
    status = -1;
  }
  switch(status){
    case 0:
      cout <<endl<<"\033[1;32m PASSED \033[0m"<<endl;
    break;
    case -1:
      cout <<endl<< "\033[1;31m FAILED  : \033[0m"<<endl<<A<<endl;
      cout << "\033[1;33m EXPECTED: \033[0m"<<endl<<expected<<endl;
    break;
  }
}
void check(string expected,bool A){
  int status;
  string res;
  if(A){
    res = "true";
  }
  else{
    res = "false";
  }
  if(res == expected){
    status = 0;
  }
  else{
    status = -1;
  }
  switch(status){
    case 0:
      cout <<endl<<"\033[1;32m PASSED \033[0m"<<endl;
    break;
    case -1:
      cout <<endl<< "\033[1;31m FAILED  : \033[0m"<<endl<<res<<endl;
      cout << "\033[1;33m EXPECTED: \033[0m"<<endl<<expected<<endl;
    break;
  }
  
}

/* TEST SHELL
bool name_test(bool debug = true){
  if(debug==false){
    title("");

    end();
    border();
  }
  
  //------------
  end(0);
  return true;
}

TEST(PROJ, TEST){
  bool sucess = name_test(true);
  EXPECT_EQ(sucess, true);
}
*/


/* SUB_TEST SHELL
if(debug==false){
    title("");

    end();
    border();
  }
*/



bool token_test(bool debug = true){
  if(debug==false){
  title("SYNTAX queue<..> test");
    Queue<Token*> test;
    test.push(new Integer(5));
    test.push(new Integer(4));
    test.push(new Operator("*"));
    test.push(new Operator("-"));
    test.push(new Operator("/"));
    test.push(new Operator("+"));
    test.print_pointers();
    t("token* T = test.front()");
    Token* T = test.front();
    t("T :");
    cout<<T<<endl;
    t("*T :");
    cout<<*T<<endl;
    t("T->TypeOf() :");
    cout<<T->TypeOf()<<endl;
    t("static_cast<Integer*>(test[0])->IntegerOnly() :");
    cout<<static_cast<Integer*>(test.front())->get_val()<<endl;
    end();
    border();
  }
  if(debug==false){
    title("STRING -> Prefix {no input}");
    string t = "5*4+3";
   // Tk_string test(t.c_str());
   // test.tokenize();
  //  test.get_prefix().print_pointers();

    end();
    border();
  }
  if(debug==false){
    title("STRING -> Prefix {input}");
    string input;
    cin>>input;
  //  Tk_string test2(input.c_str());
    //test2.tokenize();
    t("POST_FIX: ");
    t("",0);
 //   test2.get_prefix().print_pointers();

    end();
    border();
  }

  //---------
  end(0);
  return true;
}

bool shunting_yard_test(bool debug = true){
  if(debug){
    title("USER_INPUT");
//  //   Tk_string test2;
//     // test2.custom_funct();
//     string input;
//     int var;
//     cout<<"enter equation:";
//     cin>>input;
//  //   test2.set_string(input);
//     t("PRE_FIX: ");
//     t("",0);
//   //  test2.get_prefix(1).print_pointers();
//     cout<<endl;
//    // Queue<Token*> test = test2.get_prefix();
//     ShuntingYard sy(test);
//     t("POST_FIX: ");
//     t("",0);
//     sy.postfix().print_pointers();
//     RPN result(sy.postfix());
//     cout<<endl<<"["<<input<<"; x= 2:]"<<result();
    
  
    end();
    border();
  }
  
  //------------
  end(1);
  return true;
}


bool rpn_test(bool debug = true){
 if(debug==false){
//   title("RPN TEST| MANUAL QUEUE");
//   Queue<Token*> test;
//   test.push(new Integer(5));
//   test.push(new Integer(4));
//   test.push(new Operator("*"));
//   test.push(new Integer("3"));
//   test.push(new Operator("+"));
//   t("POST_FIX: ");
//   t("",0);
//   test.print_pointers();
//   RPN eq(test);
  
//   t("5*4+3 = ",1);
//   cout<<eq.rpn_process();
//     end();
//     border();
//  }
  
//   if(debug==false){
//     title("DELIMITER CHECK");
//       string t = "5,4,*,3,+";
//  //     Tk_string test(t.c_str());
//      // test.tokenize();
//       // t("POST_FIX: ");
//       // t("",0);
//    //   test.get_prefix().print_pointers();

    end();
    border();
  }

  //------------
  end(0);
  return true;
}

bool tk_str_test(bool debug = true){
  if(debug==false){
    title("TK_DATA");
    tk_data test(OPERATOR,"+");
    cout<<test;
    end();
    border();
  }
  
  if(debug==false){
    title("TK_STR");
    tk_data s;
  //  Tk_string a("5*60+100");
    //a.tokenize();
   // a.Print();
    cout<<endl;

    end();
    border();
  }
  //------------
  end(0);
  return true;
}

TEST(SHUNTING_YARD, TOKEN_TEST){
  bool sucess = token_test(true);
  EXPECT_EQ(sucess, true);
}

TEST(SHUNTING_YARD, SHUNTING_YARD_TEST){
  bool sucess = shunting_yard_test(true);
  EXPECT_EQ(sucess, true);
}

TEST(SHUNTING_YARD, RPN_TEST){
  bool success =  rpn_test(true);
  EXPECT_EQ(success, true);
}

TEST(SHUNTING_YARD, TK_STR_TEST){
  bool success =  tk_str_test(true);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


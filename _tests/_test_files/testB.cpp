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
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/token/double.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/data_pkg/tk_data.h"
#include "../../includes/tokenizer/tokenizer.h"
#include "../../includes/data_pkg/graph_info.h"
#include "../../includes/plotter/plot.h"
#include "../../includes/plotter/translator.h"

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

bool shunting_yard_test(bool debug = true){
  if(debug==true){
    title("USER_INPUT");
      std::string input = "5+4";
      cout<<"EQUATION: "<<input<<";B=5+5"<<endl;
      
      tokenizer Tr;
      Tr.set_str(input);
      Tr.tokenize();
      cout<<endl<<"INFIX  : ";
      Tr.Print();
      cout<<endl;
      cout<<Tr.get_infix().get_queue_str();

      ShuntingYard Sy(Tr.get_infix());
      Sy.postfix();
      cout<<endl<<"POSTFIX: ";
      Sy.Print();

      RPN Rn;
      Rn.set_input(Sy.get_postfix());
      double answer = Rn(2);
      cout<<endl<<"ANSWER: "<<answer;
      

    end();
    border();
  }
  if(debug==true){
    Graph_info iu("x+5");
    iu.post_fix.print_pointers();
    iu.total_pts = 100;
    iu.set_eq_domain(-2,2);
    cout<<iu.Eq_domain.x<<"<>"<<iu.Eq_domain.y<<endl;
    Graph_info * gi = &iu;
    Plot P(gi);
    P.print2();
    P.create_plot_map();
    P.Print();
    cout<<P(1).x<<"|"<<P(1).y<<endl;
    cout<<"we finished";
    Translator T(gi);
    for(int i=0;i<iu.total_pts;i++){
    T.cart_to_sfml(P(i));
    T.print();
    }
  }
  //------------
  end(1);
  return true;
}

// TEST(SHUNTING_YARD, TOKEN_TEST){
//   bool sucess = token_test(true);
//   EXPECT_EQ(sucess, true);
// }

TEST(SHUNTING_YARD, SHUNTING_YARD_TEST){
  bool sucess = shunting_yard_test(true);
  EXPECT_EQ(sucess, true);
}

// TEST(SHUNTING_YARD, RPN_TEST){
//   bool success =  rpn_test(true);
//   EXPECT_EQ(success, true);
// }

// TEST(SHUNTING_YARD, TK_STR_TEST){
//   bool success =  tk_str_test(true);
//   EXPECT_EQ(success, true);
// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


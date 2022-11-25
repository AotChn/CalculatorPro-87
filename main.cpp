#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <map>

//TEST FILES ------------------------------------------------------>[]
#include "includes/node/node.h"
#include "includes/linked_list_functions/linked_list_functions.h"
#include "includes/token/token.h"
#include "includes/token/operator.h"
#include "includes/token/integer.h"
#include "includes/token/function.h"
#include "includes/token/leftparen.h"
#include "includes/token/rightparen.h"
#include "includes/token/function.h"
#include "includes/queue/MyQueue.h"
#include "includes/shunting_yard/shunting_yard.h"
#include "includes/rpn/rpn.h"
#include "includes/token/constants.h"
#include "includes/tokenizer/tokenizer.h"
#include "includes/Graphics/window.h"
#include "includes/Graphics/animate.h"
#include "includes/Graphics/system.h"
#include "includes/Graphics/sidebar.h"

//++++++++++ ------------------------------------------------------>[]
using namespace std;
void tkizer();
void function_map_test();
int main(int argv, char** argc) {
    cout << "\n\n"<< endl;


    Animate a;
    a.run();

    







    cout << "\n\n\n=====================" << endl;
    return 0;
}


void tkizer(){

}

void adjsfl(){
    //TESTING STRING PARSEING METHOD    
    string get="s=9;y=3;u=5";
    string::iterator a = get.begin()-1;
    int i=0;
    while(*a != '\0'){
        i++;
        if(*a != '='&&*a!= ';'){
            if(i%4==0){
             std::cout<<";"<<*a<<endl;   
            }
            else{
            std::cout<<*a;
            }
        }
        
        a++;
    }
}
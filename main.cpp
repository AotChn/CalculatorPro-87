#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

//TEST FILES ------------------------------------------------------>[]
#include "includes/node/node.h"
#include "includes/linked_list_functions/linked_list_functions.h"
#include "includes/token/token.h"
#include "includes/token/tk_string.h"
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
#include <map>
#include "includes/token/tok_string.h"
//++++++++++ ------------------------------------------------------>[]
using namespace std;
void tkizer();
void function_map_test();
int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;
    tokenizer a;
    std::string p = "a+b+6";
    a.pkg_type(p);

    cout << "\n\n\n=====================" << endl;
    return 0;
}

int funct1(int a,std::string b){
    int d = a;
    cout<<"huray1";
    cout<<b;
    return 1;
}
int funct2(int a,std::string b){
    int d = a;
    cout<<"huray2";
    cout<<b;
    funct1(a,b);
    return 2;
}
int funct3(int a,std::string b){
    int d = a;
    cout<<"huray3";
    cout<<b;
    return 3;
}
int funct4(int a,std::string b){
    int d = a;
    cout<<"huray4";
    cout<<b;
    return 4;
}
void function_map_test(){
    //TESTING STD::MAP CAPABLITIES
    using intsus = int(*)(int,std::string);
    int(*f1)(int,std::string) = &funct1;
    int(*f2)(int,std::string) = &funct2;
    int(*f3)(int,std::string) = &funct3;
    int(*f4)(int,std::string) = &funct4;
    std::map<int,intsus> funct_map = {{1,f1},{2,f2},{3,f3},{4,f4}};
    std::map<int,intsus>::iterator wlk = funct_map.begin();
    int i=1;
    while(wlk!=funct_map.end()){
    funct_map.at(i)(1,"yellow");
    wlk++;
    }
    cout<<endl;
    
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
// #ifndef TOKENIZER
// #define TOKENIZER

// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <string>
// #include <map>
// #include "token.h"
// #include "operator.h"
// #include "integer.h"
// #include "leftparen.h"
// #include "rightparen.h"
// #include "alpha.h"
// #include "../array_functions/array_functions.h"
// #include "constants.h"
// #include "../tk_data/tk_data.h"
// #include "../tk_data/function_data.h"
// #include "../array_functions/array_functions.h"

// enum STATES {NON,NUM,OPER,LP,RP,FUNCT,ALPH,INV,ACCEPT};
// const int MAX_STATES = 7;
// const int MAX_OUTPUT = 4;

// // int state_table[MAX_STATES][MAX_OUTPUT] = {/*STATES|   O1          O2         O3         O4  |*/
// //                                         /*--------------------------------------------------*/
// //                                           /*NON    |*/ {NUM,       OPER,      FUNCT,     INV},
// //                                           /*NUM    |*/ {NUM,       ACCEPT,    INV,       INV},
// //                                           /*OP     |*/ {OPER,      LP,        RP,        ACCEPT},
// //                                           /*ALPH   |*/ {ALPH,      FUNCT,     ACCEPT,    INV},
// //                                           /*FUNCT  |*/ {ACCEPT,    INV,       INV,       INV},
// //                                           /*LP     |*/ {LP,        ACCEPT,    INV,       INV},
// //                                           /*RP     |*/ {RP,        ACCEPT,    INV,       INV}
// //                                           };

// class Tokenizer{

// public:

// STATES Non(char key){
//     int abs = key-'0';
//     if(abs>=0&&abs<10){
//         return NUM;
//     }
//     else
//         return OPER;
// }
// STATES Num(char key){
//     int abs = key - '0';
//     set_ST(NUM);
//     if(abs>=0&&abs<10){
        
//         return NUM;
//     }
//     return ACCEPT;
// }

// STATES Oper(char key){
    
// }
// STATES LP();
// STATES RP();
// STATES Alph();
// STATES funct();
// STATES inv();
// int larry(int a){
//     return 4;
// }

// int (Tokenizer::*funct)(int) = &larry; //FUNCTION POINTER


// std::map<int,vector<std::string>> function = {{1,NUMERALS_},{2,OPERATORS_},{3,ALPHAS_}};

//     Tokenizer();
//     Tokenizer(std::string string);
    
//     void toekn();
//     TOKEN_TYPES get_type(STATES new_ST);

//     void set_string(string str);
//     void set_ST(STATES new_ST);
    
//     STATES get_ST(){return _curr_ST;}


// private: 
//     tk_data _token;
//     std::string _tk_str;
//     STATES _curr_ST;
//     STATES _prev_ST;
//     std::string::iterator _wlk;
// };


// #endif 
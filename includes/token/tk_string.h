// #ifndef TK_STRING_H
// #define TK_STRING_H
// #include <string>
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
// #include<iostream>
// #include<fstream>
// using namespace std;

// class Tk_string
// {
// public:
//     //ctor
//     Tk_string();
//     Tk_string(int value);
//     Tk_string(string tk_string);

//     //process
//     Tk_string& operator=(const Tk_string& RHS);
//     void tokenize(string str);
//     void process_edge();
//     void custom_funct();
//     void process_repeat(string wlk_str, int &i,std::string::iterator next,std::string::iterator wlk,tk_data _prev,tk_data _next);
//     tk_data process_minus(tk_data tk,tk_data _prev);
//     void create_tk(tk_data token,tk_data _prev);
//     tk_data set_type(char key,tk_data _prev);
//     void error_check(tk_data _prev);
//     void Print();
//     void open_file(int a);

//     void set_string(string str){
//         _tk_string = str;
//     }
    
//     //accessors
//     TOKEN_TYPES TypeOf(){return INTEGER;}
//     std::string get_str(){return _tk_string;}
//     Queue<Token*> get_prefix(int a){open_file(1);tokenize(_tk_string);return _prefix;}
//     Queue<Token*> get_prefix(){return _prefix;}
    
    
// private:
//     tk_data _tk;
//     tk_data _prev;
//     tk_data _next;
//     std::string _tk_string;
//     Queue<Token*> _prefix;
//     std::vector<funct_data> custom;
//     std::string composite;

    
// };

// #endif // INTEGER_H

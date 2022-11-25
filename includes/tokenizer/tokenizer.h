/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: tokenizer.h
 *  converts string to infix queue
 *  parses string into different types that then get packed as a token obj
 * ************************************************************************* */

#ifndef AOTS_TOK_STRING_H
#define AOTS_TOK_STRING_H

//|______________________STD_LIB____________________|
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include<iostream>
#include<fstream>
//|----------------MY LIBRARY FUNCTS----------------|
#include "../token/token.h"
#include "../token/alpha.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../token/constants.h"
#include "../data_pkg/tk_data.h"
#include "../data_pkg/function_data.h"
#include "../array_functions/array_functions.h"
//|__________________________________________________|

enum TK_STATES {NON,NUM,OPER,LP,RP,FUNCT,COMP,ALPH,INV,ACCEPT}; //POSSIBLE STATES
static std::map<std::string,int> pre_def_functs = {{"sin",147},{"cos",148},{"tan",149},
                                            {"arcsin",150},{"arccos",151},{"arctan",152},
                                            {"pi",153},{"log",154},{"ln",155},
                                            {"e",156},{"$",157},{"B",303},{"C",304}};
                                            
static std::map<std::string,std::string> user_funct = {{"B","5+C"},{"C","B"}};

class tokenizer{
public:

//CTOR
tokenizer(){_cur_ST = NON,_prev_ST = NON;}
tokenizer(std::string _str){_tk_string = _str;}

//MUTATORS
void set_str(std::string str){_tk_string = str;}
void set_infix(Queue<Token*> infix){_infix = infix;}

//ACCESSORS
void Print();
std::string get_str(){return _tk_string;}
Queue<Token*> get_infix(){return _infix;}
Queue<Token*> tokenize(){pkg_type(_tk_string);return _infix;}

protected:
//PROCESS

void pkg_type(std::string _str);
void pkg_token(int type);

//_ST_FUNCTS_______________|

int Non   (std::string key);
int Num   (std::string key);
int Oper  (std::string key);
int Lp    (std::string key);
int Rp    (std::string key);
int Alpha (std::string key);
int Funct (std::string key);
int Comp  (std::string key);
int Inv   (std::string key);
int Accept(std::string key);

//FUNCTION POINTERS TO _ST_FUNCTS___________________________|
int(tokenizer::*NONTYPE_ST) (std::string) = &tokenizer::Non;
int(tokenizer::*NUMBER_ST)  (std::string) = &tokenizer::Num;
int(tokenizer::*OPERAT_ST)  (std::string) = &tokenizer::Oper;
int(tokenizer::*LEFTP_ST)   (std::string) = &tokenizer::Lp;
int(tokenizer::*RIGHTP_ST)  (std::string) = &tokenizer::Rp;
int(tokenizer::*ALPHAB_ST)  (std::string) = &tokenizer::Alpha;
int(tokenizer::*FUNCT_ST)   (std::string) = &tokenizer::Funct;
int(tokenizer::*COMP_ST)    (std::string) = &tokenizer::Comp;
int(tokenizer::*INVAL_ST)   (std::string) = &tokenizer::Inv;
int(tokenizer::*ACCEPTED_ST)(std::string) = &tokenizer::Accept;

private:
//ALL POSSIBLE STATES
std::map<int,int(tokenizer::*)(std::string)> state_map = {{NON,NONTYPE_ST},{NUM,NUMBER_ST},{OPER,OPERAT_ST},
                                                          {LP,LEFTP_ST},   {RP,RIGHTP_ST},{ALPH,ALPHAB_ST},
                                                          {FUNCT,FUNCT_ST},{INV,INVAL_ST}, {COMP,COMP_ST},
                                                          {ACCEPT,ACCEPTED_ST}};

//TK STATES IN PROCESS
int _cur_ST; //current state
int _prev_ST; //previous state

//STR MANIPULTION
std::string hold ="";
std::string token = "";
std::string _tk_string;
std::string::iterator wlk; 

//FINAL PKG
tk_data tk;
Queue<Token*> _infix;

};

#endif 

/*TODO: 
    ASSIGN TYPE                     ->[CHECK]P1
    PKG TOKEN                       ->[CHECK]P2
    DEFINE INVALID INPUTS           ->[WIP]P3
    IMPLEMENT COMPOSITE FUNCTS      ->[CHECK]P4
    IMPLEMENT USER DEFINED FUNCTS   ->[WIP]P5
    [add more ...]
*/

// one way i think we can handle multiple instaniations is to have a private variable in the class
// called variable# in which we will ++ every time the class gets called to indicate another dependent 
// variable;

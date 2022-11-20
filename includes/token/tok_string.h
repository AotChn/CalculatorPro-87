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
#include "token.h"
#include "alpha.h"
#include "integer.h"
#include "operator.h"
#include "leftparen.h"
#include "rightparen.h"
#include "constants.h"
#include "../tk_data/tk_data.h"
#include "../tk_data/function_data.h"
#include "../array_functions/array_functions.h"
//|__________________________________________________|

/* +TOKENIZER+V4 +LOGIC + + + + + + + + + + + + + + + + + + + + + + +

-----OVERVIEW:
FSM WHICH TAKES IN STRING INPUT AND THEN CONVERTS TO INFIX TOKENS 
TO BE PROCESSED IN A SHUNTING YARD CLASS TO CONVERT TO POSTFIX-

START AT S0 AND THEN TRANSIONS TO ACCORDING STATE UNTIL ARRIVING 
AT AN ACCEPTING STATE-

ONCE ARRIVING AT ACCEPTING STATE WILL PKG TOKENS IN A WRAPPER (TK_DATA)
TO BE SENT TO ACCORDING CLASS TO CREATE TOKEN-

IMPLEMENTED IS AN INVALID STATE TO PROCESS INVALID INPUTS FROM USER- 

SINCE STATES ARE THEIR OWN FUNCTION WE ARE ABLE TO ADD ADDITIONAL STATES
BY DEFINING ANOTHER FUNCTION-

EACH STATE IS MAPPED TO A CORRESPONDING INT AND IS STORED AS A FUNCTION POINTER 
WHICH THEN WILL POINT TO A SEQUENCE OF EVENT STATES EVENTUALLY LEADING TO ACCEPTING STATE-

ENCAPSULATING FUNCTION CAN BE CALLED RECURSIVELY TO HANDLE COMPOSITE FUNCTIONS-
(in this process we will inject another string to tokenize in the middle of the main process)
we are able to do this because tokens are getting pushed to the infix queue char by char 
instead of all at once; 

WE CAN ALSO SET A PRE-INFIX AND ADD ON TO IT (store answer functionality?)

This is my 4th tokenizer iteration;
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +*/ 

enum TK_STATES {NON,NUM,OPER,LP,RP,FUNCT,ALPH,INV,ACCEPT}; //POSSIBLE STATES
std::map<std::string,int> pre_def_functs = {{"sin",147},{"cos",148},{"tan",149},
                                            {"arcsin",150},{"arccos",151},{"arctan",152},
                                            {"pi",153},{"log",154},{"ln",155},
                                            {"e",156},{"$",157}};

class tokenizer{
public:

//CTOR
tokenizer(){_cur_ST = NON,_prev_ST = NON;}
tokenizer(std::string _str){_tk_string = _str;}

//MUTATORS
void set_str(std::string str){_tk_string = str;}
void set_infix(Queue<Token*> infix){_infix = infix;}
Queue<Token*> tokenize(){pkg_type(_tk_string);return _infix;}

//ACCESSORS
Queue<Token*> infix(){return _infix;}
std::string get_str(){return _tk_string;}
void Print();

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
int Accept(std::string key);
int Inv   (std::string key);

//FUNCTION POINTERS TO _ST_FUNCTS_________________________|
int(tokenizer::*NONTYPE_ST)(std::string) = &tokenizer::Non;
int(tokenizer::*NUMBER_ST)(std::string) = &tokenizer::Num;
int(tokenizer::*OPERAT_ST)(std::string) = &tokenizer::Oper;
int(tokenizer::*LEFTP_ST)(std::string) = &tokenizer::Lp;
int(tokenizer::*RIGHTP_ST)(std::string) = &tokenizer::Rp;
int(tokenizer::*ALPHAB_ST)(std::string) = &tokenizer::Alpha;
int(tokenizer::*FUNCT_ST)(std::string) = &tokenizer::Funct;
int(tokenizer::*ACCEPTED_ST)(std::string) = &tokenizer::Accept;
int(tokenizer::*INVAL_ST)(std::string) = &tokenizer::Inv;



private:
std::map<int,int(tokenizer::*)(std::string)> state_map = {{NON,NONTYPE_ST},{NUM,NUMBER_ST},{OPER,OPERAT_ST},
                                                          {LP,LEFTP_ST},  {RP,RIGHTP_ST},{ALPH,ALPHAB_ST},
                                                          {FUNCT,FUNCT_ST},  {INV,INVAL_ST}, {ACCEPT,ACCEPTED_ST}};

//TK STATES IN PROCESS
int _cur_ST; 
int _prev_ST;

//STR STORAGE
std::string hold ="";
std::string token = "";
std::string _tk_string;
std::string::iterator wlk;

//FINAL PKG
Queue<Token*> _infix;
tk_data tk;

};

void tokenizer::Print(){ 
        _infix.print_pointers();
    }

void tokenizer::pkg_type(std::string _str){
    wlk = _str.begin();
    while(wlk != _str.cend()){
        _cur_ST = 0;
        int i = 0;
        while(_cur_ST!=ACCEPT){
            hold = *wlk;
            i = (this->*(state_map.at(i)))(hold); 
            //this how we call functions pointing to member functions
        }
    }
    cout<<"{end}";
}

int tokenizer::Non(std::string key){
 //   cout<<"PASSED NON->";
    _cur_ST = NON;
    token = "" + key;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        wlk++;
        return NUM;
    }
    return OPER;
}

int tokenizer::Num(std::string key){
 //   cout<<"PASSED NUM->";
    _cur_ST = NUM;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        token = token + key;
        wlk++;
        return NUM;
    }
    return ACCEPT;
}

int tokenizer::Oper(std::string key){
//    cout<<"PASSED OPER->";
    _cur_ST = OPER;
    if(str_vect_cmp(OPERATORS_,key)){
        if(key=="("){
            return LP;
        }
        else if(key==")"){
            return RP;
        }
        else if(key=="-"){
            if(_prev_ST==OPER||_prev_ST==LP||_prev_ST==NON){
                token = "$"; 
            }
        }
            wlk++;
            return ACCEPT;
    }
    token = "";
    return ALPH;
}

int tokenizer::Lp(std::string key){
//    cout<<"PASSED LP->";
    _cur_ST = LP;
    switch(_prev_ST){
        case ALPH:{}
        case NUM:{}
        case RP: {/*ADD * OPERATOR*/}
        default:
        {wlk++;return ACCEPT;}
    }
}

int tokenizer::Rp(std::string key){
//    cout<<"PASSED RP->";
    _cur_ST = RP;
    wlk++;
    return ACCEPT;
}

int tokenizer::Alpha(std::string key){
//    cout<<"PASSED ALPH->";
    _cur_ST = ALPH;
    if(str_vect_cmp(ALPHAS_,key)){
        token = token + key;
        wlk++;
        return FUNCT;
    }
    tk._id = 99;
    return ACCEPT;
}

int tokenizer::Funct(std::string key){
   // cout<<"PASSED FUNCT->";
    _cur_ST = FUNCT;
    if(pre_def_functs.find(token)!=pre_def_functs.end()){
        return ACCEPT;
    }
    return ALPH;
}

int tokenizer::Accept(std::string key){
   pkg_token(_cur_ST);
    _prev_ST = _cur_ST;
    cout<<"[TYPE:"<<_cur_ST<<"|TOKEN :"<<token<<"]STATE ACCEPT"<<endl;
    _cur_ST = ACCEPT;
    return 8;
}

int tokenizer::Inv(std::string key){
//INVALID INPUTS
}

void tokenizer::pkg_token(int type){
    tk._str = token;
    tk._type = type;
    switch(type){
        case NUM:
            _infix.push(new Integer(tk));
            break;
        case OPER:
            _infix.push(new Operator(tk));
            break;
        case FUNCT:
            _infix.push(new Function(tk));
            break;
        case LP:
            _infix.push(new LeftParen());
            break;
        case RP:
            _infix.push(new RightParen());
            break;
        case ALPH:
            _infix.push(new Function(tk));
            break;
    }
}

#endif 

/* ++ + + ++ + + + + + + + + + +  + 
THE ID SYSTEM :

ALL TOKENS WILL HAVE AN ASSOCIATIVE ID WHICH WILL CORRESPOND TO THEIR FUNCTIONALITY
THOUGH NOT PARTICUALLY IMPORTANT TO NUMERICAL IT CAN SERVE AS A WAY TO MAP OPERATIONS
IDS ARE INT VALUES AND WE CAN CATEGORIZE FUNCTIONS BY ID I.E. 
FUNCTIONS IN 100-150 could be functions that take in 2 arguments while functions in 
151-200 range can take in 2 aruguments etc.
THIS COULD ELIMINTE THE PRECEDENCE SYSTEM 

and even allow us to handle same name functions with different functions
ie '-' OPERATOR vs '-' UNARY OPERATOR
 + + + + + ++ + + + + + + ++ +  + +*/

/*TODO: 
    ASSIGN TYPE                     ->[CHECK]P1
    PKG TOKEN                       ->[CHECK]P2
    DEFINE INVALID INPUTS           ->[WIP]P3
    IMPLEMENT COMPOSITE FUNCTS      ->[WIP]P4
    IMPLEMENT USER DEFINED FUNCTS   ->[WIP]P5
    [add more ...]
*/

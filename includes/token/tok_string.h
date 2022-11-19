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

//PROCESS
void pkg_type(std::string _str);

//MUTATORS
void set_str(std::string str){_tk_string = str;}
void set_infix(Queue<Token*> infix){_infix = infix;}

//ACCESSORS
Queue<Token*> infix(){return _infix;}
std::string get_str(){return _tk_string;}


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
std::map<int,int(tokenizer::*)(std::string)> state_map = {{0,NONTYPE_ST},{1,NUMBER_ST},{2,OPERAT_ST},
                                                          {3,LEFTP_ST},  {4,RIGHTP_ST},{6,ALPHAB_ST},
                                                          {5,FUNCT_ST},  {7,INVAL_ST}, {8,ACCEPTED_ST}};

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

};

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
    cout<<"PASSED NON->";
    _cur_ST = NON;
    token = "" + key;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        wlk++;
        return NUM;
    }
    return OPER;
}

int tokenizer::Num(std::string key){
    cout<<"PASSED NUM->";
    _cur_ST = NUM;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        token = token + key;
        wlk++;
        return NUM;
    }
    return ACCEPT;
}

int tokenizer::Oper(std::string key){
    cout<<"PASSED OPER->";
    _cur_ST = OPER;
    if(str_vect_cmp(OPERATORS_,key)){
        if(key=="("){
            return LP;
        }
        else if(key==")"){
            return RP;
        }
        else if(key=="-"){
            switch(_prev_ST){
                case OPER:{}
                case NON:{}
                case LP: {return FUNCT;}
                default:{}
            }
        }
        wlk++;
        return ACCEPT;
    }
    token = "";
    return ALPH;
}

int tokenizer::Lp(std::string key){
    cout<<"PASSED LP->";
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
    cout<<"PASSED RP->";
    _cur_ST = RP;
    wlk++;
    return ACCEPT;
}

int tokenizer::Alpha(std::string key){
    cout<<"PASSED ALPH->";
    _cur_ST = ALPH;
    if(str_vect_cmp(ALPHAS_,key)){
        token = token + key;
        wlk++;
        return FUNCT;
    }
    return ACCEPT;
}

int tokenizer::Funct(std::string key){
    cout<<"PASSED FUNCT->";
    _cur_ST = FUNCT;
    if(pre_def_functs.find(token)!=pre_def_functs.end()){
        wlk++;
        return ACCEPT;
    }
    return ALPH;
}

int tokenizer::Accept(std::string key){
    _prev_ST = _cur_ST;
    _cur_ST = ACCEPT;
    cout<<"[TYPE:"<<_prev_ST<<"|TOKEN :"<<token<<"]STATE ACCEPT"<<endl;
    return 8;
}

int tokenizer::Inv(std::string key){
//INVALID INPUTS
}


#endif 

/*TODO: 
    ASSIGN TYPE                     ->[CHECK]
    PKG TOKEN                       ->[WIP]
    DEFINE INVALID INPUTS           ->[WIP]
    IMPLEMENT COMPOSITE FUNCTS      ->[WIP]
    IMPLEMENT USER DEFINED FUNCTS   ->[WIP]
    [add more ...]
*/

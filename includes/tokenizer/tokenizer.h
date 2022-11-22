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
#include "../data_pkg/tk_data.h"
#include "../data_pkg/function_data.h"
#include "../array_functions/array_functions.h"
//|__________________________________________________|

enum TK_STATES {NON,NUM,OPER,LP,RP,FUNCT,COMP,ALPH,INV,ACCEPT}; //POSSIBLE STATES
std::map<std::string,int> pre_def_functs = {{"sin",147},{"cos",148},{"tan",149},
                                            {"arcsin",150},{"arccos",151},{"arctan",152},
                                            {"pi",153},{"log",154},{"ln",155},
                                            {"e",156},{"$",157},{"B",303},{"C",304}};
                                            
std::map<std::string,std::string> user_funct = {{"B","5+C"},{"C","B"}};

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
Queue<Token*> get_infix(){return _infix;}
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
int Comp  (std::string key);
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
int(tokenizer::*COMP_ST)(std::string) = &tokenizer::Comp;
int(tokenizer::*ACCEPTED_ST)(std::string) = &tokenizer::Accept;
int(tokenizer::*INVAL_ST)(std::string) = &tokenizer::Inv;

private:
std::map<int,int(tokenizer::*)(std::string)> state_map = {{NON,NONTYPE_ST},{NUM,NUMBER_ST},{OPER,OPERAT_ST},
                                                          {LP,LEFTP_ST},  {RP,RIGHTP_ST},{ALPH,ALPHAB_ST},
                                                          {FUNCT,FUNCT_ST},  {INV,INVAL_ST}, {COMP,COMP_ST},
                                                          {ACCEPT,ACCEPTED_ST}};

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
 //   cout<<"{end}";
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
 //  cout<<"PASSED FUNCT->";
    _cur_ST = FUNCT;
    if(pre_def_functs.find(token)!=pre_def_functs.end()){
        if(pre_def_functs[token]>300){
            return COMP;
        }
        return ACCEPT;
        }
    return ALPH;
}
int tokenizer::Comp (std::string key){
    _cur_ST = COMP;
    hold = user_funct[token];
    pkg_token(LP);
    tokenizer Inject(hold);
    Inject.set_infix(_infix);
    Inject.tokenize();
    _infix = Inject.get_infix();
    pkg_token(RP);
    return ACCEPT;
}
int tokenizer::Accept(std::string key){
    pkg_token(_cur_ST);
    _prev_ST = _cur_ST;
    //cout<<"[TYPE:"<<_cur_ST<<"|TOKEN :"<<token<<"]STATE ACCEPT"<<endl;
    _cur_ST = ACCEPT;
    return ACCEPT;
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

/*TODO: 
    ASSIGN TYPE                     ->[CHECK]P1
    PKG TOKEN                       ->[CHECK]P2
    DEFINE INVALID INPUTS           ->[WIP]P3
    IMPLEMENT COMPOSITE FUNCTS      ->[WIP]P4
    IMPLEMENT USER DEFINED FUNCTS   ->[WIP]P5
    [add more ...]
*/
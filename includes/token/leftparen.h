/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: leftparen.h
 * handles left parenthesis tokens
 * (
 * ************************************************************************* */

#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include <string>
#include "token.h"
using namespace std;

class LeftParen : public Token
{
public:
    LeftParen();

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return LPAREN;}
    
    //accessors
    string get_str(){return _info._str;} 
    int get_type(){return _info._type;}

private:
    struct tk_data _info;
};

#endif // 
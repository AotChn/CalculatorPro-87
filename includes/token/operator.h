/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: operator.h
 * handles operator tokens
 * -, +, * etc.
 * ************************************************************************* */

#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>
#include "token.h"
using namespace std;

class Operator : public Token
{
public:
    Operator();
    Operator(string op);
    Operator(tk_data info);

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return OPERATOR;}
    
    //mutators
    void set_prec();
    void set_task();

    //accessors
    virtual int get_prec(){return _prec;}
    TASKS get_task(){return _task;}; 
    string get_op(){return _info._str;} 
    int get_type(){return _info._type;}

private:
    int _prec;
    TASKS _task;
    struct tk_data _info;
};

#endif // 


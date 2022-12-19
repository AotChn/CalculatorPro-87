/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: alpha.h
 * handles alphabetical tokens
 * a b c etc. 
 * should convert all alphas to x since we only handle 1 variable instaniations
 * ************************************************************************* */

#ifndef ALPHA_H
#define ALPHA_H
#include <string>
#include "function.h"

using namespace std;

class Alpha : public Function
{
public:
    Alpha();
    Alpha(string value);

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return FUNCTION;}
    FUNCTION_TYPES funct_type(){return VARIABLE;}

    void set_var(int value);

    string get_str(){return _info._str;}
    int get_val(){return _instan;}
    

private:
    struct tk_data _info;
    int _instan;
};

#endif // ALPHA_H

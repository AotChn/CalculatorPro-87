#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include "token.h"
#include "constants.h"
#include "../array_functions/array_functions.h"
#include "operator.h"

using namespace std;

class Function : public Operator
{
public:
    Function();
    Function(string value);
    Function(tk_data info);
    Function(string value, FUNCTION_TYPES funct_type);

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return FUNCTION;}
    virtual FUNCTION_TYPES funct_type(){ return CONSANT;}
    
    void set_var(int value);
    void set_funct();
    void set_prec();

    int get_prec(){return _prec;}
    string get_str(){return _info._str;}
    int get_val(){return _instan;}
    int get_id(){return _info._id;}
    FUNCTION_TYPES get_funct(){return _funct;}
    

private:
    struct tk_data _info;
    FUNCTION_TYPES _funct;
    int _instan;
    int _prec;
};

#endif // FUNCTION_H


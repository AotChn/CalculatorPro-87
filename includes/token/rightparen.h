#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include <string>
#include "token.h"
using namespace std;

class RightParen : public Token
{
public:
    RightParen();

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return RPAREN;}
    
    //accessors
    string get_str(){return _info._str;} 
    int get_type(){return _info._type;}

private:
    struct tk_data _info;
};

#endif // 
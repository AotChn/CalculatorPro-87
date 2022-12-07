#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include "token.h"
#include "double.h"

using namespace std;

class Integer : public Token
{
public:
    Integer();
    Integer(int value);
    Integer(string value);
    Integer(tk_data info);

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return INTEGER;}
    
    string get_str(){return _info._str;}
    int get_val(){return _i;}
    

private:
    struct tk_data _info;
    int _i;
};

#endif // INTEGER_H


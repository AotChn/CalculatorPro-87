#ifndef DOUBLE_H
#define DOUBLE_H
#include <string>
#include "token.h"

using namespace std;

class Double : public Token
{
public:
    Double();
    Double(double value);
    Double(string value);
    Double(tk_data info);

    void Print(ostream &outs=cout) const ;
    TOKEN_TYPES TypeOf(){return DOUBLE;}
    
    string get_str(){return _info._str;}
    double get_val(){return _d;}
    

private:
    struct tk_data _info;
    double _d;
};

#endif // DOUBLE_H


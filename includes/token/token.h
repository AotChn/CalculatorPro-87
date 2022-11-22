#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"
#include "constants.h"
#include "../data_pkg/tk_data.h"

using namespace std;

class Token
{
public:
class Iterator{
    public:
        friend class Token;    
        friend class ShuntingYard;
        friend class RPN;        
        Iterator(){_tk = nullptr;}             
        Iterator(Token* p){_tk = p;}          
        string &operator*(){return _tk->_info._str;}                             //dereference operator
        operator bool(){
            if(_tk != nullptr){
                return true;
            }
            return false;
        }
        bool is_null(){
            if(_tk == nullptr){
                return true;
            }

            return false;
        }                             //true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right){
            if(left._tk != right._tk){
                return true;
            }
            
            return false;
        } //true if left != right
        friend bool operator==(const Iterator &left,
                               const Iterator &right){
            if(left._tk == right._tk){
                return true;
            }
            
            return false;
        } //true if left == right
 
    private:
        Token* _tk;
                       //pointer being encapsulated
    };
    
    Token();
    Token(tk_data info);
    Token(string tok_str,TOKEN_TYPES type);
    
    friend ostream& operator <<(ostream& outs, const Token& Token);
    virtual void Print(ostream& outs=cout) const;
    virtual TOKEN_TYPES TypeOf(){return NON_TYPE;}
    

private:
    tk_data _info;
};

#endif // TOKEN_H

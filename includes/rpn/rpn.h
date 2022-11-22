#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../token/token.h"
#include "../token/function.h"
#include "../token/double.h"


class RPN
{
public:
    RPN();
    RPN(Queue<Token*> postfix);
    
    double rpn_process();
    Stack<Token*> type_process(Stack<Token*> hold);
    int op_process(int a, int b);
    Stack<Token*> funct_process(Stack<Token*> hold);

    void set_input(Queue<Token*> postfix);
    void set_instan(int x);
    
    void Print(RPN Print_this,ostream &outs=cout);

    double operator ()();
    double operator ()(double value);


private:
   Queue<Token*> _postfix; 
   Token::Iterator _p;
   double _instan;
   Queue<Token*>::Iterator it;
};
    
#endif // RPN_H



/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: rpn.h
 *  reverse polish notation evaluator
 *  give x evaluate y 
 * ************************************************************************* */

#ifndef RPN_H
#define RPN_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
//|----------------MY LIBRARY FUNCTS----------------|
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../token/token.h"
#include "../token/function.h"
#include "../token/double.h"
//|__________________________________________________|

class RPN
{
public:
    //CTOR
    RPN();
    RPN(Queue<Token*> postfix);
    
    //process
    double rpn_process();
    double op_process(double a, double b);
    Stack<double> type_process(Stack<double> hold);
    Stack<double> funct_process(Stack<double> hold);

    //mutators
    void set_input(Queue<Token*> postfix);
    void set_instan(double x);
    
    void Print(RPN Print_this,ostream &outs=cout);

    //activate all processes
    double operator ()();
    double operator ()(double value);


private:
   double _instan;
   Token::Iterator _p;
   Queue<Token*> _postfix;
   Queue<Token*>::Iterator it;
};
    
#endif // RPN_H



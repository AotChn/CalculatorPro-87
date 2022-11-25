/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: shunting_yard.h
 *  takes infix queue and converts to postfix queue
 *  
 * ************************************************************************* */

#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

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
#include "../token/function.h"
#include "../token/double.h"
//|__________________________________________________|

class ShuntingYard{

public:
    //CTOR
    ShuntingYard();
    ShuntingYard(Queue<Token*> infix);

    //process
    void postfix_process();
    void type_process();
    void prec_process(); 
    
    //Mutators
    void set_infix(Queue<Token*> infix);
    
    //Acessors
    Queue<Token*> get_postfix(){return _postfix;}
    Queue<Token*> postfix(){postfix_process(); return _postfix;}
    Queue<Token*> postfix(Queue<Token*> prefix);
    void Print(){_postfix.print_pointers();}

private:

    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    Stack<Token*> _op_stack;
    Token::Iterator _p;
};

#endif 

//notes: no error checking [should be handled by tokenizer]
//we must assume all incoming infix are correct
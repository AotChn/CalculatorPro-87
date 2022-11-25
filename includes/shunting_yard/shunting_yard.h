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
    ShuntingYard(Queue<Token*> prefix);

    //Processes
    void postfix_process(); //main process
    void type_process(); //process filter by type 
    void prec_process(); //process filter by prec 
    
    //Mutators
    void set_infix(Queue<Token*> prefix);
    
    //Acessors
    Queue<Token*> get_postfix(){return _postfix;}
    Queue<Token*> postfix(){postfix_process(); return _postfix;}
    Queue<Token*> postfix(Queue<Token*> prefix);
    void Print(){_postfix.print_pointers();}

private:

    Queue<Token*> _prefix;
    Queue<Token*> _postfix;
    Stack<Token*> _op_stack;
    Token::Iterator _p;
};

#endif 
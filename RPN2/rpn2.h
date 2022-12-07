#ifndef RPN2_H
#define RPN2_H

#include <cmath>
#include "../includes/token/integer.h"
#include "../includes/token/operator.h"
#include "../includes/token/function.h"
#include "../includes/queue/MyQueue.h"
#include "../includes/stack/MyStack.h"

double calculate(double value, Token* current){
    double result;
    FUNCTION_TYPES type = static_cast<Function*>(current)->get_funct();
    if(type == VARIABLE){
            result = value;
    }
    else if(type == TRIG){
        result = sin(value);
    }
    return result;
}


class RPN2
{
public:
    RPN2();

    RPN2(Queue<Token*> postfix);

    //with variable
    double operator()(double variable = 1);

    // double evaluate(); 
    
    // double evaluate(double variable); 

    // Stack<Token*> do_math(Stack<Token*>& s, string op);

    void set_input(Queue<Token*> postfix);

private:
    Queue<Token*> _postfix;
};

RPN2::RPN2(){
    
}

RPN2::RPN2(Queue<Token*> postfix){
    _postfix = postfix;
}

void RPN2::set_input(Queue<Token*> postfix){
    _postfix = postfix;
}

double RPN2::operator()(double variable){
    Stack<Token*> myStack;
    Token* current;
    Token* topOfStack;
    Token * evaluated;
    Token*  answer;
    double result, num1, num2;

    while(!_postfix.empty()){
        current = _postfix.front();
        if(current->TypeOf() == INTEGER){
            myStack.push(current);
        }
        else if(current->TypeOf() == OPERATOR){
            string opType = static_cast<Operator*>(current)->get_op();
            topOfStack = myStack.pop();
            num1 = static_cast<Integer*>(topOfStack)->get_val();
            topOfStack = myStack.pop();
            num2 = static_cast<Integer*>(topOfStack)->get_val();

            if(opType == "+"){
                result = num1 + num2;
            }
            else if(opType == "-"){
                result = num2 - num1;
            }
            else if(opType == "*"){
                result = num1 * num2;
            }
            else if(opType == "/"){
                result = num2 / num1;
            }
            else if(opType == "^"){
                result = pow(num2, num1);
            }
            myStack.push(new Integer(result));
        }
        else if(current->TypeOf() == FUNCTION){
            if(_postfix.front()->TypeOf() == FUNCTION){
                result = calculate(variable, current);
                evaluated = new Integer(result);
                myStack.push(evaluated);
            }
            else {
                
                myStack.push(new Integer(variable));
            }
        }
        _postfix.pop();
    }
    answer = myStack.pop();
    return static_cast<Integer*>(answer)->get_val();
}

#endif
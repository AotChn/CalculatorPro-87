#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(Queue<Token*> postfix){;
    _postfix = postfix;
    _instan = 0;
}

double RPN::rpn_process(){
    Stack<double> hold;
    it = _postfix.begin();
    if(_postfix.empty()){
        return 0;
    }
    while(it!= _postfix.end()){
        _p._tk = *it;
        hold = type_process(hold);
        it++;
    }
    double result = hold.top();
    return result;
}

Stack<double> RPN::type_process(Stack<double> hold){
    switch(static_cast<Token*>(*it)->TypeOf()){
            case DOUBLE:{
               hold.push(static_cast<Double*>(*it)->get_val());
                return hold; 
            }
            case OPERATOR:{
                double i = hold.pop();
                double a = i;
                double b;
                if(hold.empty()){
                    b = 0;
                }
                else{
                    i = hold.pop();
                    b = i;    
                }
                double result = op_process(b,a);
                i = result;
                hold.push(i);
                return hold;
            }   
            case FUNCTION:{
                return funct_process(hold);
            }
        }   
        return hold;
        hold.top();

}

double RPN::op_process(double a, double b){
    double result;
    int task = (static_cast<Operator*>(_p._tk)->get_task());
    switch(task){
        case MULTIPLY:
            result = a * b;
            return result;
        case DIVIDE:
            result = a / b;
            return result;
        case SUBTRACT:
            result = a - b;
            return result;
        case ADD:
            result = a + b;
            return result; 
        case EXPONENT:
            result = pow(a,b);
            return result;
        case NEGATIVE: //prob change to function
            result = -1*a;
            return result;
    }
}

Stack<double> RPN::funct_process(Stack<double> hold){
    double result;
    switch(static_cast<Function*>(_p._tk)->get_id()){
        case 99:
        hold.push(_instan);
            return hold;
        case 147:
            result = std::sin(hold.pop());
            hold.push(result);
            return hold;
        case 148:
            result = std::cos(hold.pop());
            hold.push(result);
            return hold;
        case 149:
            result = std::tan(hold.pop());
            hold.push(result);
            return hold;
        case 150:
            result = std::asin(hold.pop());
            hold.push(result);
            return hold;
        case 151:
            result = std::acos(hold.pop());
            hold.push(result);
            return hold;
        case 152:
            result = std::atan(hold.pop());
            hold.push(result);
            return hold;
        case 153: 
            hold.push(3.14);
            return hold;
        case 155:
            result = std::log(hold.pop());
            hold.push(result);
            return hold;
    }
}

void RPN::set_input(Queue<Token*> postfix){
    _postfix = postfix;
}

void RPN::Print(RPN Print_this,ostream &outs){
    outs<<rpn_process()<<endl;
}

double RPN::operator ()(){
    return this->rpn_process();
}

double RPN::operator ()(double value){
    _instan = value;
    return this->rpn_process();
}

void RPN::set_instan(double x){
    _instan = x;
}
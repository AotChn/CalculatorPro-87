#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(Queue<Token*> postfix){;
    _postfix = postfix;
    _instan = 3;
}

double RPN::rpn_process(){
    Stack<double> hold;
    it = _postfix.begin();
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
                i = hold.pop();
                double b = i;
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
    }
}

Stack<double> RPN::funct_process(Stack<double> hold){
    switch(static_cast<Function*>(_p._tk)->get_id()){
        case 99:
        hold.push(_instan);
            return hold;
        case 147:
            hold.pop();
            double sin4 = std::sin(_instan);
            hold.push(sin4);
   //         hold.push(new Integer(_instan));
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
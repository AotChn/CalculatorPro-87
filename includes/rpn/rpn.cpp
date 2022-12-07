#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(Queue<Token*> postfix){;
    _postfix = postfix;
    _instan = 3;
}

double RPN::rpn_process(){
    Stack<Token*> hold;
    it = _postfix.begin();
    while(it!= _postfix.end()){
        _p._tk = *it;
        hold = type_process(hold);
        it++;
    }
    _p._tk = hold.top();
    double result = static_cast<Double*>(_p._tk)->get_val();
    return result;
}

Stack<Token*> RPN::type_process(Stack<Token*> hold){
    switch(_p._tk->TypeOf()){
            case DOUBLE:{
               hold.push(*it);
                return hold; 
            }
            case OPERATOR:{
                Token* i = hold.pop();
                double a = static_cast<Double*>(i)->get_val();
                i = hold.pop();
                double b = static_cast<Double*>(i)->get_val();
                double result = op_process(b,a);
                i = new Double(result);
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

Stack<Token*> RPN::funct_process(Stack<Token*> hold){
    switch(static_cast<Function*>(_p._tk)->get_id()){
        case 99:
        hold.push(new Double(_instan));
            return hold;
        case 147:
            hold.pop();
            double sin4 = std::sin(_instan);
            hold.push(new Double(sin4));
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
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
    int result = static_cast<Integer*>(_p._tk)->get_val();
    return result;
}

Stack<Token*> RPN::type_process(Stack<Token*> hold){
    switch(_p._tk->TypeOf()){
            case INTEGER:{
               hold.push(*it);
                return hold; 
            }
            case OPERATOR:{
                Token* i = hold.pop();
                int a = static_cast<Integer*>(i)->get_val();
                i = hold.pop();
                int b = static_cast<Integer*>(i)->get_val();
                int result = op_process(b,a);
                i = new Integer(result);
                hold.push(i);
                return hold;
            }   
            case FUNCTION:{
                hold.push(new Integer(_instan));
                return hold;
            }
        }   
        return hold;
        hold.top();
}

int RPN::op_process(int a, int b){
    int result;
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
            result = pow(b,a);
            return result;
    }
}

Stack<Token*> RPN::funct_process(Stack<Token*> hold){
    switch(static_cast<Function*>(_p._tk)->get_funct()){
        case VARIABLE:
        hold.push(new Integer(_instan));
            return hold;
        case TRIG:
            hold.pop();
            hold.push(new Double(std::sin(_instan)));
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

void RPN::set_instan(int x){
    _instan = x;
}
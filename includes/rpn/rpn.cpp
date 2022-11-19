#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(Queue<Token*> postfix){;
    _postfix = postfix;
    _instan = 3;
}

double RPN::rpn_process(){
    Stack<Token*> hold;
    while(_postfix.empty() == false){
        _p = _postfix.front();
        hold = type_process(hold);
        _postfix.pop();
    }
    _p = hold.top();
    int result = static_cast<Integer*>(_p._tk)->get_val();
    return result;
}

Stack<Token*> RPN::type_process(Stack<Token*> hold){
    switch(_p._tk->TypeOf()){
            case INTEGER:{
               hold.push(_p._tk);
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
        // case HYPERBOLIC:
        // return 0;
    }
}

void RPN::set_input(Queue<Token*> postfix){
    _postfix = postfix;
}

void RPN::Print(RPN Print_this,ostream &outs){
    outs<<rpn_process()<<endl;
}

 const double RPN::operator ()(){
    return this->rpn_process();
}
const double RPN::operator ()(const double value){
    _instan = value;
    return this->rpn_process();
}

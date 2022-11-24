#include "shunting_yard.h"

ShuntingYard::ShuntingYard(){

}

ShuntingYard::ShuntingYard(Queue<Token*> prefix){
    _prefix = prefix;
}

void ShuntingYard::postfix_process(){
    while(_prefix.empty() != true){
        _p = _prefix.front();
        type_process();
        _prefix.pop();
    }
    while(_op_stack.empty() != true){
        _postfix.push(_op_stack.pop());
    }
}

void ShuntingYard::type_process(){
    switch(_p._tk->TypeOf()){
        case INTEGER:
            _postfix.push(_p._tk);
            return;
        case OPERATOR:
            prec_process();
            return;
        case LPAREN:
            _op_stack.push(_p._tk);
            return;
        case RPAREN:
           while(_op_stack.top()->TypeOf()!= LPAREN){
            _postfix.push(_op_stack.pop());
           }
           _op_stack.pop();
            return;
        case FUNCTION:
            prec_process();
    }
}
void ShuntingYard::prec_process(){
    while(_op_stack.empty() != true&&_op_stack.top()->TypeOf()!=LPAREN){
        int top_prec = static_cast<Operator*>(_op_stack.top())->get_prec();
        if(static_cast<Operator*>(_p._tk)->get_prec() <= top_prec){
            _postfix.push(_op_stack.pop());
        }
        else{
            break;
        }
    }

    _op_stack.push(_p._tk);
}

void ShuntingYard::set_infix(Queue<Token*> prefix){
    _prefix = prefix;
}

 Queue<Token*> ShuntingYard::postfix(Queue<Token*> prefix){
        set_infix(prefix);
        postfix_process(); 
        return _postfix;
}
//3+(9*8+4)
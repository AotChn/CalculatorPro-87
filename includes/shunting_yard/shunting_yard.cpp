#include "shunting_yard.h"

ShuntingYard::ShuntingYard(){

}

ShuntingYard::ShuntingYard(Queue<Token*> infix){
    set_infix(infix);
}

//main process
void ShuntingYard::postfix_process(){
    //go through entire queue
    while(!_infix.empty()){
        _p = _infix.front();
        type_process();
        _infix.pop();
    }
    //pop entire op_stack
    while(!_op_stack.empty()){
        _postfix.push(_op_stack.pop());
    }
}

//process filter by type 
void ShuntingYard::type_process(){
    switch(_p._tk->TypeOf()){
        case INTEGER:
            _postfix.push(_p._tk);
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
        case OPERATOR:
            prec_process();
            return;       
        case FUNCTION:
            prec_process();
    }
}

//process filter by prec 
void ShuntingYard::prec_process(){ 
    while(_op_stack.empty() != true&&_op_stack.top()->TypeOf()!=LPAREN){ //not empty & not lp
        int top_prec = static_cast<Operator*>(_op_stack.top())->get_prec();
        if(static_cast<Operator*>(_p._tk)->get_prec() <= top_prec){ //prec <= top_prec
            _postfix.push(_op_stack.pop()); 
        }
        else{
            break;
        }
    }
    _op_stack.push(_p._tk);
}

//sets the infix 
void ShuntingYard::set_infix(Queue<Token*> infix){
    _infix = infix;
}

 Queue<Token*> ShuntingYard::postfix(Queue<Token*> infix){
        set_infix(infix);
        postfix_process(); 
        return _postfix;
}
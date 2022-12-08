#include "operator.h"


Operator::Operator(){
    _info.set_type(OPERATOR);
}

Operator::Operator(tk_data info){
    _info = info;
    set_prec();
    set_task();
}
Operator::Operator(string op){
    _info.set_str(op);
    _info.set_type(OPERATOR);
    set_prec();
    set_task();
    
}

void Operator::set_prec(){
    if(_info._str == "$"){
        _prec = 5;
    }
    if(_info._str == "^"){
        _prec = 4;
    }
    else if(_info._str == "*"){
        _prec = 3;
    }
    else if(_info._str == "/"){
        _prec = 3;
    }
    else if(_info._str == "+"){
        _prec = 2;
    }
    else if(_info._str == "-"){
        _prec = 2;
    }
    
}

void Operator::set_task(){
    if(_info._str == "^"){
        _task = EXPONENT;
    }
    else if(_info._str == "*"){
        _task = MULTIPLY;
    }
    else if(_info._str == "/"){
        _task = DIVIDE;
    }
    else if(_info._str == "+"){
        _task = ADD;
    }
    else if(_info._str == "-"){
        _task = SUBTRACT;
    }
    else if(_info._str == "$"){
        _task = NEGATIVE;
    }
}

void Operator::Print(ostream& outs) const{
    outs<<"["<<_info._str<<"]";

}

// * / + - ^

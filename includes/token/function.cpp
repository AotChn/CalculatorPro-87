#include "function.h"

Function::Function(){
    _info.set_type(FUNCTION);
}

Function::Function(string value){
    _info.set_str(value);
    _info.set_type(FUNCTION);
    set_funct();
    set_prec();
    _instan = 0;
}

Function::Function(tk_data info){
    _info = info;
    set_funct();
    set_prec();
    _instan = 0;
}

Function::Function(string value, FUNCTION_TYPES funct_type){
    _info.set_str(value);
    _info.set_type(FUNCTION);
    _funct = funct_type;
    set_prec();
    _instan = 0;
}

void Function::set_prec(){
    if(_info._id == 99){
        _prec = 6;
    }
    else{
        _prec = 5;
    }
}

void Function::set_funct(){
    if(_info._id == VARIABLE){
        _funct = VARIABLE;
    }
    else if(_info._id<10){
        _funct = TRIG;
    }
    else if(_info._str == "$"){
        _funct = MINUS;
    }
    
}

void Function::set_var(int value){
    _instan = value;
}

void Function::Print(ostream& outs) const{
    outs<<"["<<_info._str<<"]";
}


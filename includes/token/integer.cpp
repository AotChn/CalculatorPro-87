#include "integer.h"

Integer::Integer(){
    _info.set_type(INTEGER);
}

Integer::Integer(tk_data info){
    _info = info;
    _i = atoi(_info._str.c_str());
}

Integer::Integer(int value){
    _i=value;
    _info.set_type(INTEGER);
}

Integer::Integer(string value){
    _i = atoi(value.c_str());
    _info.set_type(INTEGER);
}

void Integer::Print(ostream& outs) const{
    outs<<"["<<_i<<"]";
}

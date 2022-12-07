#include "double.h"

Double::Double(){
    _info.set_type(DOUBLE);
}
Double::Double(tk_data info){
    _info = info;
    _d = stof(_info._str);
}
Double::Double(double value){
    _d = value;
   // cout<<"value: "<<_d;
    _info.set_type(DOUBLE);
}

Double::Double(string value){
    _d = stof(value.c_str());
    _info.set_type(DOUBLE);
}

void Double::Print(ostream& outs) const{
    outs<<"["<<_d<<"]";
}

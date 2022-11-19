#include "alpha.h"

Alpha::Alpha(){
    _info.set_type(FUNCTION);
}

Alpha::Alpha(string value){
    _info.set_str(value);
    _info.set_type(FUNCTION);
    _instan = 0;
}

void Alpha::set_var(int value){
    _instan = value;
}

void Alpha::Print(ostream& outs) const{
    outs<<"["<<_info._str<<"]";
}

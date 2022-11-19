#include "rightparen.h"


    RightParen::RightParen(){
        _info.set_type(RPAREN);
        _info.set_str(")");
    }

    void RightParen::Print(ostream &outs) const {
        outs<<"["<<_info._str<<"]";
    }
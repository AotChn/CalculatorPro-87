#include "leftparen.h"


    LeftParen::LeftParen(){
        _info.set_type(LPAREN);
        _info.set_str("(");
    }

    void LeftParen::Print(ostream &outs) const {
        outs<<"["<<_info._str<<"]";
    }
    

// * / + - ^

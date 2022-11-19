#include "token.h"

Token::Token(){

}
Token::Token(tk_data info){
    _info = info;
}

Token::Token(string tok_str,TOKEN_TYPES type){
    _info.set_str(tok_str);
    _info.set_type(type);
}

ostream& operator <<(ostream& outs, const Token& Token){
    Token.Print(outs);
    return outs;
}

void Token::Print(ostream &outs) const{
    outs<<"f&%$"<<endl;
    //Blank
}

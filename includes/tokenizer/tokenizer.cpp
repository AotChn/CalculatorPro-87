#include "tokenizer.h"

void tokenizer::Print(){ 
        _infix.print_pointers();
    }

void tokenizer::pkg_type(std::string _str){
    wlk = _str.begin();
    while(wlk != _str.cend()){
        _cur_ST = 0;
        int i = 0;
        while(_cur_ST!=ACCEPT){
            hold = *wlk;
            i = (this->*(state_map.at(i)))(hold); 
            //this how we call functions pointing to member functions
        }
    }
 //   cout<<"{end}";
}

int tokenizer::Non(std::string key){
 //   cout<<"PASSED NON->";
    _cur_ST = NON;
    token = "" + key;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        wlk++;
        return NUM;
    }
    return OPER;
}

int tokenizer::Num(std::string key){
 //   cout<<"PASSED NUM->";
    _cur_ST = NUM;
    if(str_vect_cmp(NUMERALS_,key)||key=="."){
        token = token + key;
        wlk++;
        return NUM;
        
    }
    return ACCEPT;
}

int tokenizer::Oper(std::string key){
//    cout<<"PASSED OPER->";
    _cur_ST = OPER;
    if(str_vect_cmp(OPERATORS_,key)){
        if(key=="("){
            return LP;
        }
        else if(key==")"){
            return RP;
        }
        else if(key=="-"){
            if(_prev_ST==OPER||_prev_ST==LP||_prev_ST==NON){
                token = "$"; 
            }
        }
            wlk++;
            return ACCEPT;
    }
    token = "";
    return ALPH;
}

int tokenizer::Lp(std::string key){
//    cout<<"PASSED LP->";
    _cur_ST = LP;
    switch(_prev_ST){
        case ALPH:{}
        case NUM:{}
        case RP: {/*ADD * OPERATOR*/}
        default:
        {wlk++;return ACCEPT;}
    }
}

int tokenizer::Rp(std::string key){
//    cout<<"PASSED RP->";
    _cur_ST = RP;
    wlk++;
    return ACCEPT;
}

int tokenizer::Alpha(std::string key){
//    cout<<"PASSED ALPH->";
    _cur_ST = ALPH;
    if(str_vect_cmp(ALPHAS_,key)){
        token = token + key;
        wlk++;
        return FUNCT;
    }
    tk._id = 99;
    return ACCEPT;
}

int tokenizer::Funct(std::string key){
 //  cout<<"PASSED FUNCT->";
    _cur_ST = FUNCT;
    if(pre_def_functs.find(token)!=pre_def_functs.end()){
        if(pre_def_functs[token]>300){
            return COMP;
        }
        return ACCEPT;
        }
    return ALPH;
}
int tokenizer::Comp (std::string key){
    _cur_ST = COMP;
    hold = user_funct[token];
    pkg_token(LP);
    tokenizer Inject(hold);
    Inject.set_infix(_infix);
    Inject.tokenize();
    _infix = Inject.get_infix();
    pkg_token(RP);
    return ACCEPT;
}
int tokenizer::Accept(std::string key){
    pkg_token(_cur_ST);
    _prev_ST = _cur_ST;
    //cout<<"[TYPE:"<<_cur_ST<<"|TOKEN :"<<token<<"]STATE ACCEPT"<<endl;
    _cur_ST = ACCEPT;
    return ACCEPT;
}

int tokenizer::Inv(std::string key){
//INVALID INPUTS
    return 56;
}

void tokenizer::pkg_token(int type){
    tk._str = token;
    tk._type = type;
    switch(type){
        case NUM:
            _infix.push(new Integer(tk));
            break;
        case OPER:
            _infix.push(new Operator(tk));
            break;
        case FUNCT:
            _infix.push(new Function(tk));
            break;
        case LP:
            _infix.push(new LeftParen());
            break;
        case RP:
            _infix.push(new RightParen());
            break;
        case ALPH:
            _infix.push(new Function(tk));
            break;
    }
}
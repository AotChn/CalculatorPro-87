// #include "tok_string.h"


// void tokenizer::pkg_type(std::string _str){
//     wlk = _str.begin();
//     while(wlk != _str.cend()){
//         _cur_ST = 0;
//         int i = 0;
//         while(_cur_ST!=ACCEPT){
//             hold = *wlk;
//             i = (this->*(state_map.at(i)))(hold); 
//             //this how we call functions pointing to member functions
//         }
//     }
//     cout<<"{end}";
// }

// int tokenizer::Non(std::string key){
//     cout<<"PASSED NON->";
//     _cur_ST = NON;
//     token = "" + key;
//     if(str_vect_cmp(NUMERALS_,key)||key=="."){
//         wlk++;
//         return NUM;
//     }
//     return OPER;
// }

// int tokenizer::Num(std::string key){
//     cout<<"PASSED NUM->";
//     _cur_ST = NUM;
//     if(str_vect_cmp(NUMERALS_,key)||key=="."){
//         token = token + key;
//         wlk++;
//         return NUM;
//     }
//     return ACCEPT;
// }

// int tokenizer::Oper(std::string key){
//     cout<<"PASSED OPER->";
//     _cur_ST = OPER;
//     if(str_vect_cmp(OPERATORS_,key)){
//         if(key=="("){
//             return LP;
//         }
//         else if(key==")"){
//             return RP;
//         }
//         else if(key=="-"){
//             switch(_prev_ST){
//                 case OPER:{}
//                 case NON:{}
//                 case LP: {return FUNCT;}
//                 default:{}
//             }
//         }
//         wlk++;
//         return ACCEPT;
//     }
//     token = "";
//     return ALPH;
// }

// int tokenizer::Lp(std::string key){
//     cout<<"PASSED LP->";
//     _cur_ST = LP;
//     switch(_prev_ST){
//         case ALPH:{}
//         case NUM:{}
//         case RP: {/*ADD * OPERATOR*/}
//         default:
//         {wlk++;return ACCEPT;}
//     }
// }

// int tokenizer::Rp(std::string key){
//     cout<<"PASSED RP->";
//     _cur_ST = RP;
//     wlk++;
//     return ACCEPT;
// }

// int tokenizer::Alpha(std::string key){
//     cout<<"PASSED ALPH->";
//     _cur_ST = ALPH;
//     if(str_vect_cmp(ALPHAS_,key)){
//         token = token + key;
//         wlk++;
//         return FUNCT;
//     }
//     return ACCEPT;
// }

// int tokenizer::Funct(std::string key){
//     cout<<"PASSED FUNCT->";
//     _cur_ST = FUNCT;
//     if(pre_def_functs.find(token)!=pre_def_functs.end()){
//         wlk++;
//         return ACCEPT;
//     }
//     return ALPH;
// }

// int tokenizer::Accept(std::string key){
//     _prev_ST = _cur_ST;
//     _cur_ST = ACCEPT;
//     cout<<"[TYPE:"<<_prev_ST<<"|TOKEN :"<<token<<"]STATE ACCEPT"<<endl;
//     return 8;
// }

// int tokenizer::Inv(std::string key){
// //INVALID INPUTS
// }


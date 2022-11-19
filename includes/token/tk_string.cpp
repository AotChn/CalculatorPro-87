// #include "tk_string.h"


// Tk_string::Tk_string(){

// }
// Tk_string::Tk_string(int value){
//     _tk_string = to_string(value);
// }

// Tk_string::Tk_string(string tk_string){
//     _tk_string = tk_string;
// }

// void Tk_string::tokenize(){ //convert string snippets to tokens 
//     custom_funct();
//     wlk = _tk_string.begin();
//     next = wlk+1;
//     prev = wlk-1;
//     _prev._type = NON_TYPE;
//     string wlk_str="";
//     int i;
//     while(*wlk != '\0'){
//         i = 1;
//         _next = set_type(*next);
//         _tk = set_type(*wlk);
//         _tk._str.push_back(*wlk);
//         wlk_str.push_back(*wlk);
//         process_repeat(wlk_str,i);
//         error_check();
//         create_tk(_tk);
//         wlk_str = "";
//         wlk = wlk + i;
//         _prev._type = _tk._type;
//         next++;
//         prev++;
//         cout<<"tk id: "<<"|"<<_tk._id<<"|";
//     }
//  }

// void Tk_string::process_repeat(string wlk_str, int &i){
//     while(_next._type==_tk._type&&_tk._type==INTEGER){ //multi-digit ints
//         wlk_str.push_back(*next);
//         _tk._str = wlk_str;
//         wlk_str = _tk._str;
//         next++;
//         i++;
//         _next = set_type(*next);
//         }
//     while(_next._type==_tk._type&&_tk._type==ALPHA){ //multi-char funct
//         wlk_str.push_back(*next);
//         _tk._str = wlk_str;
//         wlk_str = _tk._str;
//         next++;
//         i++;
//         _next = set_type(*next);
        
//     }

//     if(_tk._type==ALPHA){ //check if defined function
//         if(_tk._str =="-"){
//             _tk._str = "$";
//             _tk._type = FUNCTION;
//             return;
//         }
//         else if(_next._type!=LPAREN){
//             if(str_vect_cmp(TRIGS,_tk._str,1,_tk._id)){
//                 _tk._str.pop_back();
//                 i--;
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(HYPERBOLICS,_tk._str,1,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(CONSTANTS,_tk._str,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(LOGRITHMNS,_tk._str,1,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else{
//                 _tk._str = *wlk;
//                 _tk._id = VARIABLE;
//                 next = wlk+1;
//                 _next = set_type(*next);
//                 i = 1;
//             }
//         }
//         else if(_next._type==LPAREN){
//             if(str_vect_cmp(TRIGS,_tk._str,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(HYPERBOLICS,_tk._str,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(CONSTANTS,_tk._str,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else if(str_vect_cmp(LOGRITHMNS,_tk._str,_tk._id)){
//                 _tk._type = FUNCTION;
//                 return;
//             }
//             else{
//                 _tk._str = *wlk;
//                 _tk._id = VARIABLE;
//                 next = wlk+1;
//                 _next = set_type(*next);
//                 i = 1;
//             }
//         }
//     }
    
// }

//  void Tk_string::create_tk(tk_data tk){ //create prefix a token
//     switch(tk._type){
//         case OPERATOR:
//            _prefix.push(new Operator(_tk));
//            break;
//         case INTEGER:
//             _prefix.push(new Integer(_tk));
//             break;
//         case RPAREN:
//              _prefix.push(new RightParen());
//              break;
//         case LPAREN:
//             _prefix.push(new LeftParen());
//             break;
//         case ALPHA:
//             if(_prev._type==ALPHA||_prev._type==INTEGER){
//                 _prefix.push(new Operator("*"));
//             }
//         case FUNCTION:
//             _prefix.push(new Function(_tk));
//             break;
            
//      }
//  }

// tk_data Tk_string::set_type(char key){ //determines type of token 
//     tk_data tk;
//     if(search(DELIMITERS,3,key)!=-1){
//         tk._type = DELIMITER;
//     } 
//     else if(key == '-'){
//         tk = process_minus(tk);
//     }
//     else if(search(OPERATORS_,7,key)!=-1){
//         tk._type = OPERATOR;
//     }
//     else if(search(NUMERALS_,11,key)!=-1){
//         tk._type = INTEGER;
//     }    
//     else if(search(LEFTPAREN_,2,key)!=-1){
//         tk._type = LPAREN;
//     }
//     else if(search(RIGHTPAREN_,2,key)!=-1){
//         tk._type = RPAREN;
//     }
//     else if(search(ALPHAS_,53,key)!=-1){
//         tk._type = ALPHA;
//     }
//     else{
//         tk._type = NON_TYPE;
//     }
    
//     return tk;   
// }

// tk_data Tk_string::process_minus(tk_data tk){ //determine if minus op or unary minus
//     if(_prev._type == OPERATOR || _prev._type == LPAREN || _prev._type == NON_TYPE){

//         tk._type = ALPHA;
//         return tk;
//     }
//     else{
//         tk._type = OPERATOR;
//         return tk;
//     }
// }

// void Tk_string::Print(){ 
//         _prefix.print_pointers();
//     }

// void Tk_string::error_check(){
//     try{
//         if(_tk._type==OPERATOR&&_prev._type==OPERATOR){
//             throw 1;
//         }
//         // else if(_tk._type==FUNCTION&&_next._type!=FUNCTION){
//         //     throw 2;
//         // }
//         // else if(_tk._type==FUNCTION&&_next._type!=ALPHA){
//         //     throw 3;
//         // }

//     }
//     catch(int error_code){
//         cout<<endl<<endl<<"INVALID INPUT! WHAT THE HECK MAN! @#*&!"<<endl<<endl;
//         cout<<"error_code: ["<<error_code<<"]"<<endl;
//         exit(EXIT_FAILURE);
//     }
// }

// void Tk_string::custom_funct(){
//     // std::string ans;
//     // cout<<"Do you want to create a custom function? [y] [n] ";
//     // cin>>ans;
//     // while(ans=="y"){
//     //     std::string name;
//     //     cout<<"Enter Function Name: ";
//     //     cin>>name;
//     //     _custom_functs.push_back(name);

//     // }
//     string hold;
//     ifstream inFile;
//     ofstream output_f;
//     inFile.open("Custom_functions.txt");
//    // output_f.open("Custom_function.tet");
// // Test for failure here…
//     if(inFile.fail()){
//         cout<< "Output file opening failed \n";
//         exit(1);
//     }
//     while(inFile.eof()==false){
//         std::getline(inFile,hold,';');
//         cout<<hold;
//     }


//     inFile.close();
// }
/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: tk_data.h
 *  general data wrapper for tokens
 *  all tokens will have this as a wrapper 
 * ************************************************************************* */

#ifndef TK_DATA_H
#define TK_DATA_H

#include <iostream>
#include "../token/constants.h"

using namespace std;

struct tk_data{
public:
    
    tk_data(int type = 0, string tk_str = "",int id = 0){
        _type = type;
        _str = tk_str;
    }

    friend std::ostream& operator <<(std::ostream& outs, const tk_data &printMe){
        outs<<"["<<printMe._str<<"|"<<printMe._type<<"|"<<printMe._id<<"]";
        return outs;
    
    }

    void set_type(TOKEN_TYPES type){
        _type = type;
    }
    void set_id(int id){
        _id = id;
    }
    void set_str(string str){
        _str = str;
    }

    // int get_type(){
    //     return _type;
    // }
    // int get_id(){
    //     return _id;
    // }
    // string get_str(){
    //     return _str;
    // }

    int _id;
    int _type;
    string _str;
};

#endif
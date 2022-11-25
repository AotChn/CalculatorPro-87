/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: function_data.h
 *  data wrapper class for function tokens
 *  funct name, def, id
 * ************************************************************************* */

#ifndef FUNCT_DATA_H
#define FUNCT_DATA_H

#include <iostream>
#include "../token/constants.h"
#include<map>

using namespace std;

struct funct_data
{
public:
    
    funct_data(std::string name = "", string funct = "", int id = -1){
        _funct = funct;
        _name = name;
        _id = id;
    }

    friend std::ostream& operator <<(std::ostream& outs, const funct_data &printMe){
        outs<<"["<<printMe._name<<"|"<<printMe._funct<<"]";
        return outs;
    
    }

    string get_name(){
        return _name;
    }
    string get_funt(){
        return _funct;
    }
    string _name;
    string _funct;
    int _id;
};

#endif
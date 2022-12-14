/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: array_functions.h
 *  templated low level functions to manipulate 1D arrays 
 *  search - copy - re/allocate - print
 * ************************************************************************* */

#ifndef AOTS_ARRAY_FUNCTIONS_H
#define AOTS_ARRAY_FUNCTIONS_H

#include <set>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <assert.h>
#include <vector>
#include <cstring>

#include "../data_pkg/function_data.h"

using namespace std;
typedef string T;

const int MINIMUM_CAPACITY = 3;

//swaps two int addresses
template <class T>
void Swap(int &a,int &b);                               

//allocate capacity ; returns array
template<class T>
T* allocate(int capacity = MINIMUM_CAPACITY);

//resize array; delete old array -> return new array
template<class T>
T* reallocate(T* a, int size, int capacity);
 
//print array; capacity for debugging
template<class T>
void print_array(T* a, int size, int capacity = 0, ostream& outs = cout);

//print array
template <class T>
void print(T* a, unsigned int how_many, ostream& outs = cout);

//search array for find_me; return ptr
template<class T>
T* search_entry(T* a, int size, const T& find_me);

//search array for find_me; return int
template <class T>
int search(T* a, int size, const T& find_me);

//search array for find_me; return const ptr
template<class T>
const T* search_entry(const T* a, int size, const T& find_me); 

//search array for find_me; return int
template <class T>
int search(const T* a, int size, const T& find_me);

//shift all elements left at index; erase element at index
template <class T>
void shift_left(T* a, int& size, int shift_here);

//shift all elements left at ptr; erase element at ptr; make hole
template <class T>
void shift_left(T* a, int& size, T* shift_here);

//shift all elements right at index; erase element at index; make hole
template <class T>
void shift_right(T *a, int &size, int shift_here);

//shift all elements right at ptr; erase element at ptr
template <class T>
void shift_right(T *a, int &size, T* shift_here);

//copy src to dest
template<class T>
void copy_array(T *dest, const T* src, int many_to_copy);

//return copy of src
template <class T>
T* copy_array(const T *src, int size);

//return array as string 
template <class T>
string array_string(const T *a, int size);

//serach vector of string for key-1; return true if found; id ver. 
static bool str_vect_cmp(vector<string> master, string key, int s, int& id);

//serach vector of string for key; return true if found; id ver. 
static bool str_vect_cmp(vector<string> master, string key,int& id);

//serach vector of string for key; return true if found; str id ver
static bool str_vect_cmp(vector<funct_data> master, string key, string& id);

//serach vector of string for key; return true if found; no id 
static bool str_vect_cmp(vector<string> master, string key);

//---------------------------------------------------------------------------
//DEFINITIONS:

template <class T>
void Swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
} 

template<class T>
T* allocate(int capacity){
    T* arr = new T[capacity];
    return arr;
}            

template<class T>
T* reallocate(T* a, int size, int capacity){
    T* new_arr = allocate<T>(capacity);
    copy_array(new_arr,a,size);
    delete[] a;
    return new_arr;
}          

template<class T>
void print_array(T* a, int size, int capacity, ostream& outs){
    if(capacity){
        cout<<"( "<<size<<"/"<<capacity<<") [";
    }
    else{
        cout<<"("<<size<<") [";
    }
    print(a,size);
    cout<<" ]"<<endl;
}    

template <class T>
void print(T* a, unsigned int how_many, ostream& outs){
    T* walker = a;
    for(int i=0;i<how_many;i++){
        cout<<setw(4)<<*walker;
        walker++;
    }
}  

template<class T>
 T* search_entry(T* a, int size, const T& find_me){ 
    T* walker = a;
    for(int i=0;i<size;i++){
        if(*walker==find_me){
            return walker;
        }
        walker++;
    }
    return 0;
}       

template<class T>
const T* search_entry(const T* a, int size, const T& find_me){ 
    const T* walker = a;
    for(int i=0;i<size;i++){
        if(*walker==find_me){
            return walker;
        }
        walker++;
    }
    return 0;
}   

template <class T>
int search(T* a, int size, const T& find_me){ 
    T* found = search_entry(a,size,find_me);
    if(found){
        int key_index = found-a;
        return key_index;
    }
    else{
        return -1;
    }
}    

template <class T>
int search(const T* a, int size, const T& find_me){ 
    const T* found = search_entry(a,size,find_me);
    if(found){
        int key_index = found-a;
        return key_index;
    }
    else{
        return -1;
    }
}     

template <class T>
void shift_left(T* a, int& size, int shift_here){
    T* index = a+shift_here;
    shift_left(a,size,index);
}      

template <class T>
void shift_left(T* a, int& size, T* shift_here){
   // assert(size>0); 
    T* end = a+size-1;
    T* lead = shift_here+1;
    while(shift_here!=end){
        Swap(*shift_here,*lead);
        shift_here++;
        lead++;
    }
    size--;
}        

template <class T>
void shift_right(T *a, int &size, int shift_here){
    T* shift_index = a+shift_here;
    shift_right(a, size, shift_index);
}
     
template <class T>
void shift_right(T *a, int &size, T* shift_here){
  T* lead = a+size-1;
  T* catcher = a+size;
  T* end = shift_here+1;
  while(lead!=shift_here){
    Swap(*lead,*catcher);
    lead--;
    catcher--;
  }
    *end = *shift_here;
    size++;
}       

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy){
    for(int i=0;i<many_to_copy;i++){
        *dest = *src;
        dest++;
        src++;
    }

}      

template <class T>
T* copy_array(const T *src, int size){
    T* src_cpy = new T[size];
    const T* src_ptr = src;
    for(int i=0;i<size;i++){
        *src_cpy = *src_ptr;
        src_cpy++;
        src_ptr++;
    }
    src_cpy = src_cpy - size;
    return src_cpy;
}                  

template <class T>
string array_string(const T *a, int size){
    string str_arr = "";
    string s = " ";
    const T* walker = a;
    for(int i=0;i<size;i++){
        str_arr += to_string(*walker)+s;
        walker++;
    }
    return str_arr;
}              

static bool str_vect_cmp(vector<string> master, string key){
    vector<string>::iterator wlk = master.begin();
    while(wlk!= master.end()){
        if(*wlk == key){
            return true;
        }
        wlk++;
    }
    return false;
}

static bool str_vect_cmp(vector<string> master, string key,int &id){
    vector<string>::iterator wlk = master.begin();
    id = 0;
    while(wlk!= master.end()){
        id++;
        if(*wlk == key){
            return true;
        }
        wlk++;
    }
    return false;
}

static bool str_vect_cmp(vector<funct_data> master, string key, string & id){
    vector<funct_data>::iterator wlk = master.begin();
    while(wlk!= master.end()){
        if(wlk->get_name() == key){
           id = wlk->_funct;
            return true;
        }
        cout<<"|"<<wlk->get_name()<<"|"<<endl;
        
        wlk++;
    }
    return false;
}

static bool str_vect_cmp(vector<string> master, string key,int s, int& id){
    vector<string>::iterator wlk = master.begin();
    key.pop_back();
    id = 0;
    while(wlk!= master.end()){
        id++;
        if(*wlk == key){
            return true;
        }
       wlk++; 
    }
    return false;
}

#endif
/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: vector_class.h
 *  custom vector class meant to mimic std::vector
 *  basic vector functionalities 
 * ************************************************************************* */

#ifndef AOTS_VECTOR_CLASS_H
#define AOTS_VECTOR_CLASS_H

#include <iostream>
#include "../add_entry/add_entry.h"
#include "../array_functions/array_functions.h"

using namespace std;

template <class T>
class Vector{
    
public:
    //CTOR
    Vector(int size = 0);
    Vector(T *arr, int size);

    //BIG THREE
    Vector(const Vector& obj); //copy constructor
    Vector & operator= (const Vector& RHS); //copy assignment
    ~Vector(); //destructor
    
    //member  access functions:
    T& operator [](int index);
    const T& operator [](int index) const;

    T& at(int index);              //return reference to item at position index
    const T& at(int index) const;  //return a const item at position index

    T& front();                         //return item at position 0.
    T& back();                          //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_this_index);        //erase item at position
    int index_of(const T& item);             //search for item. retur index.

    //size and capacity:
    void set_size(int size);              //enlarge the vector to this size
    void set_capacity(int capacity);      //allocate this space
    int size() const {return _size;}  //return _size
    int capacity() const {return _capacity;} //return _capacity

    bool empty() const;                    //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);

private:

    T* _arr;
    int _capacity;
    int _size;
};

template <class T>
Vector<T>::Vector(int size){
   _size = size;
   _capacity = size+2;
   _arr = allocate<T>(_capacity);
}
template <class T>
Vector<T>::Vector(T *arr, int size){
    _size = size;
   _capacity = (_size+2);
   _arr = allocate<T>(_capacity);
    copy_array(_arr,arr,_size);
}

//BIG THREE
template <class T>
Vector<T>::Vector(const Vector& other){
    //delete [] _arr;
    _size = other._size;
    _capacity = other._capacity;
    _arr = allocate<T>(_capacity);
    copy_array(_arr,other._arr,_size);
}

template <class T>
 Vector<T>& Vector<T>::operator =(const Vector& RHS){
    delete [] _arr;
    if(this == &RHS){
        return *this;
    }
    _size = RHS._size;
    _capacity = RHS._capacity;
    _arr = allocate<T>(_capacity);
    copy_array(_arr,RHS._arr,_size);
    return *this;
}

template <class T>
Vector<T>::~Vector(){
    delete[] _arr;
}
template <class T>
T& Vector<T>::operator [](int index){
    return _arr[index];
}

template <class T>
const T& Vector<T>::operator [](int index) const{
   return _arr[index];
}

template <class T>
T& Vector<T>::at(int index){
    return _arr[index];
} 

template <class T>             
const T& Vector<T>::at(int index) const{
    return _arr[index];
}  

template <class T> 
T& Vector<T>::front(){
    return _arr[0];
}

template <class T>                         
T& Vector<T>::back(){
    return _arr[_size-1];
}                         


//Push and Pop functions:
template <class T> 
Vector<T>& Vector<T>::operator +=(const T& item){
    _arr = add_entry(_arr,item,_size,_capacity);
    return *this;
}

template <class T> 
void Vector<T>::push_back(const T& item){
    _arr = add_entry(_arr,item,_size,_capacity);
}    

template <class T>
T Vector<T>::pop_back(){
    T popped;
    _arr = remove_last_entry(_arr,popped,_size,_capacity);
    return popped;
}                    


//Insert and Erase:
template <class T>
void Vector<T>::insert(int insert_here, const T& insert_this){
     _arr = insert_entry(_arr,insert_this,insert_here,_size,_capacity);
} 

template <class T>
void Vector<T>::erase(int erase_this_index){
    _arr = erase_entry(_arr,erase_this_index,_size,_capacity);
}  

template <class T>
int Vector<T>::index_of(const T& item){
    int found = search(_arr,_size,item);
    return found;

}   

template <class T>
void Vector<T>::set_size(int size){
    //assert(size<_capacity);
    _size = size;
}

template <class T>             
void Vector<T>::set_capacity(int capacity){
    _capacity = capacity;
    _arr = reallocate(_arr,_size,_capacity);
}  

template <class T>
bool Vector<T>::empty() const{
    if(_size==0){
        return true;
    }
    return false;
}                 

//OUTPUT:
template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& _a){
        //print_array(_a._arr,_a._size,_a._capacity);
        outs << "( " <<_a._size<<"/"<<_a._capacity<<")";
        outs <<" [ ";
        for(int i=0;i<_a._size;i++){
        outs<<setw(4)<<_a._arr[i];
        }
        outs << " ]"; 
        return outs;
}


#endif
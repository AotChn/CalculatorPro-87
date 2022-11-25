/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: MyStack.h
 * Stack built using linked list 
 * 
 * ************************************************************************* */

#ifndef AOTS_STACK_H
#define AOTS_STACK_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <iomanip>
//|----------------MY LIBRARY FUNCTS----------------|
#include "../linked_list_functions/linked_list_functions.h"
//|__________________________________________________|

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        Iterator(){_ptr = NULL;}                    //default ctor
        Iterator(node<T>* p){
            _ptr = p;
        }
                                                    //Point Iterator to where p
                                                    //  is pointing to
        T &operator*(){
            return this->_ptr->_item;
        }                             //dereference operator
        T *operator->(){
            return this->_ptr->_next;
        }                            //member access operator
        bool is_null(){
            if(this->_ptr == nullptr){
                return true;
            }

            return false;
        }                             //true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right){
            if(left._ptr != right._ptr){
                return true;
            }

            return false;
        } //true if left != right

        friend bool operator==(const Iterator &left,
                               const Iterator &right){
            if(left._ptr == right._ptr){
                return true;
            }
            
            return false;
        } //true if left == right

        Iterator &operator++(){
            this->_ptr = this->_ptr->_next;
            return *this;
        }                         //member operator:
                                                        //  ++it; or
                                                        //  ++it = new_value

        friend Iterator operator++(Iterator &it,int unused){
            Iterator temp = it;
            ++(it);
            return temp;
        }          //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename TT>
    friend std::ostream& operator<<(std::ostream& outs, 
                                        const Stack<TT>& printMe);

    Iterator begin() const;             //Iterator to the head node
    Iterator end() const;            //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

template <typename T>
Stack<T>::Stack(){
    _size = 0;
    _top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _size = copyMe._size;
    _top = _copy_list(copyMe._top);
}

template <typename T>
Stack<T>::~Stack(){
    _clear_list(_top);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
    _clear_list(_top);
    _size = RHS._size;
    _top = _copy_list(RHS._top);
    return *this; 
}

template <typename T>
T Stack<T>::top(){
    if(empty()){
        return NULL;
    }
    Iterator it(_top);
    return *it;
}

template <typename T>
bool Stack<T>::empty(){
    if(size() == 0){
        return true;
    }

    return false;
}

template <typename T>
void Stack<T>::push(T item){
     _top = _insert_before(_top,_top,item);
    _size++;
}

template <typename T>
T Stack<T>::pop(){
    if(empty()){
        return 0;
    }
    T popped = _delete_node(_top,_top);
    _size--;
    return popped;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    Iterator it(_top);
    return it;
    }              //Iterator to the head node
template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const{
    Iterator it(nullptr);
    return it;
}  

template<typename TT>
std::ostream& operator<<(std::ostream& outs, const Stack<TT>& printMe){
    if(printMe._size ==0){
        outs<<"Empty Stack";
        return outs;
    }
    outs<<"Stack:";
    _print_list(printMe._top);
    return outs;
}


#endif


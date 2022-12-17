/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: MyQueue.h
 *  Queue built using linked list 
 *  
 * ************************************************************************* */

#ifndef AOTS_QUEUE_H
#define AOTS_QUEUE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include "../linked_list_functions/linked_list_functions.h"
#include "../token/token.h"
#include "../data_pkg/tk_data.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class List;   
        friend class Token;                       //give access to list to
                                                    //          access _ptr
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

        operator bool(){
            if(_ptr != nullptr){
                return true;
            }
            return false;
        }

        bool is_null(){
            if(_ptr == nullptr){
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
        node<T>* _ptr;           //pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue& operator=(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();

    void push(T item); 
    T pop();

    Iterator begin() const;        //Iterator to the head node
    Iterator end() const;         //Iterator to NULL
    void print_pointers();
    int size() const { return _size; }
    template<typename TT>
    friend std::ostream& operator << (std::ostream& outs, const Queue<TT>& printMe);
    std::string get_queue_str();

 private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

template <typename T>
Queue<T>::Queue(){
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe){
    _size = copyMe._size;
    _rear = _copy_list(_front,copyMe._front);
}

template <typename T>
 Queue<T>::~Queue(){
    _clear_list(_front);
 }
 
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& RHS){
    _clear_list(_front);
    _size = RHS._size;
    _rear = _copy_list(_front,RHS._front);
    return *this; 
}

template <typename T>
bool Queue<T>::empty(){
    if(size() == 0){
        return true;
    }
    return false;
}

template <typename T>
T Queue<T>::front(){
    Iterator it(_front);
    return *it;
}

template <typename T>
T Queue<T>::back(){
    Iterator it(_rear);
    return *it;
}

template <typename T>
void Queue<T>::push(T item){
    if(_size == 0){
        _front = _insert_head(_front,item);
        _rear = _front;
    }
    else{
        _rear = _insert_after(_front,_rear,item);
    }
    _size++;
}

template <typename T>
T Queue<T>::pop(){
    T popped = _delete_node(_front,_front);
    _size--;
    return popped;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const{
        Iterator it(_front);
        return it;
    }           //Iterator to the head node
template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const{
        Iterator it(nullptr);
        return it;
    } 

template <typename T>
void Queue<T>::print_pointers(){
    node<T> * wlk = _front;
    while(wlk != nullptr){
        std::cout<<*(wlk->_item);
        wlk=wlk->_next;
    }
}

template <typename T>
std::string Queue<T>::get_queue_str(){
    std::stringstream ss;
    std::string hold;
    std::string queue;
    node<T> * wlk = _front;
    while(wlk != nullptr){
        ss.clear();
        ss<<*(wlk->_item);
        ss>>hold;
        queue = queue+hold;
        wlk=wlk->_next;
    }
    return queue;
}

template<typename TT>
std::ostream& operator << (std::ostream& outs, const Queue<TT>& printMe){
    outs<<"Queue:";
    /*
    node<TT>* wlk = printMe;
        while(wlk !=nullptr){
        std::cout << *wlk;
        wlk=wlk->_next;
        } 
        */
    return outs;
}

#endif
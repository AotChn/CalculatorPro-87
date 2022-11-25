/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: node.h
 *  data wrapper for linked list functions
 *  item - ptr to next node
 * ************************************************************************* */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>

template <typename ITEM_TYPE>
struct node{
    //CTOR
    node(const ITEM_TYPE& item = ITEM_TYPE(), node* next = nullptr);

    //operator <<
    template <typename T>
    friend std::ostream& operator <<(std::ostream& outs, const node<T> &printMe);
    
    ITEM_TYPE _item;
    node* _next;
};
    
template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(const ITEM_TYPE& item, node* next){
    _item = item;
    _next = next;
}

template <typename T>
std::ostream& operator <<(std::ostream& outs,const node<T> &printMe){
    outs<<"["<<printMe._item<<"]-> ";
    if(printMe._next == nullptr){
        outs<<"|||";
    }
    return outs;
}

#endif
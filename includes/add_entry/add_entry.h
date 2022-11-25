/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: add_entry.h
 *  low level functions to add to list 
 *  add/removing entries
 * ************************************************************************* */

#ifndef AOTS_ADD_ENTRY_H
#define AOTS_ADD_ENTRY_H

#include <iostream>
#include <iomanip>

#include "../array_functions/array_functions.h"

using namespace std;
typedef string T;

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);
template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);
template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity);
template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity);
template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity);

template<class T> //ADDING ENTRY TO LIST
T* add_entry(T* list, const T& new_entry, int& size, int& capacity)
{   
    bool full = false;
    if(size==capacity){
        full = true;
    }
    if(full){
        capacity = capacity * 2;
        list = reallocate(list,size,capacity);
    }
    
    T* pivot = list+size;

    *pivot = new_entry;
     size++;
    return list;
}

template<class T> //REMOVING ENTRY FROM LIST
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity)
{
    bool quarter_empty;
    T* delete_index = search_entry(list,size,delete_me);
    shift_left(list,size,delete_index);
    if(size==capacity/4){
        quarter_empty = true;
        if(size<(MINIMUM_CAPACITY*2)/3){
            quarter_empty = false;
        }
    }
    if(quarter_empty){
        capacity = capacity/2;
        list = reallocate(list,size,capacity);
    }
    return list;
}

template <class T> //REMOVE THE LAST ENTRY
T *remove_last_entry(T *list, T &popped, int &size, int &capacity)
{   
    bool quarter_empty;
    T* delete_index = list+size-1;
    popped = *delete_index;
    shift_left(list,size,delete_index);
    if(size==capacity/4){
        quarter_empty = true;
        if(size<(MINIMUM_CAPACITY*2)/3){
            quarter_empty = false;
        }
    }
    if(quarter_empty){
        capacity = capacity/2;
        list = reallocate(list,size,capacity);
    }
    
    
    return list;
}

template <class T> //INSERT ENTRY AT INDEX 
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity)
{
    bool full = false;
    if(size==capacity){
        full = true;
    }
    if(full){
        capacity = capacity * 2;
        list = reallocate(list,size,capacity);
    }
    T* pivot = list+insert_here;
    shift_right(list,size,pivot);
    *pivot = insert_this;
    
    return list;
}

template <class T> //REMOVE ENTRY AT INDEX
T *erase_entry(T *list, int index, int &size, int &capacity)
{
    bool quarter_empty;
    T* delete_index = list+index;
    shift_left(list,size,delete_index);
    if(size==capacity/4){
        quarter_empty = true;
        if(size<(MINIMUM_CAPACITY*2)/3){
            quarter_empty = false;
        }
    }
    if(quarter_empty){
        capacity = capacity/2;
        list = reallocate(list,size,capacity);
    }   
    return list;
}


#endif //add_entry.h
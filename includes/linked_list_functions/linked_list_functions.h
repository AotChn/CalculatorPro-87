/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: linked_list_functions.h
 *  templated low-level functions for linked-list
 *  searching - inserting - removing - print 
 * ************************************************************************* */

#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H


#include <iostream>
#include <iomanip>
#include "../node/node.h"

    //Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head);

    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head);

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,
                                ITEM_TYPE key);


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,
                                ITEM_TYPE insert_this);

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,
                                 node<ITEM_TYPE> *after_this,
                                 ITEM_TYPE insert_this);

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                                  node<ITEM_TYPE>* before_this,
                                  ITEM_TYPE insert_this);

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prev_to_this);

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* delete_this);

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src);


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head);

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                                  ITEM_TYPE item,
                                  bool ascending=true);

    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                          ITEM_TYPE item,
                                          bool ascending=true);
    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                                   ITEM_TYPE item,
                                   bool ascending=true);
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);            //never use this function.


//Linked List General Functions DEFINITIONS:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head){
        node<ITEM_TYPE> * wlk = head;
        while(wlk !=nullptr){
        std::cout << *wlk;
        wlk=wlk->_next;
        } 
    }
    
    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head){
        
    }

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,ITEM_TYPE key){
       node<ITEM_TYPE> * found = head;
            while(found != nullptr){
                if(found->_item == key){
                    return found;
                }
                found = found->_next;
            }
            return nullptr;
    }


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,ITEM_TYPE insert_this){
        node<ITEM_TYPE> * n = new node<ITEM_TYPE>;
        n->_item = insert_this;
        n->_next = head;
        head = n;
        
        
        return head;
    }

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this,ITEM_TYPE insert_this){
        node<ITEM_TYPE> * n = new node<ITEM_TYPE>;
        n = _insert_head(after_this->_next,insert_this);

        return n;
    }

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,node<ITEM_TYPE>* before_this,ITEM_TYPE insert_this){
        node<ITEM_TYPE> * n = _previous_node(head,before_this);
        n = _insert_head(n,insert_this);

        return n;
    }

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,node<ITEM_TYPE>* prev_to_this){
        node<ITEM_TYPE>* wlk = head;
        node<ITEM_TYPE>* prev = head;
        while(wlk != prev_to_this){
            prev = wlk;
            wlk = wlk->_next;
        }
    return prev;
    }
    //delete, return item
   
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,node<ITEM_TYPE>* delete_this){
        ITEM_TYPE popped;
        if(head == delete_this){
            head = delete_this->_next;
            popped = delete_this->_item;
            delete delete_this;
            
            return popped;
        }
        node<ITEM_TYPE>* prev = _previous_node(head,delete_this);
        prev->_next = delete_this->_next;
        popped = delete_this->_item;
        delete delete_this;

        return popped;
    }

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head){
        node<ITEM_TYPE> * wlk = head;
        node<ITEM_TYPE> * cpy = nullptr;
        node<ITEM_TYPE> * tail = nullptr;
        while(wlk != nullptr){
            if(cpy == nullptr){
                cpy = new node<ITEM_TYPE>;
                cpy->_item = wlk->_item;
                cpy->_next = nullptr; 
                tail = cpy;
            }
            else{
                tail->_next = new node<ITEM_TYPE>;
                tail = tail->_next;
                tail->_item = wlk->_item;
                tail->_next = nullptr;
            }
            wlk = wlk->_next;
        }
        return cpy;
    }
    

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src){
        node<T> * wlk = src;
        node<T> * cpy = nullptr;
        node<T> * tail = nullptr;
        while(wlk != nullptr){
            if(cpy == nullptr){
                cpy = new node<T>;
                cpy->_item = wlk->_item;
                cpy->_next = nullptr; 
                tail = cpy;
            }
            else{
                tail->_next = new node<T>;
                tail = tail->_next;
                tail->_item = wlk->_item;
                tail->_next = nullptr;
            }
            wlk = wlk->_next;
        }
        dest = cpy;
        return tail;
    }


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head){
        node<ITEM_TYPE> *wlk = head;
        while(head != nullptr){
            _delete_node(head,wlk);
            wlk = head;
        }
    }

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos){
        node<ITEM_TYPE> * wlk = head;
        for(int i = 0;i<pos;i++){
            wlk = wlk->_next;
        }
        return wlk->_item;
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,ITEM_TYPE item,bool ascending){
        if(head == nullptr){
            head = _insert_head(head,item);
            return head;
        }
        node<ITEM_TYPE> * index = _where_this_goes(head,item);
        node<ITEM_TYPE> * inserted = _insert_before(head,index,item);
        return inserted;
    }

    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,ITEM_TYPE item,bool ascending){
        node<ITEM_TYPE> * index = _where_this_goes(head,item);
        if(index->_item == item){
            index->_item = _delete_node(head,index);
            node<ITEM_TYPE> * inserted = _insert_sorted(head,item*2,ascending);
            return inserted;
        }
        return head;
    }


    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,ITEM_TYPE item,bool ascending){
        node<ITEM_TYPE> * index = head;
            while(index != nullptr){
                if(index->_item >= item&&ascending==true){
                    return index;
                }
                if(index->_item <= item&&ascending==false){
                    return index;
                }
                index = index->_next;
            }
            return index;
    }

    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head){
        node<ITEM_TYPE> * wlk = head;
        while(wlk != nullptr){
            wlk = wlk->_next;
        }
        return wlk;
    }  

#endif 
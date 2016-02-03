#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "linkedlist.h"
#include <iostream>

//constructors and destructors
template <typename T>
linkedlist<T>::linkedlist()
{
    head = tail = nullptr;
    length = 0;
}

template <typename T>
linkedlist<T>::linkedlist(const linkedlist & srclist)
{
    Iterator src_itr = srclist.head;

    while (src_itr != nullptr){
        push_back(src_itr->data);
        src_itr = src_itr->next;
    }
}

template <typename T>
linkedlist<T>& linkedlist<T>::operator=(const linkedlist<T> & rhs)
{
    linkedlist<T> list(rhs);
    swap(list);
    return *this;
}

template <typename T>
void linkedlist<T>::push_back( T data){
    node * tmp = new node(data, nullptr, tail);
    if(head == nullptr)
        head = tail = tmp;
    else
        tail->next = tmp;
    length++;
}

template <typename T>
void linkedlist<T>::pop_back(){
    assert( tail != nullptr);
    node* tmp = tail;
    tail = tail->prev;
    if (tail == nullptr){
        //empty list
        delete tmp;
        head = nullptr;
    }else{
        delete tmp;
        tail->next == nullptr;
    }
        length--;
}

template <typename T>
void linkedlist<T>::push_front( T data){
    head = new node(data, head, nullptr);
    length++;
}

template <typename T>
void linkedlist<T>::pop_front(){
    assert( head != nullptr);
    node* tmp = head;
    head = head->next;
    if (head == nullptr){
        //empty list
        delete tmp;
        head = nullptr;
    }else{
        delete tmp;
        head->prev == nullptr;
    }
        length--;
}
template <typename T>
void linkedlist<T>::clear(){
    while(head){
        node * tmp = head;
        head = head->next;
        delete tmp;
    }
    length = 0;
}

template <typename T>
void linkedlist<T>::swap(linkedlist<T> & srclist){
    std::swap(head, srclist.head);
    std::swap(tail, srclist.tail);
    std::swap(length, srclist.length);
}

template <typename T>
void linkedlist<T>::resize(size_t size){
    if(size >= length)
        return;
    length = size;
    node* itr = head;
    while(size--){
        itr = itr->next;
    }
    while (itr){
        node * tmp = itr;
        itr = itr->next;
        delete tmp;
    }
}

template <typename T>
void linkedlist<T>::insert(Iterator pos, Iterator start, Iterator end){
  Iterator insert_before = pos;
  Iterator itr = start;

  while (itr != end){
      node *newNode = new node(itr->data, insert_before, insert_before->prev);
      insert_before = newNode;
      itr = itr->next;
  }
}

template <typename T>
void linkedlist<T>::erase(Iterator pos){
  if (pos->prev == nullptr){
      head = pos->next;
      length--;
      if(pos->next)
          pos->next->prev = nullptr;
      delete pos;
  }
}

#endif //LINKEDLIST_CPP

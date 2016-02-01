#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class linkedlist {

    typedef T* Iterator;
public:
    //constructos and destructors
    linkedlist();
    linkedlist(const linkedlist<T> &);
    ~linkedlist();
    linkedlist<T>& operator=(const linkedlist<T> & srcList);

    //modifiers
    void push_back(T data);
    void pop_back();
    void push_front(T data);
    void pop_front();
    void clear();
    void swap(linkedlist<T>&);
    void resize(size_t size);
    void insert(Iterator, Iterator, Iterator);
    void erase(Iterator);

    //Iterators
    Iterator begin(){return head;}
    Iterator end(){return tail;}
    Iterator rbegin(){return tail;}
    Iterator rend(){return head;}

    //accessors
    T front() const {assert(head == nullptr);return head->data;}
    T back() const {assert(tail == nullptr);return tail->data;}

    //capacity
    size_t size() const {return length;}
    bool empty() const {return (length == 0);}

private:
    struct node{
        T data;
        node * next;
        node * prev;
        node(T value, node* next, node* prev)
            :data(value)
            ,next(next)
            ,prev(prev){}
        ~node(){~T();}
    };

    node* head;
    node* tail;
    size_t length;
};

#endif // LINKEDLIST_H

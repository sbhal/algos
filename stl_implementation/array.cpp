#include "array.h"
#include <iostream>

template <class T>
int array<T>::size(){
    return length;
}

template <class T>
bool array<T>::empty(){
    return (length == 0)? true : false;
}

template <class T>
T array<T>::front(){
    return head;
}

template <class T>
T array<T>::back(){
    return head + length;
}


template <class T>
T& array<T>::at(int index){
    if(index >= length)
        std::cout <<"throw exception";
    return *(head + index);
}


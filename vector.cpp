#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"

template<class T>
vector<T>::vector(int capacity)
{
    _begin = new T[capacity];
    _size = 0;
    _capacity = capacity;
}

template<class T>
vector<T>::vector()
{
    _begin = new T[10];
    _size = 0;
    _capacity = 10;
}

template<class T>
bool vector<T>::empty() const {
    return (_size == 0)? true: false;
}

template<class T>
vector<T>& vector<T>::operator= (const vector<T>& src){
    this.clear();
    this.reserve(2*src.size());
    for(Iterator itr = src.begin(); itr != src.end(); ++itr){
        this.push_back(*itr);
    }
    return *this;
}

template<class T>
typename vector<T>::Iterator vector<T>::begin() const{
    return _begin;
}

template<class T>
typename vector<T>::Iterator vector<T>::end() const{
    return _begin + _size;
}

template<class T>
T& vector<T>::front() const{
    if( _begin != NULL)
        return *_begin;
    else
        std::cout <<"Error";
}

template<class T>
T& vector<T>::back() const{
    Iterator _end = end();
    if( _size != 0)
        return *(_end - 1);
    else{
        std::cout <<"Error";
    }
}

template<class T>
void vector<T>::push_back(const T& value){
    if ( _size + 1 > _capacity )
        reserve(2 * _capacity);
    typename vector<int>::Iterator _end = end();
    *(_end) = value;
    _size++;
}

template<class T>
void vector<T>::pop_back(){
    if (_size == 0)
        return;
    Iterator _end = end();
    *_end = 0;
    _size--;
}

template<class T>
void vector<T>::reserve(size_t capacity){
    if (_capacity >= capacity)
        return;
    Iterator _new_begin = new T[capacity];
    int size = _size;
    for(int cnt = 0; cnt != size; cnt++){
        *(_new_begin + cnt) = *(_begin + cnt);
    }
    delete[] this->_begin;
    this->_begin = _new_begin;
    _capacity = capacity;
}

template<class T>
void vector<T>::resize(size_t size){
    if(size > _capacity){
        reserve(size);
        for (Iterator itr = _begin + _capacity; itr != _begin + size; ++itr)
            *itr = 0;
        _size = _capacity = size;
    } else if (size < _capacity) {
        Iterator _new_begin = new T[size];
        for(int cnt = 0; cnt != size; cnt++){
            *(_new_begin + cnt) = *(_begin + cnt);
        }
        delete [] this->_begin;
        _begin = _new_begin;
        _size = _capacity = size;
    } else {
        std::cout <<"resize of same capacity";
    }
}

template<class T>
T& vector<T>::operator[](int index) const{
    if(index >= _size){
        std::cout << "Error";
    }
    return _begin[index];
}

template<class T>
size_t vector<T>::size() const{
    return _size;
}

template<class T>
size_t vector<T>::capacity() const{
    return _capacity;
}

template<class T>
void vector<T>::clear(){
    _size = 0;
    //_capacity = 0;
    //_begin = nullptr;
}

template<class T>
vector<T>::~vector(){
    if (_begin != nullptr)
        delete [] _begin;
    _begin = 0;
    _capacity = 0;
}
#endif // VECTOR_CPP

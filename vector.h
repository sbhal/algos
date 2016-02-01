#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template< class T >
class vector
{
    typedef T* Iterator;
public:
    vector(int);
    vector();
    ~vector();
    void push_back(const T& value);
    void pop_back();
    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    T& front() const;
    T& back() const;
    Iterator begin() const;
    Iterator end() const;
    T& operator[](int index) const;
    vector<T>& operator= (const vector<T>& rhs);
    T& at(int index) const;

    void reserve(size_t capacity);
    void resize(size_t size);
    void insert();
    void clear();
    void erase();

private:
    Iterator _begin;
    size_t _size;
    size_t _capacity;
};

#include "vector.cpp"

#endif // VECTOR_H

#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class array {
public:
    int size();
    bool empty();
    T front();
    T back();
    T& operator[](int index);
    T& at(int index);
private:
    T* head;
    int length;
};

#endif // ARRAY_H

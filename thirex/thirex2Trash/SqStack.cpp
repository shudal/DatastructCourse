#ifndef __SQ_STACK__
#define __SQ_STACK__

#include <cstring>
#include <iostream>
using namespace std;
const int DEFAULT_SIZE = 100;

template<class T>
class SqStack {
    protected:
        int top;
        int maxSize;
        T *data;
    public:
        SqStack(int size = DEFAULT_SIZE);
        virtual ~SqStack();
        int getLength() const;
        bool isEmpty() const;
        void clear();
        void traverse(void (*Visit) (const T &)) const;
        int push(const T e);
        int getTop(T &e) const;
        int pop(T &e);
        SqStack(const SqStack<T> &s);
        SqStack<T> &operator =  (const SqStack<T> &s);
};

template<class T>
SqStack<T>::SqStack(int size) {
    data = new T[size];
    top = -1;
}

template<class T>
int SqStack<T>::push(const T e) {
    data[++top] = e;
    return top;
}

template<class T>
int SqStack<T>::pop(T &e) {
    if (top >= 0) {
        e = data[top--];
    }
    return top;
}

template<class T>
int SqStack<T>::getTop(T &e) const {
    e = data[top];
    return 1;
}

template<class T>
int SqStack<T>::getLength() const {
    return top+1;
}

template<class T>
void SqStack<T>::clear() {
    top = -1;
}

template<class T>
bool SqStack<T>::isEmpty() const {
    if (top == -1) {
        return true;
    }
    return false;
}

template <class T>
SqStack<T>::~SqStack() {

}
#endif

#ifndef __NODE_H_
#define __NODE_H_
template <class T>
struct Node {
    T data;
    Node<T> *next;
    Node();
    Node(T _data, Node<T> *_next = NULL) : data(_data), next(_next) {};
};

#endif

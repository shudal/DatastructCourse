#include <iostream>
#include "LinkList.h"

using namespace std;

template<class T>
LinkList<T>::LinkList() {
    length = 0;
    head = NULL;
}

template<class T>
LinkList<T>::LinkList(T v[], int n) {
    if (n <= 1) return;
    head = new Node<T>(v[0]);

    Node<T> *next;
    Node<T> **last = &head;
    for (int i=1; i<n; i++) {
        next = new Node<T>(v[i]);
        (*last)->next = next;
        last = &next;
    }

    length = n;
}

template<class T>
void LinkList<T>::traverse(void (*visit) (const T &)) const {
    Node<T> *p = head;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
}

template<class T>
int LinkList<T>::getLength() const {
    return length;
}

template<class T>
bool LinkList<T>::empty() const {
    if (length <= 0) {
        return true;
    }
    return false;
}

template<class T>
void LinkList<T>::clear() {
    Node<T> *p = head;
    while (p != NULL) {
        delete p;
        p = p->next;
    }
    head = NULL;
    length = 0;
}

template<class T>
int LinkList<T>::locate(const T &elem) const {
    Node<T> *p = head;
    int i=0;
    while (p != NULL) {
        if (p->data == elem) {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

template<class T>
int LinkList<T>::get(int index, T &e) const {
    Node<T> *p = head;
    int i=0;
    while (p != NULL) {
        if (index == i) {
            e = p->data;
            return 0;
        }
        p = p->next;
        i++;
    }

    return -1;
}

template<class T>
int LinkList<T>::set(int index, const T &e) {
    Node<T> *p = head;
    int i=0;
    while (p != NULL) {
        if (i == index) {
            p->data = e;
            return 1;
        }
        p = p->next;
        i++;
    }

    return -1;
}

template<class T>
int LinkList<T>::del(int index, T &e) {
    length--;

    if (index == 0) {
        e = head->data;
        delete head;
        head = head->next;
        return 1;
    }

    Node<T> *p = head, *parent;
    int i=0;
    while (p != NULL) {
        if (i==index) {
            e = p->data;
            parent->next = p->next;
            delete p;
            return 1;
        }
        parent = p;
        p = p->next;
        i++;
    }

    length++;
    return -1;
}

template<class T>
int LinkList<T>::insert(int index, const T &e) {
    length++;

    Node<T> *newNodePointer = new Node<T>(e);

    if (index == 0) {
        newNodePointer->next = head;
        head = newNodePointer;
        return 1;
    }

    Node<T> *p = head, *parent;
    int i=0;
    while (p != NULL) {
        if (index == i) {
            parent->next = newNodePointer;
            newNodePointer->next = p;
            return 1;
        }
        parent = p;
        p = p->next;
        i++;
    }

    length--;
    return -1;
}

template<class T>
int LinkList<T>::insert(const T &e) {
    length++;

    if (head == NULL) {
        head = new Node<T>(e);
        return 1;
    }

    Node<T> *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new Node<T>(e);
    return 1;
}

template<class T>
LinkList<T>::LinkList(const LinkList<T> &list) {
    length = list.getLength();
    if (length == 0) return;

    T data;
    list.get(0, data);
    head = new Node<T>(data);

    Node<T> *last = head;

    Node<T> *next;
    for (int i=1; i<length; i++) {
        list.get(i, data);
        next = new Node<T>(data);
        last->next = next;
        last = next;
    }

}

template<class T>
LinkList<T>& LinkList<T>::operator= (const LinkList<T> &list) {
    clear();

    length = list.getLength();
    //if (length == 0) return;

    T data;
    list.get(0, data);
    head = new Node<T>(data);

    Node<T> *last = head;

    Node<T> *next;
    for (int i=1; i<length; i++) {
        list.get(i, data);
        next = new Node<T>(data);
        last->next = next;
        last = next;
    }
    return *this;

}
/*
 * 析构函数
 * 法二
template<class T>
LinkList<T>::~LinkList() {
    Node<T> **p = &head;
    Node<T> **next;
    while ((*p) != NULL) {
        next = &((*p)->next);
        delete (*p);
        p = next;
    }
}
*/

// 法一
template<class T>
LinkList<T>::~LinkList() {
    Node<T> *p = head;
    while (p != NULL) {
        delete p;
        p = p->next;
    }
}

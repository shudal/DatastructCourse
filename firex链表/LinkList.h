#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include "Node.h"

template<class T>
class LinkList {
    protected:
        Node<T> *head;
        int length;
    public:
        LinkList();
        LinkList(T v[], int n);
        virtual ~LinkList();
        int getLength() const;
        bool empty() const;
        void clear();
        void traverse(void (*vistit)(const T &)) const;
        int locate(const T &e) const;
        int get(int index, T &e) const;
        int set(int index, const T &e);
        int del(int index, T &e);
        int insert(int index, const T &e);
        int insert(const T &e);
        LinkList(const LinkList<T> &list);
        LinkList<T> &operator = (const LinkList<T> &list);
};
#endif

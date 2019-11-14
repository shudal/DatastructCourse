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

        class iterator {
            public:
                iterator() {
                    p = NULL;
                }
                iterator(Node<T> *_p) {
                    p = _p;
                }
                iterator operator ++ () {
                    if (p != NULL) {
                        p = p->next;
                    }
                    return *this;
                }
                bool operator != (const iterator &e) {
                    if ((p == NULL && e.p != NULL)  || (p != NULL && e.p == NULL)) {
                        return true;
                    } else if (p==NULL && e.p==NULL) {
                        return false;
                    }
                    return p->data != e.p->data;
                }
                T& operator *() {
                    return p->data;
                }
                const T& operator * () const {
                    return p->data;
                }

            private:
                Node<T> *p;

        };
        iterator begin() {
            return iterator(head);
        }
        iterator end() {
            /*
            Node<T> *p2 = head;
            while (p2->next != NULL) {
                p2 = p2->next;
            }
            */
            return iterator(NULL);
        }
};
#endif

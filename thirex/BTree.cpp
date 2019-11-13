#ifndef __BTREE_H_
#define __BTREE_H_

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include "SqStack.cpp"
using namespace std;;
const int MAX_SIZE = 100;

template<class T>
class BTree {
    private:
        struct BTNode {
            T data;
            BTNode* left;
            BTNode* right;
            int deepth;
        };
        //BTNode* b;
    public:
        BTNode *b;
        BTree(string s);
        ~BTree();
        void postOrder(BTNode *b);
        void postOrderNotRe();
        void preOrderNotRe();
        void inOrderNotRe();
        void showAncestors(char c);
        void showAncestors(BTNode* a);

};

template<class T>
BTree<T>::BTree(string s) {
    typedef BTNode *nodePointer;
    SqStack<nodePointer> nodeStack;
    BTNode *lastNode;
    int k;
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            nodeStack.push(lastNode);
            k = 1;
        } else if (c==')') {
            BTNode *aNode;
            nodeStack.pop(aNode);
        } else if (c==','){
            k = 2;
            continue;
        } else {
            lastNode = new BTNode();
            lastNode->data = c;
            lastNode->left = lastNode->right = NULL;

            if (b == NULL) {
                lastNode->deepth = 1;
                b = lastNode;
            } else {
                BTNode *topNode;
                nodeStack.getTop(topNode);
                lastNode->deepth = topNode->deepth + 1;
                switch(k) {
                    case 1:
                        topNode->left  = lastNode;
                        break;
                    case 2:
                        topNode->right = lastNode;
                        break;
                }
            }
        }
    }
}

template<class T>
BTree<T>::~BTree() {

}

template<class T>
void BTree<T>::postOrder(BTNode *b) {
    if (b->left != NULL) {
        postOrder(b->left);
    }
    if (b->right != NULL) {
        postOrder(b->right);
    }
    cout<<b->data;
}

template<class T>
void BTree<T>::inOrderNotRe() {
    typedef BTNode *nodePointer;
    SqStack<nodePointer> nodeStack;
    nodeStack.push(b);
    while (!nodeStack.isEmpty()) {
        BTNode *p;
        nodeStack.getTop(p);
        while (p != NULL) {
            nodeStack.push(p->left);
            nodeStack.getTop(p);
        }
        nodeStack.pop(p);
        if (! nodeStack.isEmpty()) {
            nodeStack.pop(p);
            cout<<p->data;
            nodeStack.push(p->right);
        }
    }
}

template<class T>
void BTree<T>::preOrderNotRe() {
    typedef BTNode *NodePointer;
    SqStack<NodePointer> nodeStack;
    BTNode *p;
    p = b;
    while (p || !nodeStack.isEmpty()) {
        while (p != NULL) {
            cout<<p->data;
            nodeStack.push(p);
            p = p->left;
        }
        nodeStack.pop(p);
        p = p->right;
    }
}

template<class T>
void BTree<T>::showAncestors(char c) {
    typedef BTNode *NodePointer;
    queue<NodePointer> nodeQueue;
    nodeQueue.push(b);
    int nodeDeepth = 0;
    while (!nodeQueue.empty()) {
        BTNode *front = nodeQueue.front();
        if (front->data == c) {
            nodeDeepth = front->deepth;
            break;
        }
        nodeQueue.pop();
        if (front->left != NULL) {
            nodeQueue.push(front->left);
        }
        if (front->right != NULL) {
            nodeQueue.push(front->right);
        }
    }
    while (!nodeQueue.empty()) nodeQueue.pop();
    nodeQueue.push(b);
    while (!nodeQueue.empty()) {
        BTNode *front = nodeQueue.front();
        if (front->deepth < nodeDeepth) {
            cout<<front->data;
        }
        nodeQueue.pop();
        if (front->left != NULL) {
            nodeQueue.push(front->left);
        }
        if (front->right != NULL) {
            nodeQueue.push(front->right);
        }
    }
}
#endif

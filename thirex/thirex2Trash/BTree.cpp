#ifndef __BTREE_H_
#define __BTREE_H_

#include <cstdio>
#include <iostream>
#include <string>
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
        };
        //BTNode* b;
    public:
        BTNode *b;
        BTree(string s);
        ~BTree();
        void postOrder();
        void postOrderNotRe(BTNode* b);
        void preOrderNotRe();
        void showAncestors(char c);
        void showAncestors(BTNode* a);

};

template<class T>
BTree<T>::BTree(string s) {
    SqStack<BTNode> nodeStack;
    typedef BTNode *nodePointer;
    SqStack<nodePointer> nodePointerStack;
    BTNode *lastNode;
    int k;
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            nodeStack.push(*lastNode);
            k = 1;
        } else if (c==')') {
            BTNode aNode;
            nodeStack.pop(aNode);
        } else if (c==','){
            k = 2;
            continue;
        } else {
            lastNode = new BTNode();
            lastNode->data = c;
            lastNode->left = lastNode->right = NULL;

            if (b == NULL) {
                b = lastNode;
            } else {
                BTNode topNode;
                nodeStack.getTop(topNode);
                switch(k) {
                    case 1:
                        topNode.left  = lastNode;
                        break;
                    case 2:
                        topNode.right = lastNode;
                        break;
                }
            }
        }
    }
}

template<class T>
BTree<T>::~BTree() {

}
#endif

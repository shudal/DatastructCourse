#ifndef __Graph_H__
#define __Graph_H__
#include "LinkList.h"
#include "LinkList.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_NUM = 20;
const int MAX_STR = 100;
const int MAX = 10000;

struct Vex {
    int id;
    string code;
    string name;
    bool operator== (const Vex v) const {
        if (code == v.code && name == v.name) {
            return true;
        } else {
            return false;
        }
    }
    bool operator != (const Vex v) const {
        if (*this == v) {
            return false;
        } else {
            return true;
        }
    }
};

struct Edge {
    Vex from;
    Vex to;
    int w;
    bool operator== (const Edge e) const {
        if (from == e.from && to == e.to && w == e.w) {
            return true;
        } else {
            return false;
        }
    }
    bool operator!= (const Edge e) const {
        if ((*this) == e) {
            return false;
        }
        return true;
    }
    bool operator < (const Edge &e) const {
        return w<e.w;
    }
};

class Graph {
    private:
        vector<Edge> g[MAX_NUM];
        int fa[MAX_NUM];
        LinkList<Vex> vexs;
        LinkList<Edge> edges;
        int vexNum;
        void visitVex(const Vex &v) {
            cout<<"code=" + v.code<<",name="<<v.name<<endl;
        }
        void visitEdge(const Edge &e) {
            cout<<"from(code=" + e.from.code + ", name="+ e.from.name + "),to(code="+ e.to.code + ", name=" + e.to.name + ")";
        }
        void genG();
        int getfather(int);
    public:
        Graph();
        ~Graph();

        bool insertVex(Vex v);
        bool delVex(Vex v);
        bool updateVex(Vex v);
        bool insertEdge(Edge e);
        bool delEdge(Edge e);
        bool updateEdge(Edge e);

        Edge getEdge(string, string);
        Vex getVex(string);
        void setVexNum(int n);

        int primMinTree();
        int kruskalMinTree();
};
#endif

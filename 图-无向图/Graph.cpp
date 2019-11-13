#include "Graph.h"

Graph::Graph() {

}
Graph::~Graph() {

}

bool Graph::insertVex(Vex v) {
    vexs.insert(v);
    vexNum++;
    return true;
}
bool Graph::delVex(Vex v) {
    vexs.del(vexs.locate(v), v);
    vexNum--;
    LinkList<Edge>::iterator iter = edges.begin();
    LinkList<Edge>::iterator iterEnd = edges.end();

    for(;iter != iterEnd; ++iter) {
        if ((*iter).from == v || (*iter).to == v) {
            delEdge(*iter);
        }
    }
    return true;
}
bool Graph::updateVex(Vex v) {
    LinkList<Vex>::iterator iter = vexs.begin();
    LinkList<Vex>::iterator iterEnd = vexs.end();
    for (; iter != iterEnd; ++iter) {
        if ((*iter).code == v.code) {
            (*iter) = v;
            return true;
        }
    }
    return false;
}
bool Graph::insertEdge(Edge e) {
    edges.insert(e);
    return true;
}
bool Graph::delEdge(Edge e) {
    edges.del(edges.locate(e), e);
    return true;
}
bool Graph::updateEdge(Edge e) {
    LinkList<Edge>::iterator iter = edges.begin();
    LinkList<Edge>::iterator iterEnd = edges.end();
    for (; iter != iterEnd; ++iter) {
        if ((*iter).from == e.from && (*iter).to == e.to) {
            (*iter).w = e.w;
            return true;
        }
    }
    return false;
}

Edge Graph::getEdge(string fromVexCode, string toVexCode) {
    Edge e;
    LinkList<Edge>::iterator iter = edges.begin();
    LinkList<Edge>::iterator iterEnd = edges.end();

    for (;iter != iterEnd; ++iter) {
        if ((*iter).from.code == fromVexCode && (*iter).to.code == toVexCode) {
            e = (*iter);
            break;
        }
    }
    return e;
}
Vex Graph::getVex(string vexCode) {
    Vex rv;
    LinkList<Vex>::iterator iter = vexs.begin();
    LinkList<Vex>::iterator iterEnd = vexs.end();

    for(;iter != iterEnd; ++iter) {
        if (vexCode == (*iter).code) {
            rv = *iter;
            break;
        }
    }
    return rv;
}
void Graph::setVexNum(int n) {
    vexNum = n;
}

int Graph::primMinTree(Edge aPath[]) {

    return true;
}
int Graph::kruskalMinTree(Edge aPath[]) {

    return 1;
};

#include "Graph.h"

Graph::Graph() {
    vexNum = 0;
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

void Graph::genG() {
    LinkList<Vex>::iterator iter;
    LinkList<Vex>::iterator iterVexEnd = vexs.end();
    LinkList<Edge>::iterator iterEdgeEnd = edges.end();
    int idCount = 0;
    for (int i=0; i<MAX_NUM; i++) {
        g[i].clear();
    }
    for (iter = vexs.begin(); iter != iterVexEnd; ++iter) {
        (*iter).id = (++idCount);
    }

    for (LinkList<Edge>::iterator e = edges.begin(); e != iterEdgeEnd; ++e) {
        string fromCode = (*e).from.code;
        string toCode = (*e).to.code;
        Vex fromVex = getVex(fromCode);
        Vex toVex = getVex(toCode);

        (*e).from.id = fromVex.id;
        (*e).to.id = toVex.id;
        g[fromVex.id].push_back(*e);

        Edge newE;
        newE.w = (*e).w;
        newE.from = toVex;
        newE.to = fromVex;
        g[toVex.id].push_back(newE);
    }
}
int Graph::primMinTree() {
    genG();
    int v[MAX_NUM];
    int dis[MAX_NUM];
    memset(v, 0, sizeof(v));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    int ans = 0;

    for (int i=1; i<=vexNum; ++i) {
        int mark = -1;
        for (int j=1; j<=vexNum; ++j) {
            if (!v[j]) {
                if (mark == -1) {
                    mark = j;
                } else if (dis[j]<dis[mark]) {
                    mark = j;
                }
            }
        }
        if (mark == -1) {
            break;
        }
        v[mark] = 1;
        ans += dis[mark];
        for (int j=0; j<g[mark].size(); ++j) {
            if (!v[g[mark][j].to.id]) {
                int x = g[mark][j].to.id;
                dis[x] = min(dis[x], g[mark][j].w);
            }
        }
    }
    return ans;
}
int Graph::getfather(int x) {
    if (x==fa[x]) return x;
    else return fa[x]=getfather(fa[x]);
}
int Graph::kruskalMinTree() {
    genG();
    int ans = 0;
    int cnt = vexNum;
    for (int i=1; i<=vexNum; ++i) {
        fa[i] = i;
    }
    int M = edges.getLength();
    LinkList<Edge>::iterator iter = edges.begin();
    LinkList<Edge>::iterator iterEnd = edges.end();
    vector<Edge> e;
    e.push_back(*iter);
    for (; iter != iterEnd; ++iter) {
        e.push_back(*iter);
    }
    sort(e.begin(), e.end());
    for (int i=1; i<=M; ++i) {
        int t1 = getfather(e[i].from.id);
        int t2 = getfather(e[i].to.id);
        if (t1 != t2) {
            fa[t1] = t2;
            ans += e[i].w;
            if (cnt == 1) {
                break;
            }
        }
    }
    return ans;
};

#include <iostream>
#include "Graph.h"
#include "Graph.cpp"

using namespace std;
int pMed = 0;
void printMenu() {
    if (pMed) return;
    cout<<"1 插入顶点"<<endl;
    cout<<"2 删除顶点"<<endl;
    cout<<"3 根据code获取顶点信息"<<endl;
    cout<<"7 更新顶点信息"<<endl;
    cout<<"4 插入边"<<endl;
    cout<<"5 删除边"<<endl;
    cout<<"6 根据fromCode和toCode获取边信息"<<endl;
    cout<<"8 更新边信息"<<endl;
    cout<<"9 Prim"<<endl;
    cout<<"10 Kruskal"<<endl;
    pMed = 1;
}
void printVex(Vex v) {
    cout<<"code="<<v.code<<", name="<<v.name<<endl;
}
void printEdge(Edge e) {
    cout<<"from:"<<endl<<"    ";
    printVex(e.from);
    cout<<"to:"<<endl<<"    ";
    printVex(e.to);
    cout<<"w="<<e.w<<endl;
    cout<<"------"<<endl;
}
int main() {
    Graph g;
    Vex v;
    Edge e;
    string vexCode;
    string fromCode, toCode;
    bool b;
    int ans;
    while (1) {
        printMenu();
        int action;
        cin>>action;
        switch (action) {
            case 1:
                cin>>v.code>>v.name;
                g.insertVex(v);
                break;
            case 2:
                cin>>vexCode;
                g.delVex(g.getVex(vexCode));
                break;
            case 3:
                cin>>vexCode;
                v = g.getVex(vexCode);
                printVex(v);
                break;
            case 4:
                cin>>fromCode>>toCode>>e.w;
                e.from = g.getVex(fromCode);
                e.to = g.getVex(toCode);
                g.insertEdge(e);
                break;
            case 5:
                cin>>fromCode>>toCode;
                e.from = g.getVex(fromCode);
                e.to = g.getVex(toCode);
                g.delEdge(e);
                break;
            case 6:
                cin>>fromCode>>toCode;
                e = g.getEdge(fromCode, toCode);
                printEdge(e);
                break;
            case 7:
                cin>>v.code>>v.name;
                b = g.updateVex(v);
                if (b) cout<<"更新成功"<<endl;
                else cout<< "更新失败"<<endl;
                break;
            case 8:
                cin>>fromCode>>toCode>>e.w;
                e.from = g.getVex(fromCode);
                e.to = g.getVex(toCode);
                b = g.updateEdge(e);
                if (b) cout<<"更新成功"<<endl;
                else cout<<"更新失败"<<endl;
                break;
            case 9:
                ans = g.primMinTree();
                cout<<"prim:最小生成树的边权和为"<<ans<<endl;
                break;
            case 10:
                ans = g.kruskalMinTree();
                cout<<"krus:最小生成树的边权和为"<<ans<<endl;
                break;
        }
    }
}

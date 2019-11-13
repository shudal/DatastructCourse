#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int maxn=10;
vector<int> tos[maxn];
int numberOfPoints;
void printTos() {
    cout<<"---"<<endl;
    for (int i=1; i<=numberOfPoints; i++) {
        for (int k=0; k<tos[i].size(); k++) {
            cout<<tos[i][k]<<" ";
        }
        cout<<endl;
    }
    cout<<"---"<<endl;
}
void bfs() {
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (! q.empty()) {
        int top = q.front();
        q.pop();
        cout<<"top="<<top<<endl;
        for (int i=0; i<tos[top].size(); i++) {
            int n = tos[top][i];
            if (! vis[n]) {
                q.push(n);
                vis[n]=1;
            }
        }
    }
}
int dfsVis[maxn];
void dfs(int n) {
    cout<<"n="<<n<<endl;
    for (int i=0; i<tos[n].size(); i++) {
        int toN = tos[n][i];
        if (! dfsVis[toN]) {
            dfsVis[toN] = 1;
            dfs(toN);
        }
    }
}
int main() {
    for (int i=0; i<maxn; i++) {
        tos[i].clear();
    }
    cin>>numberOfPoints;
    for (int i=1; i<=numberOfPoints; i++) {
        int nOfTo;
        cin>>nOfTo;
        for (int k=0; k<nOfTo; k++) {
            int n;
            cin>>n;
            tos[i].push_back(n);
        }
    }
    printTos();
    // bfs();
    memset(dfsVis, 0, sizeof(dfsVis));
    dfsVis[1] = 1;
    dfs(1);
}

#include <iostream>
#include <cstring>
using namespace std;

const int p = 10;
int ns[p];
int hash(int k) {
    int key =  k % p;
    if (ns[key] == -1) {
        return key;
    }
    while (1) {
        ++key;
        key = key % p;
        if (ns[key] == -1) {
            return key;
        }
    }
}
int main() {
    for (int i=0; i<p; i++) ns[i] = -1;
    int T=10;
    while (T--) {
        int n;
        cin>>n;
        int key = hash(n);
        ns[key] = n;
    }
    for (int i=0; i<p; i++) {
        if (ns[i] != -1) {
            cout<<"i="<<i<<", n="<<ns[i]<<endl;
        }
    }
}

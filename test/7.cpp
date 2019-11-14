#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> ns;
    ns.push_back(2);
    ns.push_back(1);
    ns.push_back(3);
    sort(ns.begin(), ns.end());
    for (int i=0; i<ns.size(); i++) {
        cout<<ns[i]<<endl;
    }
}

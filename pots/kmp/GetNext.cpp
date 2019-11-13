#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    // string pattern = "ABCDABD";
    string pattern = "ABCDABDE";
    int n = pattern.size();
    vector<int> next(n+1, 0);
    for (int i=1; i<n; i++) {
        int j = i;
        while (j>0) {
            j = next[j];
            if (pattern[i] == pattern[j]) {
                next[i+1] = j + 1;
                break;
            }
        }
    }
    cout<<"finish"<<endl;
}

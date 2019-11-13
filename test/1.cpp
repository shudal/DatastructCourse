#include <iostream>

using namespace std;
void ka() {
    struct ha {
        int t;
    };
    ha h;
    h.t = 1;
    cout<<h.t<<endl;
}
int main() {
    struct v {
        int c;
    };
    v v1;
    v1.c=2;
    cout<<v1.c<<endl;
    ka();
}

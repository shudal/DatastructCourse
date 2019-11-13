#include <iostream>

using namespace std;

struct S {
    int a;
    char c;
};
int main() {
    S s1, s2;
    s1.a = 1, s1.c = 'a';
    s2.a = 2, s2.c = 'b';
    bool b = (s1 == s2);
    cout<<b<<endl;
}

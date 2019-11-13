#include <iostream>
using namespace std;
int main() {
    int n = 2;
    int *p = &n;
    *p = 3;
    cout<<n<<endl;
}

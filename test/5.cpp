#include <iostream>

using namespace std;

const double n1 = 6.0/100;
double ka(double x) {
    return (x + x*n1);
}
double ka2(double x) {
    double sum = 0;
    for (int i=1; i<=18; i++) {
        sum += x;
        sum += (sum * n1);
    }
    return sum;
}
int main() {
    double k = 2442.1;
    while (1) {
        double k2 = ka2(k);
        cout<<k2<<endl;
        cout<<"    | k = "<<k<<endl;
        if (k2 <= 80000) {
            break;
        }

        k -= 0.001;
    }
}

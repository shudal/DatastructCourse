#include <iostream>

using namespace std;

const double n1 = 6.0/100;
double ka2(double x) {
    double sum = 0;
    for (int i=1; i<=18; i++) {
        sum += x;
        sum += (sum * n1);
        cout<<"i="<<i<<"后，sum="<<sum<<endl;
    }
    return sum;
}
int main() {
    double k = 2442;
    cout<<ka2(k);
}

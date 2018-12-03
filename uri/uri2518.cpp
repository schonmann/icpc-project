#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long double n,h,c,l;
    while(cin >> n >> h >> c >> l) {
        c /= 100;
        l /= 100;
        h /= 100;

        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(4);

        cout << n*l*(sqrt(pow(c,2) + pow(h,2))) << endl;
    }
    return 0;
}

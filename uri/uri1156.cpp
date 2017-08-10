#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double sum = 0;
    for(int i = 1; i <= 39; i+=2) {
        sum += i/(double)pow(2,((i-1)/2));
    }
    cout.precision(2);
    cout << fixed << sum << endl;
    return 0;
}

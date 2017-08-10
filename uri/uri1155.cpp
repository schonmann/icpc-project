#include <iostream>

using namespace std;

int main(void) {
    double sum = 0;
    for(int i = 1; i <= 100; i++) sum += 1/(double)i;
    cout.precision(2);
    cout << fixed << sum << endl;
    return 0;
}

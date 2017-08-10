#include <iostream>

using namespace std;

int factorial(int n) {
    int prod = n;
    while(--n >= 1) prod *= n;
    return prod;
}

int main(void) {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

#include <iostream>

using namespace std;

void printFibonacciSequence(int n) {
    int fib[46]; fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < n; i++) fib[i] = fib[i-1] + fib[i-2]; 
    for(int i = 0; i < n-1; i++) cout << fib[i] << " ";
    cout << fib[n-1] << endl;
}

int main(void) {
    int n;
    cin >> n;
    printFibonacciSequence(n);
    return 0;
}

#include <iostream>

using namespace std;

int gaussianSum(int n) {
    return n*(n+1)/2;
}

int main(void) {
    int a, n; cin >> a;
    while(n <= 0) cin >> n;
    cout << -gaussianSum(max(0,a) > 0 ? 0 : max(0,a)) + gaussianSum(max(0,a+n) > 0 ? 0 : max(0,a+n)) + gaussianSum(a+n-1) - gaussianSum(a-1) << endl;
    return 0;
}
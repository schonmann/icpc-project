#include <iostream>

using namespace std;

int main(void) {
    int x;
    cin >> x;
    int z = x;
    while(z <= x) cin >> z;
    int sum = 0;
    int i = 0;
    for(i = x; sum <= z; i++) sum += i;
    cout << i-x << endl;
    return 0;
}
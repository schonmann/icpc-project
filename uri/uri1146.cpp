#include <iostream>

using namespace std;

int main(void) {
    int x;
    while(cin >> x && x != 0) {
        int i = 1;
        while(i < x) cout << i++ << " ";
        cout << x << endl;
    }
    return 0;
}
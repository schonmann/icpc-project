#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    int age;
    int sum = 0; int n = 0;
    while(cin >> age && age >= 0) {
        sum += age;
        n++;
    }
    cout.precision(2);
    cout << fixed << sum/(float)n << endl;
    return 0;
}

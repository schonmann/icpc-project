#include <iostream>
#include <cmath>

#define PI 3.1415

using namespace std;

int main(void) {
    long long int baloonRadius, availableGasLiters;
    cin >> baloonRadius >> availableGasLiters;

    double baloonVolume = (4.0/3.0)*(PI*pow(baloonRadius, 3)); //Formato esferico.

    cout << (int) (availableGasLiters/baloonVolume) << endl;

    return 0;
}
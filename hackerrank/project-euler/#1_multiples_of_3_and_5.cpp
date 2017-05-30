#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 *  Mutual inclusion/exclusion solution.
 *  Assumptions: 1. Sum of i from 1 to n => n(n+1)/2 (The Gaussian sum).
 *               2. Let 's' be the sum of all multiples of a number 'x' from 1 to n.
 *               3. Let 'm' be the number of multiples of 'x' from 1 to 'n' => m = floor|n/x|.
 *               4. Therefore, with respect to 1,2, and 3, => s = x*(m*(m+1)/2);
 */

unsigned long int gaussianMult(int x, int n) {
    unsigned long int m = n/x;
    return x*m*(m+1) >> 1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        unsigned long int n; cin >> n; 
        unsigned long int s = 0;
        //Sum up the multiples of 3.
        s += gaussianMult(3,n-1);
        //Sum up the multiples of 5
        s += gaussianMult(5,n-1);
        //Remove the multiples from the intersection of the two series.
        s -= gaussianMult(15,n-1);
        //Output the result.
        printf("%lu\n",s);
    }
    return 0;
}

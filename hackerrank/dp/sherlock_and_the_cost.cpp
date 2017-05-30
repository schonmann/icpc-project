/*  
 *  HackerRank
 *  Problem: Sherlock and Cost
 *  Type: Dynamic Programming
 *  Time Complexity: O(N)
 *  Space Complexity: O(1)
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int * allocInts(int n) {
    return (int *) calloc(n, sizeof(int));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int * b = allocInts(n);
        int sum_high = 0; int sum_low = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if(i >= 1) {
                //We can choose to either keep b[i] or set it to 1.
                int high_to_high = abs(b[i-1]-b[i]); //Last choice was b[i-1], and now we choose b[i]!
                int high_to_low = abs(b[i-1]-1); //Last choice was b[i-1], and now we choose 1!
                int low_to_high = abs(1-b[i]); //Last choice was 1, and now we choose b[i]!
                //Store the last sums for sum update purposes.
                int last_sum_low = sum_low;
                int last_sum_high = sum_high;
                //Best sum for the last being 1.
                sum_low = high_to_low + last_sum_high;
                //Best sum for the last being b[i].
                sum_high = max(last_sum_low + low_to_high, last_sum_high + high_to_high);
            }
        }
        cout << max(sum_high, sum_low) << endl;
    }
    return 0;
}

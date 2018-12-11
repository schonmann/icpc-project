#include <iostream>
#include <vector>

/**
* Kadane's algorithm to calculate the maximum sum subarray.
*
* Time complexity: O(n)
* Space complexity: O(1)
*/

using namespace std;

typedef int T;
  
T kadaneMaxSubArraySum(vector<T> v) { 
   T max_so_far = v[0]; 
   T curr_max = v[0]; 
   for (int i = 1; i < v.size(); i++) { 
        curr_max = max(v[i], curr_max + v[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far;
}

/**
* Naive algorithm to calculate the maximum sum subarray.
*
* Time complexity: O(n^2)
* Space complexity: O(1)
*/

T naiveMaxSubArraySum(vector<T> v) {
    T max_so_far = 0;
    for(int i = 0; i < v.size(); i++) {
        T sum = 0;
        for(int j = i; j < v.size(); j++) {
            sum += v[j];
            max_so_far = max(sum, max_so_far);
        }
    }
    return max_so_far;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; vector<T> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << naiveMaxSubArraySum(v) << endl;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef int T;

int highestSumLessThanK(vector<T> arr, int k) {
    int leftIndex = 0;
    int rightIndex = arr.size() - 1;
    int bestSum = 0;
    
    while (leftIndex < rightIndex) {
        if (arr[leftIndex] + arr[rightIndex] < k) {
            bestSum = max(bestSum, arr[leftIndex] + arr[rightIndex]);
            leftIndex++;
        } else {
            rightIndex--;
        }
    }

    return bestSum;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    vector<T> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    cout << "Higher sum S = a[i] + a[j], where i < j and S < K: " << highestSumLessThanK(v, k) << endl;

    return 0;
}
#include <iostream>
#include <vector>

/**
* Longest increasing subsequence dynamic programming approach with memoization.
*
* Time complexity: O(N^2)
* Space complexity: O(N)
*/

using namespace std;

typedef int T;

int lisDP(vector<T> arr) {
    vector<T> lis(arr.size());
    lis[0] = 1;
    for (int i = 1; i < arr.size(); i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            } 
        }
    }
    int max = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(lis[i] > max) max = lis[i];
    }
    return max;
}

/**
* Longest increasing subsequence bin search approach.
*
* Time complexity: O(N log N)
* Space complexity: O(N)
*/

int binSearch(vector<T>& v, int l, int r, T key) { 
    while (r-l > 1) { 
        int m = l + (r-l)/2; 
        if (v[m] >= key) {
            r = m; 
        } else {
            l = m; 
        }     
    }
    return r; 
}
  
int lisBS(vector<int>& v) { 
    if (v.size() == 0) {
        return 0;
    } 
    vector<T> tail(v.size(), 0); 
    int length = 1;
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0]) {
            tail[0] = v[i];
        } else if (v[i] > tail[length - 1])  {
            tail[length++] = v[i];
        } else {
            tail[binSearch(tail, -1, length - 1, v[i])] = v[i];
        }
    }
    tail.resize(length);
    return tail.size();
}

void printVector(vector<T> x) {
    for(int i = 0; i < x.size(); i++) {
        cout << x[i];
        if(i < x.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; vector<T> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << "Length of the longest increasing subsequence: " << lisBS(v) << endl;

    return 0;
}
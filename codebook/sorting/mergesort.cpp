#include <iostream>
#include <vector>

/**
* Mergesort algorithm.
*
* Time complexity: O(n log(n))
* Space complexity: O(n)
*/

using namespace std;

typedef int T;

void merge(vector<T> &arr, int l, int m, int r) {
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    T L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; 
        k++; 
    }
    while (j < n2) {
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(vector<T> &arr, int l, int r) { 
    if (l < r) {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; 
    vector<T> elements(n);

    for(int i = 0; i < elements.size(); i++) {
        T x; cin >> x; elements[i] = x;
    }

    mergeSort(elements, 0, elements.size() - 1);

    for(int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if(i < elements.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}
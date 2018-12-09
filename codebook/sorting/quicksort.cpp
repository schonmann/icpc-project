#include <iostream>
#include <vector>

/**
* Quicksort algorithm.
*
* Time complexity: Θ(n log(n)) / O(n^2)
* Space complexity: O(1)
*/

using namespace std;

typedef int T;

void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(vector<T> &elements, int low, int high) {

    T pivot = elements[(low+high)/2];
    int l = low, r = high - 1;

    while(l <= r) {
        while(elements[l] < pivot && l < high) l++;
        while(elements[r] > pivot && r > low) r--;
        if(l <= r) {
            swap(elements[l], elements[r]);
            l++; r--;
        }
    }

    if(r > low) quickSort(elements, low, r+1);
    if(l < high) quickSort(elements, l, high);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; 
    vector<T> elements(n);

    for(int i = 0; i < elements.size(); i++) {
        T x; cin >> x; elements[i] = x;
    }

    quickSort(elements, 0, elements.size());

    for(int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if(i < elements.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}
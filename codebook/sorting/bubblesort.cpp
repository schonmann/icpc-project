#include <iostream>
#include <vector>

using namespace std;

typedef int T;

void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(vector<T> &elements) {
    for(int i = 0; i < elements.size(); i++) {
        for(int j = i+1; j < elements.size(); j++) {
            if(elements[i] > elements[j]) {
                swap(&elements[i], &elements[j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; 
    vector<T> elements(n);

    for(int i = 0; i < elements.size(); i++) {
        T x; cin >> x; elements[i] = x;
    }

    bubbleSort(elements);

    for(int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if(i < elements.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}
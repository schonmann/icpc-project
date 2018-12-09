#include <iostream>
#include <vector>

using namespace std;

typedef int T;

void quickSort(vector<T> elements) {

}

int main(void) {

    int n; cin >> n; 
    vector<T> elements(n);

    for(int i = 0; i < elements.size(); i++) {
        T x; cin >> x; elements[i] = x;
    }

    quickSort(elements);

    for(int i = 0; i < elements.size(); i++) {
        cout << elements[i] << endl;
    }
}
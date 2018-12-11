#include <iostream>
#include <vector>
#include <map>

/**
* Calculates the number of pairs with sum 'S' within a vector.
*
* Time complexity: O(n)
* Space complexity: O(1)
*/

using namespace std;

typedef int T;

int numPairsWithSum(vector<T> &elements, int sum) {
    map<T,int> m;
    for(int i = 0; i < elements.size(); i++) {
        m[elements[i]]++;
    }
    int count = 0;
    for(int i = 0; i < elements.size(); i++) {
        count += m[sum-elements[i]];
        if(sum - elements[i] == elements[i]) {
            count--;
        }
    }
    return count/2;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int s, n; cin >> s >> n; 
    vector<T> elements(n);

    for(int i = 0; i < elements.size(); i++) {
        T x; cin >> x; elements[i] = x;
    }

    cout << numPairsWithSum(elements, s) << endl;
}
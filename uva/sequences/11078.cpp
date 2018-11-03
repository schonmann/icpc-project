#include <limits>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int max = numeric_limits<int>::min();
		int maxDiff = numeric_limits<int>::min();
		for(int i = 0; i < n - 1; i++) {
			if(arr[i] > max) max = arr[i];
			if(max - arr[i+1] > maxDiff) maxDiff = max - arr[i+1];
		} 
		cout << maxDiff << endl;
	}
	
	return 0;
}


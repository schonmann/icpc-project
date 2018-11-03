#include <iostream>
#include <vector>

using namespace std;


vector<int> getLIS(vector<int> numbers) {
	vector<int> b, p (numbers.size());
	int u, v;

	if (numbers.size() < 1) return b;

	b.push_back (0);

	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[b.back()] < numbers[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
		for (u = 0, v = b.size() - 1; u < v;) {
			int c = (u + v) / 2;
			if (numbers[b[c]] < numbers[i]) u = c + 1; else v = c;
		}
		if (numbers[i] < numbers[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}
	
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}

int main(void) {
	
	vector<int> arr;
	int x;
	while(cin >> x) {
		arr.push_back(x);
	}
	
	vector<int> seq = getLIS(arr);
	
	cout << seq.size() << endl << "-" << endl;
	
	for(int i = 0; i < seq.size(); i++) {
		cout << arr[seq[i]] << endl;
	}
	
	return 0;
}

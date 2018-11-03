#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	
	int a, b;
	int i = 1;
	while(cin >> a >> b, !(a == 0 && b == 0)) {
		vector<int> A(a), B(b);
		
		for(int j = 0; j < a; j++) cin >> A[j];
		for(int j = 0; j < b; j++) cin >> B[j];
		
		int dp[300][300];
		
		memset(dp, 0, sizeof(dp));
		
		for(int j = 0; j < a; j++) {
			for(int k = 0; k < b; k++) {
				if(A[j] == B[k]) {
					dp[j + 1][k + 1] = dp[j][k] + 1; 
				} else {
					dp[j + 1][k + 1] = max(dp[j + 1][k], dp[j][k + 1]);
				}
			}
		}
		
		cout << "Twin Towers #" << i++ << endl;
		cout << "Number of Tiles : " << dp[a][b] << endl << endl;
	}
	
	return 0;
}

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
int main() {
	int N, W, caseNum = 0;
	while (1) {
		cin >> N >> W;
		int T[N+1][W+1];
		memset(T, 0, sizeof T);
		for (int i = 1; i <= N; i++) {
			int w, v;
			cin >> w >> v;
			for (int j = 1; j <= W; j++)
				T[i][j] = j < w ? T[i-1][j] : max(T[i-1][j-w] + v, T[i-1][j]);
		}
		int g = -1;
		for (int j = 0; j <= W; j++)
			if (T[N][j] > g)
				g = T[N][j];
		if (!(N || W))
			break;
		printf("Caso %d: %d\n", ++caseNum, g);
	}
	return 0;
}

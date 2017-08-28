#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
int main() {
	int N, W, caseNum = 0;
	while (1) {
		cin >> N >> W;
		int T[W+1];
		memset(T, 0, sizeof T);
		for (int i = 1; i <= N; i++) {
			int w, v;
			cin >> w >> v;
			for (int j = W; j >= w; j--)
				T[j] = max(T[j-w] + v, T[j]);
		}
		int g = -1;
		for (int j = 0; j <= W; j++)
			if (T[j] > g)
				g = T[j];
		if (!(N || W))
			break;
		printf("Caso %d: %d\n", ++caseNum, g);
	}
	return 0;
}

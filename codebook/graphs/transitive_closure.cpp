#include <iostream>
#include <vector>

/**
* Calculates the transitive closure using Floyd Warshall's algorithm.
*
* Time complexity: O(V^3)
* Space complexity: O(V^3)
*/

using namespace std;

vector<vector<int>> transitiveClosure(vector<vector<int>> graph) {
	int i, j, k;

    int n = graph.size();

    vector<vector<int>> reach(n, vector<int>(graph.size(), 0));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			reach[i][j] = graph[i][j];

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    return reach;
}

void printSolution(vector<vector<int>> reach) {
	cout << "Following matrix is transitive closure of the given graph" << endl;
	for (int i = 0; i < reach.size(); i++) {
		for (int j = 0; j < reach[i].size(); j++)
			cout << reach[i][j] << " ";
		cout << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> graph[i][j];

	vector<vector<int>> reach = transitiveClosure(graph);
    printSolution(reach);

	return 0;
}
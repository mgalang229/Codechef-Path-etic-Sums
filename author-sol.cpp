#include <bits/stdc++.h>

using namespace std;

const int N = 105;
// adjacency list
vector<int> graph[N];
// array to output
int nums[N];

void Dfs(int u, int p) {
	// view the logic behind the assignment of values in the README.md
	// value of the current node depends on the value of previous node
	nums[u] = (nums[p] & 1 ? 2 : 1);
	for (auto v : graph[u]) {
		// avoid performing depth-first search to the previous node because it is already visited
		if (v != p) {
			Dfs(v, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		// set the first value to 1 (we initialized index-0 to 1 because
		// this will be the previous node for the actual 1st node)
		nums[0] = 1;
		// calculate the answers for the array
		Dfs(1, 0);
		for (int i = 1; i <= n; i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';
		// since the 'graph' array of vectors is global,
		// we need to clear it for every test case
		for (int i = 0; i <= n; i++) {
			graph[i].clear();
		}
	}
	return 0;
}

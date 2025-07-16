// 03_Tree Distances_I.cpp
/*

You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.

Input

The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,...,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b:
there is an edge between nodes a and b.

Output
Print n integers: for each node 1,2,\ldots,n, the maximum distance to another node.
Constraints

1 <= n<=10^5
1 <= a,b <= n

Example
Input:
5
1 2
1 3
3 4
3 5

Output:
2 3 2 3 3
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int source, int parent, int curlevel, vector<int>&level, vector<vector<int>>&edges) {

	for (auto child : edges[source]) {
		if (child != parent) {
			level[child] = curlevel + 1;
			dfs(child, source, curlevel + 1, level, edges);
		}
	}

}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> edges(n);

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	vector<int>levelX(n, 0);
	dfs(0, -1, 0, levelX, edges);
	int node1 = max_element(levelX.begin(), levelX.end()) - levelX.begin();
	vector<int>levelY(n, 0);
	dfs(node1, -1, 0, levelY, edges);
	int daimater = *max_element(levelY.begin(), levelY.end());
	int node2 = max_element(levelY.begin(), levelY.end()) - levelY.begin();
	vector<int>levelZ(n, 0);
	dfs(node2, -1, 0, levelZ, edges);
	vector<int>maxdistanceofeachnode(n, 0);
	for (int i = 0; i < n; ++i)
	{
		maxdistanceofeachnode[i] = max(levelY[i], levelZ[i]);
	}
	for (auto it : maxdistanceofeachnode) {
		cout << it << " ";
	}
}


int main() {

	ios_base::sync_with_stdio(false),
	         cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}
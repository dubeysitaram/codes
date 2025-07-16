// 00_Subordinates.cpp

/*
Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
Input
The first input line has an integer n: the number of employees. The employees are numbered 1,2,....,n, and 
employee 1 is the general director of the company.
After this, there are n-1 integers: for each employee 2,3,...,n their direct boss in the company.
Output
Print n integers: for each employee 1,2,....,n the number of their subordinates.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
1 1 2 3

Output:
4 1 1 0 0
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int source, int parent, vector<vector<int>>& edges, vector<pair<int, int>>&timer, int& curtime) {
	int x = curtime++;

	for (auto child : edges[source]) {
		if (child != parent)dfs(child, source, edges, timer, curtime);
	}

	int y   = curtime++;
	timer[source] = {x, y};
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> edges(n);
	for (int i = 1; i < n; ++i) {
		int parent;
		cin >> parent;
		parent--;
		edges[parent].push_back(i);
		edges[i].push_back(parent);
	}
	vector<pair<int, int>>timer(n, {0, 0});
	int curtime = 0;
	dfs(0, -1, edges, timer, curtime);
	for (auto it : timer) {
		cout << (it.second - it.first) / 2 << " ";
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

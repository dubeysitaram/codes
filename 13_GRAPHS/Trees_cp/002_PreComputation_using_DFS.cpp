// 002_PreComputation_using_DFS.cpp

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

// https://www.youtube.com/watch?v=w2oz11KWNQY&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=8

// ------------------------------------------LUV SIR CP watch video if any doubt  ------------------------------------


/*

Given Q queries ,Q<=1e5;
in each query given vertex
print subtree sum of that vertex and the number of even numbers in subtree of v

*/


const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int even_count[N];

void dfs(int vertex, int par) {
	subtree_sum[vertex] = vertex;
	even_count[vertex] = (vertex % 2 == 0);

	for (int child : g[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);

		subtree_sum[vertex] += subtree_sum[child];// precomputed

		even_count[vertex] += even_count[child]; // precomputed
	}
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, -1);

	int query;
	cin >> query;
	while (query--) {
		int x;
		cin >> x;
		cout << subtree_sum[x] << " " << even_count[x] << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
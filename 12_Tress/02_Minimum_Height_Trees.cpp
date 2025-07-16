// 310 Minimum_Height_Trees.cpp
/*

A tree is an undirected graph in which any two vertices are connected by exactly one path.
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi]
indicates that there is an undirected edge between the two nodes ai and bi in the tree,
you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h.
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/

// concept yahi hai ki leaf nodes humare kisi kaam ki nhi
// most probable answer centarl nodes hi hogi
// and the answer will be either 1 or 2

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> indegree(n, 0);
		vector<vector<int>> graph(n);
		if (n == 1)return {0};
		if (n == 2)return edges[0];
		for (auto it : edges) {
			indegree[it[0]]++;
			indegree[it[1]]++;
			graph[it[0]].push_back(it[1]);
			graph[it[1]].push_back(it[0]);
		}
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 1) {
				q.push(i);
			}
		}
		int ct = 0;
		while (!q.empty()) {
			int sz = q.size();
			ct += sz;
			for (int i = 0; i < sz; i++) {
				int node = q.front();
				q.pop();
				for (auto it : graph[node]) {
					indegree[it]--;
					if (indegree[it] == 1) {
						q.push(it);
					}
				}
			}
			if (n - ct <= 2)
				break;
		}
		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}
};
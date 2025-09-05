// 947_Most_Stones_Removed_ Same_Row_or_Col.cpp
/*

On a 2D plane, we place n stones at some integer coordinate points.
 Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone
that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi]
represents the location of the ith stone,
return the largest possible number of stones that can be removed.


Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.


*/

// after reading the constraints we finded that using the simple dsu will lead to memory leakage


class Solution {
public:
	unordered_map<int, int> parent;
	unordered_map<int, int> size;
	void make(int v) {
		if (parent.find(v) == parent.end()) {
			parent[v] = v;
			size[v] = 1;
		}
	}

	int findParent(int v) {
		if (parent[v] != v)
			parent[v] = findParent(parent[v]);
		return parent[v];
	}

	void Union(int a, int b) {
		a = findParent(a);
		b = findParent(b);
		if (a != b) {
			if (size[a] > size[b])
				swap(a, b);
			parent[a] = b;
			size[b] += size[a];
		}
	}
	int removeStones(vector<vector<int>>& stones) {
		parent.clear();
		size.clear();

		for (auto& stone : stones) {
			int x = stone[0],
			    y = ~stone[1]; // ~y keeps x and y in different domains
			make(x);
			make(y);
			Union(x, y);
		}

		unordered_set<int> uniqueRoots;
		for (auto& stone : stones) {
			int x = stone[0];
			uniqueRoots.insert(findParent(x));
		}

		return stones.size() - uniqueRoots.size();
	}
};

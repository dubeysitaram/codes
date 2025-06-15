// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e5 + 7;
// const int MOD = 1e9 + 7;

// vector<int> fact(N, 1);
// vector<int> fermat(N, 1);

// int binaryexpo(int a, int b) {
// 	if (b == 0) return 1;
// 	int z = binaryexpo(a, b / 2);
// 	long long res = 1LL * z * z % MOD;
// 	if (b & 1) res = res * a % MOD;
// 	return int(res);
// }

// void factorial() {
// 	for (int i = 2; i < N; i++) {
// 		fact[i] = int(1LL * i * fact[i - 1] % MOD);
// 	}
// }

// void fermat_fact() {
// 	for (int i = 2; i < N; i++) {
// 		fermat[i] = binaryexpo(fact[i], MOD - 2);
// 	}
// }

// long long countSubsequences(int* arr, int n) {
// 	map<int, int> mp;
// 	for (int i = 0; i < n; i++) {
// 		mp[arr[i]]++;
// 	}
// 	factorial();
// 	fermat_fact();
// 	long long ans = 0;
// 	for (auto& it : mp) {
// 		int x = it.second;
// 		// compute C(2x, x) - 1
// 		long long ways = binaryexpo(2, x);
// 		ans = (ans + ways - 1 + MOD) % MOD;
// 	}
// 	return ans;
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	int n;
// 	cin >> n;
// 	vector<int> a(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	cout << countSubsequences(a.data(), n) << "\n";
// 	return 0;
// }


// class Solution {
// public:
//     vector<int> getOrder(vector<vector<int>>& tasks) {
//         int n = tasks.size();
//         vector<vector<int>> v;
//         for (int i = 0; i < n; i++) {
//             v.push_back({tasks[i][1], i, tasks[i][0]});
//         }

//         sort(v.begin(), v.end()); // sort by processing time, then index
//         tasks = v;

//         // sort by arrival time
//         sort(tasks.begin(), tasks.end(), [](vector<int>& v1, vector<int>& v2) {
//             return v1[2] < v2[2];
//         });

//         set<vector<int>> s; // corrected set declaration
//         int currtime = tasks[0][2];
//         s.insert(tasks[0]);
//         int i = 1; // start from 1 because tasks[0] already inserted
//         vector< int> executionorder;

//         while (!s.empty()) {
//             auto temp = *s.begin();
//             s.erase(s.begin());
//             executionorder.push_back(temp[1]);
//             currtime += temp[0];

//             while (i < n && tasks[i][2] <= currtime) {
//                 s.insert(tasks[i]);
//                 i++;
//             }

//             if (s.empty() && i < n) {
//                 currtime = tasks[i][2];
//                 s.insert(tasks[i]);
//                 i++;
//             }
//         }

//         return executionorder;
//     }
// };


// #include <bits/stdc++.h>
// using namespace std;

// // DSU with small-to-large merge and tracking numeric adjacencies.
// struct DSU {
//     vector<int> p, sz, adj;
//     vector<vector<int>> members;
//     DSU(int n): p(n+1), sz(n+1,1), adj(n+1,0), members(n+1) {
//         for(int i=1;i<=n;i++){
//             p[i]=i;
//             members[i].push_back(i);
//         }
//     }
//     int find(int x){
//         return p[x]==x? x : p[x]=find(p[x]);
//     }
//     void unite(int x, int y){
//         x = find(x);
//         y = find(y);
//         if(x==y) return;
//         // small-to-large: ensure x is the smaller component
//         if(members[x].size() > members[y].size())
//             swap(x,y);
//         // for each element in the smaller comp x, check new numeric adjacencies into y
//         for(int v: members[x]){
//             for(int d : {-1,+1}){
//                 int u = v + d;
//                 if(u>=1 && u<(int)p.size() && find(u)==y){
//                     // edge (v,u) is a new adjacency inside the merged comp
//                     adj[y]++;
//                 }
//             }
//         }
//         // merge x into y
//         for(int v: members[x]){
//             members[y].push_back(v);
//         }
//         members[x].clear();
//         p[x] = y;
//         sz[y] += sz[x];
//         adj[y] += adj[x];
//     }
//     // beauty = size - adjacencies
//     int beauty(int x){
//         x = find(x);
//         return sz[x] - adj[x];
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q, t_unused;
//     cin >> n >> q;
//     DSU dsu(n);

//     long long answer_sum = 0;
//     while(q--){
//         int type, a, b;
//         cin >> type >> a >> b;
//         if(type==1){
//             // add edge between a and b
//             dsu.unite(a,b);
//         } else {
//             // type 2: query beauty of component containing a
//             answer_sum += dsu.beauty(a);
//         }
//     }

//     cout << answer_sum << "\n";
//     return 0;
// }





// // --- place this DSU helper above get_ans, once per file ---
// struct DSU {
//     vector<int> p, sz, adj;
//     vector<vector<int>> members;
//     DSU(int n): p(n+1), sz(n+1,1), adj(n+1,0), members(n+1) {
//         for(int i=1;i<=n;i++){
//             p[i]=i;
//             members[i].push_back(i);
//         }
//     }
//     int find(int x){
//         return p[x]==x? x : p[x]=find(p[x]);
//     }
//     void unite(int x, int y){
//         x = find(x);
//         y = find(y);
//         if(x==y) return;
//         if(members[x].size() > members[y].size())
//             swap(x,y);
//         // count new adjacencies when merging x→y
//         for(int v: members[x]){
//             for(int d: {-1,+1}){
//                 int u = v + d;
//                 if(u>=1 && u<(int)p.size() && find(u)==y)
//                     adj[y]++;
//             }
//         }
//         // merge lists
//         for(int v: members[x])
//             members[y].push_back(v);
//         members[x].clear();
//         p[x] = y;
//         sz[y] += sz[x];
//         adj[y] += adj[x];
//     }
//     int beauty(int x){
//         x = find(x);
//         return sz[x] - adj[x];
//     }
// };

// // --- now your get_ans function ---
// int get_ans(int n, int q, int t, vector<vector<int>> &queries) {
//     DSU dsu(n);
//     long long answer_sum = 0;
//     for(auto &qr : queries) {
//         int type = qr[0], u = qr[1], v = qr[2];
//         if(type == 1) {
//             dsu.unite(u, v);
//         } else {
//             answer_sum += dsu.beauty(u);
//         }
//     }
//     return (int)answer_sum;
// }

#include <bits/stdc++.h>
using namespace std;

struct Seg {
	int n;
	vector<int> t;
	Seg(int _n): n(_n), t(4 * _n + 4, 0) {}
	void update(int v, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			t[v] = val;
			return;
		}
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v << 1, tl, tm, pos, val);
		else          update(v << 1 | 1, tm + 1, tr, pos, val);
		t[v] = max(t[v << 1], t[v << 1 | 1]);
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;
		if (l <= tl && tr <= r) return t[v];
		int tm = (tl + tr) >> 1, res = 0;
		if (l <= tm) res = max(res, query(v << 1, tl, tm, l, r));
		if (r >  tm) res = max(res, query(v << 1 | 1, tm + 1, tr, l, r));
		return res;
	}
};

int get_ans(int n, int m, const vector<int>& p) {
	if (m <= 1) return 0;
	int lo = 1, hi = n - 1, ans = n;
	auto ok = [&](int k) {
		Seg seg(n);
		vector<int> dp(n);
		for (int j = 0; j < n; j++) {
			if (j > 0)          seg.update(1, 1, n, p[j - 1], dp[j - 1]);
			if (j - k - 1 >= 0) seg.update(1, 1, n, p[j - k - 1], 0);
			int best = seg.query(1, 1, n, 1, p[j] - 1) + 1;
			if (best >= m) return true;
			dp[j] = best;
		}
		return false;
	};
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid)) ans = mid, hi = mid - 1;
		else        lo = mid + 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	cout << get_ans(n, m, p) << "\n";
	return 0;
}

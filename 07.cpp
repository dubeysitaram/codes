#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef __int128 ell;
//typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int countSum(vector<int>& nums, int target) {
	int ans = 0;
	int n = nums.size();
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = nums[i] + nums[j];
			int req = target - x;
			if (mp.find(req) != mp.end())ans += mp[req];
		}
		for (int j = 0; j < i; j++) {
			mp[nums[i] + nums[j]]++;
		}
	}
	return ans;
}

int ispossible(int mid, vector<int>&v, int n, int k) {
	int ct = 0;
	for (int i = 0; i < n; i++) {
		if (mid - nums[i] >= 0 && k >= 0) {
			k = k - (mid - nums[i]);
			ct++;
		}
	}
	return ct;
}
int maxFrequency(vector<int>& nums, int k) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int lo = nums[0];
	int hi = nums[n - 1];
	int ans = 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		int x = ispossible(mid, v, n, k);
		if (x >= ans)ans = x;

		if () {

		}
	}
}



void solve() {
	int n, target;
	cin >> n >> target;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	debug(v)
	int p = countSum(v, target);
	debug(p)

}



int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}
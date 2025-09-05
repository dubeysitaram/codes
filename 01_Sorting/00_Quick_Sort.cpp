// 00_Quick_Sort.cpp
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

// T.C--> O(nlogn) and space complexiy--->O(logn)// stack space

int Partition(vector<int>&v, int lo, int hi) {
	int mid = (hi + lo) / 2;
	int i = lo;
	int pivot = v[mid];
	swap(v[mid], v[hi]); // mid element ko pivot maan lia aur usko akhir mai  pahucha dia
	for (int j = lo; j < hi; j++) {
		if (v[j] <= pivot) {
			swap(v[j], v[i]);
			i++;
		}
	}
	swap(v[i], v[hi]);
	return i;
}
void QuickSort(vector<int>&v, int lo, int hi) {
	if (lo < hi) {
		int PartitionIndex = Partition(v, lo, hi);
		QuickSort(v, lo, PartitionIndex - 1);
		QuickSort(v, PartitionIndex + 1, hi);
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	QuickSort(v, 0, n - 1);
	for (int i = 0; i < n; i++)cout << v[i] << " ";

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
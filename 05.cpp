#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
int ans = 0;
void merge(vector<pair<int, int>>&arrindex, int lo, int mid, int hi) {
	int n = hi - lo + 1;
	vector<pair<int, int>>sortedarray(n);
	int i = 0, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= hi) {
		if (arrindex[i].first <= arrindex[j].first) {
			sortedarray[k] = arrindex[i];
			i++; k++;
		} else {
			sortedarray[k] = arrindex[j];
			ans++;
			j++; k++;
		}
	}
	while (i <= mid) {
		sortedarray[k] = arrindex[i];
		i++; k++;
	}
	while (j <= hi) {
		sortedarray[k] = arrindex[j];
		j++; k++;
	}
	i = lo; k = 0;
	while (i <= hi) {
		arrindex[i] = sortedarray[k];
		i++; k++;
	}
}


void mergesort(vector<pair<int, int>>&arrindex, int lo, int hi) {
	if (lo >= hi)return;
	int mid = lo + (hi - lo) / 2;
	mergesort(arrindex, lo, mid);
	mergesort(arrindex, mid + 1, hi);
	merge(arrindex, lo, mid, hi);
}




int inversionCount(vector<int> &arr) {
	int n = arr.size();
	vector<pair<int, int>> numindex(n);
	for (int i = 0; i < n; i++) {
		numindex[i] = {arr[i], i};
	}
	mergesort(numindex, 0, n - 1);
	return ans;
}


void solve() {


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
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;


/*

int N = 1e5+10;
int parent[N];

void make(int v){
	parent[v]=v;
}

int find(int v){ // added missing parameter 'v'
	if(parent[v]==v)return v;
	return parent[v] = find(parent[v]); // added path compression
}

void Union(int a,int b){
	int par1 = find(a);
	int par2 = find(b);
	if(par1!=par2){
		parent[par2] = par1; // corrected: assign parent of root, not just 'b'
	}
}

*/

// -----------------------------------------------union by size &&  path compression ------------------------------------------------------------------


int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int v) {
	parent[v] = v;
	size[v] = 1; // initially the size 0f each node is 1
}

int find(int v) {
	if (parent[v] == v)return v;
	// path compression means agr ksii ka parent find karne jaa rje hai to bich walo ko assign bhi kardo
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	int par1 = find(a);
	int par2 = find(b);

	if (par1 != par2) {

		if (size[par1] > size[par2]) {
			swap(par1, par2); // left wala tree hi hamesha chotta hona chaiye
		}

		parent[par1] = par2;
		size[par2] += size[par1];
	}
}

// TC ===O(alpha(n)) almost constant amotorized time complexity
















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


// --------------------------------------------LEETCODE TEMPLATE-------------------------------------------------------------
static const int N = 1e6 + 5;

int parent[N];
int Size[N];

void make(int v) {
	parent[v] = v;
	Size[v] = 1;
}

int find(int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	int c = find(a);
	int d = find(b);
	if (c != d) {
		if (Size[d] > Size[c])
			swap(d, c);
		parent[d] = c;
		Size[c] += Size[d];
	}
}

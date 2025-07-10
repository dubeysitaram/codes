#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

int N = 1e5+10;
int parent[N];
int size[N];

void make(int v){
	parent[v]=v;
	size[v]=1;
}

int find(int v){
	if(parent[v]==v)return v;
	return parent[v]=find(parent[v]); 
}

void Union(int a,int b){
	int par1 = find(a);
	int par2 = find(b);

	if(par1!=par2){

		if(size[par1]>size[par2]){
			swap(par1,par2);
		}

		parent[par1]=par2;
		size[par2] += size[par1];
	}
}


void solve() {
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++){
	make(i);
}
for(int i=0;i<k;i++){
	int u,v;
	cin>>u>>v;
	Union(u,v);
}
int connetedcomponent_ct=0;
for(int i=1;i<=n;i++){
	if(find(i)==i)connetedcomponent_ct++;
}
cout<<connetedcomponent_ct<<endl;
}


int main() {
ios_base::sync_with_stdio(false),cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
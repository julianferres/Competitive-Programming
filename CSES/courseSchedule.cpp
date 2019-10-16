#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int n, m, a, b; 
vector<vector<int>> adj;
vector<bool> visited; 
vector<int> ans;

void dfs(int v){
	visited[v] = true;
	for(int u: adj[v]){
		if(!visited[u]) dfs(u);
	}
	ans.pb(v);
}

void topological_sort(){
	visited.assign(n, false);
	ans.clear();
	forn(i,n){
		if(!visited[i]) dfs(i);
	}
	reverse(ans.begin(), ans.end());
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	forn(i,m){
		cin >> a >> b;
		adj[a-1].pb(b-1);
	}
	topological_sort();
	forn(i,n) cout << ans[i] << " "<< endl;
	return 0;

}

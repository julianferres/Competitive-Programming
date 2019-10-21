#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) for(ll i = (0); i < (ll) (n); i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define MAXN 1000
vector<bool> visited(MAXN*MAXN+1);
vector<vector<ll> > adj;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main(){
	FIN;
	ll n,m; cin >> n >> m;
	vector<string> a;
	forn(i,n){
		string s; cin >> s;
		a.pb(s);
	}
	forn(i,MAXN*MAXN+1) visited[i]=false;
	forn(i,n)
		forn(j,m){
			vector<ll> v;
			adj.pb(v);
		}
	forn(i,n)
		forn(j,m){
			if(a[i][j]=='#') visited[i]=true;
			else{
				if(i>0)if(a[i-1][j]=='.') adj[i*n+j].pb((i-1)*n+j),adj[(i-1)*n+j].pb(i*n+j);
				if(i<n-1)if(a[i+1][j]=='.') adj[i*n+j].pb((i+1)*n+j),adj[(i+1)*n+j].pb(i*n+j);
				if(j>0)if(a[i][j-1]=='.')adj[i*n+j].pb(i*n+j-1),adj[i*n+j-1].pb(i*n+j);
				if(j<m-1)if(a[i][j+1]=='.')adj[i*n+j].pb(i*n+j+1),adj[i*n+j+1].pb(i*n+j);
			}

		}

	forn(i,n*m){
		forn(j,a[i].sz) cout << a[i][j] << " ";
		cout << endl;
	}




	int ans = 0;


	return 0;
}


 

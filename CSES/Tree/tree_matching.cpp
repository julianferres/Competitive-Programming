#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

int n,a,b;
vi uso,nouso;
vvi tree;

void dfs(ll u, ll p){
	for(auto z: tree[u]){
		if(z==p) continue;
		dfs(z,u);
		nouso[u]+=max(uso[z],nouso[z]);
	}
	for(auto z: tree[u]){
		if(z==p) continue;
		uso[u]= max(uso[u],1+nouso[u]+nouso[z]-max(uso[z],nouso[z]));
	}
}




int main()
{ 	
	FIN;
	cin >> n;
	uso = vi(n); nouso = vi(n);
	tree = vvi(n);
	forn(i,n-1){
		cin >> a >> b;
		a--;b--;
		tree[a].pb(b); tree[b].pb(a);
	}
	dfs(0,0);
	cout << max(uso[0],nouso[0]) << endl;
	
    return 0;
}

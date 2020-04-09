/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
const int N = 100005;
const int mod = 1000000007;

int n;
vi g[N];
vi black(N,1), white(N,1);

ll mul(ll a, ll b){
	return a*b % mod;
}


void dfs(ll v, ll p){
	for(auto u : g[v]) {
		if(u == p) continue;
		dfs(u,v);
		white[v] = mul(white[v], white[u]+black[u]);
		black[v] = mul(black[v], white[u]);
	}
}

int main()
{
	FIN;
	cin >> n;
	forn(i,n-1){
		int a,b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b); g[b].pb(a);
	}
	dfs(0,-1);
	cout << (black[0] + white[0])%mod << endl;
	// DBGV(black, n);
	// DBGV(white, n);

	return 0;
}

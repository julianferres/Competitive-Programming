/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

vi g[MAXN];int n;
vi tsort(){  // lexicographically smallest topological sort
	vi r;priority_queue<ll> q;
	vi d(2*n,0);
	forn(i,n)forn(j,g[i].size())d[g[i][j]]++;
	forn(i,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		ll x=-q.top();q.pop();r.pb(x);
		forn(i,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}


int main(){ 
    FIN;
    int m; cin >> n >> m;
    forn(i,m){
        int a,b; cin >> a >> b; a--,b--;
        g[a].pb(b);	
    }
    vi topo = tsort();
    vi dp(n, 1);
    for(auto v: topo){
        for(auto u: g[v])
            dp[u] = max(dp[u], dp[v] + 1);
    }
    ll ans = 1;
    forn(i, n) ans = max(ans, dp[i]);
    cout << ans-1 << endl;
    return 0;
}

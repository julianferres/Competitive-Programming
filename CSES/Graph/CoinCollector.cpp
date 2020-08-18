/*    AUTHOR: julianferres, lun 17 ago 2020 21:17:55 -03 */
#include <bits/stdc++.h>
using namespace std;

// DEBUGGER
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//END DEBUGGER

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1e5+5;

vector<vector<int>> g(MAXN), gr(MAXN);
vector<bool> visto(MAXN,false);
vector<int> order, component;
vector<vector<int>> scc;

void DFS1 (int v) {
  visto[v] = true;
  for (int u : g[v]) if(!visto[u]) DFS1(u);
  order.pb(v);
}
void DFS2 (int v) {
  visto[v] = true;  component.pb(v);
  for(int u : gr[v]) if(!visto[u]) DFS2(u);
}
void find_scc(int n) {
	fill(all(visto),false);
	forn(i,n) if(!visto[i]) DFS1(i);
	fill(all(visto),false);
	forn(i,n) {
		int v=order[n-i-1];
		if(!visto[v]) { 
			DFS2(v);
			scc.pb(component);
			component.clear();
		}
	}
}

void DFS3(int v, vector<vector<int>> adj, vector<bool> &seen, vector<int> &topo){
    seen[v] = true;
    for(int u: adj[v])
        if(!seen[u])
            DFS3(u, adj, seen, topo);
    topo.pb(v);
}

ll solve(vector<vector<int>> adj, vector<int> values, int n){
    vector<int> topo; vector<bool> seen(n, false);
    forn(i, n) if(!seen[i]) DFS3(i, adj, seen, topo);

    vi dp(n);
    forn(i, n) dp[i] = values[i];
    //debug() << imie(topo);

    forn(i, n){
        for(int u: adj[i]){
            //debug() << imie(u) imie(i);
            dp[u] = max(dp[u], dp[i] + values[u]);
        }
    }

    ll ans = 0;
    forn(i, n) ans = max(ans, dp[i]);
    return ans;
}

int main(){  
    FIN;

    int n, m; cin >> n >> m;
    vi values(n); forn(i, n) cin >> values[i];

    forn(i, m){
        int a, b; cin >> a >> b;
        a--, b--; 
        g[a].pb(b); gr[b].pb(a);
    }
    find_scc(n);

    debug() <<  imie(scc);

    vector<vector<int>> nuevo_grafo(scc.size());
    vector<int> nuevo_values(scc.size());
    
    vector<int> node_to_scc(n);
    forn(i, scc.size()){
        for(int j: scc[i]) node_to_scc[j] = i;
    }

    //debug() << imie(node_to_scc);
    forn(i, n) nuevo_values[node_to_scc[i]] += values[i];

    forn(i, n)
        for(int j: g[i])
            if(node_to_scc[i] != node_to_scc[j])
                nuevo_grafo[node_to_scc[i]].pb(node_to_scc[j]);
    
    //debug() << imie(nuevo_grafo) imie(nuevo_values);

   // cout << solve(nuevo_grafo, nuevo_values, scc.size()) << "\n";
    return 0;
}

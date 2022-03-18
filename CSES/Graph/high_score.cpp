/*    AUTHOR: julianferres, mié 12 ago 2020 02:10:56 -03 */
#include <bits/stdc++.h>
using namespace std;
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
const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2505;

vi g[MAXN], h[MAXN];
vector<pair<ii, ll>> edges;

void dfs1(vi &seen, int v){
    seen[v] = true;
    for(int u: g[v])
        if(!seen[u])
            dfs1(seen, u);
}
void dfs2(vi &seen, int v){
    seen[v] = true;
    for(int u: h[v])
        if(!seen[u])
            dfs2(seen, u);
}


int main(){  
    FIN;

    int n, m; cin >> n >> m;
    edges.resize(m);

    forn(i,m){
        ll u,v,w; cin >> u >> v >> w;
        u--,v--;
        g[u].pb(v);
        h[v].pb(u);
        edges[i] = {{u, v}, -w};
    }

    vi seen(n), seen_bis(n);

    dfs1(seen, 0);
    dfs2(seen_bis, n-1);
    
    vi d(n, INF);
    d[0] = 0;

    bool changed = false;

    forn(i, n){
        changed = false;
        for(auto edge: edges){
            int u, v, w;
            u = edge.first.first;
            v = edge.first.second;
            w = edge.second;
            if(seen[u] && seen_bis[v] && d[u] + w < d[v])
                changed = true, d[v] = d[u] + w;
        }
    }
    if(changed) cout << "-1\n";
    else cout << -d[n-1] << "\n";

    return 0;
}

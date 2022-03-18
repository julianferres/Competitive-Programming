/*    AUTHOR: julianferres, vie 28 ago 2020 02:19:31 -03 */
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
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1e5+5;

vector<int> sz, p, g[MAXN];

void dfs(int v){
    if(g[v].size() == 1) sz[v] = 1;
    for(int u: g[v])
        if(u!=p[v]) {
            p[u] = v;
            dfs(u);
            sz[v] += sz[u];
        }
}

vi leaf;

void dfs_hojas(int v, int par){
    if(g[v].size()==1){
        leaf.pb(v);
    } else {
        for(int u: g[v])
            if(u != par)
                dfs_hojas(u, v);
    }
}



int main(){  
    FIN;
    int n; cin >> n;
    sz.resize(n), p.resize(n);
    vector<vi> hojas;
    forn(i, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
    }
    dfs(0);
    ll tot=sz[0], act = 0;
    
    while(true){
        bool bad = 0;
        for(int t: g[act])
            if(t!=p[act] && 2*sz[t]>tot){
                act = t; bad = true;
                break;
            }
        if(!bad) break;
    }

    if(g[act].size() == 1) hojas.pb({act});

    for(int t: g[act]){
        dfs_hojas(t, act);
        hojas.pb(leaf); leaf.clear();
    }
    cout << (sz[0]+1)/2 << "\n";


    priority_queue<pair<int, int>> q;

    forn(i, hojas.size()) q.push({hojas[i].size(), i});
    vector<pair<int, int>> ed;
    while(q.size() > 1){
        auto a = q.top(); q.pop();
        auto b = q.top(); q.pop();
        //debug() << imie("CAbJ");
        ed.pb({hojas[a.second].back(), hojas[b.second].back()});
        hojas[a.second].pop_back();
        hojas[b.second].pop_back();
        if(a.first > 1) q.push({a.first-1, a.second});
        if(b.first > 1) q.push({b.first-1, b.second});
    }
    if(q.size() == 1)
        ed.pb({act, hojas[q.top().second].back()});

    for(pair<int, int> t: ed) cout << t.first+1 << " " << t.second+1 << "\n";

    

    return 0;
}

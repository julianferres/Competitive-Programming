/*    AUTHOR: julianferres, mié 26 ago 2020 23:35:05 -03 */
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
const int MAXN  = 2e5+5;

vector<vector<int>> succ(32, vector<int>(MAXN));
vb vis(MAXN, false);
vector<int> len(MAXN, 0);

void dfs(int v){
    vis[v] = true;
    int u = succ[0][v];
    if(!vis[u]) dfs(u);
    len[v] = len[u] + 1;
}
int go(int x, int d){
    if (d<=0) return x;
    int i = 0;
    while(d){
        if(d&1) x = succ[i][x];
        d >>= 1;
        i++;
    }
    return x;
}

int main(){  
    FIN;

    int n, q; cin >> n >> q;
    forn(j, n) cin >> succ[0][j];
    forn(j, n) succ[0][j]--;
    forr(i, 1, 32)
        forn(j, n)
            succ[i][j] = succ[i-1][succ[i-1][j]];

    forn(i, n)
        if(!vis[i]) dfs(i);

    forn(i, q){
        int x, y; cin >> x >> y;
        x--, y--;
        int z = go(x, len[x]);
        if(go(x, len[x]-len[y]) == y) cout << len[x]-len[y] << "\n";
        else if(go(z, len[z]-len[y]) == y) cout << len[x]+len[z]-len[y] << "\n";
        else cout << "-1\n";
    }
    

    return 0;
}

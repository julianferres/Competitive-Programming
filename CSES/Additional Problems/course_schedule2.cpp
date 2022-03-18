/*    AUTHOR: julianferres, jue 27 ago 2020 11:08:25 -03 */
#include <bits/stdc++.h>
#include <queue>
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

vector<vector<int>> g;
vector<int> dout;

int main(){  
    FIN;
    int n, m; cin >> n >> m;
    g.resize(n); dout.resize(n);
    forn(i, m){
        int x, y; cin >> x >> y;
        x--, y--;
        dout[x]++;
        g[y].pb(x);
    }
    vi topo;

    ll seen = 0; priority_queue<int>q;
    forn(i, n) if(!dout[i]) q.push(i);
    while(q.size()) {
        int v;
        v = q.top(); q.pop();
        topo.pb(v);
        for(int u: g[v]){
            dout[u]--;
            if(!dout[u]) q.push(u);
        }                        
    }
    reverse(all(topo));

    forn(i, n) cout << topo[i]+1 << " \n"[i==n-1];
    return 0;
}

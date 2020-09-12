/*    AUTHOR: julianferres, Thu 10 Sep 2020 07:53:29 PM -03 */
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
const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN = 1005;

struct dsu{
    int par[MAXN], sz[MAXN];
    int find(int x){return par[x]=par[x]==x?x:find(par[x]);}
    void join(int x, int y){
        x = find(x), y = find(y);
        if(x==y) return;
        if(sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

int main(){  
    FIN;

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    forn(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({w, a, b});
    }
    sort(all(edges));

    dsu con;
    forn(i, n) con.par[i] = i, con.sz[i] = 1;
    forn(i, m){
        int a, b, w;
        tie(w, a, b) = edges[i];
        con.join(a-1, b-1);
    } 
    if(con.sz[con.find(0)] < n){
        cout << "NO\n";
        return 0;
    }
 
    ll ans = INF; 

    forn(i, m){
        dsu s;
        forn(iii, n) s.sz[iii] = 1, s.par[iii] = iii;
        ll mi = INF, mx = -INF;
        forr(j, i, m){
            int a, b, w;
            tie(w, a, b) = edges[j];
            if(s.find(a-1) != s.find(b-1)){
                s.join(a-1, b-1);
                mi = min(mi, (ll) w);
                mx = max(mx, (ll) w);
            }
        }
        if(s.sz[s.find(0)] == n) ans = min(ans, (ll) mx-mi);
    }
    cout << "YES\n";
    cout << ans << "\n";

    return 0;
}

/*    AUTHOR: julianferres, Thu 10 Sep 2020 01:41:28 AM -03 */
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

vector<int> par, timer;
int find(int x, int when = -1){
    int act = x; int new_timer = timer[x];
    while(par[act] != act){
        act = par[act];
        new_timer = max(new_timer, timer[act]);
    }
    timer[x] = max(when, new_timer);
    return par[x]=par[x]==x?x:find(par[x], when);
}
void join(int x, int y, int when=-1){
    if(find(x) == find(y)) return;
    if(find(x) == 1){
        par[find(y, when)] = 1;
    }
    else if(find(y) == 1){
        par[find(x, when)] = 1;
    }
    else{
        par[find(x)] = find(y);
    }
}
int find_time(int x){
    int ans = -1;
    while(x != par[x])
    {
        ans = max(ans, timer[x]);
        x = par[x];
    }
    return ans;
}

int main(){  
    FIN;
    int n, m; cin >> n >> m;
    par.resize(n+1), timer.resize(n+1, -1);
    forr(i, 1, n+1) par[i] = i;
    int manos[n+1][2];
    vector<pair<int, int>> edges, sueltos;
    multiset<pair<int, int>> remain;
    forr(i, 1, n+1){
        int l, r; cin >> l >> r;
        manos[i][0] = l;
        manos[i][1] = r;
        if(l!=-1) edges.pb({i, l}), remain.insert({i, l});
        if(r!= -1) edges.pb({i, r}), remain.insert({i, r});
    }
    forn(i, m){
        int p, h; cin >> p >> h;
        sueltos.pb({p, manos[p][h-1]});
        remain.erase(remain.find({p, manos[p][h-1]}));
    }
    vector<int> ans(n, INF);
    for(auto e: remain) join(e.first, e.second);
    for(int i = m-1; i>=0; i--){
        debug() << imie(sueltos[i]);
        join(sueltos[i].first, sueltos[i].second, i);
        debug() << imie(par) imie(timer);
    }

    forr(i, 1, n+1) if(ans[i-1] == INF) ans[i-1] = find_time(i);

    forn(i, n) cout << ans[i] << "\n";
    return 0;

    forn(i, n){
        cin >> a >> b;
        forn(i ,m){
            cout << a << b;
        }
    }
    return 0;

}


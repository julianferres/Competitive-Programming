/*    AUTHOR: julianferres, dom 23 ago 2020 01:30:58 -03 */
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
const long double EPS = 1e-9;

void bfs(int s, vector<vector<int>> g, vector<int> &d, vector<int> &p){
    int n = (int)d.size();
    queue<int> q;
    vector<bool> used(n);
    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

int main(){
    FIN;
    int n, m, dist; cin >> n >> m >> dist;
    vector<tuple<int,int,int>> edges;

    forn(i, m){
        int ai, bi, ci; 
        cin >> ai >> bi >> ci;
        ai--, bi--;
        edges.pb({ai,bi,ci});
    }
    
    ll l=0, r=INF, ans=r;
    vector<int> ans_path;
    while(l<=r){
        ll med = (l+r)/2;
        vector<vector<int>> g(n);
        forn(i, m){
            if(get<2>(edges[i])<=med)
                g[get<0>(edges[i])].pb(get<1>(edges[i]));
        }
        //debug() << imie(med) imie(g);
        vector<int> d(n, INF), p(n, -1);
        bfs(0, g, d, p);
        //debug() << imie(med) imie(d[n-1]);
        if(d[n-1] <= dist){
            ans = med;
            r = med - 1;
            vector<int> new_path;
            int act_node = n-1;
            while(act_node){
                new_path.pb(act_node);
                act_node = p[act_node];
            }
            new_path.pb(0);
            ans_path = new_path;
        }
        else l = med+1;
    }
    reverse(all(ans_path));
    if(ans == INF){
        cout << "-1\n";
        return 0;
    }

    cout << ans_path.size() -1 << "\n"; 
    forn(i, ans_path.size()) cout << ans_path[i]+1 << " "[i==ans_path.size()-1];
    return 0;
}

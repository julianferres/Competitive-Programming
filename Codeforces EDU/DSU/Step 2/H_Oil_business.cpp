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
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 5e4+5;

int par[MAXN];
int find(int x){return par[x]=par[x]==x?x:find(par[x]);}
void join(int x, int y){par[find(x)]=find(y);}

int main(){  
    FIN;

    int n, m; cin >> n >> m;
    ll s; cin >> s;
    vector<tuple<int, int, int, int>> edges;
    forn(i, n) par[i] = i;
    forn(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        edges.pb({w, a, b, i+1});
    }
    sort(all(edges));
    
    vector<bool> used(m, false); 

    for(int i = m-1; i >= 0; i--){
        int a, b, w, idx;
        tie(w, a, b, idx) = edges[i];
        if(find(a) != find(b)){
            join(a, b);
            used[idx] = true;
        }
    }
    debug() << imie(used);

    ll cum = 0;
    vector<int> ans;
    forn(i, m){
        int a, b, w, idx;
        tie(w, a, b, idx) = edges[i];
        if(!used[idx] && w + cum <= s){
            cum += w;
            ans.pb(idx);
        }
    }

    
    cout << ans.size() << "\n";
    forn(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

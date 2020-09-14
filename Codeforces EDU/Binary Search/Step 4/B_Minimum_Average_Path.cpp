/*    AUTHOR: julianferres, Mon 14 Sep 2020 07:22:54 PM -03 */
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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e8; // 998244353
const int MAXN  = 1e5+5;
typedef long double ld;

vector<int> ans;
vector<pair<int, int>> g[MAXN];
int n, m;

bool check(ld x){
    vector<int> par(n, -1); vector<ld> sum(n, INF);
    sum[0] = 0;

    forn(i, n){
        for(pair<int, int> e: g[i]){
            int j, w; tie(j, w) = e;
            if(sum[i] + w - x < sum[j]){
                 
                sum[j] = sum[i] + w - x;
                par[j] = i;
            }
        }
    }
    
    if(sum[n-1] <= 0){
        ans.clear();
        int act = n-1;
        while(act){
            ans.pb(act); act = par[act];
        }
        ans.pb(0);
        return true;
    }
    return false;
}
    


int main(){  
    FIN;

    cin >> n >> m;
    forn(i, m){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
    }

    
    ld l = 0, r=INF;

    while(r - l >= 1e-6){
        ld med = (l+r+0.0)/2;
        
        if(check(med)){
            r = med;
        } else {
            l = med;
        }
    }
    reverse(all(ans));

    cout << ans.size()-1 << "\n";
    forn(i, ans.size())  cout << ans[i]+1 << " \n"[i == (int) ans.size() - 1];

    return 0;
}

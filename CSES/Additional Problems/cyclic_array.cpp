/*    AUTHOR: julianferres, lun 24 ago 2020 15:52:42 -03 */
#include <algorithm>
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
const int MAXLOG = 18;

int main(){
    FIN;
    int n, k; cin >> n >> k;
    vector<ll> a(n+1);
    forr(i, 1, n+1) {cin >> a[i]; a[i]+=a[i-1];}

    if(a[n]<=k){ cout << "1\n"; return 0; }

    vector<ll> sig(n+1);
    ll r = 1;
    forr(i, 1, n+1){
        while(r<=n && a[r]-a[i-1] <= k) r++;
        sig[i] = r;
    }

    vi l(n+1), dp(n+1);
    for(ll i=n; i>=1; i--){
        if(sig[i] == n+1){
            dp[i] = 1;
            l[i] = a[n]-a[i-1];
        }
        else{
            l[i] = l[sig[i]];
            dp[i] = dp[sig[i]] + 1;
        }
    }

    ll ans = dp[1];
    forr(i, 1, n){ //Simulo que pasaria si el primer grupo arranca en i
        if(a[i] + l[i+1] <= k)
            ans = min(ans, dp[i+1]);
    }
    cout << ans << "\n";
}


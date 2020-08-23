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
const ll INF = 1e14; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;
const long double EPS = 1e-9;

bool check(vi a, int k, ll max_sum){
    if(a[0]>max_sum) return false;
    ll cnt = 1;
    ll act_cnt = a[0];
    forr(i, 1, a.size()){
        if(a[i]>max_sum) return false;
        if(act_cnt+a[i] <= max_sum){
            act_cnt += a[i];
        }
        else{
            cnt++;
            act_cnt = a[i];
        }
    }
    return cnt<=k;
}

int main(){  
    FIN;

    int n, k; cin >> n >> k;
    vi a(n); forn(i, n) cin >> a[i];
    
    ll l=0, r=INF, ans = r;

    while(l<=r){
        ll med = (l+r)/2;
        if(check(a, k, med))
           ans = med, r = med-1;
        else
            l = med+1;
    }
    cout << ans << "\n";

    return 0;
}

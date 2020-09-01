/*    AUTHOR: julianferres, jue 27 ago 2020 23:14:22 -03 */
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
const int MAXN  = 505;

vector<vi> memo(MAXN, vi(MAXN));
string s;
ll fact[MAXN], inv_fact[MAXN];

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m, b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m){ return binpow(a, m-2, m); }

void init(){
    fact[0] = inv_fact[0] = 1;
    forr(i, 1, MAXN){ fact[i] = fact[i-1]*i%MOD; inv_fact[i] = inv(fact[i], MOD); }
}

ll ncr(int n, int k){
    return fact[n] * inv_fact[k] % MOD * inv_fact[n-k] %MOD;
}

void solve(int l, int r){
    if((l-r+1)&1) return;
    for(int i=l+1; i<=r; i+=2){
        if((i-l+1)&1) continue;
        if(s[i] == s[l]) {
            ll aux = memo[l+1][i-1] * memo[i+1][r] %MOD;
            aux = aux*ncr((r-l+1)/2, (i-l+1)/2) %MOD;
            memo[l][r] += aux;
            memo[l][r] %= MOD;
        }
    }
}

int main(){  
    FIN;

    cin >> s;
    init();
    forr(i, 1, s.size()+1) memo[i][i-1] = 1;
    for(int i=s.size()-1; i>=0; i--)forr(j, i, s.size()) solve(i, j);
    cout << memo[0][s.size()-1] << endl;

    return 0;
}

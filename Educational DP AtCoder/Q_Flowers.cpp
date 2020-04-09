/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 2e5+5;

ll n;
vi t(2 * N,0), h(N), a(N);
vi dp(N, 0); //dp[i]: Best answer finishing in a[i]

//Max iterative segment tree
void build()
{ // build the tree
  for (ll i = n - 1; i > 0; --i)
    t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void modify(ll p, ll value)
{ // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p >> 1] = max(t[p],t[p ^ 1]);
}
ll query(ll l, ll r)
{ // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
        res = max(res, t[l++]);
    if (r & 1)
      res = max(res,t[--r]);
  }
  return res;
}



int main(){
    FIN;
    cin >> n;
    forn(i, n) cin >> h[i];
    forn(i, n) cin >> a[i];

    dp[0] = a[0];
    modify(h[0] - 1, dp[0]);

    forr(i,1,n){
        // dp[i] = max(dp[j])+a[i], j<i and h[j]<h[i]
        dp[i] = query(0, h[i]) + a[i];
        modify(h[i] - 1, dp[i]);
    }

    ll ans = 0;
    forn(i, n) ans = max(ans, dp[i]);
    show(dp, n);
    show(t, 2*n);
    cout << ans << endl;

    return 0;
}
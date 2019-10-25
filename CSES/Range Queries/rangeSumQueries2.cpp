#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
const ll N = 200005;  // limit for array size
ll n;  // array size
ll t[2 * N];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l, ll r) {  // sum on llerval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  ll q; cin >> n >> q;
  forn(i,n) cin >> t[n+i];
  build();
  forn(i,q){
    ll type,a,b; cin >> type >> a >> b; a--;
    if(type==1) modify(a,b);
    else  cout << query(a,b) << endl;
  }

  return 0;
}

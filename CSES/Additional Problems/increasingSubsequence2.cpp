/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 200005

ll n;
ll t[2 * MAXN], a[MAXN];
map <ll,ll> m;

void build()
{ // build the tree
  for (ll i = n - 1; i > 0; --i)
    t[i] = (t[i << 1]+ t[i << 1 | 1]+MOD)%MOD;
}
void modify(ll p, ll value)
{ // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p >> 1] = (t[p]+t[p ^ 1]+MOD)%MOD;
}
ll query(ll l, ll r)
{ // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
      res = (res + t[l++]+MOD)%MOD;
    if (r & 1)
      res = (res + t[--r]+MOD)%MOD;
  }
  return res;
}


int main(){
    FIN;
    cin >> n;
    ll x[n+5],ans=1;

    forn(i,n) cin >> x[i]; 
    forn(i,n) a[i] = x[i]; 
    sort(x,x+n);

    forn(i,n) //Comprimo conservando orden
        if(!esta(x[i],m)) m[x[i]] = m.size();
    forn(i,n) a[i] = m[a[i]]; 
    //DBGV(a,n);
    t[n+a[0]] = 1;
    build();
    forr(i,1,n){
        ll aux = (query(0,a[i])+1+MOD)%MOD;
        modify(a[i],(t[n+a[i]]+aux+MOD)%MOD);
        ans = (ans+aux+MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}


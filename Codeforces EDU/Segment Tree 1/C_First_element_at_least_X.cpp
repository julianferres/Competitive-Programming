/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define SZ(x) ((int)x.size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1e5+5;


ll n;
ll t[2 * MAXN];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}

ll query(ll l, ll r) {  // max on interval [l, r)
  ll res = -INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}


int main(){
  FIN;
     
  int m; cin >> n >> m;
  vi a(n);
  forn(i,n) cin >> t[n + i];

  build();


  forn(i,m){
    int tipo; cin >> tipo;
      if(tipo == 1){
        int idx, value; cin >> idx >> value;
        modify(idx, value);
      }
      else{
        int value; cin >> value;
        if(query(0,n)<value){
          cout << "-1\n";
          continue;
        }
        ll l=0,r=n-1;

        while(l<r){
          //cout << l << " " << r << endl;
          ll med = (l+r)/2;
          if(query(l,med+1)>=value){
            r = med;
          }
          else{
            l = med+1;
          }
        }


        cout << (a[l]>=value ? l : r) << "\n";
      }
  }
  return 0;
}

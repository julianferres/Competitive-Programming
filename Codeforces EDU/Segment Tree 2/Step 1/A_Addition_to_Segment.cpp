/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

ll n;
ll t[2 * MAXN];

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

ll query(int p) {
  ll res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int main() {
    FIN;
    int m;
    cin >> n >> m;

    forn(i, m){
        int tipo; cin >> tipo;

        if(tipo == 1){
            int l,r,value; cin >> l >> r >> value;
            modify(l, r, value);
        }
        else{
            int idx; cin >> idx;
            cout << query(idx) << "\n";
        }
    }    

    return 0;
}
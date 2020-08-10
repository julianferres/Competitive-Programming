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
const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

typedef pair<ll, ll> tipo;
vector <tipo> t;
int tam;

tipo combine(tipo a, tipo b){
    if(a.first == b.first)
        return {a.first, a.second + b.second};
    return (a.first < b.first) ? a : b;
}

 
void build(vector <ll> &v, int n) {  // build the tree 
  tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
  t.resize(2*tam,{0,0});
  forn(i,n) t[tam+i] = {v[i], 1};
  for (int i = tam - 1; i > 0; i--) t[i] = combine(t[i<<1],t[i<<1|1]);
}

void modify(int p, tipo value) {  // set value at position p
  for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = combine(t[p],t[p^1]);
  //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
}

tipo query(int l, int r) {  // sum on interval [l, r]
  tipo res = {INF, 1};
  for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
    if (l&1) res = combine(res, t[l++]);
    if (!(r&1)) res = combine(res, t[r--]);
  }
  return res;
}
 


int main() {
    FIN;
    int n,m; cin >> n >> m;
    vi a(n);
    forn(i, n) cin >> a[i];
    build(a, n);
    forn(i, m){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int idx, v; cin >> idx >> v;
            modify(idx, {v, 1});
        }
        else{
            int l,r; cin >> l >> r;
            pair<ll,ll> ans = query(l,r-1);
            cout << ans.first << " " << ans.second <<"\n";
        }
    }

    return 0;
}
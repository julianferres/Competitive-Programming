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

typedef struct {
  ll a, b, c, d;
} Matrix;

typedef Matrix tipo;
int modu;

vector <tipo> t;
int tam;

Matrix ones(int n) {
    Matrix r;
    r.a = 1; r.b = 0;
    r.c = 0; r.d = 1;
    return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
    Matrix r;
    r.a = a.a*b.a + a.b*b.c;
    r.b = a.a*b.b + a.b*b.d;
    r.c = a.c*b.a + a.d*b.c;
    r.d = a.c*b.b + a.d*b.d;
    r.a = (r.a + modu)%modu;
    r.b = (r.b + modu)%modu;
    r.c = (r.c + modu)%modu;
    r.d = (r.d + modu)%modu;
    return r;
}

tipo combine(tipo a, tipo b){
    Matrix res = a*b;
    return res;
}

void build(vector <tipo> &v, int n) {  // build the tree 
  tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
  t.resize(2*tam,ones(2));
  forn(i,n) t[tam+i] = v[i];
  for (int i = tam - 1; i > 0; i--) t[i] = combine(t[i<<1],t[i<<1|1]);
}

tipo query(int l, int r) {  // sum on interval [l, r]
  tipo resl = ones(2), resr=ones(2);
  for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (!(r&1)) resr = combine(t[r--], resr);
  }
  return combine(resl, resr);
}
 


int main() {
    FIN;
    int n, m; cin >> modu >> n >> m;
    vector<Matrix> a(n, ones(2));
    forn(i,n){
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a[i].a = a1;
        a[i].b = a2;
        a[i].c = a3;
        a[i].d = a4;
    }

    build(a, n);
    // cout << tam;

    forn(i,m){
        int l,r; cin >> l >> r;
        l--,r--;
        tipo ans = query(l, r);
        cout << ans.a << " " << ans.b << "\n" << ans.c << " " << ans.d << "\n\n";
    }

    // forr(i,1,2*tam){
    //     debug(t[i]);
    // }

    return 0;
}

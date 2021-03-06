/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v, n)                  \
    cerr << #v << " = ";            \
    forn(i, n) cerr << v[i] << " "; \
    cerr << endl;
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1 << 30; // const ll INF = 1LL<<60;
const int MOD = 1e9 + 7; // 998244353
const int MAXN = 2e5 + 5;

typedef long long tipo;
struct SegmentTree{
    vector<tipo> t;
    int tam;

    void build(vector<ll> &v, int n)
    { // build the tree
        // root en 1, ojas en el intervalo [tam, 2*tam-1]
        tam = sizeof(int) * 8 - __builtin_clz(n);
        tam = 1 << tam;
        t.resize(2 * tam, 0LL);
        forn(i, n) t[tam + i] = v[i];
        for (tipo i = tam - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void modify(int p, tipo value)
    { // set value at position p
        for (t[p += tam] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
        //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
    }

    tipo query(int l, int r)
    { // sum on interval [l, r]
        tipo res = 0;
        for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (!(r & 1))
                res += t[r--];
        }
        return res;
    }
};

int main()
{
    FIN;
    int n; cin >> n;
    vi a(n),imp(n),par(n);
    forn(i,n){
        cin >> a[i];
        if(i&1) par[i] = a[i];
        else imp[i] = a[i];
    }
    SegmentTree timp,tpar;
    timp.build(imp,n);
    tpar.build(par,n);

    int q; cin >> q;
    forn(i, q){
        int tipo; cin >> tipo;
        if(tipo == 0){ //asignar
            int idx, value; cin >> idx >> value;
            idx--;
            if(!(idx&1)) timp.modify(idx, value);
            else tpar.modify(idx, value);

        }
        else{
            int l,r; cin >> l >> r;
            l--,r--;
            if(!(l&1)) //Impares suman
                cout << timp.query(l, r) - tpar.query(l, r) << "\n";
            else
                cout << -timp.query(l, r) + tpar.query(l, r) << "\n";
        }
    }

    return 0;
}
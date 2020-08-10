/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef set<ll> si;
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
const ll INF = 1LL << 60;
const int MOD = 1e9 + 7; // 998244353
const int MAXN = 1e5 + 5;

vector<vi> t(MAXN, vi(41));
int tam;

vector<ll> combine(vector<ll> a, vector<ll> b)
{
    vector<ll> r(41);
    r[40] = a[40] + b[40];
    forn(i, 40){
        forr(j, i+1, 40){
            r[40] += a[j] * b[i];
        }
    }
    forn(i, 40) r[i] = a[i] + b[i];
        
    return r;
}

void build(vector<vi> &v, int n)
{ // build the tree
    tam = sizeof(int) * 8 - __builtin_clz(n);
    tam = 1 << tam;
    t.resize(2 * tam, vi(41));
    forn(i, n) t[tam + i] = v[i];
    for (int i = tam - 1; i > 0; i--)
        t[i] = combine(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, ll value)
{ // set value at position p
    p+=tam;
    vi aux(41, 0);
    t[p] = aux;
    t[p][value - 1] = 1;
    for (; p > 1; p >>= 1)
        if(p&1) t[p >> 1] = combine(t[p ^ 1], t[p]);
        else t[p >> 1] = combine(t[p], t[p^1]);
}

vi query(int l, int r)
{ // sum on interval [l, r]
  vi resl(41), resr(41);
  for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (!(r&1)) resr = combine(t[r--], resr);
  }
  return combine(resl, resr);
}

int main()
{
    FIN;

    int n, q;
    cin >> n >> q;
    vector<vi> a(n, vi(41));
    forn(i, n)
    {
        ll value;
        cin >> value;
        a[i][value-1] = 1;
    }
    build(a, n);

    forn(i, q)
    {
        // forr(i,1,16) cout << t[i][40] << " ";
        // cout << endl;
        int tipo;
        cin >> tipo;
        if (tipo == 1)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(l, r)[40] << "\n";
        }
        else
        {
            int idx, value;
            cin >> idx >> value;
            idx--;
            modify(idx, value);
        }
    }
    // forn(i,2*tam) debug(t[i]);

    return 0;
}

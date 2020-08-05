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


vector<vector<int>> t(MAXN, vector<int>(40));
int tam;

vector<int> combine(vector<int> a, vector<int> b)
{
    vector<int> r(40);
    forn(i, 40)
        r[i] = a[i] + b[i];
    return r;
}

void build(vector<vector<int>> &v, int n)
{ // build the tree
    tam = sizeof(int) * 8 - __builtin_clz(n);
    tam = 1 << tam;
    t.resize(2 * tam, vector<int>(40));
    forn(i, n) t[tam + i] = v[i];
    for (int i = tam - 1; i > 0; i--)
        t[i] = combine(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, ll value)
{ // set value at position p
    p+=tam;
    vector<int> aux(40);
    t[p] = aux;
    t[p][value - 1] = 1;
    for (; p > 1; p >>= 1)
        t[p >> 1] = combine(t[p], t[p ^ 1]);
}

vector<int> query(int l, int r)
{ // sum on interval [l, r]
    vector<int> res(40);
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = combine(res, t[l++]);
        if (!(r & 1))
            res = combine(t[r--], res);
    }
    return res;
}

int main()
{
    FIN;

    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(40));
    forn(i, n)
    {
        ll value;
        cin >> value;
        a[i][value-1] = 1;
    }
    build(a, n);

    forn(i, q)
    {
        int tipo;
        cin >> tipo;
        if (tipo == 1)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vector<int> interval = query(l, r);
            int ans = 0;
            forn(i, 40) if (interval[i])
                ans++;
            cout << ans << "\n";
        }
        else
        {
            int idx, value;
            cin >> idx >> value;
            idx--;
            modify(idx, value);
        }
    }

    return 0;
}

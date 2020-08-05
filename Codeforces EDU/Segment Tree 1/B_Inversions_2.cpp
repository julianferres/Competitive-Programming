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

int kth_one(ll k)
{
    int act_node = 1;
    while (act_node < tam)
    { //No estoy en leafs
        // cout << "act_node: " << act_node << endl;
        // cout << "k: " << k << endl;
        if (t[2 * act_node] >= k)
            act_node = 2 * act_node;
        else
        {
            k -= t[2 * act_node];
            act_node = 2 * act_node + 1;
        }
    }
    // cout << "act_node: " << act_node << endl;
    return act_node - tam;
}

int main()
{
    FIN;

    int n, m;
    cin >> n;
    vi a(n), invs(n);
    forn(i, n) cin >> invs[i];
    forn(i, n) a[i] = 1;
    build(a, n);

    vi ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        ans[i] = n-kth_one(invs[i]+1);
        modify(n-ans[i], 0);
        // forr(i, tam, 2*tam) cout << t[i] << " ";
        // cout << endl;
    }

    forn(i, n) cout << ans[i] << " \n"[i==n-1];

    return 0;
}
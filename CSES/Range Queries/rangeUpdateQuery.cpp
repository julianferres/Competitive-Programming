/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define INF 1e10

const int N = 200005; // limit for array size
int n;                // array size
ll t[2 * N];

void modify(int l, int r, int value)
{
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            t[l++] += value;
        if (r & 1)
            t[--r] += value;
    }
}
ll query(int p)
{
    ll res = 0;
    for (p += n; p > 0; p >>= 1)
        res += t[p];
    return res;
}

int main()
{
    FIN;
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> t[n + i];

    forn(i, q)
    {
        int j;
        cin >> j;
        if (j == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            modify(--a, b, u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << query(k) << endl;
        }
    }

    return 0;
}

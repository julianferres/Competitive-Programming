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
#define RAYA cerr << "===============================" << endl

const ll N = 200005; // limit for array size
ll n;                // array size
ll t[2 * N];

void build()
{ // build the tree
    for (ll i = n - 1; i > 0; --i)
        t[i] = t[i << 1] ^ t[i << 1 | 1];
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res ^= t[l++];
        if (r & 1)
            res ^= t[--r];
    }
    return res;
}

int main()
{
    FIN;
    int q;
    cin >> n >> q;
    forn(i, n) cin >> t[n + i];
    build();
    forn(i, q)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        cout << query(a, b) << endl;
    }

    return 0;
}

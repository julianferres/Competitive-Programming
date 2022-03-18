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
#define MAXN 100005
#define INF 1e18

const int N = 200005; // limit for array size
int n;                // array size
ll t[2 * N];

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
    ll res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, t[l++]);
        if (r & 1)
            res = min(res, t[--r]);
    }
    return res;
}

int main()
{
    FIN;
    ll l, r;
    cin >> n >> l >> r;
    ll a[n + 5];
    forn(i, n) cin >> a[i];
    ll cum[n + 5];
    t[n] = 0;
    cum[0] = 0;
    forn(i, n)

    {
        t[n + i + 1] = t[n + i] + a[i];
        cum[i + 1] = cum[i] + a[i];
    }
    build();
    /*forn(i, n + 1)
    {
        cout << cum[i] << " ";
    }*/
    ll ans = -INF;

    forr(i, l, n + 1)
    {
        ll left = max(0LL, i - r);
        ll right = i - l;
        ll q = query(left, right + 1);
        ans = max(cum[i] - q, ans);
    }

    cout << ans << endl;

    return 0;
}

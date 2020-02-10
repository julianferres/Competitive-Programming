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
#define M 1000000007
#define MAXN 200005

vi fact;

ll binpow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll invmod(ll a, ll m)
{
    return (binpow(a, m - 2, m) + m) % m;
}
ll c(ll n, ll k)
{
    return ((fact[n] * invmod(fact[k], M) % M) * invmod(fact[n - k], M) + M) % M;
}

int main()
{
    FIN;
    fact.pb(1LL);
    forr(i, 1, 1000004) fact.pb((fact.back() * i + M) % M);
    int n, m;
    cin >> n >> m;

    ll ans = c(2 * n - 2, n - 1);

    forn(i, m)
    {
        ll x, y;
        cin >> x >> y;
        ans -= c(y + x - 2, x - 1) * c(2 * n - x - y, n - x);
        ans = (ans + M) % M;
    }
    cout << ans << endl;

    return 0;
}

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
int t[2 * N];

void build()
{
    for (int i = n - 1; i > 0; --i)
        t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value)
{
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r)
{ // sum on interval [l, r)
    int res = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(res, t[--r]);
    }
    return res;
}

int main()
{
    FIN;
    int m;
    cin >> n >> m;
    forn(i, n) cin >> t[n + i];
    build();
    vi ans;
    ll x;
    forn(i, m)
    {
        cin >> x;
        ll l = 0, r = n;
        ll allocated = false;
        ll med;
        while (r - l > 1)
        {

            med = (l + r) / 2;
            ll lquery = query(l, med);
            ll rquery = query(med, r);
            if (lquery < x && rquery < x)
                break;
            else if (lquery >= x)
            {
                r = med;
                allocated = true;
            }
            else
            {
                l = med;
                allocated = true;
            }
        }

        if (!allocated)
        {
            ans.pb(0);
        }
        else
        {
            ans.pb(l + 1);
            modify(l, t[l + n] - x);
        }
    }
    DBGV(ans, m);
    return 0;
}
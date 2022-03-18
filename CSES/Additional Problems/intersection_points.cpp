/******************************************
*    AUTHOR:         julianferres         *
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

struct event
{
    int x, y1, y2, type;
};
bool operator<(const event &s1, const event &s2)
{
    return s1.x < s2.x || (s1.x == s2.x && s1.type < s2.type);
}

#define N 2000005 //No hace falta comprimir
int n = 2000000;
ll t[2 * N];

void build()
{ // build the tree
    for (ll i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(ll p, ll value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

vector<event> e;

int main()
{
    FIN;
    int nn;
    cin >> nn;
    forn(i, nn)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
            e.pb({x1, y1, y2, 2});
        else
        {
            e.pb({x1, y1, y2, 1});
            e.pb({x2, y1, y2, 3});
        }
    }
    sort(all(e));
    ll ans = 0;
    for (auto ee : e)
    {
        int y1 = ee.y1, y2 = ee.y2, type = ee.type;
        if (type == 1)
            modify(y1 + 1000000, t[y1 + n + 1000000] + 1);
        else if (type == 3)
            modify(y1 + 1000000, t[y1 + n + 1000000] - 1);
        else
            ans += query(y1 + 1000000, y2 + 1000001);
    }
    cout << ans << endl;

    return 0;
}

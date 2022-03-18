/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define MAXN 200005

struct data
{
    ll sum, pref, suff, ans;
};

data t[4 * MAXN];
data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
data make_data(ll val)
{
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL, val);
    return res;
}
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = make_data(a[tl]);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = make_data(new_val);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
data query(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    FIN;
    int n, m;
    cin >> n >> m;
    ll a[MAXN];
    forn(i, n) cin >> a[i];
    build(a, 1, 0, n - 1);
    forn(i, m)
    {
        ll k, x;
        cin >> k >> x;
        k--;
        update(1, 0, n - 1, k, x);
        cout << query(1, 0, n - 1, 0, n - 1).ans << endl;
    }

    return 0;
}

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

struct Vertex
{
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};
Vertex *build(ll a[], int tl, int tr)
{
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}
ll get_sum(Vertex *v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm)) + get_sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}
Vertex *update(Vertex *v, int tl, int tr, int pos, ll new_val)
{
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}

vector<Vertex *> versions;

int main()
{
    FIN;
    int n, q;
    cin >> n >> q;
    ll a[MAXN];
    forn(i, n) cin >> a[i];
    versions.pb(build(a, 0, n - 1));
    forn(i, q)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int k, a, x;
            cin >> k >> a >> x;
            k--, a--;
            Vertex *v = versions[k];
            versions[k] = update(v, 0, n - 1, a, x);
        }
        else if (c == 2)
        {
            int k, a, b;
            cin >> k >> a >> b;
            k--, a--, b--;
            Vertex *v = versions[k];
            cout << get_sum(v, 0, n - 1, a, b) << endl;
        }
        else
        {
            int k;
            cin >> k;
            k--;
            Vertex *v = versions[k];
            versions.pb(update(v, 0, n - 1, 0, get_sum(v, 0, n - 1, 0, 0)));
        }
    }

    return 0;
}

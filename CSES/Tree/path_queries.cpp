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

int n, q, a, b;
vi g[MAXN], id, idToPos(MAXN), s(MAXN, 0);
bool vis[MAXN];
ll t[2 * MAXN];

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
void dfs(ll v)
{
    id.pb(v);
    vis[v] = true;
    s[v] = 1;
    for (auto u : g[v])
    {
        if (vis[u])
            continue;
        dfs(u);
        s[v] += s[u];
    }
}

int main()
{
    FIN;
    cin >> n >> q;
    ll initvalue[MAXN];
    forn(i, n) cin >> initvalue[i];
    forn(i, n - 1)
    {
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    forn(i, n) idToPos[id[i]] = i;
    forn(i, n) modify(idToPos[i], idToPos[i] + s[i], initvalue[i]);

    forn(i, q)
    {
        ll c, ss, x;
        cin >> c;
        if (c & 1)
        {
            cin >> ss >> x;
            ss--;
            modify(idToPos[ss], idToPos[ss] + s[ss], x - initvalue[ss]);
            initvalue[ss] = x;
        }
        else
        {
            cin >> ss;
            ss--;
            cout << query(idToPos[ss]) << endl;
        }
    }
    return 0;
}
/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define MAXN 200005

vi g[MAXN], id, val(MAXN), s(MAXN), size(MAXN);

void dfs(int v, int p)
{
    id.pb(v);
    size[v] = 1;
    s[v] = s[p] + val[v];
    for (auto u : g[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
        size[v] += size[u];
    }
}

int main()
{
    FIN;
    int n, q;
    cin >> n >> q;
    forn(i, n) cin >> val[i + 1];
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    /*forn(i, q)
    {
        int c, s;
        cin >> c >> s;
        if (c == 1)
        {
            int x;
            cin >> x;
        }
        else cout << 'a' << endl;
    }*/
    dfs(1, 0);
    DBGV(id, n);
    return 0;
}

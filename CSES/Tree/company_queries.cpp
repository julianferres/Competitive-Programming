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
#define MAXN 200005
#define INF 1e18

int n, l;
vector<int> adj[MAXN];
vector<vector<int>> up;
vector<int> d(MAXN, 0);

void dfs(int v, int p)
{
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v])
    {
        if (u != p)
        {
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }
}

void preprocess(int root)
{
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main()
{
    FIN;
    int q;
    cin >> n >> q;
    forr(i, 1, n)
    {
        ll par;
        cin >> par;
        par--;
        adj[i].pb(par);
        adj[par].pb(i);
    }
    preprocess(0);

    forn(i, q)
    {
        int x, k;
        cin >> x >> k;
        x--;
        if (k > d[x])
        {
            cout << -1 << endl;
            continue;
        }
        int digit = 0;
        while (k > 0)
        {
            if (k & 1)
                x = up[x][digit];
            k >>= 1;
            digit++;
        }
        cout << x + 1 << endl;
    }

    return 0;
}
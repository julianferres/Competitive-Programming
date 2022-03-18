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
#define MAXN 100005

vi g[MAXN], id;
bool visto[MAXN];

void dfs(int v)
{
    visto[v] = true;
    for (auto u : g[v])
    {
        if (visto[u])
            continue;
        dfs(u);
    }
    id.pb(v);
}

int main()
{
    FIN;
    int n, m;
    cin >> n >> m;
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
    }
    forn(i, n) if (!visto[i]) dfs(i);
    reverse(all(id));

    vi dp(n, -1), parent(n);
    //dp tiene el camino mas largo hasta tal nodo

    forn(i, n)
    {
        int v = id[i];
        if (v == n - 1)
            break;
        if (v == 0)
            dp[v] = 1;
        if (dp[v] > 0) //Ya procese este una vez al menos
            for (auto u : g[v])
                if (dp[u] < dp[v] + 1)
                    dp[u] = dp[v] + 1, parent[u] = v;
    }
    if (dp[n - 1] < 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vi ans;
        int v = n - 1;
        while (v)
            ans.pb(v + 1), v = parent[v];
        ans.pb(1);
        reverse(all(ans));
        cout << ans.size() << endl;
        forn(i, ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}

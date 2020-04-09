/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
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
#define MAXN 100005
const ll INF = 1LL << 62;

int n;
vii g[MAXN];
vi d, p, topo, parents[MAXN], gInd[MAXN];
vector<bool> visited;

void dfs(int v)
{
    visited[v] = true;
    for (auto u : gInd[v])
    {
        if (!visited[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort()
{
    visited.assign(n, false);
    topo.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(all(topo));
}

void dijkstra(int s)
{
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<ii> q;
    q.push({0, s});
    while (!q.empty())
    {
        int v = q.top().second;
        q.pop();
        for (auto edge : g[v])
        {
            int to = edge.first;
            ll w = edge.second;

            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                parents[to].clear();
                parents[to].pb(v);
                q.push({-d[to], to});
            }
            else if (d[v] + w == d[to])
                parents[to].pb(v);
        }
    }
}

int main()
{
    FIN;
    int m;
    cin >> n >> m;
    forn(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
    }
    dijkstra(0);
    forn(i, n) forn(j, parents[i].size()) gInd[parents[i][j]].pb(i);
    topological_sort();

    vi paths(n, 0), max_len_path(n, 0), min_len_path(n, INF);
    min_len_path[0] = 0, paths[0] = 1;
    for (auto i : topo)
    {
        for (auto u : g[i])
        {
            if (d[i] + u.second == d[u.first])
            {
                paths[u.first] += paths[i];
                max_len_path[u.first] = max(max_len_path[u.first], max_len_path[i] + 1);
                min_len_path[u.first] = min(min_len_path[u.first], min_len_path[i] + 1);
            }
            paths[u.first] %= MOD;
        }
    }
    cout << d[n - 1] << " " << paths[n - 1] << " " << min_len_path[n - 1] << " " << max_len_path[n - 1] << endl;

    return 0;
}
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
#define MAXN 105
#define INF 2000000000
struct Dinic
{
    int nodes, src, dst;
    vector<int> dist, q, work;
    struct edge
    {
        ll to, rev;
        ll f, cap;
    };
    vector<vector<edge>> g;
    Dinic(int x) : nodes(x), g(x), dist(x), q(x), work(x) {}
    void add_edge(int s, int t, ll cap)
    {
        g[s].pb((edge){t, g[t].size(), 0, cap});
        g[t].pb((edge){s, g[s].size() - 1LL, 0, 0});
    }
    bool dinic_bfs()
    {
        fill(all(dist), -1);
        dist[src] = 0;
        int qt = 0;
        q[qt++] = src;
        for (int qh = 0; qh < qt; qh++)
        {
            int u = q[qh];
            forr(i, 0, g[u].size())
            {
                edge &e = g[u][i];
                int v = g[u][i].to;
                if (dist[v] < 0 && e.f < e.cap)
                    dist[v] = dist[u] + 1, q[qt++] = v;
            }
        }
        return dist[dst] >= 0;
    }
    ll dinic_dfs(int u, ll f)
    {
        if (u == dst)
            return f;
        for (int &i = work[u]; i < g[u].size(); i++)
        {
            edge &e = g[u][i];
            if (e.cap <= e.f)
                continue;
            int v = e.to;
            if (dist[v] == dist[u] + 1)
            {
                ll df = dinic_dfs(v, min(f, e.cap - e.f));
                if (df > 0)
                {
                    e.f += df;
                    g[v][e.rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst)
    {
        src = _src;
        dst = _dst;
        ll result = 0;
        while (dinic_bfs())
        {
            fill(all(work), 0);
            while (ll delta = dinic_dfs(src, INF))
                result += delta;
        }
        return result;
    }
};

int main()
{
    FIN;
    int n;
    cin >> n;
    char c;
    Dinic nt(2 * n + 2);

    forr(i, 1, n + 1) forr(j, 1, n + 1)
    {
        cin >> c;
        if (c == 'o')
            nt.add_edge(i, j + n, 1);
    }
    forr(i, 1, n + 1)
        nt.add_edge(0, i, 1);
    forr(i, n + 1, 2 * n + 1)
        nt.add_edge(i, 2 * n + 1, 1);
    cout << nt.max_flow(0, 2 * n + 1) << endl;
    forr(i, 1, n + 1) if (nt.dist[i] < 0) cout << 1 << " " << i << endl;
    forr(i, n + 1, 2 * n + 1) if (nt.dist[i] > 0) cout << 2 << " " << i - n << endl;

    return 0;
}

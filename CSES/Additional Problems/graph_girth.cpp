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
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 2505

int n;
vector<vi> g;
vii edges;
queue<ll> q;
vector<bool> used(MAXN);
vi d;

void bfs(int s, int t)
{
    forn(i, MAXN) used[i] = false;
    q.push(s);
    used[s] = true;
    used[t] = true;
    d[s] = 0;
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        for (int u : g[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
}
int main()
{
    FIN;
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
        edges.pb({a, b});
    }
    ll girth = INF;
    d.assign(n, INF);
    forn(i, m)
    {
        ii edge = edges[i];
        forn(i, n) d[i] = INF;
        bfs(edge.first, edge.second);
        //forn(i, n) cout << d[i] << " \n"[i == n - 1];
        ll dn = INF;
        for (auto u : g[edge.second])
            if (u != edge.first)
                dn = min(dn, d[u] + 1);
        //DBG(edge.first + 1), DBG(edge.second + 1);
        //cout << dn << endl;
        girth = min(girth, dn + 1);
    }
    cout << ((girth < INF) ? girth : -1) << endl;

    return 0;
}

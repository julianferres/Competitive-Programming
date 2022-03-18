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
#define MAXN 100005

//DSU
int parent[MAXN];
int size[MAXN];
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

struct edge
{
    int y;
    edge(int y) : y(y) {}
};
list<edge> g[MAXN];
set<ii> used_edge;
void add_edge(int a, int b)
{
    g[a].push_front(edge(b));
    g[b].push_front(edge(a));
}
vi p;
void go(int x)
{
    while (g[x].size())
    {
        int y = g[x].front().y;
        g[x].pop_front();
        if (!esta(mp(y, x), used_edge) && !esta(mp(x, y), used_edge))
        {
            used_edge.insert(mp(x, y));
            go(y);
        }
    }
    p.push_back(x);
}
vi get_path(int x)
{
    p.clear();
    go(x);
    reverse(p.begin(), p.end());
    return p;
}
ll d[MAXN];

int main()
{
    FIN;
    ll n, m;
    cin >> n >> m;
    forn(i, n) make_set(i);
    forn(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        add_edge(a, b);
        d[a]++, d[b]++;
        union_sets(a, b);
    }
    bool aux = true;
    forn(i, n) if (d[i] % 2 == 1) aux = false;
    bool todas_las_aristas_juntas = true;
    int padre_cc = -1;
    forn(i, n)
    {
        if (size[i] > 1)
        {
            if (padre_cc != -1 && padre_cc != find_set(i))
            {
                todas_las_aristas_juntas = false;
                break;
            }
            else
                padre_cc = find_set(i);
        }
    }
    if (!aux || !d[0] || !todas_las_aristas_juntas)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vi path = get_path(0);
    forn(i, m + 1) cout << path[i] + 1 << " ";
    cout << endl;
}
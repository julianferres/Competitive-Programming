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

struct edge
{
    int y;
    edge(int y) : y(y) {}
};
list<edge> g[MAXN];
void add_edge(int a, int b)
{
    g[a].push_front(edge(b));
}
vi p;
void go(int x)
{
    while (g[x].size())
    {
        int y = g[x].front().y;
        g[x].pop_front();
        go(y);
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
ll d_out[MAXN];
ll d_in[MAXN];

int main()
{
    FIN;
    ll n, m;
    cin >> n >> m;
    forn(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        add_edge(a, b);
        d_out[a]++, d_in[b]++;
    }
    bool aux = true;
    forr(i, 1, n - 1) if (d_out[i] != d_in[i]) aux = false;

    if (!(d_out[0] - d_in[0] == 1 && aux && d_in[n - 1] - d_out[n - 1] == 1))
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vi path = get_path(0);
    forn(i, m + 1) cout << path[i] + 1 << " ";
    cout << endl;
}
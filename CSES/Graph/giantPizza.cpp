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
#define MAXN 100005
#define INF 1e18

int n;
vi g[2 * MAXN], gt[2 * MAXN];
vector<bool> used, assignment;
vi order, comp;

void dfs1(int v)
{
    used[v] = true;
    for (int u : g[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}
void dfs2(int v, int cl)
{
    comp[v] = cl;
    for (int u : gt[v])
    {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}
bool solve_2SAT()
{
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i)
    {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2)
    {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int main()
{
    FIN;
    int people;
    cin >> people >> n;
    forn(i, people)
    {
        char sign1, sign2;
        int x1, x2;
        cin >> sign1 >> x1 >> sign2 >> x2;
        x1--, x2--;
        g[(x1 << 1) | (sign1 == '+')].pb((x2 << 1) | (sign2 != '+'));
        gt[(x2 << 1) | (sign2 != '+')].pb((x1 << 1) | (sign1 == '+'));
        g[(x2 << 1) | (sign2 == '+')].pb((x1 << 1) | (sign1 != '+'));
        gt[(x1 << 1) | (sign1 != '+')].pb((x2 << 1) | (sign2 == '+'));
    }
    n *= 2;
    bool pos = solve_2SAT();
    if (!pos)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    forn(i, n / 2)
    {
        char ans = assignment[i] ? '+' : '-';
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}

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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define MAXN 200005

int n;
vi g[MAXN], s, le(MAXN, -1), ri(MAXN, -1);
map<ll, ll> m;
bool vis[MAXN];
ll x[MAXN], cnt[MAXN];

ll block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
vi mo_s_algorithm(vector<Query> queries)
{
    vi answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = 0;
    int ans = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_r < q.r)
            if (++cnt[s[cur_r++]] == 1)
                ans++;
        while (cur_r > q.r)
            if (--cnt[s[--cur_r]] == 0)
                ans--;
        while (cur_l < q.l)
            if (--cnt[s[cur_l++]] == 0)
                ans--;
        while (cur_l > q.l)
            if (++cnt[s[--cur_l]] == 1)
                ans++;
        answers[q.idx] = ans;
    }
    return answers;
}
void dfs(ll v)
{
    s.pb(v);
    vis[v] = true;
    for (auto u : g[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
    s.pb(v);
}
void init_lr()
{
    forn(i, s.size())
    {
        if (le[s[i]] == -1)
            le[s[i]] = i;
        else
            ri[s[i]] = i;
    }
}

int main()
{
    FIN;
    cin >> n;
    block_size = (ll)sqrt(n + .0) + 1;

    forn(i, n)
    {
        int y;
        cin >> y;
        if (esta(y, m))
            x[i] = m[y]; //Compresion de coordenadas
        else
            x[i] = m.size(), m[y] = x[i];
    }

    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    init_lr();
    forn(i, 2 * n) s[i] = x[s[i]];
    vector<Query> queries(n);
    forn(i, n)
    {
        queries[i].l = le[i];
        queries[i].r = ri[i] + 1;
        queries[i].idx = i;
    }
    vi answers = mo_s_algorithm(queries);

    forn(i, n) cout << answers[i] << " ";
    cout << endl;

    return 0;
}
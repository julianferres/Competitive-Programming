/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
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
#define MAXN 100005

int n;
vii g[MAXN];

ll INF = 1LL << 62;

struct Edge
{
    ll a, b, cost;
};

void dijkstra(vii g[], ll s, ll d[])
{
    forn(i, n) d[i] = INF;
    d[s] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ll c, u, v, w;
        tie(c, u) = q.top();
        q.pop();
        if (d[u] < c)
            continue;
        for (ii x : g[u])
        {
            tie(v, w) = x;
            if (d[v] > c + w)
                d[v] = c + w, q.push({c + w, v});
        }
    }
}

int main()
{
    FIN;
    int m, k;
    cin >> n >> m >> k;
    forn(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a - 1].pb(mp(b - 1, c));
    }
    ll s = 0, t = n - 1;
    ll count[MAXN];
    forn(i, n) count[i] = 0;

    priority_queue<ii, vii, greater<ii>> q;
    q.push(mp(0LL, s));
    vi ans;
    while (!q.empty() && count[n - 1] < k)
    {
        ii x = q.top();
        ll C = x.first, u = x.second;
        q.pop();
        //cout << "C: " << C << ",u: " << u << endl;
        count[u]++;
        if (u == t)
            ans.pb(C);
        if (count[u] <= k)
        {
            if (!g[u].size())
                continue;
            for (auto x : g[u])
            {
                ll v = x.first, w_uv = x.second;
                //cout << "u: " << u << ",v: " << v << endl;
                q.push(mp(C + w_uv, v));
            }
        }
    }
    forn(i, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

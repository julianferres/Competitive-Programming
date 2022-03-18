/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
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
#define esta(x, c) ((c).find(x) != (c).end())
#define DBG(x) cerr << #x << " = " << (x) << endl
#define INF 2000000000
#define MAXN 505
#define RAYA cerr << "===============================" << endl

ll n, capacity[MAXN][MAXN];
vi adj[MAXN];
vvi ans;
bool visited[MAXN];
map<ii, int> edgesToPath;
set<ii> edges;

ll bfs(ll s, ll t, vector<ll> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        ll cur = q.front().first, flow = q.front().second;
        q.pop();
        for (ll next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                {
                    ll aux = t;
                    vi actAns(1, t + 1);
                    while (aux)
                        aux = parent[aux], actAns.pb(aux + 1);
                    reverse(all(actAns));
                    forr(i, 1, actAns.size()) edgesToPath[mp(actAns[i - 1], actAns[i])] = ans.size();
                    ans.pb(actAns);
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t)
{
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;
    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        ll cur = t;
        while (cur != s)
        {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    FIN;
    ll m;
    cin >> n >> m;
    forn(i, m)
    {
        ll a, b;
        cin >> a >> b;
        edges.insert(mp(a, b));
        a--, b--;
        capacity[a][b] = 1;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll flow = maxflow(0, n - 1);
    cout << flow << endl;

    //Refino si hay algun antiedge
    forn(i, ans.size())
        forr(j, 1, ans[i].size())
    {
        if (esta(mp(ans[i][j - 1], ans[i][j]), edges))
            continue;
        int pathToModify = edgesToPath[mp(ans[i][j], ans[i][j - 1])];
        vi tailAux;
        while (ans[i][ans[i].size() - 1] != ans[i][j - 1])
            tailAux.pb(ans[i].back()), ans[i].pop_back();
        reverse(all(tailAux));
        while (ans[pathToModify][ans[pathToModify].size() - 1] != ans[i][j - 1])
            ans[i].pb(ans[pathToModify].back()), ans[pathToModify].pop_back();
        ans[pathToModify].pop_back();
        ans[pathToModify].pop_back();
        forn(ii, tailAux.size()) ans[pathToModify].pb(tailAux[ii]);
    }

    forn(i, ans.size())
    {
        cout << ans[i].size() << endl;
        forn(j, ans[i].size())
                cout
            << ans[i][j] << " \n"[j == ans[i].size() - 1];
    }
    return 0;
}
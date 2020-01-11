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
#define FIN                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                \
  forn(i, n) cout << v[i] << " "; \
  cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 100005

ll INF = 1LL << 62;

struct Edge
{
  ll a, b, cost;
};
int n; // number of nodes
vii g[MAXN], gi[MAXN];

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
  int m;
  cin >> n >> m;
  vector<Edge> e;
  forn(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    g[a - 1].pb(mp(b - 1, c));
    gi[b - 1].pb(mp(a - 1, c));
    Edge x;
    x.a = a - 1;
    x.b = b - 1;
    x.cost = c;
    e.pb(x);
  }
  ll d[MAXN], di[MAXN];

  dijkstra(g, 0, d);
  dijkstra(gi, n - 1, di);
  //DBGV(d,n);
  //DBGV(di,n);
  ll ans = INF;
  for (auto edge : e)
  {
    ans = min(ans, d[edge.a] + di[edge.b] + edge.cost / 2);
  }
  cout << ans << endl;
  return 0;
}

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

const ll minusINF = -1LL << 40;
const ll INF = 1LL << 40;
int n;
vii g[MAXN];

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
      if (d[v] > c + w && c + w > minusINF)
      {
        d[v] = c + w, q.push({c + w, v});
      }
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
    g[a - 1].pb(mp(b - 1, -c));
  }
  ll d[MAXN];
  dijkstra(g, 0, d);
  cout << d[n - 1] << endl;
  /*if(neg_cycle)
        cout << -1 << endl;
    else
        cout << -d[n-1] << endl;*/
  return 0;
}

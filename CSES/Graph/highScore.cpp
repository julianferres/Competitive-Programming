/******************************************
*    AUTHOR:         julianferres         *
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 2505

int n, m;
vii g[MAXN], gt[MAXN];
vector<bool> used, assignment;
vi order, comp;

void dfs1(int v)
{
  used[v] = true;
  for (auto u : g[v])
  {
    if (!used[u.first])
      dfs1(u.first);
  }
  order.push_back(v);
}
void dfs2(int v, int cl)
{
  comp[v] = cl;
  for (auto u : gt[v])
  {
    if (comp[u.first] == -1)
      dfs2(u.first, cl);
  }
}
bool korasaju()
{
  used.assign(n, false);
  forn(i, n) if (!used[i]) dfs1(i);

  comp.assign(n, -1);
  for (int i = 0, j = 0; i < n; ++i)
  {
    int v = order[n - i - 1];
    if (comp[v] == -1)
      dfs2(v, j++);
  }
}

int main()
{
  FIN;
  cin >> n >> m;
  forn(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    c *= -1;
    g[a].pb({b, c});
    gt[b].pb({a, c});
  }

  korasaju();
  forn(i, n) cout << comp[i] << " \n"[i == n - 1];

  return 0;
}

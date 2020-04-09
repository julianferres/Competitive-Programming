/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
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

const int n = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
vi g[n + 5];
ii swaps[] = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};
vi d(n + 5, 0);
int index(vi v)
{
  int m = 1, r = 0, k = n / 9;
  forn(i, 8)
  {
    int d = v[i];
    int e = (d - __builtin_popcount(m & ((1 << d) - 1)));
    r += e * k;
    k /= 8 - i;
    m |= (1 << d);
  }
  return r;
}
vi permutation(int r)
{
  vi v(9);
  int m = 1, k = n / 9;
  for (int i = 0; i <= 8; i++)
  {
    int d = r / k;
    int j = 0, l = 1;
    while (j <= d)
    {
      if (!(m & (1 << l)))
        j++;
      if (j > d)
        break;
      l++;
    }
    v[i] = l;
    if (i == 8)
      break;
    r %= k;
    k /= 8 - i;
    m |= (1 << l);
  }
  return v;
}

void bfs(int s)
{
  queue<int> q;
  vector<bool> used(n);

  q.push(s);
  used[s] = true;
  while (!q.empty())
  {
    int v = q.front();
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
  vi v(9);
  forn(i, 3) forn(j, 3) cin >> v[i * 3 + j];
  forn(i, n)
  {
    vi perm = permutation(i);

    forn(j, 12)
    {
      int a = swaps[j].first, b = swaps[j].second;
      swap(perm[a], perm[b]);
      g[i].pb(index(perm));
      swap(perm[a], perm[b]);
    }
  }
  bfs(0);
  cout << d[index(v)] << endl;

  return 0;
}

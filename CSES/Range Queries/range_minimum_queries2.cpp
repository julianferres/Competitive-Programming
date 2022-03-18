/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
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
#define INF 1e10

const int N = 200005; // limit for array size
int n;                // array size
int t[2 * N];

void build()
{ // build the tree
  for (int i = n - 1; i > 0; --i)
    t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value)
{ // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p >> 1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r)
{ // sum on interval [l, r)
  int res = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
      res = min(res, t[l++]);
    if (r & 1)
      res = min(res, t[--r]);
  }
  return res;
}

int main()
{
  FIN;
  int q;
  cin >> n >> q;
  forn(i, n) cin >> t[n + i];
  build();
  forn(i, q)
  {
    int j;
    cin >> j;
    if (j == 1)
    {
      int k, x;
      cin >> k >> x;
      modify(k - 1, x);
    }
    else
    {
      int a, b;
      cin >> a >> b;
      a--;
      cout << query(a, b) << endl;
    }
  }

  return 0;
}

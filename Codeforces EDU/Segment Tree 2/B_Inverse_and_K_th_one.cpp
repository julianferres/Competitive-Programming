/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN                \
  ios::sync_with_stdio(0); \
  cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v, n)                \
  cerr << #v << " = ";            \
  forn(i, n) cerr << v[i] << " "; \
  cerr << endl;
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1 << 30; // const ll INF = 1LL<<60;
const int MOD = 1e9 + 7; // 998244353
const int MAXN = 2e5 + 5;

typedef long long tipo;

struct lazy
{
  struct node
  {
    tipo ans, l, r;
    bool upd;
    tipo INF = (tipo)(1e18 + 7);
    node base(node aux)
    {
      aux.ans = 0;
      return aux;
    } //Poner el neutro de la query
    void set_node(tipo x, tipo pos) { ans = x, l = r = pos; };
    void set_lazy(tipo x) { upd ^= 1; } //Poner operacion de update
    void combine(node a, node b)
    {
      ans = a.ans + b.ans; //Operacion de query
      l = min(a.l, b.l);
      r = max(a.r, b.r);
    }
  };
  vector<node> t;

  void push(tipo p)
  {
    if (t[p].upd == true)
    {
      t[p].ans = (t[p].r - t[p].l + 1) - t[p].ans;
      //Operacion update
      if (t[p].l < t[p].r)
      {
        t[2 * p + 1].upd ^= 1;
        t[2 * p + 2].upd ^= 1;
      }
      t[p].upd = false; //Poner el neutro del update
    }
  }

  node ask(int p, tipo l, tipo r)
  {
    push(p);
    if (l > t[p].r || r < t[p].l)
      return t[p].base(t[p]);
    if (l <= t[p].l && t[p].r <= r)
      return t[p];
    node ans;
    ans.combine(ask(2 * p + 1, l, r), ask(2 * p + 2, l, r));
    return ans;
  }

  int kth_one(int k)
  {
    int act_node = 0;
    while (t[act_node].l < t[act_node].r){ //No estoy en leafs
      push(act_node);
      push(2*act_node + 1);
      // push(2*act_node + 2);
      // cout << "Intervalo: " << t[act_node].l << " " << t[act_node].r << endl;
      if (t[2 * act_node + 1].ans >= k)
        act_node = 2 * act_node + 1;
      else
      {
        k -= t[2 * act_node + 1].ans;
        act_node = 2 * act_node + 2;
      }
    }
    return t[act_node].l;
  }

  void update(int p, tipo l, tipo r, tipo val)
  {
    push(p);
    if (l > t[p].r || r < t[p].l)
      return;
    if (l <= t[p].l && t[p].r <= r)
    {
      t[p].set_lazy(val);
      push(p);
      return;
    }
    update(2 * p + 1, l, r, val);
    update(2 * p + 2, l, r, val);
    t[p].combine(t[2 * p + 1], t[2 * p + 2]);
  }

  void build(tipo a, tipo b, int p, vector<tipo> &v)
  {
    if (a == b)
    {
      t[p].set_node(v[a], a);
      return;
    }
    tipo med = (a + b) / 2;
    build(a, med, 2 * p + 1, v);
    build(med + 1, b, 2 * p + 2, v);
    t[p].combine(t[2 * p + 1], t[2 * p + 2]);
  }
  node query(tipo l, tipo r) { return ask(0, l, r); }
  void modificar(tipo l, tipo r, tipo val) { update(0, l, r, val); }
  void construir(vector<tipo> &v, int n)
  {
    t.resize(4 * n);
    build(0, n - 1, 0, v);
  }
};

int main()
{
  FIN;

  int n, m;
  cin >> n >> m;
  vi a(n);

  lazy st;
  st.construir(a, n);

  forn(i, m)
  {
    int tipo;
    cin >> tipo;
    if (tipo == 1)
    {
      int l, r;
      cin >> l >> r;
      st.modificar(l, r - 1, 0);
    }
    else
    {
      int k; cin >> k;
      cout << st.kth_one(k + 1) << "\n";
    }
  }

  return 0;
}